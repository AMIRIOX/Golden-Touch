#include <direct.h>
#include <windows.h>

#include <iostream>
#include <map>
#include <sstream>
#include <string>

#include "highprec.hpp"
#define CHECK_NUM int
using std::stringstream;

namespace global {
std::map<std::string, CHECK_NUM> global_args;
std::string version_num;
}  // namespace global

void setConsoleColor(std::string color) {
#ifdef WIN32
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);

    if (color == "red")
        SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_INTENSITY);
    if (color == "blue")
        SetConsoleTextAttribute(hd, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    if (color == "yellow")
        SetConsoleTextAttribute(hd, FOREGROUND_RED | FOREGROUND_GREEN);
    if (color == "green")
        SetConsoleTextAttribute(hd, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
#endif  // WIN32
}
void backToDefautColor(void) {
    HANDLE hd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(
        hd, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void init_settings() {
    using namespace global;
    version_num = "0.1.0";
    global_args.insert(std::pair<std::string, CHECK_NUM>("--version", 0));
    global_args.insert(std::pair<std::string, CHECK_NUM>("--settings", 1));
    global_args.insert(std::pair<std::string, CHECK_NUM>("--add", 2));
}

inline int read() {
    int val = 0;
    int flg = 1;
    char ch = (char)getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') flg = 0;
        ch = (char)getchar();
    }
    while (ch >= '0' && ch <= '9') {
        val = (val << 1) + (val << 3) + (ch ^ 48);
        ch = (char)getchar();
    }
    return (flg ? val : ~(val - 1));
}  //快读

inline stringstream q_read() {
    std::stringstream s;
    char a = (char)getchar();
    while (a != ' ') {
        s << a;
        a = getchar();
    }
    return s;
}

void process_agrs(char const* a) {
    using global::global_args;
    using global::version_num;
    using std::endl;
    std::string ags(a);
    switch (global_args[ags]) {
        case 0: {
            setConsoleColor("green");
            std::cout << "Golden-Touch build version " << version_num << endl;
            backToDefautColor();
            break;
        }

        case 1: {
            setConsoleColor("red");
            std::cout << "fatal error: Custom settings are temporarily "
                         "unavailable. Install ";
            setConsoleColor("green");
            std::cout << "INSIDER";
            setConsoleColor("red");
            std::cout << " version golden touch to preview." << endl;
            backToDefautColor();
            break;
        }

        case 2: {
            // highint a; highint b;
            break;
        }

        default: {
            setConsoleColor("red");
            std::cout << "fatal error: unknow command args." << endl;
            backToDefautColor();
            break;
        }
    }
}
int main(int argc, char const* argv[]) {
    for (int i = 1; i < argc; i++) {
        process_agrs(argv[i]);
    }
    return 0;
}
