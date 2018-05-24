#ifndef _DECODER_CONFIG_H
#define _DECODER_CONFIG_H

#include "Config.h"
#include <QHash>
#include <QList>

class DecoderConfig : public Config{
public:
	DecoderConfig(QString &_fileName) : file(new QFile(_fileName)){
		if (file->exists()){	// �ļ����ڣ���ֻ����
			file->open(QIODevice::ReadOnly);
			// ��ȡһ�У�����Ϊ�ı��ͱ��ر���ģʽ��ͬ�����������ΪQString��
			for (QString line(QString::fromLocal8Bit(file->readLine())); line.size() != 0; line = file->readLine()){
				if (line.right(2) == "\r\n"){ line = line.left(line.size() - 2); }
				if (line.right(1) == "\n"){ line = line.left(line.size() - 1); }
				QStringList sharpParts = line.split("#");
				QStringList pointParts = sharpParts[0].split("........");
				QString realLine = pointParts[0];
				content.append(realLine.simplified());
			}
			file->close();
		}
	}
	~DecoderConfig(){
		if (file->isOpen()){
			file->close();
		}
		delete file;
	}

public:
	DecoderConfig *map(QString key, int idx){
		key2idx[key] = idx;
		return this;
	}
	void set(QString key, QString value) override{
		if (key2idx.contains(key)){		// ���ڸ�key����Ը�������
			int idx = key2idx[key];
			content[idx] = value;
		}
	}
	const QString get(QString key) const override {
		static QString empty = "";
		if (key2idx.contains(key)){		// ���ڸ�key����Ը�������
			int idx = key2idx[key];
			return content[idx];
		}
		return empty;
	}
	const QStringList keys() const override {
		return key2idx.keys();
	}
	void sync() override{
		file->open(QIODevice::WriteOnly);
		for (int i = 0; i < content.size(); i++){
			file->write((content[i]+"\n").toLocal8Bit());			// ����ɱ��ر���ģʽ��ָ���ĸ�ʽ
		}
		file->flush();
		file->close();
	}

private:
	QFile *file;
	QHash<QString, int> key2idx;
	QList<QString> content;
};

#endif