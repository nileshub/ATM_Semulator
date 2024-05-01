												      DSA PROJECT:
/******************************************************************************
                                        
Author:Nilesh G. Waghamre
Date:1May2024
 
*******************************************************************************/
//Q:THE CODE BELOW IMPLEMENTS THE ATM SEMULATOR
												
#include <bits/stdc++.h>
using namespace std;

std::vector<vector<string> > db;
void dosignin(){
    cout<<"WELCOME USER!"<<endl;
    string ph_num,email,pass;
    string bal="1500";
    cout<<"ENTER YOUR NAME: ";
    string name;
    getline(cin >> ws, name);
    cout<<"ENTER YOUR PH NUMBER: ";
    cin>>ph_num;
    cout<<"ENTER YOUR EMAIL: ";
    cin>>email;
    cout<<"ENTER NEW PASSWORD(CREATE PASSWORD): ";
    cin>>pass;
    db.push_back({name,ph_num,email,pass,bal});
    
}
void deposit(int acc){
    int amt=0;
    cout<<"ENTER AMOUNT TO DEPOSIT: ";
    cin>>amt;
    db[acc][4]=to_string(stoi(db[acc][4])+amt);
    cout<<"AMOUNT DEPOSITED TO YOUR ACCOUNT!!! "<<endl;
    cout<<"YOUR BALACE: RS "<<db[acc][4]<<" ONLY."<<endl;
}
void enquiry(int acc){
    cout<<"YOUR BALACE: RS "<<db[acc][4]<<" ONLY."<<endl;

}
void pay(int acc){
    int amt=0;
    cout<<"ENTER AMOUNT TO PAY: ";
    cin>>amt;
    db[acc][4]=to_string(stoi(db[acc][4])-amt);
    cout<<"PAYMENT HAS SUCCESSFULLY DONE FROM YOUR ACCOUNT!!! "<<endl;
    cout<<"YOUR BALACE: RS "<<db[acc][4]<<" ONLY."<<endl;

}
int dologin(int acc,string pass){
    
    if(acc>-1 && acc<db.size()){
        if(db[acc][3]==pass){
            return 1;
        }
        else{
            cout<<"INVALID CREDENTIALS.....PLEASE TRY AGAIN!!!!"<<endl<<endl;
            return -1;
        }
    }
    else{
            cout<<"INVALID CREDENTIALS.....PLEASE TRY AGAIN!!!!"<<endl<<endl;
            return -1;
        }
    return -1;
}

int main()
{
    
db.push_back({"Nilesh G. Waghmare","762001467","nileshgw245@gmail.com","Nilesh@123","1000"});

    int s;
    int i=1;
    while(s!=-1){
        
        cout<<"WELCOME TO THE CREDIT CARD SYSTEM!!!"<<endl;
        cout<<"TO SIGN IN ENTER 1"<<"   "<<"TO LOG IN IN ENTER 2"<<endl<<endl;
        cout<<"             "<<"TO EXIT ENTER -1"<<endl;
        cout<<endl;
        cin>>s;
        if(s==1){
            dosignin();
            cout<<"WELCOME TO THE FAMILY "<<db[i][0]<<" "<<"THANK YOU FOR JOINING! "<<endl<<endl;
            cout<<"YOUR ACCOUNT NUMBER IS: "<<i<<endl;
            i++;
            cout<<"PLEASE NOTE THIS ACCOUNT NUMBER FOR FUTURE TRANSACTIONS"<<endl;
            
        }
        else if(s==2){
            int acc=-1;
            string pass;
            cout<<"ENTER ACCOUNT NUMBER: ";
            cin>>acc;
            cout<<"ENTER PASSWORD: ";
            cin>>pass;
            if(dologin(acc,pass)==1){
                i++;
                cout<<"WELCOME "<<db[acc][0]<<"."<<endl;
                int s=-1;
                
                cout<<"TO DEPOSIT ENTER 1!"<<"  "<< "TO BALANCE ENQUIRY ENTER 2" <<" TO PAY FROM CREDIT-CARD ENETR 3 "<<"TO EXIT ENETR -1 "<<endl<<endl;
                cin>>s;
                if(s==1){
                    deposit(acc);
                }
                else if(s==2){
                    enquiry(acc);
                }
                else if(s==3){
                    pay(acc);
                }
                else{
                    break;
                }
            }
        }
        
        
        
    }
    return 0;
}