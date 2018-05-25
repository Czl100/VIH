#pragma once
#pragma execution_character_set("utf-8")

#ifndef _WTQ_ALGORITHM_H
#define _WTQ_ALGORITHM_H

#include "Algorithm.h"

class WTQInfo : public Algorithm{
public:
	WTQInfo(const QString& algorithmsDir, const QString &_algoName) : Algorithm(algorithmsDir, _algoName){}
public:
	void loadEnvAndArgs(OperaType type, QStringList &env, QStringList &args) override {
		Algorithm::loadEnvAndArgs(type, env, args);
		if (type == ENCODE){
			int idx1 = __secertFilePath__[0].lastIndexOf("/");
			int idx2 = __secertFilePath__[0].lastIndexOf("\\");
			int idx = idx1 > idx2 ? idx1 : idx2;
			QString fileName = __secertFilePath__[0].right(__secertFilePath__[0].size() - idx - 1);
			args.append(fileName);
			args.append(__secertFilePath__[0]);
			args.append("4");
		}
		else{
			args.append("4");
			args.append(__secertFilePath__[1]);
		}
	}

};

#endif