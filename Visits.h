#pragma once
#include <string>
using namespace std;

class Visits {
    int entrytime;
    int exittime;
    string name;

public:

    Visits(int x, int y, string z) : entrytime(x), exittime(y), name(z) {}

    int getEntryTime();

    int getExitTime();

    string getName();

};