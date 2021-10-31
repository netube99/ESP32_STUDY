# ESP-IDF 创建新工程

记录一次在 Windows 环境下的 esp-idf 新工程的创建：esp32系列，VSCode 编辑器开发，Git 管理工程代码，使用 powershell + idf 环境变量编译工程；

## 开始
### idf 的操作

打开 powershell + idf，输入命令：

```
cd C:\Users\zhong\Desktop
idf.py create-project new_project
cd new_project
idf.py set-target esp32
idf.py -C components create-component bsp
idf.py reconfigure
```

### VSCode 的操作
在工程根目录下打开 VSCode，Ctrl + Shift + P 打开插件菜单，选择 C/C++：编辑配置（JSON），根目录出现文件夹 .vscode，内含文件 c_cpp_properties.json，在 c_cpp_properties.json 中找到 compilerPath 项，更改项内容为当前芯片型号对应的编译器的地址，目前芯片型号为 esp32 所以编译器地址为：

```
"compilerPath": "C:\\Users\\zhong\\.espressif\\tools\\xtensa-esp32-elf\\esp-2021r1-8.4.0\\xtensa-esp32-elf\\bin\\xtensa-esp32-elf-gcc.exe"
```

在 c_cpp_properties.json 中添加新项 compileCommands ，内容设置为 build 文件夹下 compile_commands.json 文件的地址 :

```
"compileCommands": "build\\compile_commands.json"
```

### Git 的操作
为了让 Git 在跟踪工程代码时不要记录目录绝对值和 build 文件夹，在 Git 管理的根目录下新建文件 .gitignore，内容如下：

```
.vscode
build
```

新工程创建结束

## 注意事项

