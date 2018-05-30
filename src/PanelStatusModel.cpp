#include "PanelStatusModel.h"
#include "IPanelView.h"

#include <QList>

void PanelStatusModel::set_view(std::shared_ptr<IPanelView> v){
	connect(this, SIGNAL(open_media_signal(const QString&)), v.get(), SLOT(open_media_slot(const QString&)));
	connect(this, SIGNAL(play_signal(OperaStatus)), v.get(), SLOT(play_slot(OperaStatus)));
	connect(this, SIGNAL(open_emb_secret_signal(const QString&)), v.get(), SLOT(open_emb_secert_slot(const QString&)));
	connect(this, SIGNAL(save_emb_media_signal(const QString&)), v.get(), SLOT(save_emb_media_slot(const QString&)));

	connect(this, SIGNAL(save_ext_secret_signal(const QString&)), v.get(), SLOT(save_ext_secert_slot(const QString&)));

	// ����model�ĵ�ǰ״̬����Ⱦview
	emit open_media_signal(__mediaPath__);		// __mediaPath__����Ϊ0ʱ��view������Ϊ�ļ������ã��ûҰ�ť��
}

// ================================ ��ȡ���� ================================
const QString& PanelStatusModel::media_path(){
	return __mediaPath__;
}
OperaStatus PanelStatusModel::play_status() {
	return __playStatus__;
}

const QString& PanelStatusModel::emb_secret_path(){
	return __embSecretPath__;
}

const QString& PanelStatusModel::emb_media_path(){
	return __embMediaPath__;
}

const QString& PanelStatusModel::ext_secret_path(){
	return __extSecretPath__;
}

// ================================ д������ ================================
void PanelStatusModel::media_path(const QString& path){
	// ·����ͬ�����´�ý��
	if (__mediaPath__.compare(path)){
		__mediaPath__ = path;
		emit open_media_signal(__mediaPath__);
		__playStatus__ = PAUSE;
	}
}

void PanelStatusModel::play_status(OperaStatus status) {
	if (__playStatus__ != status){
		__playStatus__ = status;
		emit play_signal(__playStatus__);
	}
}

void PanelStatusModel::emb_secret_path(const QString& secertPath){
	// ·����ͬ�����´�ý��
	if (__embSecretPath__.compare(secertPath)){
		__embSecretPath__ = secertPath;
		emit open_emb_secret_signal(__embSecretPath__);
	}
}

void PanelStatusModel::emb_media_path(const QString& path){
	// ·����ͬ�����´�ý��
	if (__embMediaPath__.compare(path)){
		__embMediaPath__ = path;
		emit save_emb_media_signal(__embMediaPath__);
	}
}

void PanelStatusModel::ext_secret_path(const QString& path){
	if (__extSecretPath__.compare(path)){
		__extSecretPath__ = path;
		emit save_ext_secret_signal(__extSecretPath__);
	}
}