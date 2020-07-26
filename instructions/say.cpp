#include <iostream>
int main(int argc, char const *argv[]) {
    // TODO: 对于@e等的支持, socket群组的say
    for(int i=1; i<argc; ++i) {
        std::cout << argv[i] << std::endl;
    }
    return 0;
}
