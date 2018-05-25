#include "PanelStatusModel.h"
#include "IPanelView.h"

#include <QList>

void PanelStatusModel::set_view(std::shared_ptr<IPanelView> v){
	connect(this, SIGNAL(open_media_path_signal(const QString&)), v.get(), SLOT(open_media_slot(const QString&)));
	connect(this, SIGNAL(play_signal(OperaStatus)), v.get(), SLOT(play_slot(OperaStatus)));
	connect(this, SIGNAL(open_secert_path_signal(const QString&)), v.get(), SLOT(open_secert_slot(const QString&)));

	// 根据model的当前状态，渲染view
	emit open_media_path_signal(__mediaPath__);		// __mediaPath__长度为0时，view将会认为文件不可用，置灰按钮。
}

// ================================ 读取数据 ================================
const QString& PanelStatusModel::media_path(){
	return __mediaPath__;
}
OperaStatus PanelStatusModel::play_status() {
	return __playStatus__;
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

// ================================ 写入数据 ================================
void PanelStatusModel::media_path(const QString& path){
	// 路径不同则重新打开媒体
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
	// 路径不同则重新打开媒体
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