#ifndef _DEFINES_H
#define _DEFINES_H

#include <QString>

inline const QString& getApplicationConfigFilePath(){
	static QString APPLICATION_CONFIG_FILE = "app.cfg";
	return APPLICATION_CONFIG_FILE;
}

enum OperaType{
	ENCODE = 0,
	DECODE
};

#endif