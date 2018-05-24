#pragma once
#pragma execution_character_set("utf-8")

#include <QString>
#include <QCoreApplication>

inline QString app_dir(){
	return QCoreApplication::applicationDirPath();
}
