#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QApplication>
#include <QtCore/QDir>
#include <PanelController.h>
#include <PanelView.h>
#include <PanelStatusModel.h>
#include <memory>

using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// 配置工作路径为exe文件所在路径
	QDir::setCurrent(QCoreApplication::applicationDirPath());

	shared_ptr<PanelController> c = shared_ptr<PanelController>(new PanelController);
	shared_ptr<PanelView> v = shared_ptr<PanelView>(new PanelView);
	shared_ptr<PanelStatusModel> m = shared_ptr<PanelStatusModel>(new PanelStatusModel);

	c->set_view(v);
	c->set_status_model(m);

	v->show();
	return a.exec();
}
/*
void loadModel(shared_ptr<PanelStatusModel> pmodel){
	QHash<QString, AlgorithmInfoBuilder*> builderMap;
	builderMap.insert("simple", new AlgorithmInfoBuilder());
	builderMap.insert("LHH", new LHHInfoBuilder());
	builderMap.insert("WTQ", new WTQInfoBuilder());

	EncoderConfig cfg(getApplicationConfigFilePath());
	QString exeRootDir = cfg.get("exeRootDir");
	QString algorithms = cfg.get("algorithms");
	QStringList algorithmList = algorithms.split(";");
	if (exeRootDir.size() == 0){
		exeRootDir = "exe";
		qDebug() << "[warning]";
	}
	for (int i = 0; i < algorithmList.size(); i++){
		QString &algorithm = algorithmList[i].simplified();
		if (algorithm.startsWith('[') && algorithm.endsWith(']')){
			QStringList parts = algorithm.mid(1, algorithm.size() - 2).split(",");
			QString &aname = parts[0];
			QString &builderName = parts.size() == 2 ? parts[1].simplified() : "simple";
			AlgorithmInfoBuilder *builder = builderMap[builderName];
			if (builder){
				AlgorithmInfo *info = builder->build(exeRootDir, aname);
				if (info){
					pmodel->add(info);
				}
			}
			else{
				qDebug() << "[Exception]   not found builder, builderName:'" + builderName + "'";
			}
		}
		else{
			qDebug() << "[Exception]   package symbol is error,algorithm:'" + algorithmList[i] + "'";
		}
	}

	for (int i = 0; i < builderMap.keys().size(); i++){
		delete builderMap[builderMap.keys()[i]];
	}
}
*/