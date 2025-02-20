1.tasks.josn 将文件的command值换成自己的g++目录, tasks.josn负责构建编译运行

2.launch.josn 将文件的preLaunchTask值为tasks.josn中的label, 这样在调试进行之前会先执行tasks任务 代码我写了两部分, 上面的是用lldb进行调试(Codelldb插件), 注释掉的第二部分的是使用cppdbg 由于我用cppdbg调试的时候, 运行完毕, 终端console会自动关闭, 而且有些地方也不太一样,所以我用的第一种调试 3.c_cpp_properties.json 主要是指定c++版本, 指定编译器路径

生成的文件会放在当前目录的output里, 如果不存在这个文件夹会自动生成 想修改输出目录, 可以修改这部分代码: "program": "${workspaceFolder}\output${fileBasenameNoExtension}", 5.如果想调试的时候额外打开一个终端console进行输入: 如果是Codelldb: 在vscode的设置中搜索: Launch: Terminal, 改为external即可

6.回车后上一行的空行会自动删除, 如果不想让他删除可以这样做: 1.在设置界面的搜索框中输入“trimAutoWhitespace”。这个设置项控制着是否自动修剪空白字符。 2.如果该设置项为“true”，则可能会导致空行缩进被删除。将其设置为“false”可以解决这个问题。

7.更新: 加入clang编译器, 可自由选择g++或者clang++ 使用clang++, 先下载安装llvm, 网址:https://github.com/llvm/llvm-project/releases/tag/llvmorg-19.1.5 使用g++, 先下载安装mingw, github上下载这个: x86_64-14.2.0-release-posix-seh-ucrt-rt_v12-rev0.7z

8.在vscode使用Git服务

git设置HTTP代理指令：
git config --global http.proxy http://127.0.0.1:10809 // 本地ip + http端口， http端口=socks端口+1

测试是否成功
curl -x http://127.0.0.1:10809 http://ifconfig.me curl -x http://127.0.0.1:10809 http://ifconfig.co
