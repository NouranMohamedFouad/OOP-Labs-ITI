#include <iostream>
#include <graphics.h>

using namespace std;


#define BROWN 6
#define CYAN 3
#define WHITE 15


class Shape
{
protected:
    int color;
public:
    Shape(int color)
    {
        this->color=color;
    }
    void setColor(int color)
    {
        this->color=color;
    }
    int getColor()
    {
        return this->color;
    }
    virtual void draw()=0;

    ~Shape()
    {
    }
};
/////////////////////////////////////////////////////////////////////////////
class Point
{
protected:
    int x, y;
public:
    Point() : x(0), y(0) {}
    Point(int x1, int y1) : x(x1), y(y1) {}
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
};
////////////////////////////////////////////////////////////////////////////
class Line :public Shape
{
protected:
    Point start;
    Point end;
public:
    Line() :Shape(0), start(), end() {}
    Line(int x1, int y1, int x2, int y2,int color) :Shape(color), start(x1, y1), end(x2, y2) {}
    void draw()
    {
        setcolor(color);
        line(start.getX(), start.getY(), end.getX(), end.getY());
    }
};
///////////////////////////////////////////////////////////////////////////////
class Rect:public Shape
{
protected:
    Point ul;
    Point lr;
public:
    Rect() : Shape(0),ul(), lr() {}
    Rect(int x1, int y1, int x2, int y2,int color) :Shape(color), ul(x1, y1), lr(x2, y2) {}
    void draw()
    {
        setcolor(color);
        rectangle(ul.getX(), ul.getY(), lr.getX(), lr.getY());
    }
};
////////////////////////////////////////////////////////////////////////
class Circle:public Shape
{
protected:
    Point center;
    int radius;
public:
    Circle() :Shape(0), center(), radius(0) {}
    Circle(int m, int n, int r,int color) :Shape(color), center(m, n), radius(r) {}
    void draw()
    {
        setcolor(color);
        circle(center.getX(), center.getY(), radius);
    }
};
//////////////////////////////////////////////////////////////////////
class Picture
{
private:
    int size;
    Shape **items;
    int counter;
public:
    Picture(int size)
    {
        this->size=size;
        items=new Shape*[size];
        counter=-1;
    }
     void addShape(Shape *shape)
     {
         if(counter==size-1){
            return;
         }
         counter++;
         items[counter]=shape;
    }
    void paint()
    {
        for (int i=0;i<=counter;i++)
        {
            items[i]->draw();
        }
    }
    ~Picture()
    {
        for (int i=0;i<=counter;i++)
        {
            delete[] items[i];
        }
    }
};
///////////////////////////////////////////////////////////////////
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    Picture myPic(5);
    myPic.addShape(new Circle(80, 80, 50,BROWN));
    myPic.addShape(new Rect(250, 150, 400, 200,CYAN));
    myPic.addShape(new Line(720, 50, 500, 300,WHITE));
    myPic.addShape(new Circle(450,450,100,BROWN));
    myPic.paint();
    getch();
    return 0;
}
