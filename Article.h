#pragma once
#include "Edition.h"
#include <iostream>

using namespace std;

class Article :
    public Edition
{
    char magazineName[90];
    int number;
    int first_page;
    int last_page;

public:
    void input();
    void input_from_file(ifstream& fin);
    void output();
    bool operator >(Article d);
};

