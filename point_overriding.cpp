#include<iostream>
using namespace std;

class Point 
{
    private:
        int x,y;
    public:
        Point(int x=0,int y=0)
        {
            this->x=x;
            this->y=y;
        }    
        virtual void display();
};

void Point ::display()
{
    cout << " Points : (" << x << "," << y << ") \n";
}

class Pixel : public Point
{
    private:
        string colourcode;
    public:
        Pixel(int x , int y , string colourcode ) : Point (x,y) 
        {
            this->colourcode=colourcode;
        }                               
        void display();                                                               
};

void Pixel :: display()
{
    cout << " Colour Code : " << colourcode;
}

int main()
{
    Point *ptr = NULL;
    int ch;
    cout << " Enter \n 1. to call Point class \n 2. to call Pixel class \n";
    cin >> ch;
    if (ch==1)
    {
        int x,y;
        cout<< "Enter value of x and y \n ";
        cin >> x >> y;
        ptr = new Point(x,y);
    }
    else if ( ch ==2 )
    {
        string a ;
        cout<< "Enter Colour Code : ";
        cin>> a;

        ptr=new Pixel(0,0,a);

    }
    else 
        cout << "Invalid Input !!!! ";
    ptr ->display();
}
