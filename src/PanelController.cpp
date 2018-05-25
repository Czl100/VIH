#pragma once
#pragma execution_character_set("utf-8")

#include "PanelController.h"
#include "IPanelView.h"
#include "PanelStatusModel.h"
#include <QFileDialog>
#include <QUrl>
#include "OpenAlgorithmsDialog.h"

void PanelController::open_video_slot(){
	QString path = QFileDialog::getOpenFileName(nullptr, "选择多媒体文件", ".", "*.*");
	if (path.size() == 0){
		return;
	}
	__statusModel__->media_path(path);

}

void PanelController::play_video_slot(){
	OperaStatus status = __statusModel__->play_status();
	switch (status){
	case PAUSE:
		__statusModel__->play_status(RUNNING);
		break;
	case RUNNING:
		__statusModel__->play_status(PAUSE);
		break;
	}
}

void PanelController::play_progress_slot(){

}

void PanelController::open_algorithm_slot(){
	OpenAlgorithmsDialog dialog = OpenAlgorithmsDialog(__statusModel__->algo_idx(), __statusModel__->algos_list());
	dialog.exec();
	int newidx = dialog.retval();
	__statusModel__->algo_idx(newidx);
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
