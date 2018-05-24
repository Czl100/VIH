#include "PanelStatusModel.h"
#include "IPanelView.h"

void PanelStatusModel::set_view(std::shared_ptr<IPanelView> v){
	connect(this, SIGNAL(open_media_path_signal(const QString&)), v.get(), SLOT(open_media_slot(const QString&)));
	connect(this, SIGNAL(play_signal(bool)), v.get(), SLOT(play_slot(bool)));
	connect(this, SIGNAL(open_secert_path_signal(const QString&)), v.get(), SLOT(open_secert_slot(const QString&)));

	// 根据model的当前状态，渲染view
	emit open_media_path_signal(__mediaPath__);		// __mediaPath__长度为0时，view将会认为文件不可用，置灰按钮。
}

// ================================ 读取数据 ================================
const QString& PanelStatusModel::media_path(){
	return __mediaPath__;
}
bool PanelStatusModel::playing() {
	return __isplaying__;
}

const QString& PanelStatusModel::secert_path(){
	return __secertPath__;
}

// ================================ 写入数据 ================================
void PanelStatusModel::media_path(const QString& path){
	// 路径不同则重新打开媒体
	if (__mediaPath__.compare(path)){
		__mediaPath__ = path;
		emit open_media_path_signal(__mediaPath__);
	}
}
void PanelStatusModel::playing(bool isplaying) {
	if (__isplaying__ != isplaying){
		__isplaying__ = isplaying;
		emit play_signal(__isplaying__);
	}
}

void PanelStatusModel::secert_path(const QString& secertPath){
	// 路径不同则重新打开媒体
	if (__secertPath__.compare(secertPath)){
		__secertPath__ = secertPath;
		emit open_secert_path_signal(__secertPath__);
	}
}