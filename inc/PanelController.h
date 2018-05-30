#pragma once
#pragma execution_character_set("utf-8")

#ifndef __PANEL_CONTROLLER_
#define __PANEL_CONTROLLER_

#include "IPanelController.h"
#include "VihThreadRunner.h"

class PanelController : public IPanelController{
	Q_OBJECT
public:
	PanelController();
public slots :
	void open_algorithm_slot() override;

	void open_video_slot() override;
	void play_video_slot() override;
	void play_progress_slot() override;

	void open_emb_secert_slot() override;
	void save_emb_media_slot() override;
	void start_emb_slot() override;

	void save_ext_secert_slot() override;
	void start_ext_slot() override;
	

	void runnerSlot(int exitCode, const QString &line, int val);

private:
	VihThreadRunner __runner__;
};

#endif