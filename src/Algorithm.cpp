#pragma once
#pragma execution_character_set("utf-8")

#include "Algorithm.h"

std::shared_ptr<Config> Algorithm::s_cfg[2] = {nullptr, nullptr};
QString Algorithm::s_encoderCfgPath = "";
QString Algorithm::s_decoderCfgPath = "";

void Algorithm :: sync(OperaType type){
	s_cfg[type]->sync();
}
const QString Algorithm::get(OperaType type, const QString& key){
	return s_cfg[type]->get(key);
}
const QString Algorithm::algo_name() {
	return __algoName__;
}
const QString Algorithm::workspace() {
	return __workspace__;
}
const QString Algorithm::encoder_path(){
	return __encoderPath__;
}
const QString Algorithm::decoder_path() {
	return __decoderPath__;
}
const QString Algorithm::encoder_cfg_path() {
	return s_encoderCfgPath;
}
const QString Algorithm::decoder_cfg_path() {
	return s_decoderCfgPath;
}
const QString Algorithm::exe_path(OperaType type) {
	return type == ENCODE ? __encoderPath__ : __decoderPath__;
}
const QHash<QString, QString> &Algorithm::param_map(OperaType type) {
	return __algoParams__[type];
}
const QString Algorithm::config_get(const QString &key, OperaType type) {
	return s_cfg[type]->get(key);
}
const Config &Algorithm::config(OperaType type) {
	return *s_cfg[type];
}
const QString Algorithm::secert_file_path(OperaType type) {
	return __secertFilePath__[type];
}
int Algorithm::encode_width() {
	return s_cfg[ENCODE]->get("SourceWidth").toInt();
}
int Algorithm::encode_height() {
	return s_cfg[ENCODE]->get("SourceHeight").toInt();
}
int Algorithm::encode_frames() {
	return s_cfg[ENCODE]->get("FramesToBeEncoded").toInt();
}
const QString Algorithm::input_file_path(OperaType type) {
	return s_cfg[type]->get("InputFile");
}
const QString Algorithm::output_file_path(OperaType type) {
	return s_cfg[type]->get("OutputFile");
}
void Algorithm::input_file_path(OperaType type, const QString &path){
	s_cfg[type]->set("InputFile", path);
}
void Algorithm::output_file_path(OperaType type, const QString &path){
	s_cfg[type]->set("OutputFile", path);
}
void Algorithm::encode_frames(const int frames){
	s_cfg[0]->set("FramesToBeEncoded", QString::number(frames));
}
void Algorithm::encode_width_height(int w, int h) {
	s_cfg[0]->set("SourceWidth", QString::number(w)); s_cfg[0]->set("SourceHeight", QString::number(h));
}
void Algorithm::secert_file_path(OperaType type, const QString &path) {
	__secertFilePath__[type] = path;
}
void Algorithm::config_set(const QString &key, const QString& val, OperaType type){
	s_cfg[type]->set(key, val);
}

void Algorithm::add_param(OperaType type, const QString &key, const QString& val){
	__algoParams__[type][key] = val;
}
void Algorithm::del_param(OperaType type, const QString &key){
	__algoParams__[type].remove(key);
}
void Algorithm::clear_param(OperaType type){
	__algoParams__[type].clear();
}