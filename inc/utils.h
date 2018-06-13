#pragma once
#pragma execution_character_set("utf-8")

#include <QString>
#include <QCoreApplication>
#include <QTextCodec>

inline QString app_dir(){
	return QCoreApplication::applicationDirPath();
}

QString to_gb2312(const QString& str)
{
	QTextCodec* gb2312Codec = QTextCodec::codecForName("gb2312");

	QByteArray byteGb2312 = gb2312Codec->fromUnicode(str);

	return QString(byteGb2312);
}
