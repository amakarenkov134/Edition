#include "Article.h"

void Article::input()
{
    cin.ignore();
    cout << "������� �������� ������: ";
    cin.getline(name, 90);
    cout << "������� ������� ������: ";
    cin.getline(autor, 90);
    cout << "������� �������� �������: ";
    cin.getline(magazineName, 90);
    cout << "������� ����� �������: ";
    cin >> number;
    cout << "������� ��� �������: ";
    cin >> year;
    cout << "������� ����� ��������, � ������� ���������� ������: ";
    cin >> first_page;
    cout << "������� ����� ��������, ��� ������������� ������: ";
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
    cout << name << endl << "�������� �������:" << magazineName << endl << "����� �������:" << number << endl << "�����:" << autor << endl << "��� ������� �������:" << year << endl << "����� ��������, ��� ���������� ������:" << first_page << endl << "����� ��������, ��� ������ �������������:" << last_page << endl;
    cout << endl;
    cout << endl;
}

bool Article::operator>(Article d)
{
    if (strcmp(name, d.name) == 1) return true;
    return false;
}
