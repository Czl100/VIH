#pragma once
#pragma execution_character_set("utf-8")

#ifndef _LHH_ALGORITHM_H
#define _LHH_ALGORITHM_H

#include "Algorithm.h"

class LHHInfo : public Algorithm{
public:
	LHHInfo(const QString& algorithmsDir, const QString &_algoName) : Algorithm(algorithmsDir, _algoName){}
public:
	void loadEnvAndArgs(OperaType type, QStringList &env, QStringList &args) override {
		Algorithm::loadEnvAndArgs(type, env, args);
		type == ENCODE ? args.append(__secertFilePath__[0]) : args.append(__secertFilePath__[1]);
	}
};


#endif