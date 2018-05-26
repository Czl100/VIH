#pragma once
#pragma execution_character_set("utf-8")

#ifndef _DEFINES_H
#define _DEFINES_H

#include <QString>

inline const QString& getApplicationConfigFilePath(){
	static QString APPLICATION_CONFIG_FILE = "app.cfg";
	return APPLICATION_CONFIG_FILE;
}

// 操作类型：编码、解码
enum OperaType{
	ENCODE = 0,
	DECODE
};

// 操作状态：停止、运行、暂停。
enum OperaStatus{
	STOP=0,
	RUNNING,
	PAUSE
};

#endif