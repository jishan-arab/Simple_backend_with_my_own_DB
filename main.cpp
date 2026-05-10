#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Person
{
public:
    Person(string n, string g) : balance(0), name(n), gender(g) {}

    string name;
    string gender;
    int balance;
};

int main()
{
    string cmd;
    vector<Person> accounts;

    do
    {
        cout << "cmd: ";
        cin >> cmd;

        if (cmd == "help")
        {

            cout<<"\n"<<"============================================================="<<endl;
            cout << "newacc -> TO CREAT NEW ACCOUNT"<<endl;                            //  going to use getline funtion incomplet
            cout << "print  -> TO PRINT BALANCE OF ACCOUNT"<<endl;                     // working
            cout << "edit   -> TO edit account which will be created by new acc"<<endl; // not created have too
            cout << "exit   -> TO EXIT"<<endl;
            cout<<"============================================================="<<endl;
            cout<<"\n";
        }

        // still wworking on it
        if (cmd == "new")
        {
            string n, g;
            cout << "name: ";
            cin >> n;
            cout << "mail(m) or femail(f): ";
            cin >> g;

            accounts.push_back(Person(n, g));

            ofstream out("data.txt", ios::app);
            out << "name = " << n << "\n" << "gender = " << g << '\n';
        }
        if (cmd == "print")
        {
        }

    } while (cmd != "exit");
}