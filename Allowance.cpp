#include "Allowance.h"

void Allowance::input()
{
    cin.ignore();
    cout << "Введите название электронного методического пособия: ";
    cin.getline(name, 90);
    cout << "Введите фамилию автора: ";
    cin.getline(autor, 90);
    cout << "Введите ссылку для скачивания: ";
    cin.getline(link, 90);
}

void Allowance::input_from_file(ifstream& fin)
{
    fin.getline(name, 90);
    fin.getline(autor, 90);
    fin.getline(link, 90);
    fin >> year;
}

void Allowance::output()
{
    cout << name << endl << "Автор:" << autor << endl << "Ссылка для скачивания:" << link << endl << "Год издания:" << year << endl;
    cout << endl;
}

bool Allowance::operator>(Allowance d)
{
    if (strcmp(name, d.name) == 1) return true;
    return false;
}
