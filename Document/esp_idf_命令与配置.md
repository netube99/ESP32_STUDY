# ESP-IDF 命令与配置笔记

[ESP-IDF 编程指南](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/index.html)
[使用 ESP-IDF 构建系统](https://docs.espressif.com/projects/esp-idf/zh_CN/latest/esp32/api-guides/build-system.html#id3)

在当前CMD使用ESP-IDF
```
%userprofile%\esp\esp-idf\export.bat
```
在当前PowerShell使用ESP-IDF
```
.$HOME/esp/esp-idf/export.ps1
```

ESP-IDF 命令列表
```
idf.py --help
```



## 创建项目流程

生成新项目
```
在当前目录下生成项目
idf.py create-project [项目名称]

在指定目录下生成项目（自生成项目名文件夹）
idf.py create-project
df.py create-project --path [项目目录] [项目名称]
```

设置目标芯片

esp32 — 适用于 ESP32-D0WD、ESP32-D2WD、ESP32-S0WD (ESP-SOLO)、ESP32-U4WDH、ESP32-PICO-D4
esp32s2— 适用于 ESP32-S2
esp32c3— 适用于 ESP32-C3
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

编译并烧录
idf.py build flash -p [串口号]
```
