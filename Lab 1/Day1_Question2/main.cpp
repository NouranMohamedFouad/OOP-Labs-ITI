#include <iostream>

using namespace std;

void swapByValue(int a,int b) {

    cout<<"before Swap By Value: x="<<a<<",y="<<b<<endl;

    int temp=a;
    a=b;
    b=temp;
    cout<<"after Swap By Value: x="<<a<<",y="<<b<<endl;
}
//////////////////////////////////////////
void swapByAddress(int *a,int *b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
//////////////////////////////////////////
void swapByReference(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
//////////////////////////////////////////



int main()
{
    int x=5,y=10;
    swapByValue(x,y);

    cout<<endl;

    int x2=5,y2=10;
    cout<<"before Swap By Address: x="<<x2<<",y="<<y2<<endl;
    swapByAddress(&x2, &y2);
    cout<<"before Swap By Address: x="<<x2<<",y="<<y2<<endl;

    cout<<endl;


    int x3=5,y3=10;
    cout<<"before Swap By Reference: x="<<x3<<",y="<<y3<<endl;
    swapByReference(x3,y3);
    cout<<"before Swap By Reference: x="<<x3<<",y="<<y3<<endl;

    cout<<endl;


    return 0;
}
