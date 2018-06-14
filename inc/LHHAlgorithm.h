#pragma once
#pragma execution_character_set("utf-8")

#ifndef _LHH_ALGORITHM_H
#define _LHH_ALGORITHM_H

#include "AlgoConf.h"
#include "Algorithm.h"
#include "AlgorithmBuilder.h"

class LHHAlgorithm : public Algorithm{
public:
	LHHAlgorithm(const QString& algorithmsDir, const QString &_algoName) : Algorithm(algorithmsDir, _algoName){}
public:
	void loadEnvAndArgs(OperaType type, QStringList &env, QStringList &args) override {
		Algorithm::loadEnvAndArgs(type, env, args);
		type == ENCODE ? args.append(AlgoConf::emb_secret_path()) : args.append(AlgoConf::ext_secret_path());
	}
};

class LHHBuilder : public AlgorithmBuilder{
	IAlgorithm *ctor(const QString& exeRootDir, const QString &_algoName) override{
		return new LHHAlgorithm(exeRootDir, _algoName);
	}
};


#endif