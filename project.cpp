#include <iostream>
#include <fstream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <thread>
#include <chrono>
using namespace std;
#include "Issue.h"
int verification()
{
    string user, pass, user1, pass1;
    ifstream fin("pass.txt");
    fin >> user;
    fin >> pass;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter username: ";
        cin >> user1;
        cout << "Enter password: ";
        cin >> pass1;
        if (user1 == user && pass1 == pass)
        {
            return 1;
        }
        else
        {
            cout << "Invalid username or password" << endl;
        }
    }
    return 0;
}
int main()
{
    int j = 0;
    int i = verification();
    loading();
    if (i == 1)
    {
        while (j != 4)
        {
            clear();
            cout << "1->Student" << endl
                 << "2->Book" << endl
                 << "3->issue" << endl
                 << "4->exit" << endl;
            cin >> j;
            if (j == 1)
            {
                loading();
                clear();
                menuStudent();
            }
            if (j == 2)
            {
                loading();
                clear();
                menuBook();
            }
            if (j == 3)
            {
                loading();
                clear();
                menuissue();
            }
        }
    }
    return 0;
}