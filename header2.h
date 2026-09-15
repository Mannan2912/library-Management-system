class student
{
public:
    int ID, Class;
    char name[20];
    int checkint(string x)
    {
        int a;
        while (1)
        {
            try
            {
                cout << "Enter " << x << ": ";
                cin >> a;
                if (cin.fail())
                {
                    throw "Enter a integer";
                }
                else
                {
                    throw a;
                }
            }
            catch (int e)
            {
                a = e;
                break;
            }
            catch (const char *e)
            {
                cout << e << endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }
        return a;
    }
    student() {};
    student(int ID, int Class, char name[20])
    {
        this->ID = ID;
        this->Class = Class;
        strcpy(this->name, name);
    }
    void display()
    {
        cout << ID << setw(10) << Class << setw(10) << name << endl;
    }
    void input()
    {
        Class = checkint("class");
        cout << "Enter name: ";
        cin >> name;
    }
};
void loading()
{
    cout << "Loading";
    flush(cout);
    for (int i = 0; i < 3; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "." << flush;
    }
    this_thread::sleep_for(chrono::milliseconds(500));
    cout << endl;
}
int checkstudent()
{
    ifstream fin("student2.dat", ios::binary);
    student s;
    if (!fin.read((char *)&s, sizeof(s)))
    {
        return 0;
    }
    return 1;
}
void write()
{
    int ID, Class;
    int i = 1;
    char name[20];
    ofstream fout("student2.dat", ios::binary);
    while (1)
    {
        student s1(ID, Class, name);
        s1.ID = s1.checkint("ID");
        s1.Class = s1.checkint("class");
        cout << "Enter name: ";
        cin >> s1.name;
        student s(ID, Class, name);
        s.ID=s1.ID;
        s.Class=s1.Class;
        strcpy(s.name, s1.name);
        fout.write((char *)&s, sizeof(s));
        cout << "Do you Want to continue(0/1): ";
        cin >> i;
        if (i == 0)
        {
            break;
        }
    }
    fout.close();
}
void copy()
{
    ofstream fout("copy2.dat", ios::binary);
    ifstream fin("student2.dat", ios::binary);
    student s;
    while (fin.read((char *)&s, sizeof(s)))
    {
        fout.write((char *)&s, sizeof(s));
    }
    fout.close();
    fin.close();
}
void read()
{
    int a = checkstudent();
    ifstream fin("student2.dat", ios::binary);
    student s;
    if (a == 0)
    {
        cout << "File is empty";
    }
    else
    {
        cout << "ID " << setw(10) << "class" << setw(10) << "name" << endl;
        while (fin.read((char *)&s, sizeof(s)))
        {
            s.display();
        }
    }
    fin.close();
}
int search(int searchID)
{
    int a = checkstudent();
    if (a == 0)
    {
        cout << "File is empty";
        return 0;
    }
    else
    {
        ifstream fin("student2.dat", ios::binary);
        student s;
        int x = 0;
        while (fin.read((char *)&s, sizeof(s)))
        {
            if (s.ID == searchID)
            {
                x = 1;
                break;
            }
        }
        fin.close();
        if (x == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
void add()
{
    student s1;
    int i;
    for (int l = 0; l < 3; l++)
    {
        cout << "Enter ID to add: ";
        cin >> s1.ID;
        i = search(s1.ID);
        if (i == 0)
        {
            ofstream fout("copy2.dat", ios::binary);
            ifstream fin("student2.dat", ios::binary);
            student s;
            while (fin.read((char *)&s, sizeof(s)))
            {
                fout.write((char *)&s, sizeof(s));
            }
            s1.input();
            fout.write((char *)&s1, sizeof(s1));
            fout.close();
            fin.close();
            remove("student2.dat");
            rename("copy2.dat", "student2.dat");
            break;
        }
        else
        {
            cout << "Already exists" << endl;
        }
    }
}
void update()
{
    int a = checkstudent();
    if (a == 0)
    {
        cout << "File is empty" << endl;
    }
    else
    {
        student s1;
        int i;
        for (int l = 0; l < 3; l++)
        {
            cout << "Enter ID to update: ";
            cin >> s1.ID;
            i = search(s1.ID);
            if (i == 0)
            {
                cout << "It does not exist" << endl;
            }
            else
            {
                ofstream fout("copy2.dat", ios::binary);
                ifstream fin("student2.dat", ios::binary);
                student s;
                while (fin.read((char *)&s, sizeof(s)))
                {
                    if (s.ID != s1.ID)
                    {
                        fout.write((char *)&s, sizeof(s));
                    }
                    else
                    {
                        cout << "Enter new ID,class,name: ";
                        s.ID = s.checkint("ID");
                        s.Class = s.checkint("class");
                        cout << "Enter name: ";
                        cin >> s.name;
                        fout.write((char *)&s, sizeof(s));
                    }
                }
                fout.close();
                fin.close();
                remove("student2.dat");
                rename("copy2.dat", "student2.dat");
                break;
            }
        }
    }
}
void del()
{
    int a = checkstudent();
    if (a == 0)
    {
        cout << "File is empty" << endl;
    }
    else
    {
        student s1;
        int i;
        for (int l = 0; l < 3; l++)
        {
            cout << "Enter ID to delete: ";
            cin >> s1.ID;
            i = search(s1.ID);
            if (i == 0)
            {
                cout << "It does not exist" << endl;
            }
            else
            {
                ofstream fout("copy2.dat", ios::binary);
                ifstream fin("student2.dat", ios::binary);
                student s;
                while (fin.read((char *)&s, sizeof(s)))
                {
                    if (s.ID != s1.ID)
                    {
                        fout.write((char *)&s, sizeof(s));
                    }
                }
                fout.close();
                fin.close();
                remove("student2.dat");
                rename("copy2.dat", "student2.dat");
                break;
            }
        }
    }
}
void clear()
{
#if defined(_WIN32) || defined(_WIN64)
    {
        system("cls");
    }
#else
    {
        system("clear");
    }
#endif
}
void menuStudent()
{
    int j = 0, a, searchID;
    char i;
    do
    {

        cout << "1. Write a new file" << endl;
        cout << "2. Read" << endl;
        cout << "3. Add" << endl;
        cout << "4. Update" << endl;
        cout << "5. Delete" << endl;
        cout << "6. Search" << endl;
        cout << "Enter your choice: ";
        cin >> a;
        switch (a)
        {
        case 1:
            loading();
            clear();
            write();
            break;
        case 2:
            loading();
            clear();
            read();
            break;
        case 3:
            loading();
            clear();
            add();
            break;
        case 4:
            loading();
            clear();
            update();
            break;
        case 5:
            loading();
            clear();
            del();
            break;
        case 6:
            loading();
            clear();
            cout << "Enter ID to search: ";
            cin >> searchID;
            j = search(searchID);
            if (j == 1)
                cout << "Found";
            else
                cout << "Not Found";
            break;
        default:
            cout << "Invalid choice";
            break;
        }
        cout << "\nDo you want to continue(y/n): ";
        cin >> i;
        if (i == 'n')
        {
            break;
        }
    } while (1);
}