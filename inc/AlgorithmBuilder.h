#pragma once
#pragma execution_character_set("utf-8")

#ifndef __ALGORITHM_BUILDER_H
#define __ALGORITHM_BUILDER_H

#include <QString>
#include "IAlgorithm.h"

class AlgorithmBuilder{
public:
	// 该函数的职责是 调用算法的构造函数并返回
	virtual IAlgorithm *ctor(const QString& exeRootDir, const QString &_algoName) = 0;
private:
	IAlgorithm *build(const QString& exeRootDir, const QString &_algoName){
		// 校验

		// 创建
		return ctor(exeRootDir, _algoName);
	}
};

#endif
