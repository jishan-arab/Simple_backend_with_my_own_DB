
//remaining
//name:meow meow |age:12|gender:m|isAdmin:0  have to remove any white space after name 156

//.txt file for simple human readable record unsensitive info;
//andupdate.txt after change in .bin file;
//what can admin; 

#include <iostream>
#include <string>
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
    person login;
    person p;

    char $[50];
    bool loginsucc = false;
    bool anyupdate = 0, exit = false;
    do
    {

        // login or signup {43-204};
        char meow[50];
        cout << "login or signup: ";
        cin.getline(meow, 50);

        // login {48-96};
        if (strcmp(meow, "login") == 0)
        {

            person p;
            char find[50];
            char passowrdFind[50];
            bool found = false;
            bool nameFound = false;

            cout << "name: ";
            cin.getline(find, 50);

            cout << "password: ";
            cin.getline(passowrdFind, 50);

            recodPos = 0;

            ifstream in("data.bin", ios::binary);
            while (in.read((char *)&p, sizeof(p)))
            {
                if (strcmp(p.name, find) == 0)
                {
                    nameFound = true;
                    if (strcmp(p.password, passowrdFind) == 0)
                    {
                        login = p;
                        found = true;
                        loginsucc = true;
                        cout << "\n----------------\n";
                        cout << "LOGIN AS " << find << "\n";
                        cout << "WE WELCOME YOU\n";
                        cout << "----------------\n";
                        break;
                    }
                }
                if (!found)
                    recodPos++;
            }
            in.close();

            if (!found)
            {
                recodPos = 0;
                if (!nameFound)
                    cout << "invalid username\n";
                else
                    cout << "invalid password\n";
            }
        }

        // signup {99-197};
        else if (strcmp(meow, "signup") == 0)
        {

            cout << "==creating new account==" << '\n';
            person p;

            // name
            bool valid = 0;
            char find[50];
            do
            {
                cout << "name: ";

                cin.getline(find, 50);

                // if all white space

                for (int i = 0; find[i] != '\0'; i++)
                {
                    if (find[i] != ' ')
                    {
                        valid = 1;
                        break;
                    }
                }

                if (!valid)
                {
                    cout << "enter a valid field" << '\n';
                }

                else
                {
                    // check DB for dulplicate
                    bool forerror = false;
                    ifstream in("data.bin", ios::binary);
                    while (in.read((char *)&p, sizeof(p)))
                    {
                        if (strcmp(p.name, find) == 0)
                        {

                            valid = false;
                            forerror = true;
                        }
                    }
                    in.close();
                    if (forerror)
                    {
                        cout << "username taken" << '\n';
                    }
                }

            } while (!valid);
            strncpy(p.name, find, 50);

            // password
            cout << "passwword: ";
            cin.getline(p.password, 50);

           

            // age
            do
            {
                cout << "age: ";
                char temp[10];
                cin.getline(temp, 10);
                p.age = atoi(temp);
                if (p.age <= 0)
                    cout << "numbers only! try again\n";
                else
                    break;
            } while (1);

            // gender
            do
            {
                cout << "gender(m or f)= ";

                cin.getline(p.gender, 10);

                if (strcmp(p.gender, "m") == 0 || strcmp(p.gender, "f") == 0)
                {
                    break;
                }
                cout << "invalid! enter m or f only\n";

            } while (1);

            // write in file;
            ofstream out("data.bin", ios::binary | ios::app);
            out.write((char *)&p, sizeof(p));
            out.close();

            ofstream outt("data.txt", ios::app);
            outt << "\nname:" << p.name << "|" << "age:" << p.age << "|" << "gender:" << p.gender << '|'<<"isAdmin:"<<login.isadmin;

            outt.close();

            cout
                << "==account created==" << '\n';
        }

        if (strcmp(meow, "exit") == 0)
        {

            exit = true;
            break;
        }

    } while (loginsucc == false);

    // main home loop {206-353};
    do
    {
        if (login.isadmin)
        {
            do
            {
                cout << "-------------" << "\n";
                cout << "ADMIN ACCOUNT" << "\n";
                cout << "-------------" << "\n";

            } while (0);

            if (strcmp($, "scr acc") == 0)
            {

                char search[50];
                bool found = false;

                cout << "enter name: ";

                cin.getline(search, 50);

                ifstream in("data.bin", ios::binary);
                while (in.read((char *)&p, sizeof(p)))
                {
                    if (strcmp(p.name, search) == 0)
                    {
                        cout << "==========================" << '\n';
                        cout << "Name: " << p.name << '\n';
                        cout << "age: " << p.age << '\n';
                        cout << "Gender: " << p.gender << '\n';
                        // balance will do something
                        cout << "==========================" << '\n';
                        found = true;
                        break;
                    }
                }
                in.close();

                if (!found)
                {
                    cout << "==========================" << '\n';
                    cout << "no record found" << '\n';
                    cout << "==========================" << '\n';
                }
            }
        }

        if (exit == true)
        {

            break;
        }

        cout << "$: ";
        cin.getline($, 50);

        if (strcmp($, "help") == 0)
        {

            cout << "\n";
            cout << "=============================================================" << '\n';
            cout << "newacc -> TO CREAT NEW ACCOUNT" << '\n';                         // changer to using signup
            cout << "scr acc  -> TO PRINT  ACCOUNT detiles" << '\n';                  // working
            cout << "edit   -> TO edit account which was created by new acc" << '\n'; // not created have too
            cout << "exit   -> TO EXIT" << '\n';
            cout << "=============================================================" << '\n';
            cout << "\n";
        }

        // EDIT

        if (strcmp($, "edit") == 0)
        {
            char tempEdit[20];
            char newName[50];
            cout << "\n";
            cout << "================================" << "\n";
            cout << "what you want to edit" << '\n'
                 << "\n";
            cout << "name " << '\n';
            cout << "gender " << '\n'
                 << "\n";
            cout << "edit: ";
            cin.getline(tempEdit, 20);

            // search

            if (strcmp(tempEdit, "name") == 0)
            {
                bool valid = 1;
                do
                {

                    valid = 0;
                    cout << "new name: ";
                    cin.getline(newName, 50);

                    for (int i = 0; newName[i] != '\0'; i++)
                    {
                        if (newName[i] != ' ')
                        {
                            valid = 1;
                            break;
                        }
                    }
                    if (valid==0)
                    {
                        cout <<" not a valid input";
                    }

                    if (valid)
                    {
                        ifstream in("data.bin", ios::binary);
                        while (in.read((char *)&p, sizeof(p)))
                        {
                            if (strcmp(p.name, newName) == 0)
                            {
                                valid = 0;
                                break;
                            }
                        }in.close();
                    }

                    
                    if (valid == 0)
                    {
                        cout << "name taken pussy take diffrint name" << "\n";
                    }

                } while (valid == 0);

                if (valid)
                {
                    strcpy(login.name, newName);
                    cout << "\n"
                         << "name update to " << login.name << "\n";

                    anyupdate = 1;
                }
            }

            cout << "============================";
        }

        if (anyupdate)
        {
            vector<person> all;
            person temp;

            ifstream update("data.bin", ios::binary);
            while (update.read((char *)&temp, sizeof(temp)))
            {
                all.push_back(temp);
            }
            update.close();

            all[recodPos] = login;

            ofstream out("data.bin", ios::binary);
            for (person &P : all)
            {
                out.write((char *)&P, sizeof(p));
            }
            out.close();
            anyupdate = 0;
            cout << '\n'
                 << "=========";
            cout << "updated";
            cout << "=========" << "\n"
                 << "\n";
        }

    } while (strcmp($, "exit") != 0);

    cout << "=========================" << '\n';
    cout << "meow meow sassion closed" << '\n';
    cout << "=========================" << '\n';
}