#pragma once
#pragma execution_character_set("utf-8")

#ifndef _ALGORITHM_PROCESS_INFORMATION_H
#define _ALGORITHM_PROCESS_INFORMATION_H

#include "IAlgorithm.h"

class Algorithm : public IAlgorithm{

public:
	Algorithm(const QString &algorithmsDir, const QString &_algoName) :IAlgorithm(algorithmsDir, _algoName){}

public:
	void sync(OperaType type)override;
	const QString get(OperaType type, const QString& key)override;
	const QString algo_name() override;
	const QString workspace() override;
	const QString encoder_path()override;
	const QString decoder_path() override;
	const QString encoder_cfg_path() override;
	const QString decoder_cfg_path() override;
	const QString exe_path(OperaType type) override;
	const QHash<QString, QString> &param_map(OperaType type) override;
	const QString config_get(const QString &key, OperaType type) override;
	const Config &config(OperaType type) override;
	const QString secert_file_path(OperaType type) override;
	int encode_width() override;
	int encode_height() override;
	int encode_frames() override;

	const QString input_file_path(OperaType type) override;
	const QString output_file_path(OperaType type) override;
	void input_file_path(OperaType type, const QString &path)override;
	void output_file_path(OperaType type, const QString &path);
	void encode_frames(const int frames)override;
	void encode_width_height(int w, int h) override;
	void secert_file_path(OperaType type, const QString &path) override;
	void config_set(const QString &key, const QString& val, OperaType type)override;

	void add_param(OperaType type, const QString &key, const QString& val) override;
	void del_param(OperaType type, const QString &key) override;
	void clear_param(OperaType type) override;
};

#endif