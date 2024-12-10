#include <iostream>

using namespace std;


template <class T>
class Stack
{
private:
    int top;
    int size;
    T *items;
    static int counter;
public:
    Stack(int size){
        this->size=size;
        top=-1;
        items=new T[size];
        counter++;
    }
    ///////////////////////////////////
    ~Stack(){
        delete[] items;
    }
    ///////////////////////////////////
    T push(T item){
        if(top==size-1)
        {
            return 0;
        }
        top++;
        items[top]=item;
        return 1;
    }
    ////////////////////////////////////
    T pop()
    {
        if(top==-1)
        {
            throw exception();
        }
        T data=items[top];
        top--;
        return data;
    }
    ////////////////////////////////////
    int display()
    {
        if(top==-1){
           return 0;
        }
        else
        {
            for(int i=0;i<=top;i++)
            {
                cout<<items[i]<<"\t";
            }
            cout<<endl;
            return 1;
        }
    }
    ////////////////////////////////////
    T* getEmployees(){
        return items;
    }
    ////////////////////////////////////
    int getTop(){
        return top;
    }
    ////////////////////////////////////
    static int getCounter(){
        return counter;
    }
};

template<class T>
int Stack<T>::counter=0;

///////////////////////////////////////////////////////////////////////////////////

int main()
{
    Stack<int> stack(5);
    cout<<(stack.push(5) ? "pushed successfully \n" : "push failed \n");
    cout<<(stack.push(6)?"pushed successfully \n":"push failed \n");
    cout<<(stack.push(7)?"pushed successfully \n":"push failed \n");
    cout<<(stack.push(8)?"pushed successfully \n":"push failed \n");
    cout<<(stack.push(9)?"pushed successfully \n":"push failed \n");
    stack.display();

    Stack<int> stackInt2(5);

    Stack<char> stack2(4);
    cout<<(stack2.push('A')?"pushed successfully \n":"push failed \n");
    cout<<(stack2.push('B')?"pushed successfully \n":"push failed \n");
    cout<<(stack2.push('C')?"pushed successfully \n":"push failed \n");
    cout<<(stack2.push('D')?"pushed successfully \n":"push failed \n");
    cout<<(stack2.push('f')?"pushed successfully \n":"push failed \n");
    stack2.display();

    cout<<Stack<int>::getCounter()<<" objects are created ,Int data type\n";
    cout<<Stack<char>::getCounter()<<" objects are created ,Char data type\n";

    return 0;
}
