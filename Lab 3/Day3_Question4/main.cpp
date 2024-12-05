#include <iostream>

using namespace std;

class List{
private:
    int top;
    int current;
    int size;
    int *items;

public:
    List()
    {
        this->size=1;
        items=new int[size];
        top=0;
        current=-1;
    }
    ///////////////////////////////////
    ~List(){
        delete[] items;
    }
    ///////////////////////////////////
    void push(int item){
        if(current==size-1)
        {
            size++;
            int* newList=new int[size];

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
    int pop()
    {
        if(current==-1)
        {
            throw exception();
        }
        size--;
        int* newList=new int[size];

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
    int* getItems(){
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
    List list;
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

    try
    {

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
        list.pop();
        list.display();
        list.pop();
        list.display();
        list.pop();
        list.display();
        list.pop();
    }
    catch(exception& e)
    {
        cout<<"the list is already empty"<<endl;
    }

    return 0;
}
