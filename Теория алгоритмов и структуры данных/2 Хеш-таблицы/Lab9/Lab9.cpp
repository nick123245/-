#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include "hashtable.h"

void show_student(student* p)
{
    cout << "���: " << p->get_fio() << endl;
    cout << "������: " << p->get_group() << endl;
    cout << "�������: " << p->get_rating() << endl;
}

int main()
{
    srand(time(0));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<string> surnames = { "������","������","�������","�����","����","��������","������","���","����","������","�����","�����" };
    vector<string> names = { "����","����","�����","������","����","�������","�����","������","�����","�����","��������","����","�������","������","�������" };
    vector<string> patronymics = { "��������","��������","���������","����������","��������","�����������","���������","����������","��������","���������","������������","��������","����������","����������","����������" };

    hashtable* table = nullptr;

    int oper;

    do
    {
        cout << "1.�������� ���-�������" << endl;
        cout << "2.���������� ���-�������" << endl;
        cout << "3.����� �� �����" << endl;
        cout << "4.����������� ���-�� ��������" << endl;
        cout << "5.�������� ���-�������" << endl;
        cout << "6.�������� �� �����" << endl;
        cout << "7.�������������� �� �����" << endl;
        cout << "0.�����" << endl;

        cin >> oper;
      

        switch (oper)
        {
        case 1:
        {
            int size;
            cout << "������ = ";
            cin >> size;
            table = new hashtable(size);
            break;
        }
        case 2:
        {
            int count;
            cout << "���-�� ��-��� = ";
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
            cout << "������� ���� ��� ������: ";
            getline(cin, fio);

            student* p = table->find(fio);
            if (p == nullptr)
                cout << "������� �� ������" << endl;
            else
            {
                show_student(p);
            } 
            break;
        }
        case 4:
        {
            int count = table->count_collision();
            cout << "���-�� �������� = " << count << endl;
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
            cout << "������� ���� ��� ��������: ";
            getline(cin, fio);

            bool res = table->remove(fio);
            if (res)
                cout << "�������� ������� ���������" << endl;
            else
                cout << "������� �� ������" << endl;
            break;
        }
        case 7:
        {
            string fio;
            cout << "������� ��� ��� ������: ";
            getline(cin, fio);

            student* p = table->find(fio);
            if (p == nullptr)
                cout << "������� �� ������" << endl;
            else
            {
                cout << "��� ��������? 1.������ 2.�������" << endl;
                int choose;
                cin >> choose;
               

                switch (choose)
                {
                    case 1:
                    {
                        int group;
                        cout << "������� ����� ������: ";
                        cin >> group;
                        
                        p->set_group(group);
                        break;
                    }
                    case 2:
                    {
                        double rating;
                        cout << "������� ����� �������: ";
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

