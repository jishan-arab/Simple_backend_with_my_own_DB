#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Person
{
public:
    Person(string n) : name(n), balance(0) {}

    string name;
    int balance;

    void getter() { cout << name << "\n"; }
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
            //WORKING ON NEW AND PRINT
            cout << "new   TO CREAT NEW ACCOUNT";
            cout << "print   TO PRINT BALANCE OF ACCOUNT";
            cout << "exit   TO EXIT";
            
        }


        // still wworking on it
        // if (cmd == "new")
        // {
        //     string n;
        //     cout << "name: ";
        //     cin >> n;
        //     accounts.push_back(Person(n));
        // }

        // if (cmd == "print")
        // {
        //     for (auto &p : accounts)
        //         p.getter();
        // }

    } while (cmd != "exit");
}