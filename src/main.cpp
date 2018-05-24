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
