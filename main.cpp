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
        if (strcmp(what, "Книга") == 0) e[i] = new Book;
        else if (strcmp(what, "Статья") == 0) e[i] = new Article;
        else if (strcmp(what, "Пособие") == 0) e[i] = new Allowance;
        else { cout << "Некорректные данные в файле"; return 1; }
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
        cout << "1.Вывести список изданий \n2.Поиск всех изданий запрашиваемого автора\n3.Вывод полной информации о запрашиваемом издании\n4.Сортировка по названию издания\n0.Выход" << endl;
        cin >> p;
        switch (p)
        {
        case 1:
        {
            cout << "Список изданий:\n";
            for (int i = 0; i < n; i++)
            {
                e[i]->output();
            }
            break;
        }
        case 2:
        {
            char full_name[30];
            cout << "Введите фамилию человека: ";
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
            if (!f) cout << "Издания этого человека не найдены\n";
            break;
        }
        case 3:
        {
            char full_name[30];
            cout << "Введите название издания: ";
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
            if (!f) cout << "Издания не найдены\n";
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
            cout << "\nОтсортированный список изданий:\n\n";
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
            cout << "Выберите другой вариант!" << endl;
            break;
        }


    } while (!exit);

    return 0;
}
