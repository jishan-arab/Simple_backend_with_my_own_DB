#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

struct person
{
    char name[50];
    int age;
    char gender[10];
    double balance;
};

int main()
{
    string cmd;

    do
    {
        cout << "cmd: ";
        getline(cin,cmd);
       

      

        if (cmd == "help")
        {

            cout << "\n";
            cout << "=============================================================" << '\n';
            cout << "newacc -> TO CREAT NEW ACCOUNT" << '\n';
            cout << "scr acc  -> TO PRINT  ACCOUNT detiles" << '\n';                  // working
            cout << "edit   -> TO edit account which was created by new acc" << '\n'; // not created have too
            cout << "exit   -> TO EXIT" << '\n';
            cout << "=============================================================" << '\n';
            cout << "\n";
        }

        // still wworking on it
        if (cmd == "new")
        {

            person p;
            p.balance = 0;

            cout << "name=  ";
            
            cin.getline(p.name, 50);
             
            while (1)
            {
                cout << "age= ";
                cin >> p.age;
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "invalid! numbers only, try again" << '\n';
                }
                else
                    break; 
            }

            cout << "gender= ";
            cin.ignore(1000,'\n');
            cin.getline(p.gender, 10);

            ofstream out("data.bin", ios::binary | ios::app);
            out.write((char *)&p, sizeof(p));
            out.close();

            out << "account created!" << '\n';
        }
        if (cmd == "scr acc")
        {
            person p;
            char search[50];
            bool found = false;

            cout << "enter name: ";
         
            cin.getline(search, 50);

            ifstream in("data.bin",ios::binary);
            while(in.read((char*)&p , sizeof(p))){
                 if(strcmp(p.name, search) == 0){
                     cout <<"=========================="<< '\n';
                    cout << "Name: "    << p.name << '\n';
                    cout << "age: "    << p.age << '\n';
                    cout << "Gender: "  << p.gender << '\n';
                    cout << "Balance: " << p.balance << '\n';
                    cout <<"=========================="<< '\n';
                    found = true;
                    break;
                 }
            }
            in.close();

            if (!found)
            {
                cout <<"=========================="<< '\n';
                cout<<"no record found"<<'\n';
                cout <<"=========================="<< '\n';
            }
            
        }

    } while (cmd != "exit");
}