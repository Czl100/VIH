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
		__vihShowButton__->setDisabled(false);
	}
	else{
		__playButton__->setDisabled(true);
		__vihShowButton__->setDisabled(true);
	}
}

void PanelView::play_slot(bool isplaying){
	isplaying ? __player__->play() : __player__->pause();
	__playButton__->setText(isplaying ? "暂停" : "播放");
}

void PanelView::open_secert_slot(const QString& path){
	__secertEdit__->setText(path);
}