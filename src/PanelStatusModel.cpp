#include "PanelStatusModel.h"
#include "IPanelView.h"

#include <QList>

void PanelStatusModel::set_view(std::shared_ptr<IPanelView> v){
	connect(this, SIGNAL(open_media_path_signal(const QString&)), v.get(), SLOT(open_media_slot(const QString&)));
	connect(this, SIGNAL(play_signal(OperaStatus)), v.get(), SLOT(play_slot(OperaStatus)));
	connect(this, SIGNAL(open_secert_path_signal(const QString&)), v.get(), SLOT(open_secert_slot(const QString&)));

	// ����model�ĵ�ǰ״̬����Ⱦview
	emit open_media_path_signal(__mediaPath__);		// __mediaPath__����Ϊ0ʱ��view������Ϊ�ļ������ã��ûҰ�ť��
}

// ================================ ��ȡ���� ================================
const QString& PanelStatusModel::media_path(){
	return __mediaPath__;
}
OperaStatus PanelStatusModel::play_status() {
	return __playStatus__;
}

const QString& PanelStatusModel::secert_path(){
	return __secertPath__;
}

// ================================ д������ ================================
void PanelStatusModel::media_path(const QString& path){
	// ·����ͬ�����´�ý��
	if (__mediaPath__.compare(path)){
		__mediaPath__ = path;
		emit open_media_path_signal(__mediaPath__);
		__playStatus__ = PAUSE;
	}
}
void PanelStatusModel::play_status(OperaStatus status) {
	if (__playStatus__ != status){
		__playStatus__ = status;
		emit play_signal(__playStatus__);
	}
}

void PanelStatusModel::secert_path(const QString& secertPath){
	// ·����ͬ�����´�ý��
	if (__secertPath__.compare(secertPath)){
		__secertPath__ = secertPath;
		emit open_secert_path_signal(__secertPath__);
	}
}