#pragma once
#pragma execution_character_set("utf-8")

#include "PanelController.h"
#include "IPanelView.h"
#include "PanelStatusModel.h"
#include <QFileDialog>
#include <QUrl>

void PanelController::open_video_slot(){
	QString path = QFileDialog::getOpenFileName(nullptr, "Chose Origin YUV File", ".", "*.*");
	if (path.size() == 0){
		return;
	}
	__status_model__->media_path(path);

}

void PanelController::play_video_slot(){
	__status_model__->playing(!__status_model__->playing());
}

void PanelController::start_vih_slot(){

}
