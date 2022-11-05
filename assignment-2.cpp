#include <iostream>
#include"BigDecimalIntClass.h"
#include<algorithm>
#include<string>
using namespace std;

class Bigreal:public BigDecimalInt
{
public:
    BigDecimalInt real;
    BigDecimalInt decm;
    Bigreal(string user_input);
    Bigreal ();
    Bigreal (const Bigreal& other);
    Bigreal& operator= ( Bigreal& other);
    Bigreal (Bigreal&& other);
    Bigreal& operator=(Bigreal&& other);
    ~Bigreal();
};

Bigreal& Bigreal::operator=(Bigreal&& other){
    string *ptr1=&other.real.number;
    string *ptr2=&other.decm.number;
    this->real.number=other.real.number;
    this->decm.number=other.decm.number;
    ptr1=nullptr;
    ptr2=nullptr;
    return *this;
}

Bigreal::Bigreal(Bigreal&& other){
    string *ptr1=&other.real.number;
    string *ptr2=&other.decm.number;
    this->real.number=other.real.number;
    this->decm.number=other.decm.number;
    ptr1=nullptr;
    ptr2=nullptr;
}

Bigreal& Bigreal::operator=( Bigreal& other){
    this->real.number=other.real.number;
    this->decm.number=other.decm.number;
    return *this;
}

Bigreal::Bigreal (const Bigreal& other){
    this->real.number=other.real.number;
    this->decm.number=other.decm.number;
}

Bigreal::Bigreal(string user_input)
{
    int x=0;
    for (int i = 0; i < user_input.size(); i++)
    {
        if(user_input[i]=='.'){
            x=i;
        }
    }

    for (int i = 0; i < x; i++)
    {
        real.number+=user_input[i];
    }
    for (int i = x+1; i < user_input.size(); i++)
    {
        decm.number+=user_input[i];
    }   
}
Bigreal::Bigreal (){
    real.number="0";
    decm.number="0";
}
Bigreal::~Bigreal()
{
}

int main(){
    string User_input;
    cout<<"Add your number here : ";
    cin>>User_input;
    Bigreal b(User_input);
    Bigreal c("12222.333");
    c=b;
    cout<<c.real.number;

}