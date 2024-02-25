#include <iostream>
#include<fstream>
#include<ctime>
#include<Windows.h>
#include "Edition.h"
#include "Book.h"
#include "Allowance.h"
#include "Article.h"

using namespace std;


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    ifstream fin("Edition.txt");
    if (!fin) { cout << "File not found"; return 1; }
    const int n = 6;
    Edition* e[n];
    char what[30];

    for (int i = 0; i < n; i++)
    {
        fin.getline(what, 30);
        if (strcmp(what, "�����") == 0) e[i] = new Book;
        else if (strcmp(what, "������") == 0) e[i] = new Article;
        else if (strcmp(what, "�������") == 0) e[i] = new Allowance;
        else { cout << "������������ ������ � �����"; return 1; }
        e[i]->input_from_file(fin);
        fin.get();
    }



    int p;
    bool exit = false;
    bool exit1 = 1;
    do {
        cout << "____________________________________________________";
        cout << endl;
        cout << "\nMENU" << endl;
        cout << "____________________________________________________";
        cout << endl;
        cout << "1.������� ������ ������� \n2.����� ���� ������� �������������� ������\n3.����� ������ ���������� � ������������� �������\n4.���������� �� �������� �������\n0.�����" << endl;
        cin >> p;
        switch (p)
        {
        case 1:
        {
            cout << "������ �������:\n";
            for (int i = 0; i < n; i++)
            {
                e[i]->output();
            }
            break;
        }
        case 2:
        {
            char full_name[30];
            cout << "������� ������� ��������: ";
            cin.ignore();
            cin.getline(full_name, 90);
            bool f = false;
            for (int i = 0; i < n; i++)
            {
                if (e[i]->compare_fio(full_name))
                {
                    e[i]->output(); f = true;
                }
            }
            if (!f) cout << "������� ����� �������� �� �������\n";
            break;
        }
        case 3:
        {
            char full_name[30];
            cout << "������� �������� �������: ";
            cin.ignore();
            cin.getline(full_name, 90);
            bool f = false;
            for (int i = 0; i < n; i++)
            {
                if (e[i]->compare_name(full_name))
                {
                    e[i]->output(); f = true;
                }
            }
            if (!f) cout << "������� �� �������\n";
            break;
        }

        case 4:
        {
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - 1 - i; j++)
                {
                    if (e[j + 1]->sorting(e[j])) { Edition* temp = e[j + 1]; e[j + 1] = e[j]; e[j] = temp; }
                }
            }
            cout << "\n��������������� ������ �������:\n\n";
            for (int i = 0; i < n; i++)
            {
                e[i]->output();
                cout << endl;
            }
            break;
        }
        case 0:
        {
            exit = true;
            break;
        }
        default:
            cout << "�������� ������ �������!" << endl;
            break;
        }


    } while (!exit);

    return 0;
}
