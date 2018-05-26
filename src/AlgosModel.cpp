#include "AlgosModel.h"

AlgosModel::AlgosModel():__algoIdx__(0){}

// 读函数
const QString AlgosModel::workspace(){
	return __algos__[__algoIdx__]->workspace();
}
const QString AlgosModel::exe_path(){
	return __algos__[__algoIdx__]->exe_path(__operaType__);
}
const QStringList AlgosModel::algos_list(){
	QStringList algolist;
	for (int i = 0; i < __algos__.size(); i++){
		algolist.append(__algos__[i]->algo_name());
	}
	return algolist;
}
int AlgosModel::algo_idx(){
	return __algoIdx__;
}

// 写函数
void AlgosModel::workspace(const QString& ws){

}
void AlgosModel::exe_path(const QString& ep){

}
void AlgosModel::add_algorithm(std::shared_ptr<IAlgorithm> algorithm){
	__algos__.append(algorithm);
}

void AlgosModel::algo_idx(int idx){
	__algoIdx__ = idx;
}