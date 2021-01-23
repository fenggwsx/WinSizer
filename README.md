# 项目说明

该项目中编写了一个能够精确地更改窗口尺寸的软件`WinSizer`

# 使用说明

打开WinSizer，界面如下：

![](https://fenggwsx.gitee.io/res/upload_images/4440f828.png)

首先需要点击“抓取窗口”按钮抓取要更改尺寸的窗口:

![](https://fenggwsx.gitee.io/res/upload_images/16f8f1ba.png)

抓取成功后会显示目标窗口的“窗口类名”和“窗口标题”，通过这两项内容可以判断窗口是否抓取正确，同时还会显示窗口的宽度和高度，如下图所示：

![](https://fenggwsx.gitee.io/res/upload_images/da7ce51a.png)

最后修改“宽度”和“高度”，点击“调整大小”即可

“最大化”和“最小化”按钮可以分别将目标窗口最大化和最小化

值得注意的是，勾选“仅抓取可见窗口”并不意味着抓取的每一个窗口都真正可见，在代码中是通过函数`IsVisible`来判断的，这意味着只有窗口不具有`WS_VISIBLE`样式才不会被抓取到

由于Windows下的许多窗口有阴影，而阴影也算入窗口大小，会导致窗口尺寸的改变产生一定的偏差

# 开源说明

本项目开源，可以直接克隆我的仓库

```
git clone https://github.com/fenggwsx/WinSizer.git
```
