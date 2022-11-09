#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Client
{
private:
    string name;
    string Account_ID;
public:
    Client(string uname,string ID);
    void setClient();
    string getClient();
};

Client::Client(string uname, string ID)
{
    this->name=uname;
    this->Account_ID=ID;
}
void Client::setClient()
{
    string clientName;
    cout << "<<<Enter your name : \n>>>";
    cin >> clientName;
    this -> name = clientName;
}

string Client::getClient(){
    return this->name;
}

class BankAccount
{
private:
    string account_ID;
    double balance;
public:
    BankAccount();
    BankAccount(double money);
    void withdraw();
    void deposit();
    void setAcconut();
    double getAcconut();

};

BankAccount::BankAccount()
{
    this -> balance = 0;
}
void BankAccount::setAcconut()
{
    double yourBalance;
    cout << "<<<Enter yout balance : \n>>";
    cin >> yourBalance;
    this -> balance = yourBalance;
}
double BankAccount::getAcconut()
{
    return balance;
}
BankAccount::BankAccount(double money)
{
    this->balance=money;
}

void BankAccount::deposit(){
    double floos;
    cout<<"add The Ammount to be deposited";
    cin>>floos;
    balance+=floos;
    cout<<"your new balance is :"<<balance;
}

void BankAccount::withdraw(){
    double floos;
    cout<<"Enter amount to be withdrawn";
    cin>>floos;
    while (true)
    {
        if (floos>balance)
    {
        cout<<"You don't own such money \n your balance is:"<<balance;
    }else{
        balance=balance-floos;
        break;
    }
    }   
}

class savingsbankaccount:public BankAccount
{
private:
    double minimum_balance;
public:
    savingsbankaccount();
};

savingsbankaccount::savingsbankaccount()
{
    minimum_balance=1000;
}


class BankApp
{
private:
    vector<Client> clients;
public:
    BankApp(/* args */);
};

BankApp::BankApp(/* args */)
{
}

int main(){

Client c("A2BDEREKR", "fcai 909");
c.getClient();
// BankAccount U();
// U.setAcconut();


}