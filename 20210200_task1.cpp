#include <iostream>
#include <functional>
#include <cmath>
using namespace std;
class Function{
    virtual double evaluate_at(double value)=0;
};

class derivative:public Function{
public:
    derivative(function<double(double)>fun, double deltax){}
};

class simple_function:public Function{
private:
    function<double (double)> fun;
public:
    simple_function(function<double(double)>fun){this->fun=fun;}
    double evaluate_at(double value){
        return  fun(value);
    }
};

double cube(double x){
    return x*x*x;
}
class composit_function:public Function{
private:
    function<double(double)>f;
    function<double(double)>g;
public:
    composit_function(function<double(double)>f,
    function<double(double)>g){
        this->f=f;
        this ->g=g;
    }
    double evaluate_at(double value){
        return f(g(value));
    }
};

double square(double x){
    return x*x;
}

int main() {
    composit_function xyz(cube,square);
    cout<<xyz.evaluate_at(5);
}