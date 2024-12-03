#include <iostream>

using namespace std;


class Complex{
private:
        int real;
        int img;
public:
    Complex()
    {
        real=0;
        img=0;
    }
    Complex(int r,int i)
    {
        real=r;
        img=i;
    }
    /////////////////////////
    ~Complex()
    {
        cout<<"the destructor of the complex \n";
    }
    /////////////////////////
    void setReal(int r)
    {
        real=r;
    }
    /////////////////////////
    void setImg(int i)
    {
        img=i;
    }
    /////////////////////////
    int getReal()
    {
        return real;
    }
    /////////////////////////
    int getImg()
    {
        return img;
    }
    /////////////////////////
    Complex setComplex(int real,int img)
    {
        this->real=real;
        this->img=img;
    }
    /////////////////////////
    Complex add(Complex c)
    {
        Complex Res(real+c.real,img+c.img);
        //Res.real=real+c.real;
        //Res.img=img+c.img;
        return Res;
    }
    /////////////////////////
    Complex subtract(Complex c)
    {
        Complex Res(real-c.real,img-c.img);
        //Res.real=real-c.real;
        //Res.img=img-c.img;
        return Res;
    }
    /////////////////////////
    void display()
    {
        if(real==0 && img==0) {
            cout<<"No data"<<endl;
        }
        if(real!=0)
        {
            cout<<real;
        }
        if(img!=0)
        {
            if(img>0 && real!=0)
            {
              cout<<"+";
            }
            cout<<img<<"j"<<endl;
        }
        cout<<endl;
    }
};

//////////////////////////////////////////////////////////////////////////////////

int main()
{

    int real,img;
    cout<<"Enter the real number: ";
    cin>>real;
    cout<<"Enter the imaginary number: ";
    cin>>img;
    Complex comp(real,img);
    cout<<"complex number is: ";
    comp.display();


    int choice;
    cout<<"press 1 to ADD, 2 to Subtract, 3 to set complex : ";
    cin>>choice;

    if (choice==1)
    {

        cout<<"Enter the real number for the other complex: ";
        cin>>real;
        cout<<"Enter the imaginary number for the other complex: ";
        cin>>img;
        Complex comp2(real,img);

        Complex result=comp.add(comp2);
        cout<<"result is: ";
        result.display();
    }
    else if(choice==2)
    {
        cout<<"Enter the real number for the other complex: ";
        cin>>real;
        cout<<"Enter the imaginary number for the other complex: ";
        cin>>img;
        Complex comp2(real,img);

        Complex result=comp.subtract(comp2);
        cout<<"result is: ";
        result.display();
    }
    else if(choice==3)
    {
        cout<<"Enter the real number: ";
        cin>>real;
        cout<<"Enter the imaginary number: ";
        cin>>img;
        comp.setComplex(real,img);
        cout<<"complex number is: ";
        comp.display();
    }
    else
    {
        cout<<"Invalid choice!"<<endl;
    }
    return 0;
}
