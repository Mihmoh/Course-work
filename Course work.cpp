#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#define MAX_SIZE 260
using namespace std;

class Book
{
private:
    string pathToFile;
public:

    Book()
    {
        pathToFile = "";
    }

    Book(string NAME)
    {
        pathToFile = NAME;
    }

    ~Book()
    {
        pathToFile.clear();
    }

    friend void menu();
};

void printMenu()
{
    cout << "1 - choose file of your book" << endl
        << "2 - start reading" << endl
        << "0 - exit" << endl;
}

int checkInt() {
    int value = 0;
    while (true) {
        if (cin >> value) {
            break;
        }
        else {
            cin.clear();
            cin.ignore();
            cout << "Enter right value ";
        }
    }
    return value;
}

void continuationCondition() //пауза продолжения
{
    char s;
    rewind(stdin);
    printf("\nPress enter to continue... \n");
    scanf_s("%c", &s);
}

void menu()
{
    Book book;
    int chooser = 1;
    printMenu();
    while (chooser != 0)
    {
        chooser = checkInt();
        switch (chooser)
        {
        case 1:
        {            
            system("cls");
            cout << "Enter path to file of your book" << endl;
            cin.ignore();
            getline(cin, book.pathToFile);
            printMenu();
            break;
        }
        case 2:
        {
            string line;
            ifstream in(book.pathToFile);
            if (in.is_open())
            {
                cout << "\nPress 1 to read line by line, 2 to show the whole text" << endl;
                chooser = checkInt();
                switch (chooser)
                {
                case 1:
                {
                    while (getline(in, line))
                    {

                        system("cls");
                        cout << line << endl;
                        cout << "\n1 - next line, 2 - stop reading" << endl;
                        chooser = checkInt();
                        if (chooser == 2)
                            break;
                    }
                    in.close();
                    system("cls");
                }
                case 2:
                {
                    while (getline(in, line))
                    {

                        cout << line << endl;
                    }
                    in.close();
                    continuationCondition();
                    system("cls");
                }
                }
            }
            else
            {
                system("cls");
                cout << "There is no such file" << endl;
            }           
            printMenu();
            break;
        }
        case 3:
        {
            system("cls");
            return;
        }
        }
    }
}

int main()
{
    menu();
}
