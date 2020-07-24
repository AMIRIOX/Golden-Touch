# 提供给Minecraft玩家的Golden-Touch
[English](README-en.md) | [简体中文](README.md)

这是在终端（cmd，powershell或bash）中模拟Minecraft命令的工具   

# 简单介绍
<details>
<summary>文件夹结构介绍</summary>
<ul>
<li> instructions : 主要的源文件目录,每个文件名为`{MC指令}.cpp,提供对应指令的模拟效果 </li>
<li> depend-tools : 一些依赖的小工具,如将图片转换为字符画 </li>
<li> static/entities_text_graph : 存放生物ASCII字符画, 用于console打印 </li>
<li> static/images : 存放生物图片, 用于生成字符画 </li>
</ul>
</details>

# 如何使用：
## prep works:
* 如果是Ubuntu/Debian等Linux发行版, 无需做任何额外工作   
* 如果是Windows/macOS需要安装git的对应平台版本, 请注意将git安装目录下的/usr/bin/添加环境变量,并安装clang或gcc编译器   
* 首先克隆仓库(使用`cnpmjs`镜像来加速):    
```bash
$ git clone https://github.com.cnpmjs.org/AMIRIOX/Golden-Touch.git gdtch
$ cd gdtch
```

## 编译和使用
当前不支持cmake编译或自动化脚本编译(已加入开发计划), 请手动编译.     
以summon.cpp为例: (您可以将`clang++`替换为`g++`)       
**如果您的操作系统是Windows,请在编译时使用-D WIN32或直接使用g++编译器**   
**同时,您还需要加入`-L. {您的ShLwApi.Lib所在位置}/x64/ShLwApi.Lib`**   
Linux/macOS:   
```
$ cd instructions
$ clang++ ./summon.cpp -o ../bin/summon -std=c++11
$ ../bin/summon wither 2
$ ../bin/summon wolf 1
```
Windows:   
```
> cd instructions
> g++ summon.cpp -o ../bin/summon.exe -std=c++11 -L. {您的ShLwApi.Lib所在位置}/x64/ShLwApi.Lib
> cd bin
> summon wither 2
> summon wolf 3
```
另外,您需要在Windows下注意的是, 一般{您的ShLwApi.Lib所在位置}都会有`Windows Kits`(包含空格),则您需要写成`Windows" "Kits`   

# 如何贡献
* fork本仓库, 修改代码, 提交`pull request`
## 您可以...
* 收集更多的 Minecraft 生物/物品图片, 要求:
    * 重命名为对应实体名,放在`static/images/`下, 然后使用(注意路径):
    ```bash
    $ cd ~/gdtch/depend-tools/
    $ java tograph ../static/images/{对应实体名}.png > ../static/entities_text_graph/{对应实体名}.txt
    ```
    * 图片格式为`50*50`的png格式图片
* 提一些issues, 以便我们更好的为您开发`golden-touch`
* 修改README-en.md的不通顺翻译,或增加更多语言版本的README.md