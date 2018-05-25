#ifndef _DEFINES_H
#define _DEFINES_H

#include <QString>

inline const QString& getApplicationConfigFilePath(){
	static QString APPLICATION_CONFIG_FILE = "app.cfg";
	return APPLICATION_CONFIG_FILE;
}

// �������ͣ����롢����
enum OperaType{
	ENCODE = 0,
	DECODE
};

// ����״̬��ֹͣ�����С���ͣ��
enum OperaStatus{
	STOP=0,
	RUNNING,
	PAUSE
};

#endif