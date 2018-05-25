#pragma once
#pragma execution_character_set("utf-8")

#ifndef __INTERFACE_ALGORITHM_H
#define __INTERFACE_ALGORITHM_H

#include <QString>
#include <memory>
#include "DecoderConfig.h"
#include "EncoderConfig.h"
#include "defines.h"

class IAlgorithm {

public:
	IAlgorithm(const QString &algorithmsDir, const QString &_algoName) :
		__algoName__(_algoName)
		{
			__exespace__ = algorithmsDir + "/" + __algoName__ + "/";
			__encoderPath__ = __exespace__ + "lencod.exe";
			__decoderPath__ = __exespace__ + "ldecod.exe";
			__workspace__ = __exespace__ + "/workspace";

	}

	virtual ~IAlgorithm(){}

public:
	virtual void sync(OperaType type) = 0;		//同步
	virtual const QString get(OperaType type, const QString& key) = 0;	// 获取值
	virtual const QString algo_name() = 0;								// 获得算法的名字
	virtual const QString workspace() = 0;								// 获得算法工作路径
	virtual const QString encoder_path() = 0;							// 获得算法的编码器路径
	virtual const QString decoder_path() = 0;							// 获得算法解码器路径
	virtual const QString encoder_cfg_path() = 0;						// 获得编码器配置文件路径
	virtual const QString decoder_cfg_path() = 0;						// 获得解码器配置文件路径
	virtual const QString exe_path(OperaType type) = 0;					// 获得可执行文件路径
	virtual const QHash<QString, QString> &param_map(OperaType type) = 0;		// 获得输入参数的mapper
	virtual const QString config_get(const QString &key, OperaType type) = 0;	// 获得配置文件中的数据
	virtual const Config &config(OperaType type) = 0;							// 直接返回配置文件
	virtual const QString secert_file_path(OperaType type) = 0;					// 返回秘密文件路径
	virtual int encode_width() = 0;												// 编码的宽度
	virtual int encode_height() = 0;											// 编码的高度
	virtual int encode_frames() = 0;											// 编码的帧数
	virtual const QString input_file_path(OperaType type) = 0;					// 输入的yuv文件路径
	virtual const QString output_file_path(OperaType type) = 0;					// 输出的264文件路径

	virtual void input_file_path(OperaType type, const QString &path) = 0;		// 设置输入的文件路径
	virtual void output_file_path(OperaType type, const QString &path) = 0;		// 设置输出的文件路径
	virtual void encode_frames(const int frames) = 0;							// 设置编码帧数
	virtual void encode_width_height(int w, int h) = 0;							// 设置编码宽度和高度
	virtual void secert_file_path(OperaType type, const QString &path) = 0;		// 设置秘密文件路径
	virtual void config_set(const QString &key, const QString& val, OperaType type) = 0;	// 设置配置文件的值

	virtual void add_param(OperaType type, const QString &key, const QString& val) = 0;		// 添加参数对
	virtual void del_param(OperaType type, const QString &key) = 0;							// 删除参数对
	virtual void clear_param(OperaType type) = 0;											// 清空参数

	// 默认参数加载方案，配置命令所需要的args和环境变量env
	virtual void loadEnvAndArgs(OperaType type, QStringList &env, QStringList &args);

protected:
	QString __workspace__;
	QString __exespace__;
	const QString __algoName__;
	QString __encoderPath__;
	QString __decoderPath__;

	QHash<QString, QString> __algoParams__[2];	// 0-编码的参数模型， 1-解码的参数模型
	QString __secertFilePath__[2];

protected:
	static std::shared_ptr<Config> s_cfg[2];			// 0-编码的配置文件， 1-解码得配置文件
	static QString s_encoderCfgPath;
	static QString s_decoderCfgPath;

public:

	static void open_algorithm_config(const QString &algorithmsDir){
		s_encoderCfgPath = algorithmsDir + "/encoder.cfg";
		s_decoderCfgPath = algorithmsDir + "/decoder.cfg";

		// 加载配置文件到内存
		s_cfg[0] = std::shared_ptr<Config>(new EncoderConfig(s_encoderCfgPath));
		DecoderConfig *dcfg = new DecoderConfig(s_decoderCfgPath);
		s_cfg[1] = std::shared_ptr<Config>(dcfg->map("InputFile", 0)
			->map("OutputFile", 1)
			->map("RefSequence", 2)
			->map("Decoded Pircture Buffer", 3)
			->map("SNR Offset", 5));
	}
};

#endif