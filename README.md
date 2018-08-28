# Algorithm

## Introduction / 简介

A Simple Algorithm &amp; Data Structure Library, mainly for OIer and ACMer, short enough.

简单的算法和数据结构仓库。为 OIer 与 ACMer 设计，代码较短。

The code mainly written in C++, maybe useful in the future.

代码主要使用 C++ 编写，在未来可能会有用。

Inspired by [KACTL](https://github.com/kth-competitive-programming/kactl). Now just simple a hack on it.

受到 [KACTL](https://github.com/kth-competitive-programming/kactl) 项目的启发。目前项目仅仅是在原项目基础上的简单 Hack。

More suitalbe for Chinese competitors. Compact code and easy to write.

更适合于中国竞赛选手。代码紧凑，容易实现。

Printable & Copy-paste:able. Document Template written by LaTeX.

可以打印出来，也可以复制粘贴。文档模板使用 LaTeX 编写。

For better supporting of Chinese Characters, use XeLaTeX or LuaLaTeX (if you don't mind the slow compiling) to compile.
Ensure argument `-shell-escape` has been passed.

为了获得更好的中文支持，请使用 XeLaTeX 或 LuaLaTeX（如果您不在意编译速度）编译。确保传递 `-shell-escape` 参数。

If you want to hack this project, please go to content folder, modify the code and don't forget `chapter.tex` file.

## How to Build / 如何构建

### Dependencies / 依赖

For users who are using \*nix, you should already had Python and the basic toolchain of your system. What you only need is a TeX mainstream distribution (like TeX Live, etc.), the latest release of TeX Live could be found on [CTAN](https://ctan.org/tex-archive/systems/texlive/Images).

对于 \*nix 用户，您应该具有 Python 与基本的系统工具链。您需要的唯一依赖是一个主流的 TeX 发行版（如 TeX Live 等），TeX Live 的最新版本可以通过 [CTAN](https://ctan.org/tex-archive/systems/texlive/Images) 获得。

For users who are using Windows, what you need is Python 3 and a TeX mainstream distribution. You can get the latest Python on [Get Python](https://www.python.org/downloads/). You can get TeX Live through the link above. I prefer to use cygwin or MSYS2 for Windows. Please find one that suits you.

对于 Windows 用户，您需要的是 Python 3 、一个主流的 TeX 发行版以及适当的 \*nix 工具链。您可以在 [Get Python](https://www.python.org/downloads/) 找到 Python 3 的最新版本。您可以在上面的连接中获得 TeX Live。我推荐使用 cygwin 或 MSYS。请找一套适合您的工具链。

Special For Windows XP users: You can't use TeX Live 2018 or later. You can get TeX Live 2017 instead, on [CTAN FTP](ftp://tug.org/historic/systems/texlive/2017/), and you can't use Python 3.5 or later, use Python 3.4.x instead. You can get Python 3.4.4 on [Python Release 3.4.4](https://www.python.org/downloads/release/python-344/).

对 Windows XP 用户的特别提示：您不能使用 TeX Live 2018 或更高版本。您可以使用 TeX Live 2017 替代，它可以在 [CTAN FTP](ftp://tug.org/historic/systems/texlive/2017/) 获得，您也不能使用 Python 3.5 或更高版本，请使用 Python 3.4.x，您可以在 [Python Release 3.4.4](https://www.python.org/downloads/release/python-344/) 获得 Python 3.4.4。

### Compiling on \*nix / 在 \*nix 平台上编译文档

It is easy to compile on \*nix platform. Just clone the project (or download the zip file), and run `make fast`.

在 \*nix 平台上编译十分容易。只需要 Clone 或下载 ZIP 文件后运行 `make fast` 即可。

### Building on Windows / 在 Windows 平台上编译文档

It is even simplier to build on Windows platform. Run `build.bat` and it will do everything for you - checking the dependencies, running the compiler.

在 Windows 平台上编译更容易。运行 `build.bat` 即可。脚本会检查依赖并运行编译器。

### Quick Checklist for Windows / 给 Windows 平台的快速检查单

**Please check everything below and ensure everything works as expected before compiling on Windows.**

**在 Windows 平台编译之前请检查以下各项，确保一切工作正常。**

Open a command prompt window and check everything below:

打开命令提示符窗口，检查下列各项：

- [ ] rm --version
- [ ] python --version
- [ ] xelatex --version

Everything is fine if you don't see things like `'SOMETHING' is not recognized as an internal or external command,
operable program or batch file.`. The build script also checks it for you and ensure everything is working as expected.

如果您没有看到类似 `'什么东西' 不是内部或外部命令，也不是可运行的程序或批处理文件。`的提示，那说明一切工作正常。编译脚本也会为您检查依赖，确保一切工作正常。

If you are experiencing problems, check your environment varible and ensure that your toolchain, XeLaTeX and Python are included in your PATH.

如果您遇到了问题，请检查您的工具链、XeLaTeX 和 Python 的路径在环境变量中。

### Hacking / 修改本项目

All source code of C++ is in `content` folder. Modify them as you like, and don't forget to modify `chapter.tex` as well if you added new files.

所有 C++ 源代码都在 `content` 文件夹中。您可以随意编辑。如果增加了文件，也需要编辑 `chapter.tex` 文件。

Coded with :heart: By MingqiHuang.
