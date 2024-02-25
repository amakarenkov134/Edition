#include "Article.h"

void Article::input()
{
    cin.ignore();
    cout << "Введите название статьи: ";
    cin.getline(name, 90);
    cout << "Введите фамилию автора: ";
    cin.getline(autor, 90);
    cout << "Введите название журнала: ";
    cin.getline(magazineName, 90);
    cout << "Введите номер выпуска: ";
    cin >> number;
    cout << "Введите год издания: ";
    cin >> year;
    cout << "Введите номер страницы, с которой начинается статья: ";
    cin >> first_page;
    cout << "Введите номер страницы, где заканчивается статья: ";
    cin >> last_page;
}

void Article::input_from_file(ifstream& fin)
{
    fin.getline(name, 90);
    fin.getline(autor, 90);
    fin.getline(magazineName, 90);
    fin >> number;
    fin >> year;
    fin >> first_page;
    fin >> last_page;

}

void Article::output()
{
    cout << name << endl << "Название журнала:" << magazineName << endl << "Номер выпуска:" << number << endl << "Автор:" << autor << endl << "Год издания журнала:" << year << endl << "Номер страницы, где начинается статья:" << first_page << endl << "Номер страницы, где статья заканчивается:" << last_page << endl;
    cout << endl;
    cout << endl;
}

bool Article::operator>(Article d)
{
    if (strcmp(name, d.name) == 1) return true;
    return false;
}
