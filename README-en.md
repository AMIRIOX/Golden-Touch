# Golden-Touch for Minecraft players
[简体中文](README.md) | [English](README-en.md)

This is a tool to simulate Minecraft commands in the terminal (cmd, powershell or bash)
Disclaimer: Pictures and other materials come from [https://minecraft-zh.gamepedia.com](https://minecraft-zh.gamepedia.com), the copyright of these picture files belongs to [Mojang Studios](https://minecraft -zh.gamepedia.com/Mojang_Studios/), please contact to delete infringement.

# basic introduction
<details>
<summary>Introduction to folder structure</summary>
<ul>
<li> instructions: The main source file directory, each file is named `{MC instruction}.cpp, which provides the simulation effect of the corresponding instruction </li>
<li> depend-tools: Some dependent small tools, such as converting pictures into character paintings </li>
<li> static/entities_text_graph: store biological ASCII characters, used for console printing </li>
<li> static/images: store biological pictures, used to generate character paintings </li>
</ul>
</details>

# how to use:
## prep works:
* If it is a Linux distribution such as Ubuntu/Debian, no additional work is required  
* If you need to install the corresponding platform version of git for Windows/macOS, please pay attention to adding environment variables to /usr/bin/ in the git installation directory, and install the clang or gcc compiler   
* First clone the warehouse (use the `cnpmjs` image to speed up):  
```bash
$ git clone https://github.com.cnpmjs.org/AMIRIOX/Golden-Touch.git gdtch
$ cd gdtch
```

## Compile and use
> news: script compilation is already supported~ 

Note, if you are a Windows operating system, please:   
     * Enter the `instructions` directory and modify `cmpl.sh`        
     * Change `D:/Windows" "Kits/..../ShLwApi.Lib` after `-L.` in line 10 (the line with g++) to your `ShLwApi.Lib` directory    
     * Install git, please pay attention to whether your git supports running bash shell scripts   
Otherwise, you don't need to do any preparations.    
Open the bash terminal in the project root directory and enter    
```bash
$ ./instructions/cmpl.sh
$ ./bin/say hello-world I-love-golden-touch
$ ./bin/summon wither 3
```
<!--Currently, cmake compilation or free script compilation is not supported.   
Please compile manually.   
Take summon.cpp as an example: (you can replace `clang++` with `g++`)   
**If your operating system is Windows, please use -D WIN32 when compiling or use g++ compiler directly**   
**At the same time, you also need to add `-L. {Your ShLwApi.Lib location}/x64/ShLwApi.Lib`**   
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
> g++ summon.cpp -o ../bin/summon.exe -std=c++11 -L. {location of your ShLwApi.Lib}/x64/ShLwApi.Lib
> cd bin
> summon wither 2
> summon wolf 3
```
In addition, what you need to pay attention to under Windows is that generally {the location of your ShLwApi.Lib} will have `Windows Kits` (including spaces), then you need to write `Windows" "Kits`-->

# How to contribute
* Fork this warehouse, modify the code, and submit a pull request
## you can...
* To collect more Minecraft creature/item pictures, requirements:
    * Rename it to the corresponding entity name, put it under `static/images/`, and then use (note the path):
    ```bash
    $ cd ~/gdtch/depend-tools/
    $ java tograph ../static/images/{corresponding entity name}.png> ../static/entities_text_graph/{corresponding entity name}.txt
    ```
    * The picture format is `50*50` png format picture
* Mention some issues so that we can better develop `golden-touch` for you
* Modify the uncomfortable translation of README-en.md, or add more language versions of README.md

*translate by [Google Translate](https://translate.google.cn/)