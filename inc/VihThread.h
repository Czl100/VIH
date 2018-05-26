#pragma once
#pragma execution_character_set("utf-8")

#ifndef __VIH_THREAD_H
#define __VIH_THREAD_H

#include <QThread>
#include <QString>
#include <QStringList>

class PanelStatusModel;

class VihThread : public QThread{
public:
	VihThread(const QString& mediaPath, const PanelStatusModel& model);
	~VihThread(){}

public:
	void stop();

protected:
	void run() override;

private:
	QString __mediaPath__;
	QString __workspace__;
	QString __exePath__;
	QStringList __env__;
	QStringList __args__;
	int base;
	volatile bool stopped;
};

#endif
