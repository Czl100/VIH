# 视频信息隐藏系统
这是一款用于进行视频信息隐藏的系统，支持一下功能：
* 多媒体文件播放
* 基于文件的信息隐藏
* 基于文件的信息提取
* 通过配置文件进行算法选择
* 日志记录系统
* 视频信息隐藏/提取的进度显示
    * 进度条显示
    * 控制台进度描述
* 选择信息隐藏/提取算法
    * 三维低码率增长信息隐藏
    * 基于循环码的信息隐藏
    * 参考像素多分类的QDCT域信息隐藏
    * 低码率增长信息隐藏
    * 适应拖尾系数信息隐藏
    * 三元码信息隐藏

## 一、目录结构
```
├── application/green   # 应用程序绿色版本
|       ├── workspace       # 应用程序工作空间(程序运行必需)
|       |       ├── algorithms      # 算法文件夹(程序运行必需)
|       |       |       ├── A算法           # A算法程序文件夹(程序运行必需)
|       |       |       |   ├── workspace       # A算法工作空间(程序运行必需)
|       |       |       |   ├── lencod.exe      # 嵌入应用程序(程序运行必需)
|       |       |       |   └── ldecod.exe      # 提取应用程序(程序运行必需)
|       |       |       |
|       |       |       ├── B算法           # B算法程序文件夹(程序运行必需)
|       |       |       |   ├── ...
|       |       |       |   ├── ...
|       |       |       |   └── ...
|       |       |       |
|       |       |       ├── decoder.cfg     # 解码配置文件(程序运行必需)
|       |       |       └── encoder.cfg     # 解码配置文件(程序运行必需)
|       |       |
|       |       ├── tmp             # 临时文件夹(程序运行必需)
|       |       ├── app.cfg         # 应用程序配置文件(程序运行必需)
|       |       └── test            # 用于测试多媒体文件
|       |
|       └── vih.exe         # 视频信息隐藏系统的可执行程序
|
├── ffmpeg              # FFMPEG库目录。仓库中本没有该目录，需要进行相关开发，需要添置该目录。
├── inc                 # 视频信息隐藏头文件
├── src                 # 视频信息隐藏cpp文件
└── sln                 # 视频信息隐藏系统解决方案/工程文件, 开发入口.
```

## 二、依赖
### 1.*FFMPEG*
FFMPEG是一款多媒体操作框架，可以对多媒体文件(AVI/MP4/MKV/...)进行音频提取、视频提取、YUV提取以及封装多媒体文件。FFMPEG所需要的动态链接库(dll)已经放置到了*application*目录下，不用作额外的安装。

### 2.*Qt*
Qt是C++的界面设计框架，视频信息隐藏系统实现了基于Qt的MVC框架。Qt所需要的dll已经放置到了*application*目录下，不用作额外的安装。

### 3.*JM8.6*
JM是一款开源的H.264/AVC编解码器，是视频信息隐藏/提取算法的实现平台。JM通过提供可执行程序的形式，由视频信息隐藏系统调用，不用作额外的安装。JM8.6版本较低，后期可以使用更高版本的JM平台。

## 三、使用
视频信息隐藏系统是绿色软件，已经将所需要的所有文件放置到了*application*文件夹下，不需要进行其他任何的额外的安装和配置。
### 1.*信息隐藏*
### 2.*信息提取*
### 3.*算法选择*
### 4.*调试控制台*

## 四、添加算法
### 1.*Algorithm接口*
### 2.*AlgorithmBuilder*
为了方便选择性的加载不同算法，因此引入了Builder模式，并构建了AlgorithmBuilder类。类AlgorithmBuilder和类Algorithm是配套的，每当实现了一个Algorithm后，就需要实现一个对应的AlgorithmBuilder。一个AlgorithmBuilder的引入需要两个步骤:
* a) 实现AlgorithmBuilder<br>
主要是实现AlgorithmBuilder的ctor方法，这个方法用来告诉Builder如何实例化一个Algorithm。
```cpp
class NewBuilder : public AlgorithmBuilder{
    IAlgorithm *ctor(const QString& algorithmsDir, const QString &_algoName) override{
        return new NewAlgorithm(algorithmsDir, _algoName);
    }
};
```
* b) 添加至builderMapper<br>
为了根据app.cfg的配置加载算法，因此需要将Builder实例化，并添加至builderMapper中。
```cpp
// 本代码位于main.cpp中
#include "NewBuilder.h"
bool check_load_model(shared_ptr<PanelStatusModel> m){
    ...
    QHash<QString, AlgorithmBuilder*> builderMap;
    builderMap.insert("LHH", new LHHBuilder());
    builderMap.insert("WTQ", new WTQBuilder());
    builderMap.insert("NEW", new NewBuilder());
    ...
}
```
* c) 重新编译

### 3.*算法文件夹*
通过JM编译好隐藏/提取算法的可执行程序(lencod.exe/ldecod.exe)，可以构建算法文件夹。需要确保算法文件夹的命名、路径和此说明中的统一，否则无法加载算法。
```
└── 算法名(文件夹)
    ├── workspace       # 算法工作空间
    ├── lencod.exe      # 信息隐藏算法可执行程序
    └── ledecod.exe     # 信息提取算法可执行程序
```
### 4.*app.cfg*
