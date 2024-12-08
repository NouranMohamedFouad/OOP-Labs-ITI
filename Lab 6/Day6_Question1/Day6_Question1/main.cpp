#include <iostream>

using namespace std;

/////////////////////////////////////////////////
class GeoShape
{
protected:
    float dim1;
    float dim2;
public:
    GeoShape()
    {
        dim1=dim2=0;
    }
    GeoShape (float x,float y)
    {
        dim1=x;
        dim2=y;
    }
    void setDim1(float x)
    {
        dim1=x;
    }
    void setDim2(float x)
    {
        dim2=x;
    }
    float getDim1()
    {
        return dim1;
    }
    float getDim2()
    {
        return dim2;
    }
    float calculateArea()
    {

    }
};

///////////////////////////////////////////////////////
class Rect: protected GeoShape
{
public:
    Rect(float x, float y):GeoShape(x, y)
    {

    }
    float calculateArea()
    {
        return dim1*dim2;
    }
};
/////////////////////////////////////////////////////////////////

class Circle:private GeoShape
{

public:
    Circle(float r): GeoShape(r,r)
    {

    }
    void setRadius(float r)
    {
        dim1=dim2=r;
    }
    float getRadius()
    {
        return dim1;
    }
    float calculateArea()
    {
        return 22.0/7*dim1*dim2;
    }
};

////////////////////////////////////////////////////////////

class Square: private Rect
{
public:
    Square(float x): Rect(x, x)
    { }
    void setSquareDim(float x)
    {
        dim1=dim2=x;
    }
    float getSquareDim()
    {
        return dim1;
    }
    float calculateArea()
    {
        return Rect::calculateArea();
    }
};

//////////////////////////////////////////////////////////////
class Triangle: public GeoShape
{
public:
    Triangle(float b, float h): GeoShape (b, h)
    { }
    float calculateArea()
    {
        return 0.5*dim1*dim2;
    }
};


////////////////////////////////////////////////////////////
int main()
{
    Circle c(5.5);
    cout<<"Circle Area: "<<c.calculateArea()<<endl;

    Rect rect(5,8);
    cout<<"Rectangle Area: "<<rect.calculateArea()<<endl;

    Square square(5);
    cout<<"Square Area: "<<square.calculateArea()<<endl;

    Triangle triangle(4,4.5);
    cout<<"Triangle Area: "<<triangle.calculateArea()<<endl;
    return 0;
}
