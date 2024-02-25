#include "Book.h"

void Book::input()
{
    cin.ignore();
    cout << "Введите название книги: ";
    cin.getline(name, 90);
    cout << "Введите фамилию автора: ";
    cin.getline(autor, 90);
    cout << "Введите год издания: ";
    cin >> year;
    cout << "Введите количество страниц: ";
    cin >> pages;

}

void Book::input_from_file(ifstream& fin)
{
    fin.getline(name, 90);
    fin.getline(autor, 90);
    fin >> year;
    fin >> pages;
}

void Book::output()
{
    cout << name << endl << "Автор:" << autor << endl << "Год издания книги:" << year << endl << "Количество страниц:" << pages << endl;
    cout << endl;
}

bool Book::operator>(Book d)
{
    if (strcmp(name, d.name) == 1) return true;
    return false;
}
