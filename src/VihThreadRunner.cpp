
#include "VihThreadRunner.h"

bool VihThreadRunner::start(std::shared_ptr<VihThread> t){
	// 若还有线程在运行，则放弃运行新线程。
	if (__status__ == RUNNING){
		return false;
	}
	__t__ = t;
	connect(__t__.get(), &VihThread::algoMessageSignal, this, [&](int exitCode, const QString &line, int val){
		// 停止
		if (val == 100){
			__status__ = STOP;
		}
		emit runnerSignal(exitCode, line, val);
	});


	__t__->start();
	__status__ = RUNNING;
	return true;
}

void VihThreadRunner::stop(){
	if (__status__ != STOP){
		__t__->stop();
		__status__ = STOP;
	}
}
