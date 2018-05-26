#pragma once
#pragma execution_character_set("utf-8")

#include "VihThread.h"
#include "PanelStatusModel.h"

VihThread::VihThread(const QString& mediaPath, const PanelStatusModel& model){
	__mediaPath__ = mediaPath;
}

void VihThread::run(){

}