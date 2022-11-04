#include <iostream>
#include"BigDecimalIntClass.h"
using namespace std;

class Bigreal:private BigDecimalInt
{
private:
    BigDecimalInt real;
    BigDecimalInt decm;
public:
    Bigreal(string user_input);
    BigReal ();
    ~Bigreal();
};

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
Bigreal::BigReal (){
    real.number="0";
    decm.number="0";
    return 0;
}
Bigreal::~Bigreal()
{
}

int main(){
    string User_input;
    cout<<"Add your number here : ";
    cin>>User_input;
    Bigreal b(User_input);
}