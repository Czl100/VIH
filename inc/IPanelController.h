#pragma once
#pragma execution_character_set("utf-8")

#ifndef __INTERFACE_PANEL_CONTROLLER_
#define __INTERFACE_PANEL_CONTROLLER_

#include <QtCore/QObject>
#include <memory>

class IPanelView;
class PanelStatusModel;

class IPanelController : public QObject{
	Q_OBJECT
public:
	IPanelController():__view__(nullptr){}
	~IPanelController(){ }	
	void set_view(std::shared_ptr<IPanelView> view);
	void set_status_model(std::shared_ptr<PanelStatusModel> model);

public slots :

	virtual void open_video_slot() = 0;		// 打开目录选择视频文件
	virtual void play_video_slot() = 0;		// 播放视频
	virtual void play_progress_slot() = 0;	// 调整进度条

	virtual void open_secert_slot() = 0;	// 打开目录选择秘密文件
	virtual void start_vih_slot() = 0;		// 开始视频信息隐藏
	virtual void start_ext_slot() = 0;		// 开始视频信息提取

protected:
	std::shared_ptr<IPanelView> __view__;
	std::shared_ptr<PanelStatusModel> __statusModel__;
};

#endif