/*
    Created by Sercan Değirmenci on 01.03.2015
*/

#include "lab1.h"

using namespace std;


int main(int argc, char **argv) {
    sercand::Lab1 lab;
    for (int i = 0; i < 16; ++i) {
        lab.output(i);
        lab.delayMs(500);
    }
    return 0;
}
