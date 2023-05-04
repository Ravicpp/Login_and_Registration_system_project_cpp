#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"\t\t\t____________________________________________________\n\n\n";
    cout<<"\t\t\t                   WELCOME TO THE LOGIN PAGE         \n\n\n";
    cout<<"\t\t\t___________________   MENU    ________________________\n\n\n";
    cout<<"                                                             \n\n";
    cout<<"\t| press 1 to LOGIN                          |"<<endl;
    cout<<"\t| press 2 to REGISTER                       |"<<endl;
    cout<<"\t| press 3 to IF YOU FORGOT YOUR PASSWORD    |"<<endl;
    cout<<"\t| press 4 to EXIT                           |"<<endl;
    cout<<"\n\t\t\tplease enter your choice :";
    cin>>c;
    cout<<endl;
     
    switch(c){
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
            cout<<"\t\t\t Thankyou! \n\n";
            break;

        default:
            system("cls");
            cout<<"\t\t\t please select from the option give above \n"<<endl;
            main();
    }
   return 0;
}

void login(){
    int count=1;
    string userId, password, id, pass;
    system("cls");
    cout<<"\t\t\t please enter the username and password :"<<endl;
    cout<<"\t\t\t USERNAME ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD ";
    cin>>password;

    ifstream input("records.txt");

    while(input>>id>>pass)
    {
        if(id==userId && pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<userId<<"\n Your Login is successful \n Thanks for logging in ! \n";
        main();
    }
     else{
         cout<<"\n LOGIN ERROR \n please check your username and password\n";
         main();
    }
}


void registration(){
    string ruserID,rpassword,rid,rpass;
    system("cls");
    cout<<"\t\t\t Enter the username :";
    cin>>ruserID;
    cout<<"\t\t\t Enter the password :";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    f1<<ruserID<<' '<<rpassword;
    system("cls");
    cout<<"\n\t\t\t Registration is successfull \n";
    main();
}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? No worries \n";
    cout<<"press 1 to search your id by username"<<endl;
    cout<<"press 2 to go back to the main menu"<<endl;
    cout<<"\t\t\t Enter your choice : ";
    cin>>option;
    switch(option){
        case 1:
        {
            int count=1;
            string suserId,sId,spass;
            cout<<"\n\t\t\tEnter the username which you remembered : ";
            cin>>suserId;

            ifstream f2("records.txt");
            while(f2>>sId>>spass){
                if(sId==suserId){
                    count=1;
                }
            }
            f2.close();
           if(count==1){
            cout<<"\n\n Your account is found \n";
            cout<<"\n\n Your password is :"<<spass;
            main();
           }
           else{
            cout<<"\n\t Sorry! your account is not found! \n";
           }
           break;
        }
        case 2:
        {
            main();
        }
        default:
        cout<<"\t\t\t Wrong choice ! please try again"<<endl;
        forgot();
    }
}



