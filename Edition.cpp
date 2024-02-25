#include "Edition.h"
#include <iostream>

Edition::Edition()
{
	std::cout << "Констуктор класса Edition" << std::endl;
}

Edition::~Edition()
{
	std::cout << "Деструктор класс Edition" << std::endl;
}

bool Edition::compare_name(char* snp)
{
	if (strcmp(name, snp) == 0) return true;
	return false;
}

bool Edition::compare_fio(char* snp)
{
	if (strcmp(autor, snp) == 0) return true;
	return false;
}

bool Edition::sorting(Edition* e)
{
	if (strcmp(name, e->name) == -1) return 1;
	else return 0;
}
