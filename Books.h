#include "header2.h"
class Book
{
    public:
    int ID;
    char name[20];

    Book() {};
    Book(int ID, char name[20])
    {
        this->ID = ID;
        strcpy(this->name, name);
    }
    void display()
    {
        cout << ID << setw(10) << name << endl;
    }
    void input()
    {
        cout << "Enter  name";
        cin >> name;
    }
};
int checkbook()
{
    ifstream fin("Book.dat", ios::binary);
    Book b;
    if (!fin.read((char *)&b, sizeof(b)))
    {
        return 0;  
    }
    return 1;
}
void writeBook()
{
    ofstream fout("Book.dat", ios::binary);
    int ID, i;
    char name[20];
    while (1)
    {
        cout << "Enter ID and name of the book";
        cin >> ID >> name;
        Book b1(ID, name);
        fout.write((char *)&b1, sizeof(b1));
        cout << "Do you want to continue(1/0)";
        cin >> i;
        if (i == 0)
        {
            break;
        }
    }
    fout.close();
}
void copyBook()
{
    ofstream fout("copy.dat", ios::binary);
    ifstream fin("Book.dat", ios::binary);
    Book b;
    while (fin.read((char *)&b, sizeof(b)))
    {
        fout.write((char *)&b, sizeof(b));
    }
    fout.close();
    fin.close();
}
void readBook()
{
    int a=checkbook();
    if(a==0)
    {
        cout<<"File is empty"<<endl;
    }
    else
    {
        ifstream fin("Book.dat", ios::binary);
        Book b;
        if (!fin.read((char *)&b, sizeof(b)))
        {
            cout<<"File is empty"<<endl;
        }
        else
        {
            cout << "ID " << setw(10) << "name"<<endl ;
            while (fin.read((char *)&b, sizeof(b)))
            {
                b.display();
            }
        }
        fin.close();
    }
}
int searchBook(int searchID)
{
    int a=checkbook();
    if(a==0)
    {
        cout<<"File is empty"<<endl;
        return 0;
    }
    else
    {
        ifstream fin("Book.dat", ios::binary);
        Book b;
        int x = 0;
        while (fin.read((char *)&b, sizeof(b)))
        {
            if (b.ID == searchID)
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
void addBook()
{
    Book b1;
    int i;
    for (int l = 0; l < 3; l++)
    {
        cout << "Enter ID to add: ";
        cin >> b1.ID;
        i = searchBook(b1.ID);
        if (i == 0)
        {
            ofstream fout("copy.dat", ios::binary);
            ifstream fin("Book.dat", ios::binary);
            Book b;
            while (fin.read((char *)&b, sizeof(b)))
            {
                fout.write((char *)&b, sizeof(b));
            }
            b1.input();
            fout.write((char *)&b1, sizeof(b1));
            fout.close();
            fin.close();
            remove("Book.dat");
            rename("copy.dat", "Book.dat");
            break;
        }
        else
        {
            cout << "Already exists" << endl;
        }
    }
}
void updateBook()
{
    int z=checkbook();
    if(z==0)
    {
        cout<<"File is empty"<<endl;
    }
    else
    {
        Book b1;
        int i;
        for (int l = 0; l < 3; l++)
        {
            cout << "Enter ID to update: ";
            cin >> b1.ID;
            i = searchBook(b1.ID);
            if (i == 0)
            {
                cout << "It does not exist" << endl;
            }
            else
            {
                ofstream fout("copy.dat", ios::binary);
                ifstream fin("Book.dat", ios::binary);
                Book b;
                while (fin.read((char *)&b, sizeof(b)))
                {
                    if (b.ID != b1.ID)
                    {
                        fout.write((char *)&b, sizeof(b));
                    }
                    else
                    {
                        cout << "Enter new ID,name: ";
                        cin >> b.ID >> b.name;
                        fout.write((char *)&b, sizeof(b));
                    }
                }
                fout.close();
                fin.close();
                remove("Book.dat");
                rename("copy.dat", "Book.dat");
                break;
            }
        }
    }
}
void delBook()
{
    int z=checkbook();
    if(z==0)
    {
        cout<<"File is empty"<<endl;
    }
    else
    {
        Book b1;
        int i;
        for (int l = 0; l < 3; l++)
        {
            cout << "Enter ID to delete: ";
            cin >> b1.ID;
            i = searchBook(b1.ID);
            if (i == 0)
            {
                cout << "It does not exist" << endl;
            }
            else
            {
                ofstream fout("copy.dat", ios::binary);
                ifstream fin("Book.dat", ios::binary);
                Book b;
                while (fin.read((char *)&b, sizeof(b)))
                {
                    if (b.ID != b1.ID)
                    {
                        fout.write((char *)&b, sizeof(b));
                    }
                }
                fout.close();
                fin.close();
                remove("Book.dat");
                rename("copy.dat", "Book.dat");
                break;
            }
        }
    }
}
void menuBook()
{
    int j = 0, a, searchID;
    char i;
    do
    {

        cout << "1. Write a new book file" << endl;
        cout << "2. Read the book file" << endl;
        cout << "3. Add a book" << endl;
        cout << "4. Update a book" << endl;
        cout << "5. Delete a book" << endl;
        cout << "6. Search a book" << endl;
        cout << "Enter your choice: ";
        cin >> a;
        switch (a)
        {
        case 1:
            loading();
            clear();
            writeBook();
            break;
        case 2:
            loading();  
            clear();
            readBook();
            break;
        case 3:
            loading();
            clear();
            addBook();
            break;
        case 4:
            loading();
            clear();
            updateBook();
            break;
        case 5: 
            loading();
            clear();
            delBook();
            break;
        case 6:
            loading();
            clear();
            cout << "Enter ID to search: ";
            cin >> searchID;
            j = searchBook(searchID);
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