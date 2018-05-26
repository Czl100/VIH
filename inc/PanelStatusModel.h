#pragma once
#pragma execution_character_set("utf-8")

#ifndef __PANEL_STATUS_MODEL_H
#define __PANEL_STATUS_MODEL_H

#include <QObject>
#include <memory>
#include <QList>
#include "AlgosModel.h"
#include "defines.h"

class QString;
class IPanelView;
class Algorithm;

class PanelStatusModel : public QObject, public AlgosModel{

	Q_OBJECT

// 发送的信号
signals :
	void open_media_path_signal(const QString& path);
	void open_secert_path_signal(const QString& path);
	void play_signal(OperaStatus status);

// 初始化
public:
	PanelStatusModel() :__mediaPath__(""), __playStatus__(STOP){}

// 将信号和view的slots连接
public:
	void set_view(std::shared_ptr<IPanelView> v);

// 写函数
public:
	void media_path(const QString& path);
	void play_status(OperaStatus status);
	void secert_path(const QString& path);

// 读函数
public:
	const QString& media_path();
	OperaStatus play_status();
	const QString& secert_path();

private:
	QString __mediaPath__;
	QString __secertPath__;
	OperaStatus __playStatus__;
};

#endif