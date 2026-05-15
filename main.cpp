// check for dulicate user acc with same name user with same name alrady exist

// will change scr account inside admin pravilage
// admin account are not done yet

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

class person
{
public:
    char name[50];
    char password[50];
    int age;
    char gender[10];

    private:
    double balance;
};

int main()
{
    char cmd[50];
    bool loginsucc = false;
    bool exit = false;
    do
    {

        char meow[50];
        cout << "login or signup: ";
        cin.getline(meow, 50);

        if (strcmp(meow, "login") == 0)
        {
            cout << "working on it " << '\n';

            person p;
            char find[50];
            char passowrdFind[50];
            bool found = false;

            cout << "name: ";
            cin.getline(find, 50);

            cout << "password: ";
            cin.getline(passowrdFind, 50);

            ifstream in("data.bin", ios::binary);
            while (in.read((char *)&p, sizeof(p)))
            {
                if ((strcmp(p.name, find) == 0) && (strcmp(p.password, passowrdFind) == 0))
                {
                    found = true;
                    loginsucc = true;
                    cout << "login as " << find << '\n';
                    cout << "WE WELCOME YOU" << '\n';
                    break;
                }

                else if (!(strcmp(p.name, find) == 0))
                {
                    cout << "invalid username" << '\n';
                }
                else if (!(strcmp(p.password, passowrdFind) == 0))
                {
                    cout << "invalid password" << '\n';
                }
            }
            in.close();
        }

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
                            // when found match
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

            // password slating and haching remaning

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
            cout << "==account created==" << '\n';
        }

        if (strcmp(meow, "exit") == 0)
        {

            exit = true;
            break;
        }

    } while (loginsucc == false);

    do
    {
        if (exit == true)
        {

            break;
        }

        cout << "cmd: ";
        cin.getline(cmd, 50);

        if (strcmp(cmd, "help") == 0)
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

        // if user is admin then
        if (0)
        {
            if (strcmp(cmd, "scr acc") == 0)
            {
                person p;
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
                        //balance will do something
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

    } while (strcmp(cmd, "exit") != 0);

    cout << "=========================" << '\n';
    cout << "meow meow sassion closed" << '\n';
    cout << "=========================" << '\n';
}