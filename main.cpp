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

    string getter() { return name; }
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
            // WORKING ON NEW AND PRINT
            cout << "new   TO CREAT NEW ACCOUNT";
            cout << "print   TO PRINT BALANCE OF ACCOUNT";
            cout << "exit   TO EXIT";
        }

        // still wworking on it
        if (cmd == "new")
        {
            string n;
            cout << "name: ";
            cin >> n;
            accounts.push_back(Person(n));

            ofstream file("data.txt"); 
            for (auto &p : accounts)
                file << p.getter() << "\n";
            file.close();
        }
        if (cmd == "print")
        {

            for (auto &p : accounts)
            {
                p.getter();
            }
        }

    } while (cmd != "exit");
}