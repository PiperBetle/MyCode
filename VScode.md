# VScode 介绍
VScode 是一款强大的编辑器，至少在对于 OIer 来说 VScode 是最好的选择，VScode 是轻量级编辑器，不像 VS 或者 Clion 一样是重量级编辑器，不方便 OIer 使用（并且还疯狂占用 CPU）；也不像 Dev-cpp 一样尽管可以直接使用，但是功能却一言难尽……这个时候就要看 VScode 了！  
VScode 支持打开文件夹，代码补全，代码片段插入，强大的调试功能，Markdown 的编辑和浏览，括号匹配，本地历史记录保存，修改代码缩进风格，内部控制台，连体字符，内置 git，内置编码查看修改，代码查看，宏展开等等……绝对是 OIer 的不二之选。
# VScode 下载和安装
直接在[官网](https://code.visualstudio.com/Download)下载即可，但是由于某些不知道的原因下载比较慢，建议配合多线程下载器使用，比如说 ~~Minecraft 启动器~~ 多线程下载器 [pcl2](https://afdian.net/@LTCat)，可以在 1min 内下载完毕，下载完毕后不用多想一路下一个就行了，不像某 P2P 一样会附带捆绑。  
我相信大多数人先看见 VScode 打开时那堆英文就劝退了，实际上等待一会儿 VScode 就会让你下载中文插件，或者 Ctrl+Shift+X 打开拓展界面输入 Chinese 安装第一个插件就行了，最后重启再打开显示的就是中文了。再实际上重启不用按叉叉再打开 VScode （这个叫大退），只要 Ctrl+Shift+P 输入 reload 就可以重启了（这个叫小退）。  
VScode 的默认字体不是连体等宽字体，我们不妨在[这里](https://github.com/tonsky/FiraCode)下载 Fira Code，一款连体等宽字体，然后在设置里输入：
```json
"editor.fontFamily": "Fira Code",
```
字体就变成漂亮的连体等宽字体 Fira Code 了。
众所周知 VScode 在配置时比较麻烦，这点可以通过登录 Github 账号解决，也可以通过下载 VScode 绿色版解决。这里就介绍一下怎么下载 VScode 绿色版。  
首先还是在[这里](https://code.visualstudio.com/Download)下载，不过这次下载的是 .zip 压缩包，解压完之后在 Code.exe 同级目录下新建文件夹 data，里面存放的就是各种配置，包括拓展、设置等等。在里面新建一个 tmp 的文件夹表示临时文件会在这里面生成。这个时候打开 Code.exe 就可以了，绿色版就是这么简单……  
# VScode 配置 c++ 环境
注意支持 win7 的最后一个版本 [1.70.3](https://vscode.cdn.azure.cn/stable/a21a160d630530476218b85db95b0fd2a8cd1230/VSCode-win32-x64-1.70.3.zip)。

~~都2022年了总是 c++ 了~~  
首先安装 C/C++ 插件，实际上有这个插件就行了，下载时可能 VScode 会热情赠送一些~~没用~~的插件，会拖慢启动速度而且没什么用处，可以直接不下载那些插件。  
然后需要一个 c++ 在 Path 里的环境，所以需要一个 MinGW，考虑到 Dev-cpp 的 MinGW 过于古老，建议到 [winlibs](https://www.winlibs.com) 里面下载一个 MinGW，下载下来是个压缩包，解压后放在自己喜欢的位置（也可以直接删掉 Dev-cpp 里的 MinGW，把这个替换进去），然后 右键此电脑-属性-高级系统设置-环境变量，选择变量 Path ，如果没有 MinGW 就新建一个，输入 MinGW 的解压地址，再来个 \\bin 。比如说我把 MinGW 直接解压到 C 盘下面，添加的路径就是 C:\\MinGW64\\bin 。打开 cmd 输入 `g++ -v` 就可以知道环境变量是否安装成功，如果成功是会显示 gcc 的版本的。  
再次回到 VScode ，先选择一个自己喜欢的文件夹，以后的文件都放这里了。Ctrl+Shift+P 输入 C/C++编辑配置(JSON) 就会自动生成一个 .json 文件，一般来说是没什么问题的，直接关掉就行了。  
这个时候打开工作文件夹里的 .cpp 文件，就可以看到代码补全和代码高亮发挥了作用，如果没有就小退/大退一下。如果还是没有代码补全试试 Ctrl+Shift+P 打开首选项：打开设置(JSON)，输入以下文字：
```json
"[cpp]": {
	"editor.quickSuggestions": true
},
```  
如果还是没有效果可能是因为没有 .net4.5 以上的环境，可以在[这里](https://dotnet.microsoft.com/zh-cn/download/dotnet-framework/net452)下载，建议下载脱机版。  
但是这样并不好，因为只能编译却不能运行，VScode 就只发挥了一般的高级编辑器的作用，然而 VScode 却不是一般的高级编辑器，而是高级的高级编辑器（胡言乱语++）。有的同学可能已经在 F11 试图运行了，结果却全屏了，因为我们需要修改 VScode 的配置让其能生成 .exe 文件并且打开 .exe文件。
## 指令
这个非常简单，直接使用 cmd 自己输指令编译运行就行了。但是略微有些麻烦，不如 Code Runner。可能用 Linux 的比较顺手？
## Code Runner
不得不说 Code Runner 挺好用的。Ctrl+Shift+X 输入 Code Runner 就可以下载 Code Runner 插件，然后直接就可以 Ctrl+Alt+N 运行了~
但是输入和输出都在小小的面板里，不得不说有点难受，可以选择移动面板的位置来修改，另外可以 Ctrl+Shift+P 输入首选项：打开设置(JSON)，在 settings.json 输入这些内容就可以在终端里运行（不是面板里的终端）。
```json
"code-runner.clearPreviousOutput": true,//运行前清屏
"code-runner.runInTerminal": true,//在终端里运行
"terminal.integrated.cursorStyle": "line",//终端光标是线的形状
"terminal.integrated.defaultLocation": "editor",//终端在页面里
"terminal.integrated.cursorBlinking": true,//终端光标闪烁
"terminal.integrated.fontSize": 15,//终端字体大小为 15
"terminal.integrated.enableMultiLinePasteWarning": false,//在终端邮件粘贴时不警告
"code-runner.saveFileBeforeRun": true,//运行前保存文件
```
这样修改过之后就是作者喜欢的形状了（还是建议按照自己喜好修改）。  
不过这样弄完之后有些比较麻烦的事情，请看下面：
### 不能处理带空格的文件
这是因为 Code Runner 默认配置的问题，可以在设置里输入
```json
"code-runner.executorMap": {
	"cpp": "cd $dir && g++ \"$fileName\" -o VScodeRunner -O2 -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -Wconversion && ./VScodeRunner",
},
```
注意到 VScode 的默认终端是 powershell，如果不喜欢可以把终端改成 cmd。  
```json
"terminal.integrated.defaultProfile.windows": "Command Prompt",//将默认终端改成cmd
"code-runner.executorMap": {
	"cpp": "cd $dir && g++ \"$fileName\" -o VScodeRunner -O2 -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -Wconversion && VScodeRunner",// cmd 的语法就不用 ./ 了
},
```
Code Runner 原理是在终端里输入指令运行，所以你也可以试试自己 diy 哦！`$dir` 表示当前文件所在的文件夹名称，`$fileName` 表示当前文件的名称。
多说无益，给个表：
- `$workspaceRoot` 当前工程目录路径
- `$dir` 要运行的代码文件所在的目录
- `$dirWithoutTrailingSlash` 要运行的代码文件所在的目录(不带尾后斜杆)
- `$fullFileName` 要运行的代码文件全路径
- `$fileName` 要运行的代码文件名称
- `$fileNameWithoutExt` 要运行的代码文件名称(不带后缀名)
- `$driveLetter` 要运行的代码文件所在盘符(只用于Windows系统)
- `$pythonPath` Python解释器路径

如果不想清一色 VScodeRunner 就这样把所有 VScodeRunner 改成 `\"$fileNameWithoutExt\"`，这样产生的 exe 文件名就和 cpp 文件名一样。
### 小优化
众所周知有的机子编译 c++ 程序比较慢，在台式机上问题不大是秒出，但是在我的垃圾电脑上跑的就比较慢。Code Runner 在编译时期只有编译完才可以输入，有时候着急就按了好几下粘贴了好几次……这不太好，解决的最好方式是编译结束后输出一条结束语，最简单的方法就是在 settings.json 里插入 echo 语句，不过这样输出是白色的不太好看，所以我选择另一种方式：写一个小程序：
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<windows.h>
int main(int argc,char const *argv[]){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::string c2;
	for(int i=1;i<argc;i++)c2+=argv[i];
	system(("echo \033[36;40m"+c2).data());
	system("echo|set /p=\033[37;40m");
	return 0;
}
```
众所周知 c++ 的 main 函数可以放一个 int 变量和 char 数组指针的数组指针，argc 表示数组指针的数量，argv 记录了参数内容。这个 exe 的大体意思是把所有参数组合起来，用蓝色输出，第二个 system 是让颜色改成默认的黑白，否则后面一直是蓝黑。`|set /p=` 的作用是让 echo 不换行。
这个程序编译完之后，可以在 cmd 里输入
```sh
VScodeRunner "2345 6789"
```
来检查正确性，如果输出的是蓝色的 `2345 6789` 就表示这个程序没问题。把编译完的文件放入工作文件夹改成喜欢的名字比如 IcePrint.exe 然后把 settings.json 这么改：
```json
"code-runner.executorMap": {
	"cpp": "cd $dir && g++ \"$fileName\" -o VScodeRunner -O2 -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -Wconversion && \"$workspaceRoot\"\\IcePrint \"Compile OK\" && ./VScodeRunner",
},
```
如果使用 echo 直接输出：
```json
"code-runner.executorMap": {
	"cpp": "cd $dir && g++ \"$fileName\" -o VScodeRunner -O2 -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -Wconversion && echo \"Compile OK\" && ./VScodeRunner",
},
```
同理也可以改成 `\"$fileNameWithoutExt\"`。结果令人满意QAQ 也可以自己写自己的 IcePrint，甚至可以自己写随机数来控制输出的内容和颜色，甚至还能放几句台词？？？反正一切皆有可能只要你会基础 cmd 语法和基础 c++ 语法。
### Ubuntu
按照 bash 的语法修改一下，其实就是上面 powershell 的语法：
```json
"code-runner.executorMap": {
	"cpp": "cd $dir && g++ \"$fileName\" -o VScodeRunner -O2 -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -Wconversion && ./VScodeRunner",
},
```
## launch.json 和 tasks.json
注意：此方法从来没有在 win7 及以下版本成功过，似乎 win7 不能运行 `tasks.json`，而且支持 win7 的最后一个 VScode 版本是 1.70.3。

这个做法看似麻烦实际不难，而且是考场上没有 Code Runner 时的做法。  
一般的配置方式都是写个 `tasks.json`，使用 `launch.json` 调用一个 task，然后就可以跑程序了。  
首先在刚刚的 `.vscode` 里建 `launch.json`，输入以下代码：
```json
{
	"version": "0.2.0",
	"configurations": [
		{
			"name": "编译并调试(VScode)",
			"type": "cppdbg",
			"request": "launch",
			"program": "${fileDirname}\\VScodeRunner.exe",
			"cwd": "${fileDirname}",
			"preLaunchTask": "g++ compile"
		},
		{
			"name": "编译并运行(ConsolePauser)",
			"type": "cppvsdbg",
			"request": "launch",
			"program": "${workspaceFolder}\\ConsolePauser.exe",
			"args": ["VScodeRunner.exe"],
			"cwd": "${fileDirname}",
			"console": "newExternalWindow",
			"preLaunchTask": "g++ compile (no debug)"
		},
		{
			"name": "编译并运行(pause)",
			"type": "cppvsdbg",
			"request": "launch",
			"program": "VScodeRunner.exe",
			"cwd": "${fileDirname}",
			"console": "externalTerminal",
			"preLaunchTask": "g++ compile (no debug)"
		}
	]
}
```
这里的 `name` 就是名字，给自己看的而已，`request` 就写 `launch`，`program` 就是你要运行的程序，`cwd` 表示你写的指令的相对位置，`preLaunchTask` 就是你要调用的 task 了。  
仔细研究上述代码，发现他们的 `type` 不同，`cppdbg` 表示调试的意思，而 `cppvsdbg` 表示运行，这个调试就是字面意思，没什么可以研究的。运行中还带个 `console` 表示类型，`newExternalWindow` 表示新跳出一个窗口，`externalTerminal` 表示新跳出一个窗口，运行结束后自动暂停。  
注意中间那个写法，`ConsolePauser` 就是 Dev-c++ 里面的 `ConsolePauser`，我在这里调用就可以仿照 Dev-c++ 的操作界面了。`ConsolePauser` 的好处就是可以计时以及获得返回值，`args` 就是参数表，也就是说你可以在 cmd 里面输入 `ConsolePauser VScodeRunner.exe` 来以 Dev-c++ 的形式运行个 exe。  
这里附上 `tasks.json` 的写法：
```json
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "shell",
			"label": "g++ compile",
			"command": "g++",
			"args": [
				"${file}",
				"-g",
				"-o",
				"${fileDirname}\\VScodeRunner",
				"-O2",
				"-Wall",
				"-Wextra",
				"-Wpedantic",
				"-Wshadow",
				"-Wconversion",
				"-std=c++20"
			],
			"problemMatcher": [
				"$gcc"
			]
		},
		{
			"type": "shell",
			"label": "g++ compile (no debug)",
			"command": "g++",
			"args": [
				"${file}",
				"-o",
				"${fileDirname}\\VScodeRunner",
				"-O2",
				"-Wall",
				"-Wextra",
				"-Wpedantic",
				"-Wshadow",
				"-Wconversion",
				"-std=c++20"
			],
			"problemMatcher": [
				"$gcc"
			]
		}
	]
}
```
如果是 Ubuntu 把相应的语法改成 bash 的语法就行了。

如果在 CSP 的时候机子不太行，不能跑 `tasks.json`，那我推荐一个赛场上很适合写的方法，把所有指令压缩到 cmd 的参数列表里面，win7 和远古版本 VScode 也肯定支持哦：
```json
{
	"version": "0.2.0",
	"configurations": [
		{
			"name": "(Windows) 快速启动",
			"type": "cppvsdbg",
			"request": "launch",
			"program": "C:\\Windows\\System32\\cmd.exe",
			"args": [
				"/c g++ ${file} -o ${fileBasenameNoExtension} -Wl,--stack=104857600 -O2 -Wall -Wextra -Wshadow -std=c++14 && ${fileBasenameNoExtension}.exe"
			],
			"cwd": "${fileDirname}",
			"console": "externalTerminal"
		}
	]
}
```
# VScode 其他配置
## VSCode git
### git 安装
[git](https://git-scm.com/downloads) 是一个重要的源代码管理工具，VScode 也带了 git ，Ctrl+Shift+G 可以召唤 git，然而在这之前，你应该先安装 git。
### 绑定 GitHub
安装完 git 之后建议先把本地电脑和 GitHub 绑定起来，
```cpp
ssh-keygen -t rsa -C "your email"
```
在 cmd 或者 git bush 输入这句话，your email 是你注册 GitHub 的邮箱，跳出一段话后直接回车，然后再直接回车，然后再再直接回车，就会产生一个奇怪的正方形，这个时候打开用户文件夹，发现里面多了个 .ssh 文件夹，用 VScode 打开 id_rsa.pub，发现里面是一串以 ssh-rsa 开头的字符串，将所有字符复制，打开 GitHub 的[这个](https://github.com/settings/keys)页面，选择 New SSH Key，Title随意 ，Key 里就是刚刚那串字符串（要 ssh-rsa 这个前缀），然后 Add SSH Key 后输入密码就行了。  
可以通过在 cmd 或者 git bush 输入
```cpp
ssh -T git@github.com
```
检测是否成功，如出现
```cpp
Are you sure you want to continue connecting (yes/no/[fingerprint])?
```
字样就输入 yes 然后回车，如果出现
```cpp
Hi "Your Name"! You've successfully authenticated, but GitHub does not provide shell access.
```
就代表成功连接了 Github
### 上传仓库
直接 Ctrl+Shift+G 选择上传到Github，选择是公有仓库还是私有仓库就行了。
### 更新
之后你的更改都会在 Ctrl+Shift+G 页面显示出来，可以暂存更改，在消息中输入文字后 Ctrl+Enter 就可以提交更改，但是这只是在本机的更改，并不会影响 Github ，这个时候选择右上角 3 个点选择推送就行了，如果你想把 Github 上仓库的内容替换本地，就选择拉取。
## Python
对于 OIer 来说光是 C/C++ 显然是不够的，比如说 Python 也是一种~~在高精度上~~重要的语言，Python 是解释性语言，不需要这么复杂的配置，我在上面 Code Runner 章节也贴出了 Python 和 Ruby 的 Code Runner 参数，然后下载 Python 的插件就有了高亮和代码补全，直接 Ctrl+Shift+N 运行即可。
## Markdown
对于 OIer 来说 Markdown 也是很重要的，用来写题解，笔记或者感想等都是非常有用的。VScode 内部自带了 Markdown，只要建一个 xxx.md 文件就好了，Ctrl+K V 就可以一边编辑 Markdown 一边浏览了，非常方便！！
## 用户代码片段
别人随便按几下就是一个板子，随便按几下就是一个函数，羡慕吗？这就是用户代码片段。只要文件-首选项-用户片段-新建"xx"文件夹的代码片段文件，选择一个喜欢的名字就可以弄用户代码片段了，是一个 .code-snippets 文件。  
这里给出一个板子：
```json
{
	"快速幂": {//补全提示
		"scope": "cpp",//出现的文件
		"prefix": "add_qp",//补全关键词
		"body": [//插入部分主体
			"inline int qp(int a,int b,int t=1){for(;b;b>>=1,a=a*a%MOD)if(b&1)t=t*a%MOD;return t;}"
		]
	}，
	"模板": {
		"scope": "cpp",
		"prefix": "add_mod",
		"body": [
			"#include<iostream>",//以逗号隔开
			"#include<cstdio>",
			"#include<algorithm>",
			"using std::cin;using std::cout;",
			"signed main(){",
			"//\tfreopen(\".in\",\"r\",stdin);",//注意这种情况需要转义符
			"//\tfreopen(\".out\",\"w\",stdout);",
			"//\tstd::ios::sync_with_stdio(false);",
			"//\tcin.tie(nullptr);cout.tie(nullptr);",
			"\treturn 0;",
			"}"//json文件语法，最后一个没有逗号
		]
	}//json文件语法，最后一个没有逗号
}
```
有人说：我这一个一个修改转义符一个一个加上引号也太麻烦了吧！确实有点，但是作为一名成熟的 OIer，写个程序为自己所用还是没什么问题的：
```cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using std::cin;using std::cout;
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	std::string a,b="";
	while(std::getline(cin,a)){
		cout<<b<<"\"";b=",\n";
		for(char it:a){
			switch(it){
				case '\t':cout<<"\\t";continue;
				case '\"':cout<<"\\\"";continue;
				case '\\':cout<<"\\\\";continue;
				default:cout<<it;
			}
		}
		cout<<"\"";
	}
	return 0;
}
```
## VScode 插件
### Chinese
[下载链接](https://marketplace.visualstudio.com/items?itemName=MS-CEINTL.vscode-language-pack-zh-hans) 
不认识英语的蒟蒻表示很赞。
### Code Runner
[下载链接](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner) 
一件运行代码，简单到不解释。
### C/C++
[下载链接](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) 
提供了 C/C++ 的代码补全和代码高亮。
### Python
[下载链接](https://marketplace.visualstudio.com/items?itemName=ms-python.python) 
提供了 Python 的代码补全和代码高亮
### Drawio
[下载链接](https://marketplace.visualstudio.com/items?itemName=hediet.vscode-drawio) 
提供了 VScode 对 .drawio 文件的支持
### MindMap
[下载链接](https://marketplace.visualstudio.com/items?itemName=Souche.vscode-mindmap) 提供了 VScode 对 .km 文件的支持
### One Dark Pro
[下载链接](https://marketplace.visualstudio.com/items?itemName=zhuangtongfa.Material-theme) 添加了 3 个暗色主题，主题色调 紫红黄橙蓝绿，非常优雅。
### Horizon Theme
[下载链接](https://marketplace.visualstudio.com/items?itemName=alexandernanberg.horizon-theme-vscode) 粉粉的，真好看。
### background-cover
[下载链接](https://marketplace.visualstudio.com/items?itemName=manasxx.background-cover) 给你的 VScode 加个背景！  
总不可能天天对着黑屏幕写代码，当然是对着自己喜欢的背景写代码啊。  
注意的是有 标题为 background 图标是魔理沙的插件，那个插件下载完后字体会很奇怪QAQ。
### Fix VScode Checksums
[下载链接](https://marketplace.visualstudio.com/items?itemName=lehni.vscode-fix-checksums) 当你装完背景之后 VScode 会贴心提示你 Code 已损坏，安装此插件后 Ctrl+Shift+P 输入 Apply 然后大退就可以去掉 VScode 的贴心提示。
### Colorful Comments
[下载链接](https://marketplace.visualstudio.com/items?itemName=ParthR2031.colorful-comments) 在注释里加上一些特殊字符可以让注释变成彩色的，比如说 `//*` 是绿色，`//!` 是红色，特殊的，注释再注释是删除线，`//TODO` 是橙色。
### Hex Editor
[下载链接](https://marketplace.visualstudio.com/items?itemName=ms-vscode.hexeditor) 提供了 16 进制文本编辑器。
### Error Lens
[下载链接](https://marketplace.visualstudio.com/items?itemName=usernamehw.errorlens) 将代码报错信息移动到行内。
### vscode-pdf
[下载链接](https://marketplace.visualstudio.com/items?itemName=tomoki1207.pdf) VScode 竟然不能看 .pdf 文件，大怒！还好有插件！
### Markdown PDF
[下载链接](https://marketplace.visualstudio.com/items?itemName=yzane.markdown-pdf) 可以把 .md 文件导出成为 .pdf .html 文件，操作简单，右键即可。
### LeetCode
[下载链接](https://marketplace.visualstudio.com/items?itemName=LeetCode.vscode-leetcode) 有的时候想做 LeetCode 的题，装了这个插件直接在 LeetCode 里切。
### vscode-luogu
[下载链接](https://marketplace.visualstudio.com/items?itemName=yltx.vscode-luogu) 有的时候想做洛谷的题，装了这个插件直接在洛谷里切。
### Codeforces Bot
[下载链接](https://marketplace.visualstudio.com/items?itemName=avi01.codeforcesbot-ext) 有的时候想做 Codeforces 的题，装了这个插件直接在 Codeforces 里切。
### Bracket Pair Colorizer 2
[下载链接](https://marketplace.visualstudio.com/items?itemName=CoenraadS.bracket-pair-colorizer-2) 有的恶心题不免出现括号套括号套括号套括号套括号……的情况，这个插件可以给每一层括号匹配不同的颜色，将不匹配的括号渲染成红色  
然而现在 VScode 已经自带此功能了，可以做到和插件一样的效果并且加载速度飞快，常常高亮还没加载出来括号匹配就渲染完了。这里给个板子：
```json
"editor.bracketPairColorization.enabled": true,
"editor.guides.bracketPairs": "active",
"workbench.colorCustomizations": {
	"editorBracketHighlight.foreground1": "#ffd700",
	"editorBracketHighlight.foreground2": "#da70d6",
	"editorBracketHighlight.foreground3": "#87cefa"
},
```
实际上不写也可以有默认的括号匹配，这里给出只是为了 diy 爱好者自己 diy。
### vscode-icons
[下载链接](https://marketplace.visualstudio.com/items?itemName=vscode-icons-team.vscode-icons) 我只想说这个插件修改后的图标真好看。
### Local History
[下载链接](https://marketplace.visualstudio.com/items?itemName=xyz.local-history) 顾名思义，每次保存代码时可以在本地产生一份备份，有的时候，Ctrl+Z 是解决不了问题的。然而现在 VScode 自带这个功能了。只要在 Ctrl+Shift+E 里选择时间线……
### Settings Sync
[下载链接](https://marketplace.visualstudio.com/items?itemName=Shan.code-settings-sync) 不同机子上 VScode 配置不同步怎么办？用这个插件就可以同步，然而现在 VScode 只要登录 GitHub 账号就可以同步了……
### 小霸王
[下载链接](https://marketplace.visualstudio.com/items?itemName=gamedilong.anes) 这真的是小霸王，我只能……啊这了……
### thief-book
[下载链接](https://marketplace.visualstudio.com/items?itemName=C-TEAM.thief-book) 可以在面板的下面偷偷放出小说的字样，神不知鬼不觉，其他人第一眼没反应过来，第二眼字已经不见了！小说的格式是 .txt，编码必须是 UTF-8。
### Cloudmusic
[下载链接](https://marketplace.visualstudio.com/items?itemName=yxl.cloudmusic) 一边写代码一边听歌有时候还是不错的。
### daily anime
[下载链接](https://marketplace.visualstudio.com/items?itemName=deepred.daily-anime) 可以快速看见这周什么番会更新，也可以随机获取一条 ACGN 的句子......
### Zhihu On VSCode
[下载链接](https://marketplace.visualstudio.com/items?itemName=niudai.vscode-zhihu) 来知乎，分享你新编的故事。
### QQ
[下载链接](https://marketplace.visualstudio.com/items?itemName=takayama.vscode-qq) 机房不让用 QQ 怎么办？没有人知道你的 VScode 里有个 QQ。
## VScode 常用配置
### settings.json
我这里把我的settings挂上来，至于是什么效果可以扔到 settings.json 使用鼠标悬停的方式看是什么效果：
```json
{
	"editor.fontFamily": "Fira Code",
	// "editor.fontFamily": "JetBrains Mono",
	// "editor.fontFamily": "Ubuntu Mono",
	"editor.insertSpaces": false,
	"editor.fontLigatures": true,
	"editor.detectIndentation": false,
	"debug.onTaskErrors": "showErrors",
	"code-runner.clearPreviousOutput": true,
	"code-runner.runInTerminal": true,
	"terminal.integrated.cursorStyle": "line",
	"terminal.integrated.defaultLocation": "editor",
	"terminal.integrated.cursorBlinking": true,
	"editor.fontSize": 14,
	"terminal.integrated.fontSize": 15,
	"debug.console.fontSize": 14,
	"workbench.iconTheme": "vscode-icons",
	"code-runner.saveFileBeforeRun": true,
	"workbench.colorTheme": "Tomorrow Night Blue",
	"workbench.colorCustomizations": {
		"editorCursor.foreground": "#88E7E7"
	},
	"code-runner.executorMap": {
		"cpp": "cd $dir && g++ \"$fileName\" -o VScodeRunner -O2 -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -Wconversion && ./VScodeRunner",
	},
	"terminal.integrated.enableMultiLinePasteWarning": false,
	"files.autoGuessEncoding": true,
	"editor.minimap.maxColumn": 100,
	"files.defaultLanguage": "cpp",
	"explorer.copyRelativePathSeparator": "\\",
	"editor.hover.delay": 200,
	"extensions.ignoreRecommendations": true,
	"files.autoSave": "afterDelay",
	"editor.fastScrollSensitivity": 12,
	"workbench.list.fastScrollSensitivity": 12,
	"terminal.integrated.fastScrollSensitivity": 12,
	"files.eol": "\n",
	"workbench.sideBar.location": "right",
	"diffEditor.ignoreTrimWhitespace": false,
	"security.workspace.trust.untrustedFiles": "open",
}
```
还有个更生猛的全部禁用斜体：
```cpp
"editor.tokenColorCustomizations": { //禁用所有主题的斜体
	"textMateRules": [
		{
			"scope": [
				"comment",
				"comment.block",
				"comment.block.documentation",
				"comment.line",
				"constant",
				"constant.character",
				"constant.character.escape",
				"constant.numeric",
				"constant.numeric.integer",
				"constant.numeric.float",
				"constant.numeric.hex",
				"constant.numeric.octal",
				"constant.other",
				"constant.regexp",
				"constant.rgb-value",
				"emphasis",
				"entity",
				"entity.name",
				"entity.name.class",
				"entity.name.function",
				"entity.name.method",
				"entity.name.section",
				"entity.name.selector",
				"entity.name.tag",
				"entity.name.type",
				"entity.other",
				"entity.other.attribute-name",
				"entity.other.inherited-class",
				"invalid",
				"invalid.deprecated",
				"invalid.illegal",
				"keyword",
				"keyword.control",
				"keyword.operator",
				"keyword.operator.new",
				"keyword.operator.assignment",
				"keyword.operator.arithmetic",
				"keyword.operator.logical",
				"keyword.other",
				"markup",
				"markup.bold",
				"markup.changed",
				"markup.deleted",
				"markup.heading",
				"markup.inline.raw",
				"markup.inserted",
				"markup.italic",
				"markup.list",
				"markup.list.numbered",
				"markup.list.unnumbered",
				"markup.other",
				"markup.quote",
				"markup.raw",
				"markup.underline",
				"markup.underline.link",
				"meta",
				"meta.block",
				"meta.cast",
				"meta.class",
				"meta.function",
				"meta.function-call",
				"meta.preprocessor",
				"meta.return-type",
				"meta.selector",
				"meta.tag",
				"meta.type.annotation",
				"meta.type",
				"punctuation.definition.string.begin",
				"punctuation.definition.string.end",
				"punctuation.separator",
				"punctuation.separator.continuation",
				"punctuation.terminator",
				"storage",
				"storage.modifier",
				"storage.type",
				"string",
				"string.interpolated",
				"string.other",
				"string.quoted",
				"string.quoted.double",
				"string.quoted.other",
				"string.quoted.single",
				"string.quoted.triple",
				"string.regexp",
				"string.unquoted",
				"strong",
				"support",
				"support.class",
				"support.constant",
				"support.function",
				"support.other",
				"support.type",
				"support.type.property-name",
				"support.variable",
				"variable",
				"variable.language",
				"variable.name",
				"variable.other",
				"variable.other.readwrite",
				"variable.parameter"
			],
			"settings": {
				"fontStyle": ""
			}
		}
	]
},
```
这个问题本来应该在第一段回答，为了防止影响理解就放在这里了：怎么把绿色版的配置变成本地的配置呢？  
这里举个例子，假如我的用户名字叫做 piper，并且之前修改过 VScode 的配置，那么在 C:\\Users\\piper 目录下有一个 .vscode 的文件夹，里面有一个 extensions 的文件夹和 argv.json 的文件，全部拷贝到 data 文件夹里。同时在 C:\\Users\\piper\\AppData\\Roaming 文件夹里有个叫 Code 的文件夹，也拷贝到 data 文件夹里，然后启动 Code.exe，如果是移动完第一次启动可能不会生效，只需要小退/大退一下就会生效。  
对于绿色版和安装版，C:\\Users\\piper\\AppData\\Roaming\\Code\\User 和 F:\\VSCode\\data\\user-data\User （这里假设解压到了 F 盘）是同一个东西，C:\\Users\\piper\\AppData\\Roaming\\Code\\User\\settings.json 和 F:\\VSCode\\data\user-data\\User\\settings.json 就是后文多次提到的 Ctrl+Shift+P 首选项：打开设置(JSON)。当然也可以修改工作文件夹里的 .vscode 文件夹里的 settings.json 来覆盖全局配置。设置用户自定义快捷键的 keybindings.json 也是同理。（如果你没有修改过，没有这个文件是正常的）  
另外说一句，卸载掉 VScode 之后 C:\\Users\\piper\\.vscode 和 C:\\Users\\piper\\AppData\\Roaming\\Code 这两个文件夹仍然存在，如果不删掉这两个文件夹，以后再下载 Code 会保持原来的配置……所以如果不小心搞坏了 VScode，删掉这两个文件夹后又是一条好汉。
### keybindings.json
- Ctrl+N 新建文件
- Ctrl+Shift+N 新建窗口
- Ctrl+P 搜索并打开文件
- Ctrl+Shift+P 选择功能
- Ctrl+Shift+E 打开资源管理器
- Ctrl+Shift+D 打开调试栏
- Ctrl+Shift+F 打开工作文件夹搜索栏
- Ctrl+Shift+H 打开工作文件夹替換栏
- Ctrl+Shift+G 打开 Git 栏
- Ctrl+Shift+X 打开拓展栏
- Ctrl+B 打开或关闭以上 6 个
- Ctrl+Shift+K 删除本行
- Ctrl+Shift+Enter 跳到上一行开头
- Ctrl+Enter 跳到下一行开头
- Ctrl+S 保存
- Ctrl+Shift+S 另存为
- Ctrl+K S 全部保存
- Ctrl+C 复制
- Ctrl+X 剪切
- Ctrl+V 粘贴
- Ctrl+Z 撤销
- Ctrl+Y 恢复
- Ctrl+I 代码补全
- Ctrl+F 搜索
- Ctrl+O 打开文件
- Ctrl+K Ctrl+O 打开文件夹
- Ctrl+H 替换
- Ctrl+A 全选
- Ctrl+G 跳到指定行
- Ctrl+L 选择这行
- Ctrl+~ 打开面板终端
- Ctrl+K Ctrl+X 删除尾部空格
- Ctrl+K R 在资源管理器打开当前文件
- Ctrl+K V 打开 Markdown 浏览
- Ctrl+K Z进入禅模式
- Ctrl+Shift+~ 打开终端
- Ctrl+, 打开设置
- Ctrl+/ 注释
- Ctrl+Shift+\ 跳到匹配的括号
- Ctrl+tab 切换文件
- Ctrl+[ 向左缩进一次
- Ctrl+] 向右缩进一次
- Ctrl+- 窗口缩小
- Ctrl+= 窗口放大
- Ctrl+Up 光标不动，页面上移
- Ctrl+Dn 光标不动，页面下移
- Ctrl+Left 左移一块
- Ctrl+Right 右移一块
- Ctrl+F2 选中所有当前选中项
- Ctrl+F4 功能更强的关闭
- Ctrl+W 关闭文件
- Ctrl+U 回到上一次的光标位置
- Ctrl+K F 关闭文件夹
- Alt+F4 关闭 VScode
- Alt+Up 将这行代码上移
- Alt+Dn 将这行代码下移
- Alt+Shift+F 格式化
- Alt+Shift+I 在选中行末尾插入光标
- Alt+Shift+Up 向上复制一行
- Alt+Shift+Dn 向下复制一行
- Alt+Shift+Left 缩小选择的代码块
- Alt+Shift+Right 扩大选择的代码块
- Alt+左键 插入光标
- Alt+Shift+左键 多列插入光标
- Ctrl+Alt+Shift+Up 向上移动并插入光标
- Ctrl+Alt+Shift+Dn 向下移动并插入光标
- F2 重命名
- F5 编译
- F8 跳到下一个错误
- F9 设置断点
- F11 全屏
- F12 转到定义
- Home 转到行首
- End 转到行尾
- Ctrl+Home 转到文件首
- Ctrl+End 转到文件尾
- Alt+F12 查看定义
- Shift+F12 查看引用
- Ctrl+K Ctrl+T 更改主题
- Ctrl+K Ctrl+S UI 界面修改快捷键
- Alt+Z 切换自动换行  
当然也可以修改自己的快捷键，就像 settings.json 的位置一样修改 keybindings.json 就可以了。不过我建议还是 Ctrl+K Ctrl+S 调出 UI 界面修改比较方便，所以这里就不放出 keybindings.json 的板子了。  
其实看似快捷键一堆，常用的也没多少，而且这些快捷键有许多也是编辑器的通用快捷键，所以上手很简单。
以上就是 VScode 的简要入门，看了这么多是不是感觉会的更少了……这就是标题从入门到更加入门的含义。