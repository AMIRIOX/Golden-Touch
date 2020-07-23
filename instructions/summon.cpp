// // #include <direct.h>
// // #include <windows.h>

#include <iostream>
#include <map>
// // template <typename T>
// // bool process(T* entity, unsigned int num) {
// //     return entity->show(num);
// // }
std::string ent_graph[] = {
    {"cat ../static/entities_text_graph/wither.txt"},
    {"cat ../static/entities_text_graph/wolf.txt"}, 
    {"ccc"}
};
void init_entities(std::map<std::string, int>& ent) {
    ent.insert(std::pair<std::string, int>("wither",0));
    ent.insert(std::pair<std::string, int>("wolf",1));
}
int main(int argc, char* const argv[]) {
    // // entity ent(argv[1]);
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
