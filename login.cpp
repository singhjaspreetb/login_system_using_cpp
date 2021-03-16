#include <iostream>
#include <string>
#include <fstream>
using namespace std;
bool login()
{
    string usr,pwd,un,pw;

    cout<<"Enter Your Username : "; 
    cin>>usr;
    cout<<"Enter Your Password : "; 
    cin>>pwd;

    ifstream read("data\\"+usr+".txt");
    getline(read,un);
    getline(read,pw);

    if(usr==un && pwd==pw)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()	
{
    int choice;

    cout<<"Select the option............\n1 : Register\n2 : Login\n3 : Exit\nChoice : ";
    cin>>choice;

    if(choice==1)
    {
        string usr,pwd;

        cout<<"Enter Your Username : "; 
        cin>>usr;
        cout<<"Enter Your Password : "; 
        cin>>pwd;

        ofstream file;
        file.open("data\\"+usr+".txt");
        file<<usr<<endl<<pwd;
        file.close();

        main();
    }
    else if(choice==2)
    {
        bool check=login();
        if(check)
        {
            cout<<"You Loged In.........\n";
            system("PAUSE");
            return 0;
        }
        else
        {
            cout<<"Details Not Found..........\n";
            system("PAUSE");
            return 0;
        }
    }
    else
    {
        return 0;
    }
}