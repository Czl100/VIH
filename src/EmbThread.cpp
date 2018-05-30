#pragma once
#pragma execution_character_set("utf-8")

#include "EmbThread.h"
#include "empeg/Emedia.h"
#include "PanelStatusModel.h"
#include "AlgoConf.h"
#include <QDebug>

using namespace std;

EmbThread::EmbThread(shared_ptr<PanelStatusModel> model){
	__mediaPath__ = model->media_path();
	__workspace__ = model->workspace();
	__exePath__ = model->exe_path();
	model->loadEnvAndArgs(__env__, __args__);			// 秘密文件的路径是在model中的
}

void EmbThread::run(){
	// 1).media->yuv转换
	shared_ptr<Emedia> media = Emedia::generate(__mediaPath__.toStdString());
	QString yuvwhere = "D://media.yuv";
	QString audiowhere = "D://audio.aac";
	QString videowhere = "D://video.264";
	media->xyuv(yuvwhere.toStdString());
	media->xaudio(audiowhere.toStdString());
	int high = media->high();
	int width = media->width();
	int frames = media->frames();

	// 2).更新配置文件
	AlgoConf::encode_height(high);
	AlgoConf::encode_width(width);
	AlgoConf::encode_frames(frames);
	AlgoConf::input_file_path(ENCODE, yuvwhere);
	AlgoConf::output_file_path(ENCODE, videowhere);
	AlgoConf::sync(ENCODE);

	// 3).配置进程环境
	QProcess p;
	stopped = false;
	p.setWorkingDirectory(__workspace__);
	p.setEnvironment(__env__);
	qRegisterMetaType<QProcess::ProcessError>("QProcess::ProcessError");
	connect(&p, SIGNAL(error(QProcess::ProcessError)), this, SLOT(processErrorSlot(QProcess::ProcessError)));

	QString strEnv;
	QString strCmd = __exePath__ + " ";
	for (int i = 0; i < __env__.size(); i++){ strEnv.append(__env__[i] + ";"); }
	for (int i = 0; i < __args__.size(); i++){ strEnv.append(__args__[i] + " "); }
	qDebug() << QString("[Start]  cmd:%1; env:%2").arg(strCmd).arg(strEnv);

	// 4).进程开始
	p.start(__exePath__, __args__);			// 进程开始执行
	p.waitForReadyRead();
	int cnt = 1;
	// 没有读取完，或者stop为false则一直读
	for (QByteArray line = p.readLine(); line.size() != 0 && (!stopped); line = p.readLine(), cnt++){
		p.waitForReadyRead();
	}
	if (stopped){
		p.terminate();			// 终止进程, 将会触发进程错误，由此来通知主线程进程结束。
	}
	else{						// 进程正常结束
		p.waitForFinished();
		int exitCode = p.exitCode();
		emit algoMessageSignal(exitCode, "Finished", 100);
	}
	__env__.clear();
	__args__.clear();
}