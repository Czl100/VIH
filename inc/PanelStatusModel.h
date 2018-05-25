#ifndef __PANEL_STATUS_MODEL_H
#define __PANEL_STATUS_MODEL_H

#include <QObject>
#include <memory>
#include <QList>
#include "IAlgorithm.h"
#include "defines.h"

class QString;
class IPanelView;
class Algorithm;

class PanelStatusModel : public QObject{

	Q_OBJECT

// ���͵��ź�
signals :
	void open_media_path_signal(const QString& path);
	void open_secert_path_signal(const QString& path);
	void play_signal(OperaStatus status);

// ��ʼ��
public:
	PanelStatusModel() :__mediaPath__(""), __playStatus__(STOP), __algoIdx__(0){}

// ���źź�view��slots����
public:
	void set_view(std::shared_ptr<IPanelView> v);

// д����
public:
	void media_path(const QString& path);
	void play_status(OperaStatus status);
	void secert_path(const QString& path);
	void add_algorithm(std::shared_ptr<IAlgorithm> algorithm);
	void algo_idx(int idx);

// ������
public:
	const QString& media_path();
	OperaStatus play_status();
	const QString& secert_path();
	const QStringList algos_list();
	int algo_idx();

private:
	QString __mediaPath__;
	QString __secertPath__;
	OperaStatus __playStatus__;
	QList<std::shared_ptr<IAlgorithm>> __algos__;
	int __algoIdx__;
};

#endif