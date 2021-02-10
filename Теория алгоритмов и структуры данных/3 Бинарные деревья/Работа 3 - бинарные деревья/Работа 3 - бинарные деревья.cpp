#include <iostream>
#include "BinaryTree.h"

int main()
{
    setlocale(LC_ALL, "rus");
    int choice;

    BinaryTree* ideal_tree = nullptr;
    BinaryTree* find_tree = nullptr;

    do
    {
        cout << "1.Создать идеально сбалансированной дерево" << endl;
        cout << "2.Вывести идеально сбалансированное дерево" << endl;
        cout << "3.Сформировать дерево поиска" << endl;
        cout << "4.Вывести дерево поиска" << endl;
        cout << "5.Поиск элемента" << endl;
        cout << "0.Выход" << endl;

        cin >> choice;

        if (choice == 1)
        {
            int count;
            cout << "Введите кол-во эл-тов: ";
            cin >> count;

            ideal_tree = new BinaryTree();
            ideal_tree->FormIdealTree(count);
        }
        else if (choice == 2)
        {
            if (ideal_tree != nullptr)
                ideal_tree->Show();
            else
                cout << "Создайте идеально сбалансированной дерево" << endl;
        }
        else if (choice == 3)
        {
            if (ideal_tree != nullptr)
            {
                find_tree = new BinaryTree();
                find_tree->FormTreeFind(*ideal_tree);
            }
            else
                cout << "Создайте идеально сбалансированной дерево" << endl;
        }
        else if (choice == 4)
        {
            if (find_tree != nullptr)
                find_tree->Show();
            else
                cout << "Сформируйте дерево поиска" << endl;
        }
        else if (choice == 5)
        {
            if (find_tree != nullptr)
            {
                cout << "Введите искомый элемент: ";
                char key;
                cin >> key;

                int count = find_tree->Search(key);
                if (count == 0)
                    cout << "Нет таких эл-тов" << endl;
                else
                    cout << "Кол-во = " << count << endl;
            }
            else
                cout << "Сформируйте дерево поиска" << endl;
        }
    } 
    while (choice != 0);
}