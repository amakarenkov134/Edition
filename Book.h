#pragma once
#include "Edition.h"
#include <iostream>

using namespace std;

class Book :
    public Edition
{
    int pages;

public:
    void input();
    void input_from_file(ifstream& fin);
    void output();
    bool operator >(Book d);
};

