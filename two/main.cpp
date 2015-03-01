/*
    Created by Sercan Değirmenci on 01.03.2015
*/

#include "lab1.h"

using namespace std;


int main(int argc, char **argv) {
    sercand::Lab1 lab;

    if (argc > 1) {
        auto str = argv[1];

        int num = 0;
        for (int i = 0; i < 4; ++i) {
            if (str[i] == '1') {
                num += 1 << (3 - i);
            }
        }
        std::cout << str << " : " << num << std::endl;
        lab.output(num);
        lab.delayMs(1000);
    } else {
        for (int i = 0; i < 16; ++i) {
            lab.output(i);
            lab.delayMs(500);
        }
    }
    return 0;
}
