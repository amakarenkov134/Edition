#pragma once
#include <fstream>
class Edition
{
protected:
    char name[90];
    char autor[90];
    int year;

public:
    Edition();
    ~Edition();
    virtual void input() = 0;
    virtual void output() = 0;
    virtual void input_from_file(std::ifstream& fin) = 0;
    bool compare_name(char* snp);
    bool compare_fio(char* snp);
    bool sorting(Edition* e);
};

