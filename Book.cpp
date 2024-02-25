#include "Book.h"

void Book::input()
{
    cin.ignore();
    cout << "������� �������� �����: ";
    cin.getline(name, 90);
    cout << "������� ������� ������: ";
    cin.getline(autor, 90);
    cout << "������� ��� �������: ";
    cin >> year;
    cout << "������� ���������� �������: ";
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
    cout << name << endl << "�����:" << autor << endl << "��� ������� �����:" << year << endl << "���������� �������:" << pages << endl;
    cout << endl;
}

bool Book::operator>(Book d)
{
    if (strcmp(name, d.name) == 1) return true;
    return false;
}
