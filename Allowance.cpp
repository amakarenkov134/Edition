#include "Allowance.h"

void Allowance::input()
{
    cin.ignore();
    cout << "������� �������� ������������ ������������� �������: ";
    cin.getline(name, 90);
    cout << "������� ������� ������: ";
    cin.getline(autor, 90);
    cout << "������� ������ ��� ����������: ";
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
    cout << name << endl << "�����:" << autor << endl << "������ ��� ����������:" << link << endl << "��� �������:" << year << endl;
    cout << endl;
}

bool Allowance::operator>(Allowance d)
{
    if (strcmp(name, d.name) == 1) return true;
    return false;
}
