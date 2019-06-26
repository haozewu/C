# C

### 目录

[C语言开发环境配置](#c语言开发环境配置)

[关于本项目说明](#关于本项目说明)

[贡献指南](#贡献指南)

## C语言开发环境配置

- vscode安装
  - 编辑器我们推荐使用VSCode，并针对VSCode配置了一套设置文件
  - [下载VSCode](https://code.visualstudio.com/download)
  - 然后根据计算机版本完成VSCode的安装

- mingw安装
  - 需要安装C/C++编译工具和调试工具。

## 关于本项目说明

文件夹.vscode中为C语言开发的配置，配置了C语言开发所用到的编译指令和gdb调试工具。

文件夹example包含了一部分初始化的代码，以下为代码简要解释

- 中文测试
  - 在控制台输出一句你好，世界
  - getchar函数用于等待输入，以使得文字停留在屏幕上
- 子函数求和
  - scanf函数可以接受输入
  - 内置一个sum子函数
- 示例代码更新
  - [浙江大学数据结构课程部分代码](https://www.icourse163.org/course/ZJU-93001)

## 贡献指南

- 我们欢迎大家将一些适合入门的C语言程序上传到example文件夹下，这将帮助更多人进步
- 在上传范例之后，请在readme中把代码解释稍作说明
- 在Pull Request前，请将你的编译生成和临时文件全部删除
