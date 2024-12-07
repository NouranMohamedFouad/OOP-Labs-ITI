#include <iostream>

using namespace std;



class Base{
protected:
    int a;
    int b;
public:
    Base()
    {
        cout<<"non parametrized Base Constructor"<<endl;
        a=0;
        b=0;
    }
    Base(int a,int b)
    {
        cout<<"parametrized Base Constructor"<<endl;

        this->a=a;
        this->b=b;
    }
    ~Base()
    {
        cout<<"Base Destructor"<<endl;
    }
    void setA(int a){
        this->a=a;
    }
    void setB(int b){
        this->b=b;
    }
    int getA()
    {
        return a;
    }
    int getB()
    {
        return b;
    }
    int sum(){
        return a+b;
    }
    void display1(){
        cout<<"a="<<a<<"\t b="<<b<<endl;
        cout<<"sum="<<sum()<<endl;
    }
};
//////////////////////////////////////////////////////

class Derived : public Base
{
protected:
    int c;
public:
    Derived():Base()
    {
        cout<<"non parametrized Derived Constructor"<<endl;

        c=0;
    }
    Derived(int a,int b,int c):Base(a,b)
    {
        cout<<"parametrized Derievd Constructor"<<endl;

        this->c=c;
    }
    ~Derived()
    {
        cout<<"Derived Destructor"<<endl;
    }
    void setC(int c){
        this->c=c;
    }
    int getC()
    {
        return c;
    }
    int sum(){
        return Base::sum()+c;
    }
    void display2(){
        cout<<"a="<<a<<"\t b="<<b<<"\t c="<<c<<endl;
        cout<<"sum="<<sum()<<endl;

    }

};

/////////////////////////////////////////////////////////

class SecondDerived : public Derived
{
protected:
    int d;
public:
    SecondDerived():Derived()
    {
        cout<<"non parametrized SecondDerived Constructor"<<endl;

        d=0;
    }
    SecondDerived(int a,int b,int c,int d):Derived(a,b,c)
    {
        cout<<"parametrized SecondDerived Constructor"<<endl;
        this->d=d;
    }
    ~SecondDerived()
    {
        cout<<"SecondDerived Destructor"<<endl;
    }
    void setD(int d){
        this->d=d;
    }
    int getD()
    {
        return d;
    }
    int sum(){
        return Derived::sum()+d;
    }
    void display3(){
        cout<<"a="<<a<<"\t b="<<b<<"\t c="<<c<<"\t d="<<d<<endl;
        cout<<"sum="<<sum()<<endl;
    }
};
/////////////////////////////////////////////////////////////////////
void displayBase(Base b)
{
        cout<<"sum="<<b.sum()<<endl;
}

void displayDerived(Derived d)
{
        cout<<"sum="<<d.sum()<<endl;
}
/////////////////////////////////////////////////////////////////////


int main()
{
    //SecondDerived secD(1,2,3,4);
    //secD.display3();

    //SecondDerived secD;
    //secD.display3();

    Derived d(1,2,3);
    //d.display2();

    //Derived d;
    //d.display2();

    //Base b(1,2);
    //b.display1();

    //displayBase(d); //prints the Base sum
    displayDerived(d);



    return 0;
}
