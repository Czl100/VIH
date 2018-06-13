
#include "AlgoConf.h"
#include <QDir>
using namespace std;

std::shared_ptr<Config> AlgoConf::s_cfg[2] = { nullptr, nullptr };
QString AlgoConf::s_encoderCfgPath = "";
QString AlgoConf::s_decoderCfgPath = "";
bool AlgoConf::s_isopenAlgoConfig = false;

void AlgoConf::open_algorithm_config(const QString &algorithmsDir){
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
	s_isopenAlgoConfig = true;
}


void AlgoConf::sync(OperaType type){
	s_cfg[type]->sync();
}

// ================================ 读出 ================================
const QString AlgoConf::encoder_cfg_path(){
	return s_encoderCfgPath;
}
const QString AlgoConf::decoder_cfg_path(){
	return s_decoderCfgPath;
}
const QString AlgoConf::get(OperaType type, const QString& key){
	return s_cfg[type]->get(key);
}
const Config &AlgoConf::config(OperaType type){
	return *s_cfg[type];
}
int AlgoConf::encode_width(){
	return s_cfg[ENCODE]->get("SourceWidth").toInt();
}
int AlgoConf::encode_height(){
	return s_cfg[ENCODE]->get("SourceHeight").toInt();
}
int AlgoConf::encode_frames(){
	return s_cfg[ENCODE]->get("FramesToBeEncoded").toInt();
}
int AlgoConf::encode_fps(){
	return s_cfg[ENCODE]->get("FrameRate").toInt();
}
const QString AlgoConf::input_file_path(OperaType type){
	return s_cfg[type]->get("InputFile");
}
const QString AlgoConf::output_file_path(OperaType type){
	return s_cfg[type]->get("OutputFile");
}

// ================================ 写入 ================================
void AlgoConf::set(const QString &key, const QString& val, OperaType type){
	s_cfg[type]->set(key, val);
}
void AlgoConf::encode_width_height(int w, int h){
	s_cfg[ENCODE]->set("SourceWidth", QString::number(w)); 
	s_cfg[ENCODE]->set("SourceHeight", QString::number(h));
}
void AlgoConf::encode_width(int w){
	s_cfg[ENCODE]->set("SourceWidth", QString::number(w));
}
void AlgoConf::encode_height(int h){
	s_cfg[ENCODE]->set("SourceHeight", QString::number(h));
}
void AlgoConf::encode_frames(const int frames){
	s_cfg[ENCODE]->set("FramesToBeEncoded", QString::number(frames));
}
void AlgoConf::encode_fps(const int fps){
	s_cfg[ENCODE]->set("FrameRate", QString::number(fps));
}
void AlgoConf::output_file_path(OperaType type, const QString &path){
	if (type == ENCODE){
		s_cfg[type]->set("OutputFile", "\"" + path + "\"");
	}
	else{
		s_cfg[type]->set("OutputFile", path);
	}
}
void AlgoConf::input_file_path(OperaType type, const QString &path){
	if (type == ENCODE){
		s_cfg[type]->set("InputFile", "\"" + path + "\"");
	}
	else{
		s_cfg[type]->set("InputFile", path);
	}
}