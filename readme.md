# 视频信息隐藏系统

## 一、环境配置
主要依赖于第三方框架`Qt`和第三方库`mpeg`。
### *1.Qt配置*
### *2.mpeg配置*

## 二、MVC
本系统采用了MVC框架，这里列出MVC三个角色所提供的相关接口和信号。
### *1.View*
```C++
// 提供视图接口
class BasePanelView{
public:
	virtual ~BasePanelView(){}
	virtual void link_controller(const IPanelController &controller) = 0;
};

// 提供视图接口 以及 视图信号
class IPanelView : public QMainWindow, public BasePanelView{
	Q_OBJECT

public:
	IPanelView(QWidget *parent = nullptr) :QMainWindow(parent){}

public slots :
	virtual void open_media_slot(const QString& mediaPath) = 0;
	virtual void play_slot(bool isplaying) = 0;
	virtual void open_secert_slot(const QString& mediaPath) = 0;
};
```
### *2.Controller*
```C++
class IPanelController : public QObject{
	Q_OBJECT
public:
	IPanelController():__view__(nullptr){}
	~IPanelController(){ }	
	void set_view(std::shared_ptr<IPanelView> view);                // 设置Controller的View，也会在View中注册该Controller
	void set_status_model(std::shared_ptr<PanelStatusModel> model); // 设置Controller的Model，也会在Model中注册View

public slots :
	virtual void open_video_slot() = 0;		// 打开目录选择视频文件
	virtual void play_video_slot() = 0;		// 播放视频
	virtual void play_progress_slot() = 0;	// 调整进度条

	virtual void open_secert_slot() = 0;	// 打开目录选择秘密文件
	virtual void start_vih_slot() = 0;		// 开始视频信息隐藏
	virtual void start_ext_slot() = 0;		// 开始视频信息提取
};
```
### *3.Model*
```C++
class PanelStatusModel : public QObject{
	Q_OBJECT
// 发送的信号
signals :
	void open_media_path_signal(const QString& path);
	void open_secert_path_signal(const QString& path);
	void play_signal(bool isplay);

// 初始化
public:
	PanelStatusModel() :__mediaPath__(""), __isplaying__(false){}

// 将信号和view的slots连接
public:
	void set_view(std::shared_ptr<IPanelView> v);

// 写函数
public:
	void media_path(const QString& path);
	void playing(bool isplaying);
	void secert_path(const QString& path);

// 读函数
public:
	const QString& media_path();
	bool playing();
	const QString& secert_path();
};
```
