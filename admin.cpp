// run this file to  convert {simple user} to an {admin user}
#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

using namespace std;

class person
{
public:
    bool isadmin = 0;
    char name[50];
    char password[50];
    int age;
    char gender[10];
};

int main()
{

    int recodPos = 0;
    person p;
    person temp;
    person login;
    bool found = false;
    vector<person> all;

    cout << "\n-------------------------------\n";
    cout << "THIS TOOL IS USE TO SET ADMIN\n ";
    cout << "ADVICE TO USE CAREFULLY!!!\n";
    cout << "-------------------------------\n\n";
    cout << "want to give(give)  or  want to remove(remove): " << "\n";

    char ADMIN[50];
    do
    {

        cout << "$: ";
        cin.getline(ADMIN, 50);

        bool skip = 1;
        if (strcmp(ADMIN, "give") == 0)
        {
            char srname[50];

            recodPos = 0;
            all.clear();
            found = false;

            cout << "name: ";
            cin.getline(srname, 50);
            skip = 1;
            ifstream in("data.bin", ios::binary);
            while (in.read((char *)&p, sizeof(p)))
            {
                if (strcmp(p.name, srname) == 0)
                {
                    skip = 0;
                    break;
                }
                recodPos++;
            }
            in.close();

            if (!skip)
            {
                ifstream store("data.bin", ios::binary);
                while (store.read((char *)&temp, sizeof(temp)))
                {
                    all.push_back(temp);
                }
                store.close();

                p.isadmin = 1;

                all[recodPos] = p;

                ofstream out("data.bin", ios::binary);
                for (person &P : all)
                {
                    out.write((char *)&P, sizeof(p));
                }
                out.close();

                cout << "admin given to " << p.name << "\n";
            }
            else
            {
                cout << "user not found\n";
            }
        }
        else if (strcmp(ADMIN, "remove") == 0)
        {
            char srname[50];

            recodPos = 0;
            all.clear();
            found = false;

            cout << "name: ";
            cin.getline(srname, 50);
            skip = 1;
            ifstream in("data.bin", ios::binary);
            while (in.read((char *)&p, sizeof(p)))
            {
                if (strcmp(p.name, srname) == 0)
                {
                    skip = 0;
                    break;
                }
                recodPos++;
            }
            in.close();

            if (!skip)
            {
                ifstream store("data.bin", ios::binary);
                while (store.read((char *)&temp, sizeof(temp)))
                {
                    all.push_back(temp);
                }
                store.close();

                p.isadmin = 0;

                all[recodPos] = p;

                ofstream out("data.bin", ios::binary);
                for (person &P : all)
                {
                    out.write((char *)&P, sizeof(p));
                }
                out.close();

                cout << "admin remove " << p.name << "\n";
            }
            else
            {
                cout << "user not found\n";
            }
        }
        else if (!skip)
        {
            cout << "not a valid entry" << "\n";
        }

    } while (strcmp(ADMIN, "exit") != 0);
}
