#pragma once
#pragma execution_character_set("utf-8")

#ifndef __ALGO_CONF_H
#define __ALGO_CONF_H

#include <QString>
#include <memory>
#include "Config.h"
#include "EncoderConfig.h"
#include "DecoderConfig.h"
#include "defines.h"

class AlgoConf{
public:
	// ���㷨�����ļ�
	static void open_algorithm_config(const QString &algorithmsDir);
	// ͬ��
	static void sync(OperaType type);
	

	// ����
	static const QString encoder_cfg_path();						// ��ñ����������ļ�·��
	static const QString decoder_cfg_path();						// ��ý����������ļ�·��
	static const Config &config(OperaType type);					// ֱ�ӷ��������ļ�
	static const QString get(OperaType type, const QString& key);	// ��ȡ�����ļ���ֵ
	static int encode_width();										// ����Ŀ��
	static int encode_height();										// ����ĸ߶�
	static int encode_frames();										// �����֡��
	static int encode_fps();										// ���������
	static const QString input_file_path(OperaType type);			// ����������ļ�·��
	static const QString output_file_path(OperaType type);			// ����������ļ�·��
	static const QString emb_secret_path();
	static const QString ext_secret_path();

	// д��
	static void set(const QString &key, const QString& val, OperaType type);
	static void encode_width_height(int w, int h);
	static void encode_width(int w);										// ����Ŀ��
	static void encode_height(int h);										// ����ĸ߶�
	static void encode_frames(const int frames);							// ���ñ���֡��
	static void encode_fps(const int fps);									// ��������
	static void output_file_path(OperaType type, const QString &path);		// ����������ļ�·��
	static void input_file_path(OperaType type, const QString &path);		// ����������ļ�·��
	static void emb_secret_path(const QString& path);
	static void ext_secret_path(const QString& path);

protected:
	static std::shared_ptr<Config> s_cfg[2];			// 0-����������ļ��� 1-����������ļ�
	static QString s_encoderCfgPath;
	static QString s_decoderCfgPath;
	static bool s_isopenAlgoConfig;
	static QString s_embSecretPath;
	static QString s_extSecretPath;
};

#endif