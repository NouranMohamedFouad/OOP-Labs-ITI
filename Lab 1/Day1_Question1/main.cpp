#include <iostream>

using namespace std;

class Complex{
        int real;
        int img;
    public:
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
        Complex add(Complex c)
        {

            Complex Res;
            Res.real=real+c.real;
            Res.img=img+c.img;
            return Res;
        }
        /////////////////////////
        Complex subtract(Complex c)
        {
            Complex Res;
            Res.real=real-c.real;
            Res.img=img-c.img;
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
    Complex comp;
    int real,img;

    cout<<"Enter the real number: ";
    cin>>real;
    comp.setReal(real);
    cout<<"Enter the imaginary number: ";
    cin>>img;
    comp.setImg(img);
    cout<<"complex number is: ";
    comp.display();

    int choice;
    cout<<"press 1 for ADD, 2 for Subtract : ";
    cin>>choice;

    if (choice==1)
    {
        Complex comp2;
        cout<<"Enter the real number for the other complex: ";
        cin>>real;
        comp2.setReal(real);
        cout<<"Enter the imaginary number for the other complex: ";
        cin>>img;
        comp2.setImg(img);

        Complex result=comp.add(comp2);
        cout<<"result is: ";
        result.display();
    }
    else if(choice==2)
    {
        Complex comp2;
        cout<<"Enter the real number for the other complex: ";
        cin>>real;
        comp2.setReal(real);
        cout<<"Enter the imaginary number for the other complex: ";
        cin>>img;
        comp2.setImg(img);

        Complex result=comp.subtract(comp2);
        cout<<"result is: ";
        result.display();
    }
    else
    {
        cout<<"Invalid choice!"<<endl;
    }

    return 0;
}
