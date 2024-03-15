#include<iostream>
using namespace std;

#include<string>

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
        Point(const Point &c)
        {
            this->x=c.x;
            this->y=c.y;
        }
        void printPoint()
        {
            cout << " Points : (" << x << "," << y << ") \n";
        }
};

class Pixel : public Point
{
    private:
        string colourcode;
    public:
        Pixel(int x , int y , string colourcode ) : Point (x,y) 
        {
            this->colourcode=colourcode;
        }                               
        void printPixel()
        {
            cout<< "Colour code : " << colourcode << endl;
        }                                               
        Pixel(const Pixel &c)
        {
            this->colourcode= c.colourcode;
        }                                                                   
};

int main()
{
    int x,y;
    string a;
    cout<< "Enter value of x and y \n ";
    cin >> x >> y;
    cout<< "Enter Colour Code : ";
    cin>> a;
    Pixel c1(x,y,a);
    c1.printPixel();
    Point c2(x,y);
    c2.printPoint();
};
