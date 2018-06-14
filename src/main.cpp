#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QApplication>
#include <QtCore/QDir>
#include <PanelController.h>
#include <PanelView.h>
#include <PanelStatusModel.h>
#include <memory>
#include "AlgoConf.h"
#include "LHHAlgorithm.h"
#include "WTQAlgorithm.h"
#include "defines.h"

using namespace std;

void loadModel(shared_ptr<PanelStatusModel> m){
	QString algorithmsRootDir = "algorithms/";
	// 建立builder映射
	QHash<QString, AlgorithmBuilder*> builderMap;
	builderMap.insert("LHH", new LHHBuilder());
	builderMap.insert("WTQ", new WTQBuilder());

	// 算法配置文件
	AlgoConf::open_algorithm_config(algorithmsRootDir);

	// 算法运行环境初始化
	EncoderConfig cfg(app_config_path());
	QString algorithms = cfg.get("algorithms");
	QStringList algorithmList = algorithms.split(";");
	for (int i = 0; i < algorithmList.size(); i++){
		QString &algorithm = algorithmList[i].simplified();
		if (algorithm.startsWith('[') && algorithm.endsWith(']')){
			QStringList parts = algorithm.mid(1, algorithm.size() - 2).split(",");
			QString &aname = parts[0];
			QString &builderName = parts[1].simplified();
			AlgorithmBuilder *builder = builderMap[builderName];
			if (builder){
				IAlgorithm *algo = builder->ctor(algorithmsRootDir, aname);
				if (algo){
					m->add_algorithm(shared_ptr<IAlgorithm>(algo));
				}
			}
		}
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// 配置工作路径为exe文件所在路径
	QDir::setCurrent(QCoreApplication::applicationDirPath());
	
	

	// 构建MVC
	shared_ptr<PanelController> c = shared_ptr<PanelController>(new PanelController);
	shared_ptr<PanelView> v = shared_ptr<PanelView>(new PanelView);
	shared_ptr<PanelStatusModel> m = shared_ptr<PanelStatusModel>(new PanelStatusModel);

	// 链接MVC
	loadModel(m);
	c->set_view(v);
	c->set_status_model(m);

	v->show();
	return a.exec();
}


