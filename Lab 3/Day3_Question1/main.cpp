#include <iostream>

using namespace std;


typedef struct Employee{
	string name;
	int code;
	int salary;
}Employee;


class Stack{
private:
    int top;
    int size;
    Employee *items;
    static int counter;

public:
    Stack(int size){
        cout<<"\ncreating the constructor...\n";
        this->size=size;
        top=-1;
        items=new Employee[size];
        counter++;
    }
    //////////////////////////////////
    Stack(Stack& s)
    {
        cout<<"\ncalling the copy constructor...\n";
        this->size=s.size;
        this->top=s.top;
        this->items=new Employee[size];
        for(int i=0;i<size;i++)
        {
            this->items[i]=s.items[i];
        }
    }

    ///////////////////////////////////
    ~Stack(){
        cout<<"\ncalling the destructor...\n";
        delete [] items;
    }
    ///////////////////////////////////
    int push(Employee emp){
        if(top==size-1)
        {
            return 0;
        }
        top++;
        items[top].code=emp.code;
        items[top].name=emp.name;
        items[top].salary=emp.salary;

        return 1;
    }
    ////////////////////////////////////
    Employee pop()
    {
        if(top==-1)
        {
            throw exception();
        }

        Employee data=items[top];
        top--;
        return data;
    }
    ////////////////////////////////////
    int display()
    {
        if(top==-1){
            cout<<"No data \n";
            return 0;
        }
        else
        {
            for(int i=0;i<top;i++)
            {
                cout<<"Employee number"<<i+1<<": \n";
                cout<<"code:"<<items[i].code<<"\t name:"<<items[i].name<<"\t salary:"<<items[i].salary<<endl;
            }
            return 1;
        }
    }
    ////////////////////////////////////
    Employee* getEmployees(){
        return items;
    }
    ////////////////////////////////////
    int getTop(){
        return top;
    }
    ////////////////////////////////////
    Stack operator=(Stack& s)
    {
        this->size=s.size;
        this->top=s.top;
        items=new Employee[size];
        for(int i=0;i<size;i++)
        {
            this->items[i]=s.items[i];
        }
        return *this;
    }
};

int Stack::counter=0;

void viewContentByReference(Stack & s){
    s.display();
}

void viewContentByValueWithoutCpyConstrutor(Stack s){
    s.display();
}

void viewContentByValueWithCpyConstrutor(Stack s){
    s.display();
}
//////////////////////////////////////////////////////

int main()
{
    Employee emp;
    emp.code=1;
    emp.name="nouran";
    emp.salary=10000;

    Stack s(5);

    viewContentByReference(s);
    //viewContentByValueWithoutCpyConstrutor(s);
    //viewContentByValueWithCpyConstrutor(s);
    Stack s2(5);
    s2=s;
    return 0;
}
