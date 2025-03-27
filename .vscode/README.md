1.tasks.josn 将文件的command值换成自己的g++目录, tasks.josn负责构建编译运行
解决调试窗口执行完毕自动秒关闭：在tasks.json文件中进行如下更改： ${fileDirname}\\output\\${fileBasenameNoExtension}.exe && pause，就是添加了&&pause就行了
2.launch.josn 将文件的preLaunchTask值为tasks.josn中的label, 这样在调试进行之前会先执行tasks任务 代码我写了两部分, 上面的是用lldb进行调试(Codelldb插件), 注释掉的第二部分的是使用cppdbg 由于我用cppdbg调试的时候, 运行完毕, 终端console会自动关闭, 而且有些地方也不太一样,所以我用的第一种调试 3.c_cpp_properties.json 主要是指定c++版本, 指定编译器路径

生成的文件会放在当前目录的output里, 如果不存在这个文件夹会自动生成 想修改输出目录, 可以修改这部分代码: "program": "${workspaceFolder}\output\${fileBasenameNoExtension}",
5.如果想调试的时候额外打开一个终端console进行输入: 如果是Codelldb: 在vscode的设置中搜索: Launch: Terminal, 改为external即可

6.回车后上一行的空行会自动删除, 如果不想让他删除可以这样做: 1.在设置界面的搜索框中输入“trimAutoWhitespace”。这个设置项控制着是否自动修剪空白字符。 2.如果该设置项为“true”，则可能会导致空行缩进被删除。将其设置为“false”可以解决这个问题。

7.更新: 加入clang编译器, 可自由选择g++或者clang++ 使用clang++, 先下载安装llvm, 网址:https://github.com/llvm/llvm-project/releases/tag/llvmorg-19.1.5 使用g++, 先下载安装mingw, github上下载这个: x86_64-14.2.0-release-posix-seh-ucrt-rt_v12-rev0.7z

8.在vscode使用Git服务
# git设置HTTP代理指令：
git config --global http.proxy http://127.0.0.1:10809 // 本地ip + http端口， http端口=socks端口+1
# 测试是否成功
curl -x http://127.0.0.1:10809 http://ifconfig.co

curl -x http://127.0.0.1:10809 http://ifconfig.me



/*
颜色配置, 很重要, 调了半天的颜色.
还有背景图片设置.
{
    "explorer.confirmPasteNative": false,
    "editor.mouseWheelZoom": true,
    "explorer.confirmDragAndDrop": false,
    "explorer.confirmDelete": false,
    "background.fullscreen": {
        
        "images": [

            // "file:///D:\\壁纸\\123 (4).png",
            // "file:///D:\\壁纸\\123 (8).png",
            // "file:///D:\\壁纸\\123 (9).png",
            // "file:///D:\\壁纸\\123 (10).png",
            // "file:///D:\\壁纸\\123 (11).png",
            // "file:///D:\\壁纸\\123 (12).png",
            // "file:///D:\\壁纸\\123 (13).png",
            // "file:///D:\\壁纸\\123 (14).png",
            // "file:///D:\\壁纸\\123 (16).png",
            // "file:///D:\\壁纸\\123 (17).png"
        ],
        "opacity": 0.18,
        "size": "cover",
        "position": "center",
        "interval": 0,
        "random": true
    },
    "C_Cpp.default.cppStandard": "c++11",
    "C_Cpp.default.cStandard": "c11",
    "C_Cpp.default.intelliSenseMode": "gcc-x64",
    "git.confirmSync": false,
    "git.openRepositoryInParentFolders": "never",
    "editor.trimAutoWhitespace": false,
    "editor.renderWhitespace": "boundary",
    "git.enableSmartCommit": true,
    "extensions.ignoreRecommendations": true,
    "workbench.settings.applyToAllProfiles": [
        "debug.console.closeOnEnd"
    ],
    "debug.console.historySuggestions": false,
    "terminal.external.windowsExec": "C:\\Windows\\System32\\cmd.exe",
    "terminal.integrated.defaultProfile.windows": "PowerShell",
    "debug.showSubSessionsInToolBar": true,
    "debug.console.closeOnEnd": true,
    "workbench.statusBar.visible": false,
    "code-runner.runInTerminal": true,
    "code-runner.saveFileBeforeRun": true,
    "clangd.path": "c:\\Users\\cheat\\AppData\\Roaming\\Code\\User\\globalStorage\\llvm-vs-code-extensions.vscode-clangd\\install\\19.1.2\\clangd_19.1.2\\bin\\clangd.exe",
    "terminal.integrated.enableMultiLinePasteWarning": "never",
    "editor.bracketPairColorization.enabled": true,
    "editor.semanticHighlighting.enabled": false,
    "editor.tokenColorCustomizations": {
        "textMateRules": [
        // 关键字
        { "scope": "keyword", "settings": { "foreground": "#569CD6" } },
        // 类型, 例如 int,
        { "scope": "storage.type", "settings": { "foreground": "#569CD6" } },
        // 常量
        { "scope": "constant.language", "settings": { "foreground": "#c586c0" } },
        // 变量名
        { "scope": "variable.other", "settings": { "foreground": "#ABB2BF" } },
        // 全局变量
        { "scope": "variable.other.global", "settings": { "foreground": "#ABB2BF" } },
        // const
        { "scope": "storage", "settings": { "foreground": "#C586C0" } },
        // include
        { "scope": "keyword.control.directive.include", "settings": { "foreground": "#C586C0" } },
        // define
        { "scope": "keyword.control.directive.define", "settings": { "foreground": "#C586C0" } },
        // 头文件名
        { "scope": "string.quoted.other.lt-gt.include", "settings": { "foreground": "#C586C0" } },
        // 1e5 的 e
        { "scope": "keyword.other.unit.exponent.decimal", "settings": { "foreground": "#B5CEA8" } },

        // 函数名
        { "scope": "entity.name.function", "settings": { "foreground": "#4169E1" } }, // 1E90FF, 4169E1
        // 数字
        { "scope": "constant.numeric", "settings": { "foreground": "#b5cea8" } },
        // 参数
        { "scope": "variable.parameter", "settings": { "foreground": "#9CDCFE" } },
        // 字符串
        //{ "scope": "string.quoted", "settings": { "foreground": "#90EE90" } },
        // 注释
        { "scope": "comment.line", "settings": { "foreground": "#5C6370" } },
        // 宏
        { "scope": "entity.name.function.preprocessor", "settings": { "foreground": "#c586c0" } },
        
        ]
    },
    
    "workbench.colorCustomizations": {
        "editorBracketHighlight.foreground1": "#d4d4d4",
        "editorBracketHighlight.foreground2": "#DA70D6",
        "editorBracketHighlight.foreground3": "#179FFF",
        "editorBracketHighlight.foreground4": "#24D600",
        "editorBracketHighlight.foreground5": "#00D8D8",
        "editorBracketHighlight.foreground6": "#EE0255",
        //         // 修改编辑器背景颜色
        // "editor.background": "#282c34",
        //         // 修改侧边栏背景颜色
        // "sideBar.background": "#21252b",
        //         // 修改状态栏颜色
        // "statusBar.background": "#007ACC",
        // "terminal.background": "#282c34",
        // "terminal.foreground": "#282c34",
        // "terminalCursor.background": "#282c34",
        // "terminalCursor.foreground": "#282c34",
        //  "titleBar.border": "#007ACC",
        // 更多颜色键名参考：https://code.visualstudio.com/api/references/theme-color
    },
    "workbench.iconTheme": "eq-material-theme-icons",
    "workbench.colorTheme": "One Monokai",
}

*/
