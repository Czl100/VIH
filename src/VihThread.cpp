#pragma once
#pragma execution_character_set("utf-8")

#include "VihThread.h"

#include <QDebug>
#include <string>
#include <memory>

using namespace std;

void VihThread::processErrorSlot(QProcess::ProcessError error){
	// 进程的运行出现问题，将会导致异常结束。
	if (stopped){
		emit algoMessageSignal(-1, "Stop Process", 100);
	}
	else{
		switch (error){
		case QProcess::FailedToStart: emit algoMessageSignal(-1, "FailedToStart", 100);  break;
		case QProcess::Crashed: emit algoMessageSignal(-1, "Crashed", 100);  break;
		case QProcess::Timedout: emit algoMessageSignal(-1, "Timedout", 100);  break;
		case QProcess::ReadError: emit algoMessageSignal(-1, "ReadError", 100);  break;
		case QProcess::WriteError: emit algoMessageSignal(-1, "WriteError", 100);  break;
		case QProcess::UnknownError: emit algoMessageSignal(-1, "UnknownError", 100); break;
		default:emit algoMessageSignal(-1, "Error", 100); break;
		}
	}
}

void VihThread::stop(){
	stopped = true;
}