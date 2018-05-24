#pragma once
#pragma execution_character_set("utf-8")

#include "PanelController.h"
#include "IPanelView.h"
#include "PanelStatusModel.h"
#include <QFileDialog>
#include <QUrl>

void PanelController::open_video_slot(){
	QString path = QFileDialog::getOpenFileName(nullptr, "选择多媒体文件", ".", "*.*");
	if (path.size() == 0){
		return;
	}
	__statusModel__->media_path(path);

}

void PanelController::play_video_slot(){
	__statusModel__->playing(!__statusModel__->playing());
}

void PanelController::play_progress_slot(){

}

void PanelController::open_secert_slot() {
	QString path = QFileDialog::getOpenFileName(nullptr, "选择秘密文件", ".", "*.*");
	if (path.size() == 0){
		return;
	}
	__statusModel__->secert_path(path);
}

void PanelController::start_vih_slot(){

}

void PanelController::start_ext_slot() {

}
