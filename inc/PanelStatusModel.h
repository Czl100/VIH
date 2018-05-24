#ifndef __PANEL_STATUS_MODEL_H
#define __PANEL_STATUS_MODEL_H

#include <QObject>
#include <memory>

class QString;
class IPanelView;

class PanelStatusModel : public QObject{

	Q_OBJECT

// 发送的信号
signals :
	void open_media_path_signal(const QString& path);
	void open_secert_path_signal(const QString& path);
	void play_signal(bool isplay);

// 初始化
public:
	PanelStatusModel() :__mediaPath__(""), __isplaying__(false){}

// 将信号和view的slots连接
public:
	void set_view(std::shared_ptr<IPanelView> v);

// 写函数
public:
	void media_path(const QString& path);
	void playing(bool isplaying);
	void secert_path(const QString& path);

// 读函数
public:
	const QString& media_path();
	bool playing();
	const QString& secert_path();

private:
	QString __mediaPath__;
	QString __secertPath__;
	bool __isplaying__;
};

#endif