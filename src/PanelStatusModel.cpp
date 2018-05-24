#include "PanelStatusModel.h"
#include "IPanelView.h"

void PanelStatusModel::set_view(std::shared_ptr<IPanelView> v){
	connect(this, SIGNAL(open_media_path_signal(const QString&)),
		v.get(), SLOT(open_media_slot(const QString&)));
	connect(this, SIGNAL(play_signal(bool)),
		v.get(), SLOT(play_slot(bool)));

	// ����model�ĵ�ǰ״̬����Ⱦview
	emit open_media_path_signal(__mediaPath__);		// __mediaPath__����Ϊ0ʱ��view������Ϊ�ļ������ã��ûҰ�ť��
}


const QString& PanelStatusModel::media_path(){
	return __mediaPath__;
}
bool PanelStatusModel::playing() {
	return __isplaying__;
}

void PanelStatusModel::media_path(const QString& path){
	// ·����ͬ�����´�ý��
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