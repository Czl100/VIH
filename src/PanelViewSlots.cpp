#pragma once
#pragma execution_character_set("utf-8")

#include "PanelView.h"
#include <QUrl>
#include <QMediaPlayer>
#include <QVideoWidget> 
#include <QPushButton>
#include <QLineEdit>

void PanelView::open_media_slot(const QString& path){
	if (path.size()){
		__player__->stop();
		__player__->setMedia(QUrl::fromLocalFile(path));
		__player__->play();
		__player__->pause();
		__playButton__->setDisabled(false);
		__embShowButton__->setDisabled(false);
		__extShowButton__->setDisabled(false);
	}
	else{
		__playButton__->setDisabled(true);
		__embShowButton__->setDisabled(true);
		__extShowButton__->setDisabled(true);
	}
}

void PanelView::play_slot(OperaStatus status){
	switch (status){
	case STOP:
		__player__->stop();
		break;
	case RUNNING:
		__player__->play();
		__playButton__->setText("暂停");
		break;
	case PAUSE:
		__player__->pause();
		__playButton__->setText("播放");
		break;
	}
}

void PanelView::open_emb_secert_slot(const QString& path){
	__embSecretEdit__->setText(path);
}

void PanelView::save_emb_media_slot(const QString& path){
	__embMediaEdit__->setText(path);
}

void PanelView::save_ext_secert_slot(const QString& path){
	__extSecretEdit__->setText(path);
}