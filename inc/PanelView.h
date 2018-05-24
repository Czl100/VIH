#pragma once
#pragma execution_character_set("utf-8")

#ifndef __PANEL_VIEW_H
#define __PANEL_VIEW_H

#include "IPanelView.h"
#include <QString>

class QMediaPlayer;
class QPushButton;
class IPanelController;
class QProgressBar;
class QLineEdit;

class PanelView : public IPanelView{
	Q_OBJECT
public:
	PanelView(QWidget *parent = nullptr);

public slots :
	void open_media_slot(const QString& mediaPath) override;
	void play_slot(bool isplaying) override;
	void open_secert_slot(const QString& mediaPath) override;

	void link_controller(const IPanelController &controller) override;

private:
	void __init_layout__();

private:
	QMediaPlayer* __player__;
	QPushButton* __playButton__;
	QPushButton* __openMediaButton__;
	QPushButton* __vihShowButton__;
	QPushButton* __hideButton__;
	QPushButton* __extButton__;
	QProgressBar* __progress__;
	QWidget* __vihWidget__;
	QLineEdit* __secertEdit__;
	QPushButton* __openSecertButton__;
};


#endif