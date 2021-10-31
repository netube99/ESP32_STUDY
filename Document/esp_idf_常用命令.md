# ESP-IDF 常用命令

* [ESP-IDF 编程指南](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/index.html)
* [使用 ESP-IDF 构建系统](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/build-system.html#id3)

在 Linux 当前终端添加 ESP-IDF 的环境变量
```
. $HOME/esp/esp-idf/export.sh
```

## 创建项目

生成新项目
```
在当前目录下生成项目
idf.py create-project [项目名称]

在指定目录下生成项目（自生成项目名文件夹）
idf.py create-project
df.py create-project --path [项目目录] [项目名称]
```

设置目标芯片型号

* esp32 — 适用于 ESP32-D0WD、ESP32-D2WD、ESP32-S0WD (ESP-SOLO)、ESP32-U4WDH、ESP32-PICO-D4
* esp32s2— 适用于 ESP32-S2
* esp32c3— 适用于 ESP32-C3
* 新型号均可以此类推

```
idf.py set-target [目标芯片]
```

配置项目
```
idf.py menuconfig
```

编译与烧录
```
分开操作
idf.py build
idf.py -p [串口号] flash

编译并使用高速烧录
idf.py -p [串口号] -b [波特率] flash
idf.py -p COM3 -b 2000000 flash

编译烧录烧录并打开串口监视
idf.py -p COM3 -b 2000000 flash monitor
```

## 项目管理命令

每当项目从 github 上 clone 一个工程到本地后，或者手动修改过工程内部的命名或结构后

```
idf.py reconfigure
```

在工程中加入组件，然后需要重新生成项目结构

```
idf.py -C components create-component [组件名]
idf.py reconfigure
```

清理编译生成的文件

```
基础的清理
idf.py clean
清理整个 build 文件夹的内容
idf.py fullclean
```
