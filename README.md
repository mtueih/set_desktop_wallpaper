# set_desktop_wallpaper

![Platform](https://img.shields.io/badge/Platform-Windows-blue)
[![C Standard](https://img.shields.io/badge/C-C99+-blue.svg)](https://zh.cppreference.com/c)
[![CMake](https://img.shields.io/badge/CMake-3.24+-green.svg)](https://cmake.org/)
[![GitHub License](https://img.shields.io/github/license/mtueih/set_desktop_wallpaper)](LICENSE)
[![CI](https://github.com/mtueih/set_desktop_wallpaper/actions/workflows/ci.yml/badge.svg)](https://github.com/mtueih/set_desktop_wallpaper/actions/workflows/ci.yml)
[![CD](https://github.com/mtueih/set_desktop_wallpaper/actions/workflows/cd.yml/badge.svg)](https://github.com/mtueih/set_desktop_wallpaper/actions/workflows/cd.yml)

一个用于设置系统桌面壁纸的轻量级 C 库。

目前只支持 Windows 平台。

## CLI

此项目包含一个 CLI 工具：`set_desktop_wallpaper`。

### 使用方法

- `set_desktop_wallpaper <image_path>`。

### 参数说明

`image_path` 是包含**目标图片路径**的单个字符串。

“**目标图片路径**”允许**绝对路径**和**相对路径**。

### 行为说明

多余的参数会被忽略。

## API

此项目只包含用于实现一个行为的 API 函数，所有 API 函数都只是用于实现这个行为的不同变体。

其中，`set_desktop_wallpaper_w()` 接受宽字符串。这主要是为了支持 Windows 平台，因为 Windows 平台原生使用宽字符串编码。当手头已有宽字符串时，使用宽字符串版本，可减少不必要的编码转换开销。

### `set_desktop_wallpaper()`

设置桌面壁纸（单张图片）。

```c
bool set_desktop_wallpaper(const char *image_file_path);
```

参数：

- `image_file_path`：包含目标图片路径的单个字符串（应使用系统代码页编码）。

返回值：

（`bool`）是否设置成功，设置成功返回 _`true`_，否则返回 _`false`_。

### `set_desktop_wallpaper_w()`

`set_desktop_wallpaper()` 的宽字符串版本。

```c
bool set_desktop_wallpaper_w(const wchar_t *image_file_path);
```

## 在其他项目中使用（仅库）

### 添加依赖

#### CPM.cmake

环境要求：[CPM.cmake](https://github.com/cpm-cmake/CPM.cmake)。

在 `CMakeLists.txt` 中：

```cmake
include(${PROJECT_SOURCE_DIR}/cmake/CPM.cmake)

CPMAddPackage("gh:mtueih/set_desktop_wallpaper#v0.2.0")
```

#### CMake find_package（需已安装）

在 `CMakeLists.txt` 中：

```cmake
find_package(set_desktop_wallpaper REQUIRED)
```

### 链接库

在 `CMakeLists.txt` 中：

```cmake
target_link_libraries(your_target PRIVATE set_desktop_wallpaper::set_desktop_wallpaper)
```

### 在代码中使用

#### 引入头文件

```cpp
#include <set_desktop_wallpaper/set_desktop_wallpaper.h>
```

#### 使用库函数

在 C 代码中：

```c
set_desktop_wallpaper("C:\\Users\\mtueih\\Pictures\\wallhaven-e82xxr.jpg");
```

在 C++ 代码中：

```cpp
set_desktop_wallpaper::set_desktop_wallpaper("C:\\Users\\mtueih\\Pictures\\wallhaven-e82xxr.jpg");
```

## 从源码构建

### 环境要求

- [CMake](https://cmake.org/) 3.24+。
- 支持 [C99](https://zh.cppreference.com/c/99)+ 的 [C 编译器](https://zh.cppreference.com/c/compiler_support)（MSVC / MinGW-w64 / Clang）。

### 构建步骤

#### 克隆仓库

```bash
git clone https://github.com/mtueih/set_desktop_wallpaper.git --depth 1 -b v0.2.0
cd set_desktop_wallpaper
```

#### 配置、构建与安装

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release -DSET_DESKTOP_WALLPAPER_INSTALL_LIB=ON -DSET_DESKTOP_WALLPAPER_INSTALL_CLI=ON
cmake --build build --config Release --parallel
cmake --install build --config Release --strip --prefix install
```

有关上述命令的说明：

- 配置命令。通过 `-DSET_DESKTOP_WALLPAPER_INSTALL_LIB=ON` 与 `-DSET_DESKTOP_WALLPAPER_INSTALL_CLI=ON` 分别启用了库与 CLI 工具的安装，你可以按需安装，如果不需要安装某一个，将对应选项删除即可。
- 安装命令。通过 `--prefix install` 将产物安装在了 `install` 目录下，而不是全局安装，以便你按自己的方式使用安装产物。如果你希望全局安装，则删除它即可。

## 许可协议

本项目采用 [ISC 许可证](https://www.isc.org/licenses/) 授权——详情请参阅 [LICENSE](LICENSE) 文件。
