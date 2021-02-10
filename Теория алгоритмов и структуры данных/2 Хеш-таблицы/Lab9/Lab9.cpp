#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include "hashtable.h"

void show_student(student* p)
{
    cout << "ФИО: " << p->get_fio() << endl;
    cout << "Группа: " << p->get_group() << endl;
    cout << "Рейтинг: " << p->get_rating() << endl;
}

int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<string> surnames = { "Иванов","Петров","Сидоров","Тесла","Маск","Эйнштейн","Ньютон","Гук","Кюри","Сталин","Ленин","Маркс" };
    vector<string> names = { "Иван","Петр","Сидор","Никола","Илон","Альберт","Исаак","Роберт","Мария","Иосиф","Владимир","Карл","Алексей","Михаил","Дмитрий" };
    vector<string> patronymics = { "Иванович","Петрович","Сидорович","Николаевич","Илонович","Альбертович","Исаакович","Робертович","Маркович","Иосифович","Владимирович","Карлович","Алексеевич","Михаилович","Дмитриевич" };

    hashtable* table = nullptr;

    int oper;

    do
    {
        cout << "1.Создание хэш-таблицы" << endl;
        cout << "2.Заполнение хэш-таблицы" << endl;
        cout << "3.Поиск по ключу" << endl;
        cout << "4.Определение кол-ва коллизий" << endl;
        cout << "5.Просмотр хэш-таблицы" << endl;
        cout << "6.Удаление по ключу" << endl;
        cout << "7.Редактирование по ключу" << endl;
        cout << "0.Выход" << endl;

        cin >> oper;
      

        switch (oper)
        {
        case 1:
        {
            int size;
            cout << "Размер = ";
            cin >> size;
            table = new hashtable(size);
            break;
        }
        case 2:
        {
            int count;
            cout << "Кол-во эл-тов = ";
            cin >> count;

            for (int i = 0; i < count; i++)
            {
                string fio = surnames[rand() % surnames.size()] + " " + names[rand() % names.size()] + " " + patronymics[rand() % patronymics.size()];
                int group = rand() % 100 + 1;
                double rating = (rand() % 100) /*/ 10.0*/;

                student* p = new student(fio, group, rating);
                table->add(fio, p);
            }
            break;
        }
        case 3:
        {
            string fio;
            cout << "Введите ключ для поиска: ";
            getline(cin, fio);

            student* p = table->find(fio);
            if (p == nullptr)
                cout << "Элемент не найден" << endl;
            else
            {
                show_student(p);
            } 
            break;
        }
        case 4:
        {
            int count = table->count_collision();
            cout << "Кол-во коллизий = " << count << endl;
            break;
        }
        case 5:
        {
            table->show();
            break;
        }
        case 6:
        {
            string fio;
            cout << "Введите ключ для удаления: ";
            getline(cin, fio);

            bool res = table->remove(fio);
            if (res)
                cout << "Удаление успешно завершено" << endl;
            else
                cout << "Элемент не найден" << endl;
            break;
        }
        case 7:
        {
            string fio;
            cout << "Введите ФИО для поиска: ";
            getline(cin, fio);

            student* p = table->find(fio);
            if (p == nullptr)
                cout << "Элемент не найден" << endl;
            else
            {
                cout << "Что поменять? 1.Группа 2.Рейтинг" << endl;
                int choose;
                cin >> choose;
               

                switch (choose)
                {
                    case 1:
                    {
                        int group;
                        cout << "Введите новую группу: ";
                        cin >> group;
                        
                        p->set_group(group);
                        break;
                    }
                    case 2:
                    {
                        double rating;
                        cout << "Введите новый рейтинг: ";
                        cin >> rating;
                        p->set_rating(rating);
                        break;
                    }
                }
            }
        }
        default:
            break;
        }
    } 
    while (oper != 0);
}

