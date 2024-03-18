#include <iostream>
using namespace std;

class Shape
{
    private:
        string shapeName;
    public:
        Shape(string shapeName )
        {
            this->shapeName=shapeName;
        }  
        string getName()
        {
            return shapeName;
        } 
        virtual double getArea() =0;
};

class Triangle : public Shape
{
    private:
        int h,b;
    public:
        Triangle(double b , double h) : Shape ("Triangle") 
        {
            this->b=b;
            this->h=h;
        }  
        double getArea()
        {
            return 0.5*b*h;
        }
};

class Circle : public Shape{
    private:
        double r;
    public:
        Circle(double r ) : Shape("Circle") 
        {
            this->r=r;
        }   
        double getArea()
        {
            return 3.14*r*r;
        }
};

int main()
{
    Shape *ptr= NULL;
    int ch;
    cout<< " Menu : \n Enter : \n 1. to calculate Area of Triangle \n 2. to calculate Area of Circle";
    cin>>ch;
    
    if( ch ==1 )
    {
        cout<< " Enter base and height of Triangle : \n ";
        int a,b;
        cin>> a >>b ;
        ptr = new Triangle(a,b);
    }
    else if (ch == 2 )
    {
        int r;
        cout<< " Enter radius \n";
        cin>> r;
        ptr = new Circle(r);
    }
    else 
    {
        cout << " invalid Input. Try Again !!!!";
    }

    cout<< " Area : " << ptr ->getArea();
}
