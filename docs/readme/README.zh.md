<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a id="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->

简体中文 | [English](./README.en.md)

**自述文件版本** 0.9.4

<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
![Static Badge](https://img.shields.io/badge/Qt-Target%20version%206.9.3-green?style=flat-square&logo=qt&link=qt.io) ![Static Badge](https://img.shields.io/badge/C%2B%2B%20standard-20-blue?style=flat-square&logo=c%2B%2B&link=https%3A%2F%2Fen.cppreference.com%2Fw%2Fcpp%2F20.html) ![Static Badge](https://img.shields.io/badge/Material%20Symbols%20version-4.0.0-yellow?style=flat-square&logo=materialdesign&color=%236750A4&link=https%3A%2F%2Ffonts.google.com%2Ficons) ![Static Badge](https://img.shields.io/badge/Version-0.9-yellow?style=flat-square) ![Static Badge](https://img.shields.io/badge/Made%20with-love-red?style=flat-square)



<!-- PROJECT LOGO -->
<br />

<div align="center">



  <h3 align="center">Material3-QWidget</h3>

  <p align="center">
    基于QWidget的Material Design 3风格组件库
    <br />
    <a href="./docs/"><strong>探索文档 »</strong></a>
    <br />
    <br />
  </p>

</div>



<!-- TABLE OF CONTENTS -->

<details>
  <summary>目录</summary>
  <ol>
    <li>
      <a href="#about-the-project">关于此项目</a>
      <ul>
        <li><a href="#built-with">构建依赖</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">开始使用</a>
      <ul>
        <li><a href="#prerequisites">前提条件</a></li>
        <li><a href="#installation">安装</a></li>
      </ul>
    </li>
    <li><a href="#usage">使用</a></li>
    <li><a href="#roadmap">里程碑</a></li>
    <li><a href="#license">许可证</a></li>
    <li><a href="#contact">联系我们</a></li>
    <li><a href="#acknowledgments">鸣谢</a></li>
  </ol>
</details>




<!-- ABOUT THE PROJECT -->

## 关于此项目

![Screen Shot](./screenshots/screenshots.png)

欢迎使用Material3-QWidget，这是我一个尝试为QWidget带来模仿Material Design 3风格的UI库的小项目。

以下是项目的一些亮点：

* 支持自定义调色板
* 支持深色/浅色模式随系统设定自动切换

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### 构建依赖

* ![Static Badge](https://img.shields.io/badge/Qt-6.9.3-green?style=flat-square&logo=qt&logoColor=green&link=qt.io)
* ![Static Badge](https://img.shields.io/badge/C%2B%2B-20-blue?style=flat-square&logo=C%2B%2B&logoColor=blue&link=https%3A%2F%2Fen.cppreference.com%2Fw%2Fcpp%2F20.html)
* ![Static Badge](https://img.shields.io/badge/Material%20Symbols-4.0.0-yellow?style=flat-square&logo=materialdesign&color=%236750A4&link=https%3A%2F%2Ffonts.google.com%2Ficons)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->

## 开始使用

您可以选择编译并安装这个库，亦可以在许可证兼容的情况下将此项目作为子项目直接引入。

* **如果使用`.so`/`.a`/`.dll`文件引入了此库**：您可能想要利用`includes`目录，所有的头文件都在那儿。
* **如果作为子项目引入**：请确保许可证兼容；`examples` 目录提供了如何引入的示例。



### 前提条件

以下是编译成功的前提条件：

* **Qt**：由于我们依赖 `QGuiApplication::styleHints()`，**所以必须使用Qt6**.

* **CMake**：最小版本3.16。

### 安装

由于我们在`resource.qrc`中引入了material symbols，编译时间可能较长。

*（文档正在施工中...）*

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->

## 使用

请参阅`examples`目录以获取关于如何引入与如何使用的示例。

在将来，`docs`目录会设置一个文档中心。



> 目前文档中心还没有设置好...

要使用文档中心，请确保系统上有`Node.JS`与`pnpm`。

在项目的根目录执行：

```bash
cd docs
pnpm i
pnpm approve-builds
pnpm dev
```

这将拉起本地服务器，默认地址应该是[http://localhost:5173](http://localhost:5173)。

这个端口不一定一直是`5173`，比如如果有别的程序占了这个窗口它就会变，要检查实际的端口号，检查终端的输出：

```bash
➜  docs git:(main) ✗ pnpm dev

> m3qw.docs@ dev /home/marcus/Desktop/Repositories/Public/material3-qwidget/docs
> react-router dev

  ➜  Local:   http://localhost:5173/
  ➜  Network: use --host to expose
  ➜  press h + enter to show help
```

在以上的输出里，端口号为`5173`。

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->

## 里程碑

* 基础套件
  * [x] 主题加载器
  * [x] 字体加载器
  * [x] 图标加载器
  * [x] 默认调色板（随着组件的新增后续会增加字段）
* 组件
  * [x] 应用栏
  * [x] 应用栏图标按钮
  * [ ] 导航抽屉（*正在施工*）
  * [ ] 图标按钮（*抱歉，此组件的施工计划有所推迟*）
  * [ ] ...
* 文档
  * [x] 自述
  * [ ] 文档中心（*规划中*）
  * [ ] 示例程序（*正在施工中*）
* 国际化
  * [ ] EN-US
  * [ ] ZH-CN

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- LICENSE -->

## 许可证

* **此项目本身**以`GNU GENERAL PUBLIC LICENSE Version 3`授权，请参阅[COPYING](./COPYING)。
* **我们亦引入了material symbols字体**，该项目以`Apache License Version 2.0`授权，请参阅[res/fonts/material-symbols/COPYING](./res/fonts/material-symbols/COPYING)。

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->

## 联系我们

如有疑问，请提一个新issue。

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ACKNOWLEDGMENTS -->

## 鸣谢

感谢[othneildrew/Best-README-Template](https://github.com/othneildrew/Best-README-Template.git)提供的自述文件模板！！

<p align="right">(<a href="#readme-top">back to top</a>)</p>