// // #include <direct.h>
// // #include <windows.h>
// // #include <boost/filesystem/path.hpp>
// // #include <boost/filesystem/operations.hpp>
//*--------  standard include   -------------
#include <iostream>
#include <map> 
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <locale>
#include <Shlwapi.h>
//*-------  standard include end ------------

//*------- global variables -----------------
enum os{
    WINDOWS,
    MACOS,
    LINUX,
    UNIX,
    IOS
};
os platform;
std::vector<std::string> ent_graph;
//*------- global variables end -------------

//*-------  Platform include  ---------------
#ifdef _WIN32
   #include <windows.h>
   #include <direct.h>
   #include <shlwapi.h>
   #include <Shlwapi.h> 
#elif __APPLE__
    #if TARGET_IPHONE_SIMULATOR
        #include <mach-o/dyld.h>
    #elif TARGET_OS_IPHONE
        #include <mach-o/dyld.h>
    #elif TARGET_OS_MAC
        #include <mach-o/dyld.h>
    #else
    #   error "Unknown Apple platform, not supported."
    #endif
#elif __ANDROID__
    # error "Android not supported."
#elif __linux__
    #include <unistd.h>
    #include <linux/limits.h>
#elif __unix__ // all unices not caught above
    // Unix
#endif
//*-------  Platform include end  ---------------

// // template <typename T>
// // bool process(T* entity, unsigned int num) {
// //     return entity->show(num);
// // }//    -
// // std::string getDir() {
// //     return boost::filesystem::initial_path<boost::filesystem::path>().string();
// // }
// TODO: support UNIX.
void init_env() {
#ifdef _WIN32
   platform = os::WINDOWS;
#elif __APPLE__
    #if TARGET_IPHONE_SIMULATOR
        platform = os::IOS;
    #elif TARGET_OS_IPHONE
        platform = os::IOS;
    #elif TARGET_OS_MAC
        platform = os::MACOS;
    #else
    #   error "Unknown Apple platform, not supported."
    #endif
#elif __ANDROID__
    # error "Android not supported."
#elif __linux__
    platform = os::LINUX;
#elif __unix__ // all unices not caught above
    platform = os::UNIX;
#endif
}
std::string getCurPath() {
    if(platform == os::WINDOWS) {
        // // CHAR c[MAX_PATH];
        // // DWORD result = GetCurrentDirectoryA(MAX_PATH, c);
        // get current executable file dir
        wchar_t szExePath[MAX_PATH] = {0};
        GetModuleFileNameW(NULL, szExePath, sizeof(szExePath));
        PathRemoveFileSpecW(szExePath);
        // convert to c_str
        size_t len = wcslen(szExePath) + 1;
        size_t converted = 0;
        char *CStr;
        CStr=(char*)malloc(len*sizeof(char));
        wcstombs(CStr,szExePath, len);
        /*
        char res[1024]; 
        memset(res,0,sizeof res);
        sprintf(res , "%s", szExePath );
        //remove /xxx/xxx/xxx/summon.exe
        std::string ret(res);
        std::cout << ret << std::endl << std::endl;
        std::string::size_type pos = ret.find("summon.exe");
        if(pos!=std::string::npos) ret.substr(0,pos);
        return ret;
        */
       return std::string(CStr);
    }else if(platform == os::MACOS) {
        char _path[512];
        unsigned size = 512;
        #ifdef __APPLE__
            #if TARGET_OS_MAC
            _NSGetExecutablePath(_path, &size);
            #endif // TARGET_OS_MAC
        #endif
        _path[size] = '\0';
        return std::string(_path);
    } else if(platform == os::LINUX) {
        #if __linux__
        char _path[512];
        int size = readlink("/proc/self/exe", path, 512);
        _path[size] = '\0';
        return std::string(_path);
        #endif
    }
    return "";
}
void init_entities(std::map<std::string, int>& ent) {
    ent.insert(std::pair<std::string, int>("wither",0));
    ent.insert(std::pair<std::string, int>("wolf",1));
    ent.insert(std::pair<std::string, int>("ender_dragon",2));
    std::string dir = getCurPath();
    std::string wolf = std::string("cat ") + dir + std::string("/../static/entities_text_graph/wolf.txt");
    std::string wither = std::string("cat ") + dir + std::string("/../static/entities_text_graph/wither.txt");
    std::string ender_dragon = std::string("cat ") + dir + std::string("/../static/entities_text_graph/ender_dragon.txt");
    ent_graph.push_back(wither);
    ent_graph.push_back(wolf);
    ent_graph.push_back(ender_dragon);
}
int main(int argc, char* const argv[]) {
    // // entity ent(argv[1]);
    // // std::cout << argv[0] << std::endl;
    // // std::cout << getDir() << std::endl;
    // // //std::cout << getCurPath() << std::endl;
    //std::cout << "ok";
    //std::string dir = getCurPath();
    //std::cout << dir << std::endl;
    std::cout << getCurPath() << std::endl;
    std::map<std::string, int> entities;
    init_entities(entities);
    if(argc>2) std::cout << argv[2] << " ";
    std::cout << argv[1] << " has summoned." << std::endl << std::endl;
    // // std::cout << ent_graph[entities[argv[1]]] << std::endl;
    system(ent_graph[entities[argv[1]]].c_str());
    return 0;
}

// // void setConsoleColor(std::string color) {
// // #ifdef WIN32
// //     HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
// //     if (color == "red")
// //         SetConsoleTextAttribute(hd, FOREGROUND_RED |
// FOREGROUND_INTENSITY);
// //     if (color == "blue")
// //         SetConsoleTextAttribute(hd, FOREGROUND_BLUE |
// FOREGROUND_INTENSITY);
// //     if (color == "yellow")
// //         SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN);
// // #endif  // WIN32
// // }

// // void backToDefautColor(void) {
// // #ifdef WIN32
// //     HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
// //     SetConsoleTextAttribute(
// //         hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
// // #endif  // WIN32
// // }
