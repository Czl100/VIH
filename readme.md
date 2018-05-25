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
    virtual void link_controller(const IPanelController &controller) = 0;
};

// 提供视图对Model信号的接收
class IPanelView : public QMainWindow, public BasePanelView{
public slots :
    virtual void open_media_slot(const QString& mediaPath) = 0;
    virtual void play_slot(Status status) = 0;
    virtual void open_secert_slot(const QString& mediaPath) = 0;
    virtual void embed_slot(Status  status) = 0;
    virtual void extract_slot(Status  status) = 0;
};
```
### *2.Controller*
```C++
class IPanelController : public QObject{
    void set_view(std::shared_ptr<IPanelView> view);                // 设置Controller的View，也会在View中注册该Controller
    void set_status_model(std::shared_ptr<PanelStatusModel> model); // 设置Controller的Model，也会在Model中注册View

public slots :
    virtual void open_video_slot() = 0;     // 打开目录选择视频文件
    virtual void play_video_slot() = 0;     // 播放视频
    virtual void play_progress_slot() = 0;  // 调整进度条

    virtual void open_secert_slot() = 0;    // 打开目录选择秘密文件
    virtual void start_vih_slot() = 0;      // 开始视频信息隐藏
    virtual void start_ext_slot() = 0;      // 开始视频信息提取
    virtual void stop_vih_slot() = 0;       // 停止视频信息隐藏
    virtual void stop_ext_slot() = 0;       // 停止视频信息隐藏
};
```
### *3.Model*
```C++
class PanelStatusModel : public QObject{
public signals :
    void open_media_path_signal(const QString& path);   // 打开多媒体的信号
    void open_secert_path_signal(const QString& path);  // 打开秘密文件的信号
    void play_signal(Status status);                    // 多媒体播放信号(Operate, Stop, Pause)
    void embed_signal(Status status);                   // 嵌入的信号(Operate, Stop, Pause)
    void extract_signal(Status status);                 // 提取的信号(Operate, Stop, Pause)
    
public:
    void set_view(std::shared_ptr<IPanelView> v);       // 将信号和view的slots连接

public:
    void media_path(const QString& path);               // 设置多媒体文件
    void play_status(Status status);                    // 设置播放状态
    void secert_path(const QString& path);              // 设置秘密文件
    void embed_status(Status status);                   // 设置嵌入过程的状态
    void extract_status(Status status);                 // 设置提取过程的状态

public:
    const QString& media_path();                        // 返回当前打开的多媒体
    Status playing();                                   // 返回播放操作的状态
    const QString& secert_path();                       // 返回当前打开秘密文件的状态
    Status embed_status(Status status);                 // 返回嵌入操作的状态
    Status extract_status(Status status);               // 返回提取操作的状态
};
```
