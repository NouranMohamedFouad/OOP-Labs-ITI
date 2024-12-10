#include <iostream>

using namespace std;

template<class T>
class List{
private:
    int top;
    int current;
    int size;
    T *items;

public:
    List()
    {
        this->size=1;
        items=new T[size];
        top=0;
        current=-1;
    }
    ///////////////////////////////////
    ~List(){
        delete[] items;
    }
    ///////////////////////////////////
    void push(T item){
        if(current==size-1)
        {
            size++;
            T* newList=new T[size];

            for(int i=0;i<=current;i++) {
                newList[i]=items[i];
            }
            current++;
            newList[current]=item;
            delete[] items;
            items=newList;
        }
        else{
            current++;
            items[current]=item;
        }
    }
    ////////////////////////////////////
    T pop()
    {
        if(current==-1)
        {
            throw -1;
        }
        size--;
        T* newList=new T[size];

        for(int i=0;i<current;i++) {
            newList[i]=items[i];
        }
        int data=items[current];
        current--;
        delete[] items;
        items=newList;
        return data;
    }
    ////////////////////////////////////
    int display()
    {
        if(current==-1){
           return 0;
        }
        else
        {
            for(int i=0;i<size;i++)
            {
                cout<<items[i]<<" ";
            }
            cout<<endl;
            return 1;
        }
    }
    ////////////////////////////////////
    T* getItems(){
        return items;
    }
    ////////////////////////////////////
    int getTop(){
        return top;
    }
    ///////////////////////////////////
    int getCurrent(){
        return current;
    }
};



int main()
{
    try
    {
        List<int> list;
        list.push(5);
        list.display();
        list.push(6);
        list.display();
        list.push(7);
        list.display();
        list.push(8);
        list.display();
        list.push(9);
        list.display();
        list.push(10);
        list.display();
        list.push(11);
        list.display();
        list.pop();
        list.display();
        list.pop();
        list.display();
        list.pop();
        list.display();
        list.pop();
        list.display();
        list.pop();
        list.pop();
        list.display();
        cout<<endl;



        List<char> list2;
        list2.push('A');
        list2.display();
        list2.push('B');
        list2.display();
        list2.push('C');
        list2.display();
        list2.push('D');
        list2.display();
        list2.push('E');
        list2.display();
        list2.push('F');
        list2.display();
        list2.push('G');
        list2.display();
        list2.pop();
        list2.display();
        list2.pop();
        list2.display();
        list2.pop();
        list2.display();
        list2.pop();
        list2.display();
        list2.pop();
        list2.pop();
        list2.display();
        list2.pop();
        list2.display();
        list2.pop();
        list2.display();
    }
    catch(int msg)
    {
        cout<<"the list is already empty"<<endl;
    }
    return 0;
}
