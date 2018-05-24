#pragma once
#pragma execution_character_set("utf-8")

#ifndef __INTERFACE_PANEL_VIEW_
#define __INTERFACE_PANEL_VIEW_

#include <QObject>
#include <QtWidgets/QMainWindow>

class IPanelController;
class QString;

// 提供视图接口
class BasePanelView{
public:
	virtual ~BasePanelView(){}

	virtual void link_controller(const IPanelController &controller) = 0;
};

// 提供视图接口 以及 视图信号
class IPanelView : public QMainWindow, public BasePanelView{
	Q_OBJECT

public:
	IPanelView(QWidget *parent = nullptr) :QMainWindow(parent){}

public slots :
	virtual void open_media_slot(const QString& mediaPath) = 0;
	virtual void play_slot(bool isplaying) = 0;
	virtual void open_secert_slot(const QString& mediaPath) = 0;
};

#endif