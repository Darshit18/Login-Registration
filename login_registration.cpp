#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void menu()
{
    cout<<"\tPress 1 to Login"<<endl;
    cout<<"\tPress 2 to Registration"<<endl;
    cout<<"\tPress 3 to Forgot Password"<<endl;
    cout<<"\tPress 4 to Exit"<<endl;
}

void login();
void registration();
void forgot();



int main()
{
    int choice;
    menu();
    cout<<"\tEnter a choice from above: ";
    cin>>choice;
    cout<<endl;
    switch (choice)
    {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout<<"\tThank you!"<<endl;
    default:
        cout<<"\tPlease select from the option given : ";
        menu();

    }
}

void login()
{
    int c=0;
    string u_id,password,id,pass;

    cout<<"\tPlease Enter username and password: "<<endl;
    cout<<"\tUSERNAME: ";
    cin>>u_id;
    cout<<"\tPASSWORD: ";
    cin>>password;

    ifstream input("records.txt");
    while(input>>id>>pass)
    {
        if(id==u_id && pass==password)
        {
            c=1;
        }
    }
    input.close();
    if(c==1)
    {
        cout<<u_id<<"\n Your login is succesfull: "<<endl;
        main();
    }
    else
    {
        cout<<"\n Please check your login! "<<endl;
        main();
    }
}

void registration()
{
    string r_userid,r_password,r_id,r_pass;
    cout<<"\tEnter the username: ";
    cin>>r_userid;
    cout<<"\tEnter the password: ";
    cin>>r_password;

    ofstream f1("records.txt", ios::app);
    f1<<r_userid<<" "<<r_password<<endl;
    cout<<"Registration is succesfull!"<<endl;
    main();
}
void forgot()
{
    int option;
    cout<<"\t Forgot the password!"<<endl;
    cout<<"\tPress 1 to search your id by username "<<endl;
    cout<<"\tPress 2 to go back to menu: "<<endl;
    cin>>option;
    switch (option)
    {
    case 1:
        {
            int c=0;
            string s_id,id,pass;
            cout<<"\tEnter the username: ";
            cin>>s_id;

            ifstream f2("records.txt");
            while(f2>>id>>pass)
            {
                if(id==s_id)
                {
                    c=1;
                }
            }
            f2.close();
            if(c==1)
            {
                cout<<"\tYour account is found!"<<endl;
                cout<<"\tYour password is: "<<pass;
                main();
            }
            else
            {
                cout<<"Sorry your account is not found!"<<endl;
            }
        }
        break;
    case 2:
        {
            main();
        }
    default:
        cout<<"\tWrong choice! Please try again"<<endl;
        forgot();

    }
}
