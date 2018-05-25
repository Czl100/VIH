#include "PanelStatusModel.h"
#include "IPanelView.h"

#include <QList>

void PanelStatusModel::set_view(std::shared_ptr<IPanelView> v){
	connect(this, SIGNAL(open_media_path_signal(const QString&)), v.get(), SLOT(open_media_slot(const QString&)));
	connect(this, SIGNAL(play_signal(bool)), v.get(), SLOT(play_slot(bool)));
	connect(this, SIGNAL(open_secert_path_signal(const QString&)), v.get(), SLOT(open_secert_slot(const QString&)));

	// ����model�ĵ�ǰ״̬����Ⱦview
	emit open_media_path_signal(__mediaPath__);		// __mediaPath__����Ϊ0ʱ��view������Ϊ�ļ������ã��ûҰ�ť��
}

// ================================ ��ȡ���� ================================
const QString& PanelStatusModel::media_path(){
	return __mediaPath__;
}
bool PanelStatusModel::playing() {
	return __isplaying__;
}

const QString& PanelStatusModel::secert_path(){
	return __secertPath__;
}

const QStringList PanelStatusModel::algos_list(){
	QStringList algolist;
	for (int i = 0; i < __algos__.size(); i++){
		algolist.append(__algos__[i]->algo_name());
	}
	return algolist;
}

int PanelStatusModel::algo_idx(){
	return __algoIdx__;
}

// ================================ д������ ================================
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

void PanelStatusModel::secert_path(const QString& secertPath){
	// ·����ͬ�����´�ý��
	if (__secertPath__.compare(secertPath)){
		__secertPath__ = secertPath;
		emit open_secert_path_signal(__secertPath__);
	}
}

void PanelStatusModel::add_algorithm(std::shared_ptr<IAlgorithm> algorithm){
	__algos__.append(algorithm);
}

void PanelStatusModel::algo_idx(int idx){
	__algoIdx__ = idx;
}