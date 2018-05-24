#pragma once
#pragma execution_character_set("utf-8")

#include "PanelView.h"
#include "IPanelController.h"
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QProgressBar>
#include <QLabel>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

PanelView::PanelView(QWidget *parent) : IPanelView(parent),
__player__(new QMediaPlayer()), 
__playButton__(new QPushButton("播放")), __openMediaButton__(new QPushButton("打开")), __vihShowButton__(new QPushButton("信息隐藏")),
__vihWidget__(new QWidget), __progress__(new QProgressBar), __secertEdit__(new QLineEdit),
__hideButton__(new QPushButton("嵌入")), __extButton__(new QPushButton("提取")), __openSecertButton__(new QPushButton("..")){
	
	setWindowTitle("视频信息隐藏系统");
	__progress__->setRange(0, 100);
	__progress__->setValue(0);
	__openSecertButton__->setFixedSize(22, 22);
	__init_layout__();
}

void PanelView::__init_layout__(){
	// 1).配置中心组件以及基础布局
	setCentralWidget(new QWidget);
	QVBoxLayout *panelLayout = new QVBoxLayout;
	centralWidget()->setLayout(panelLayout);

	// 2).添加视频播放相关组件布局
	QVBoxLayout * playerLayout = new QVBoxLayout;
	QHBoxLayout * playerButtonLayout = new QHBoxLayout;
	QVideoWidget* vw = new QVideoWidget();
		// 2.1).配置videoWidget的属性
		vw->setMinimumSize(500, 400);
		QPalette pal(vw->palette());
		pal.setColor(QPalette::Background, Qt::black);
		vw->setAutoFillBackground(true);
		vw->setPalette(pal);
	__player__->setVideoOutput(vw);
	playerButtonLayout->addWidget(__openMediaButton__);
	playerButtonLayout->addWidget(__playButton__);
	playerButtonLayout->addWidget(__vihShowButton__);
	playerLayout->addWidget(vw);
	playerLayout->addLayout(playerButtonLayout);

	// 3).信息隐藏界面
	QVBoxLayout* vihLayout = new QVBoxLayout;
	__vihWidget__->setLayout(vihLayout);
		// 3.1).
		QHBoxLayout* secLayout = new QHBoxLayout;
		secLayout->addWidget(new QLabel("秘密文件"));
		secLayout->addWidget(__secertEdit__);
		secLayout->addWidget(__openSecertButton__);
		// 3.2).
		QHBoxLayout* vihStartLayout = new QHBoxLayout;
		__vihWidget__->setLayout(vihStartLayout);
		vihStartLayout->addWidget(new QLabel("工作进度"));
		vihStartLayout->addWidget(__progress__);			// 进度条
		vihStartLayout->addWidget(__hideButton__);			// 按钮
		vihStartLayout->addWidget(__extButton__);			// 按钮
	vihLayout->addLayout(secLayout);
	vihLayout->addLayout(vihStartLayout);
	__vihWidget__->hide();

	// 4).
	panelLayout->addLayout(playerLayout);
	panelLayout->addWidget(__vihWidget__);
	panelLayout->addLayout(secLayout);

	// 5).菜单栏
	QMenu *toolMenu = menuBar()->addMenu("工具箱");
}

void PanelView::link_controller(const IPanelController &controller){
	// 打开多媒体选择目录的按钮事件注册
	connect(__openMediaButton__, SIGNAL(clicked()), &controller, SLOT(open_video_slot()));

	// 播放按钮事件注册
	connect(__playButton__, SIGNAL(clicked()), &controller, SLOT(play_video_slot()));

	// 显示和隐藏 信息隐藏相关的操作。
	connect(__vihShowButton__, &QPushButton::clicked, this, [=](){
		__vihWidget__->isHidden() ? __vihWidget__->show() : __vihWidget__->hide();
	});

	// 
	connect(__openSecertButton__, SIGNAL(clicked()), &controller, SLOT(open_secert_slot()));
	connect(__hideButton__, SIGNAL(clicked()), &controller, SLOT(start_vih_slot()));
	connect(__extButton__, SIGNAL(clicked()), &controller, SLOT(start_ext_slot()));
}

