#include <iostream>
using namespace std;
namespace {
std::string version = "0.1.0";
}
int main(int argc, char const *argv[]) {
    // TODO: 使用string和map解决if else过多,或使用泛型和其他设计模式
    if (std::string(argv[1]) == "--version" || std::string(argv[1]) == "-v") {
        std::cout << ::version;
    }
    return 0;
}
