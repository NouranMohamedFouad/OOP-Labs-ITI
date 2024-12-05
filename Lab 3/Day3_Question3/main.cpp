#include <iostream>

using namespace std;

#define TERMINATOR '\0'

class String{
private:
    int size;
    char *ptr;
public:
    String(char *s)
    {
        size=intStringLength(s)+1;
        ptr=new char[size];
        for(int i=0;i<size-1;i++)
        {
            ptr[i]=s[i];
        }
        ptr[size-1]=TERMINATOR;
        //cout<<"\ncalling the constructor...\n";
    }
    ///////////////////////////////////
    String(const String& s)
    {
        //cout<<"\ncalling the copy constructor...\n";
        size=s.size;
        ptr=new char[size];
        for(int i=0;i<size;i++)
        {
            ptr[i]=s.ptr[i];
        }
    }
    ///////////////////////////////////
    ~String(){
        //cout<<"\ncalling the destructor...\n";
        if(ptr!=NULL){
            delete[] ptr;
        }

    }
    ////////////////////////////////////
    int display()
    {
        int i=0;
        while(ptr[i]!=TERMINATOR)
        {
            cout<<ptr[i];
            i++;
        }
        cout<<endl;
        return 1;

    }
    ////////////////////////////////////
    char* getString(){
        return ptr;
    }
    ////////////////////////////////////
    int getSize(){
        return size;
    }
    ////////////////////////////////////////
    int intStringLength(char* str)
    {
        int i=0;
        while(str[i] != TERMINATOR ){
            i++;
        }
        return i;
    }
    ///////////////////////////////////////////
    void intStringCat(String& source)
    {
        cout<<"\nbefore concatenation:"<<display()<<endl;

        int resSize=(this->size+source.size);
        char* temp=new char[resSize];
        int ptrSize1=intStringLength(this->ptr);
        int ptrSize2=source.intStringLength(source.ptr);

        int i=0;
        while(i<ptrSize1)
        {
            temp[i]=this->ptr[i];
            i++;
        }
        int j=0;
        while(j<ptrSize2){
            temp[i]=source.ptr[j];
            i++;
            j++;
        }
        temp[i]=TERMINATOR;
       // String res(temp);
        delete[] this->ptr;
        this->ptr = temp;
        this->size = resSize;
    }
    ///////////////////////////////////////////
    int intStringComp(String &source)
    {
        int i=0;
        int j=0;
        int flag=1;
        while(flag)
        {
            if(this->ptr[i] == TERMINATOR && source.ptr[j] != TERMINATOR)
            {
                j++;
                flag=0;

            }
            else if(this->ptr[i] != TERMINATOR && source.ptr[j] == TERMINATOR)
            {
                i++;
                flag=0;
            }
            else if(this->ptr[i] == TERMINATOR && source.ptr[j] == TERMINATOR)
            {
                flag=0;
            }
            else if(this->ptr[i]==source.ptr[j])
            {
                i++;
                j++;
            }
             else if(this->ptr[i]>source.ptr[j])
            {
                return 1;
            }
            else if(this->ptr[i]<source.ptr[j])
            {
                return -1;
            }


        }
        if(i==j){
            return 0;
        }
        else if(i>j)
        {
            return 1;
        }
        else if(i<j)
        {
            return -1;
        }
    }
    //////////////////////////////////////////
    void intStringCopy(String &source)
    {
        if(intStringLength(source.ptr)+1<= size)
        {
            int i=0;
            while(source.ptr[i]!= TERMINATOR)
            {
                this->ptr[i]=source.ptr[i];
                i++;
            }
            ptr[i]=TERMINATOR;
        }
        else
        {
            int sourceSize=intStringLength(source.ptr);
            delete[] this->ptr;
            this->ptr=new char[sourceSize];
            this->size=sourceSize;

            int i=0;
            while(source.ptr[i]!=TERMINATOR)
            {
                this->ptr[i]=source.ptr[i];
                i++;
            }
            this->ptr[i]=TERMINATOR;
        }
    }
    //////////////////////////////////////
    String operator+(String& s2)
    {
        cout<<"\n+ operator\n";
        int resSize=(this->size+s2.intStringLength(s2.ptr))+1;
        char* temp=new char[resSize];
        int ptrSize1=this->intStringLength(this->ptr);
        int ptrSize2=s2.intStringLength(s2.ptr);
        int i=0;
        while(i<ptrSize1)
        {
            temp[i]=this->ptr[i];
            i++;
        }
        temp[i]=' ';
        i++;
        for(int j=0;j<ptrSize2;j++,i++)
        {
            temp[i]=s2.ptr[j];
        }
        temp[i]=TERMINATOR;
        String res(temp);
        delete[] temp;
        return res;
    }
   /////////////////////////////////////
   String operator+=(String& c2)
    {
        cout<<"\n+= operator\n";

        this->intStringCat(c2);
        return *this;
    }
    ///////////////////////////////////
    int operator==(String& S2)
    {
        cout<<"\n== operator\n";

        if(intStringLength(this->ptr)==intStringLength(S2.ptr))
        {
            return 1;
        }
        return 0;
    }
    ////////////////////////////////////
    int operator<(String& S2){
        cout<<"\n< operator\n";

        if(intStringLength(this->ptr)< intStringLength(S2.ptr)){
            return 1;
        }
        return 0;
    }
    ////////////////////////////////////
    int operator>(String& S2){
        cout<<"\n> operator\n";

        if(intStringLength(this->ptr)>intStringLength(S2.ptr)){
            return 1;
        }
        return 0;
    }
    ////////////////////////////////////
    int operator>=(String& S2){
        cout<<"\n>= operator\n";

        if(intStringLength(this->ptr)>=intStringLength(S2.ptr)){
            return 1;
        }
        return 0;
    }
    ////////////////////////////////////
    int operator<=(String& S2){
        cout<<"\n<= operator\n";

        if(intStringLength(this->ptr)<=intStringLength(S2.ptr)){
            return 1;
        }
        return 0;
    }
    ////////////////////////////////////
    String operator=(String& old){
        this->intStringCopy(old);
        return *this;
    }
};

/////////////////////////////////////////////////////
int main()
{
    char *s="my name is nouran";
    char *s2="graduate";
    char *s3="test";


    String b(s);
    String b2(s2);
    String b3(s3);

    b3=b;
    cout<<"the result of b3=b2:\n";

    b3.display();
    String res=b+b2;
    cout<<"the result of b+b2:\n";
    res.display();

    b+=b2;
    b.display();
    if(b<=b2){
        cout<<"\nyess b2 is greater than or equal b\n";
    }else{
        cout<<"\nno b2 is not greater than or equal b\n";

    }
    if(b==b2){
        cout<<"\nyess b2 is equal b\n";
    }else{
        cout<<"\nno b2 is not equal b\n";

    }

    return 0;
}
