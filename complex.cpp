#include <iostream>
using namespace std;

class Complex
{   
    private:
        float a,b;
    public:
        Complex()
        {
            this->a=this->b=0;
        }   
        Complex(float a, float b)
        {
            this->a=a;
            this->b=b;
        } 
        Complex(const Complex &C)
        {
            this->a=C.a;
            this->b=C.b;
        }
        float getA()
        {
            return a;
        }
        float getB()
        {
            return b;
        }
        void setA(float a)
        {
            this->a=a;
        }
        void setB(float b)
        {
            this->b=b;
        }
        void printComplex()
        {
            cout<<" : "<<a<<"+i"<<b<<endl;

        }
        Complex addComplex(const Complex &C)
        {
            float a=this->a + C.a;
            float b = this->b +C.b;
            Complex result(a,b);
            return result;
        }
        Complex subComplex(const Complex &C)
        {
            float a=this->a - C.a;
            float b = this->b -C.b;
            Complex result(a,b);
            return result;
        }
        Complex mulComplex(const Complex &C) {
            float a = (this->a * C.a) - (this->b * C.b);
            float b = (this->a * C.b) + (this->b * C.a);
            Complex result(a, b);
            return result;
        }
};

int main()
{
    float r1,i1,r2,i2;
    cout<< " Enter first complex number : (first real and then imaginary)";
    cin>>r1>>i1;
    Complex C1(r1,i1);
    cout<< " Enter second complex number : (first real and then imaginary)";
    cin>>r2>>i2;
    Complex C2(r2,i2);

    Complex C3= C1.addComplex(C2);
    cout << " Sum of two complex number is  ";
    C3.printComplex();
    
    Complex C4= C1.subComplex(C2);
    cout << " Difference of two complex number is  ";
    C4.printComplex();
    
    Complex C5= C1.addComplex(C2);
    cout << " Product of two complex number is  ";
    C5.printComplex();
}
