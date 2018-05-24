#pragma once
#pragma execution_character_set("utf-8")

#ifndef __PANEL_CONTROLLER_
#define __PANEL_CONTROLLER_

#include "IPanelController.h"

class PanelController : public IPanelController{
	Q_OBJECT
public slots :
	void open_video_slot() override;
	void play_video_slot() override;
	void play_progress_slot() override;

	void open_secert_slot() override;
	void start_vih_slot() override;
	void start_ext_slot() override;
};

#endif