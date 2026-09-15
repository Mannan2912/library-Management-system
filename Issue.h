#include "Books.h"
class issue
{
    public:
    int ID_student, ID_book;
    char date_issue[20],date_return[20];

    issue() {};
    issue(int ID_student,  int ID_book,  char date_issue[20], char date_return[20])
    {
        this->ID_student = ID_student;
        this->ID_book = ID_book;
        strcpy(this->date_issue,date_issue);
        strcpy(this->date_return,date_return);
    }
    void display()
    {
        cout << ID_student  << setw(15) << ID_book <<setw(17)<<date_issue<<setw(15)<<date_return<< endl;
        ;
    }
    void input()
    {
        cout << "Enter Book Id ";
        cin >> ID_book ;
        cout<<"Enter date of issue and return";
        cin>>date_issue>>date_return;
    }
    friend int searchissue(int searchID);
    friend void addissue();
    friend void updateissue();
    friend void delissue();
};
int check()
{
    ifstream fin("issue.dat", ios::binary);
    issue i;
    if (!fin.read((char *)&i, sizeof(i)))
    {
        return 0;
    }
    return 1;
}
void writeissue()
{
    int ID_student, ID_book;
    char date_issue[20],date_return[20];
    int j = 1;
    ofstream fout("issue.dat", ios::binary);
    while (j != 0)
    {
        cout << "Enter ID of the student";
        cin >> ID_student ;
        cout << "Enter Id  of the book";
        cin >> ID_book ;
        cout<<"Enter date of issue and reurn";
        cin>>date_issue>>date_return;
        issue i(ID_student, ID_book, date_issue,date_return);
        fout.write((char *)&i, sizeof(i));
        cout << "Do you want to continue(0/1): ";
        cin >> j;
    }
    fout.close();
}
void copyissue()
{
    ofstream fout("copy.dat", ios::binary);
    ifstream fin("issue.dat", ios::binary);
    issue i;
    while (fin.read((char *)&i, sizeof(i)))
    {
        fout.write((char *)&i, sizeof(i));
    }
    fout.close();
    fin.close();
}
void readissue()
{
    ifstream fin("issue.dat", ios::binary);
    issue i;
    int a=check();
    if (a==0)
    {
        cout<<"File is empty";
    }
    else
    {
        cout << "ID_student " << setw(10) << "ID_Book" <<setw(15)<<"date_issue"<<setw(15)<<"date_return"<< endl;
        while (fin.read((char *)&i, sizeof(i)))
        {
            i.display();
        }
    }
    fin.close();
}
int searchissue(int searchID)
{
    int a=check();
    if(a==0)
    {
        cout<<"File is empty";
        return 0;
    }
    else
    {
        ifstream fin("issue.dat", ios::binary);
        issue i;
        int x = 0;
        while (fin.read((char *)&i, sizeof(i)))
        {
            if (i.ID_student == searchID)
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
void addissue()
{
 


    issue i1;
    for (int l = 0; l < 3; l++)
    {
        cout << "Enter student ID to add: ";
        cin >> i1.ID_student;
        int j = searchissue(i1.ID_student);
        if (j == 0)
        {
            int a = search(i1.ID_student);
            if (a == 1)
            {
                cout<<"Enter Book ID";
                cin>>i1.ID_book;
                int b = searchBook(i1.ID_book);
                if (b == 1)
                {
                    cout<<"Issue date and return date";
                    cin>>i1.date_issue>>i1.date_return;
                    ofstream fout("copy.dat", ios::binary);
                    ifstream fin("issue.dat", ios::binary);
                    issue i;
                    while (fin.read((char *)&i, sizeof(i)))
                    {
                        fout.write((char *)&i, sizeof(i));
                    }
                    fout.write((char *)&i1, sizeof(i1));
                    fout.close();
                    fin.close();
                    remove("issue.dat");
                    rename("copy.dat", "issue.dat");
                    break;
                }
                else
                {
                    cout << "Invalid book" << endl;
                }
            }
            else
            {
                cout << "invalid student" << endl;
            }
        }
        else
        {
            cout << "Already exists" << endl;
        }
    }
}
void updateissue()
{
    int z=check();
    if(z==0)
    {
        cout<<"File is empty";
    }
    else
    {

        issue i1;
        issue i2;
        issue i3;
        int i;
        for (int l = 0; l < 3; l++)
        {
            cout << "Enter student  ID to update: ";
            cin >> i1.ID_student;
            i = searchissue(i1.ID_student);
            if (i == 0)
            {
                cout << "It does not exist" << endl;
            }
            else
            {
               cout<<"Enter new student ID";
               cin>>i3.ID_student;
               i=search(i3.ID_student);
               if(i==0)
               {
                  cout<<"Invalid student"<<endl;
               }
               else
               {
                    cout<<"Enter New Book ID";
                    cin>>i3.ID_book;
                    i=searchBook(i3.ID_book);
                    if(i==0)
                    {
                        cout<<"Invalid Book"<<endl;
                    }
                    else
                    {
                        ofstream fout("copy.dat",ios::binary);
                        ifstream fin("issue.dat",ios::binary);
                        while(fin.read((char*)&i2,sizeof(i2)))
                        {
                            if (i1.ID_student!=i2.ID_student)
                            {
                                fout.write((char*)&i2,sizeof(i2));
                            }
                            else
                            {
                                cout<<"New issue date and return date: ";
                                cin>>i3.date_issue>>i3.date_return;
                                fout.write((char*)&i3,sizeof(i3));
                            }
                        }
                        fin.close();
                        fout.close();
                        remove("issue.dat");
                        rename("copy.dat","issue.dat");
                        break;
                    }
               }
            }
        }
    }
}
void delissue()
{ 
    int z=check();
    if(z==0)
    {
        cout<<"File is empty";
    }
    else
    {

        issue i1;
        int i;
        for (int l = 0; l < 3; l++)
        {
            cout << "Enter ID of student to delete: ";
            cin >> i1.ID_student;
            i = searchissue(i1.ID_student);
            if (i == 0)
            {
                cout << "It does not exist" << endl;
            }
            else
            {
                ofstream fout("copy.dat", ios::binary);
                ifstream fin("issue.dat", ios::binary);
                issue i2;
                while (fin.read((char *)&i2, sizeof(i2)))
                {
                    if (i2.ID_student != i1.ID_student)
                    {
                        fout.write((char *)&i2, sizeof(i2));
                    }
                }
                fout.close();
                fin.close();
                remove("issue.dat");
                rename("copy.dat", "issue.dat");
                break;
            }
        }
    }
}
void menuissue()
{
    int j = 0, a, searchID;
    char i;
    do
    {

        cout << "1. Write a new issue file" << endl
         << "2. Read issue file" << endl
         << "3. Add a new issue " << endl
         << "4. Update a issue" << endl
         << "5. Delete a issue" << endl
         << "6. Search a issue" << endl
         << "Enter your choice: ";
        cin >> a;
        switch (a)
        {
        case 1:
            loading();
            clear();
            writeissue();
            break;
        case 2:
            loading();
            clear();
            readissue();
            break;
        case 3:
            loading();
            clear();
            addissue();
            break;
        case 4:
            loading();
            clear();
            updateissue();
            break;
        case 5:
            loading();
            clear();
            delissue();
            break;
        case 6:
            loading();
            clear();
            cout << "Enter ID of student  to search: ";
            cin >> searchID;
            j = searchissue(searchID);
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