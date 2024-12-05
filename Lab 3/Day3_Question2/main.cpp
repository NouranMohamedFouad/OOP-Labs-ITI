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

        Complex operator+(Complex c2){
            cout<<"+ operator \n";

            Complex res;
            res.real=this->real+c2.real;
            res.img=this->img+c2.img;
            return res;
        }
        //////////////////////////////////
        Complex operator-(Complex c2){
            cout<<"- operator\n";

            Complex res;
            res.real=this->real-c2.real;
            res.img=this->img-c2.img;
            return res;
        }
        ///////////////////////////////////
        Complex operator+(int x){
            cout<<"+ operator for value\n";

            Complex res;
            res.real=this->real+x;
            res.img=this->img+x;
            return res;
        }
        //////////////////////////////////
         Complex operator-(int x){
            cout<<"- operator for value\n";

            Complex res;
            res.real=this->real-x;
            res.img=this->img-x;
            return res;
        }
        //////////////////////////////////
        int operator==(Complex c2){
            cout<<"== operator\n";

            if(this->real==c2.real && this->img==c2.img)
            {
                return 1;
            }
            return 0;
        }
        //////////////////////////////////
        Complex operator+=(Complex c2)
        {
            cout<<"+= operator\n";
            this->real=this->real+c2.real;
            this->img=this->img+c2.img;
            return *this;
        }
        //////////////////////////////////
        Complex operator=(Complex c)
        {
            cout<<"=operator\n";

            this->real=c.real;
            this->img=c.img;
            return *this;
        }
        //////////////////////////////////
        Complex operator=(int x)
        {
            cout<<"=operator for value\n";

            this->real=x;
            this->img=x;
            return *this;
        }
        //////////////////////////////////
        Complex operator++() //prefix
        {
            cout<<"++operator \n";

            this->real=this->real+1;
            this->img=this->img+1;
            return *this;
        }
        //////////////////////////////////
        Complex operator++(int x)
        {
            cout<<"++operator postfix\n";

            Complex c2=*this;
            this->real=this->real+1;
            this->img=this->img+1;
            return c2;
        }
        //////////////////////////////////
        Complex operator--() //prefix
        {
            cout<<"--operator \n";

            this->real=this->real-1;
            this->img=this->img-1;
            return *this;
        }
        //////////////////////////////////
        Complex operator--(int x) //postfix
        {
            cout<<"--operator postfix\n";

            Complex c2=*this;
            this->real=this->real-1;
            this->img=this->img-1;
            return c2;
        }
        ///////////////////////////////////
        operator float() const
        {
            return real;
        }
        ////////////////////////////////////
        friend Complex operator+(int x,Complex c2);
        ////////////////////////////////////
        friend Complex operator-(int x,Complex c2);
};
//////////////////////////////////////////////////////////////////////////////////
Complex operator+(int x,Complex c2){
    cout<<"value +operator \n";

    Complex res;
    res.real=c2.real + x;
    res.img=c2.img + x;
    return res;
}
//////////////////////////////////
 Complex operator-(int x,Complex c2){
    cout<<"value -operator \n";

    Complex res;
    res.real=x-c2.real;
    res.img=x-c2.img;
    return res;
}
/////////////////////////////////



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
    cout<<"complex fnumber is: ";
    comp.display();
    Complex com2;
    com2.setReal(real);
    com2.setImg(img);
    Complex com3;
    com3=--com2;
    com3.display();
    com3=com2--;
    com3.display();

    if(comp==com2)
    {
        cout<<"2 complex are same \n";
    }
    else
    {
        cout<<"2 complex are not same \n";
    }


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
