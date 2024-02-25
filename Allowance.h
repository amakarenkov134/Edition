#pragma once
#include "Edition.h"
#include <iostream>

using namespace std;

class Allowance :
    public Edition
{
    char link[90];

public:
    void input();
    void input_from_file(ifstream& fin);
    void output();
    bool operator >(Allowance d);
};

