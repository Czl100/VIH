#ifndef __PANEL_STATUS_MODEL_H
#define __PANEL_STATUS_MODEL_H

#include <QObject>
#include <memory>

class QString;
class IPanelView;

class PanelStatusModel : public QObject{

	Q_OBJECT

// ���͵��ź�
signals :
	void open_media_path_signal(const QString& path);
	void play_signal(bool isplay);

// ��ʼ��
public:
	PanelStatusModel() :__mediaPath__(""), __isplaying__(false){}

// ���źź�view��slots����
public:
	void set_view(std::shared_ptr<IPanelView> v);

// ������
public:
	void media_path(const QString& path);
	void playing(bool isplaying);

// д����
public:
	const QString& media_path();
	bool playing();

private:
	QString __mediaPath__;
	bool __isplaying__;
};

#endif