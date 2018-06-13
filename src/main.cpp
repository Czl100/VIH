#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QApplication>
#include <QtCore/QDir>
#include <PanelController.h>
#include <PanelView.h>
#include <PanelStatusModel.h>
#include <memory>
#include "AlgoConf.h"
#include "LHHAlgorithm.h"
#include "WTQAlgorithm.h"

using namespace std;

void loadModel(shared_ptr<PanelStatusModel> m);
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// 配置工作路径为exe文件所在路径
	QDir::setCurrent(QCoreApplication::applicationDirPath());
	
	shared_ptr<PanelController> c = shared_ptr<PanelController>(new PanelController);
	shared_ptr<PanelView> v = shared_ptr<PanelView>(new PanelView);
	shared_ptr<PanelStatusModel> m = shared_ptr<PanelStatusModel>(new PanelStatusModel);

	loadModel(m);
	c->set_view(v);
	c->set_status_model(m);

	v->show();
	return a.exec();
}

void loadModel(shared_ptr<PanelStatusModel> m){
	QString algorithmsRootDir = "algorithms/";
	AlgoConf::open_algorithm_config(algorithmsRootDir);
	// LHH
	m->add_algorithm(shared_ptr<Algorithm>(new LHHAlgorithm(algorithmsRootDir, "三维低码率增长信息隐藏")));
	m->add_algorithm(shared_ptr<Algorithm>(new LHHAlgorithm(algorithmsRootDir, "基于循环码的信息隐藏")));
	m->add_algorithm(shared_ptr<Algorithm>(new LHHAlgorithm(algorithmsRootDir, "参考像素多分类的QDCT域信息隐藏")));
	// WTQ
	m->add_algorithm(shared_ptr<Algorithm>(new WTQAlgorithm(algorithmsRootDir, "低码率增长信息隐藏")));
	m->add_algorithm(shared_ptr<Algorithm>(new WTQAlgorithm(algorithmsRootDir, "适应拖尾系数信息隐藏")));
	m->add_algorithm(shared_ptr<Algorithm>(new WTQAlgorithm(algorithmsRootDir, "三元码信息隐藏")));
}
