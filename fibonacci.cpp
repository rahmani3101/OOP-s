#include<iostream>
using namespace std;

void fibo(int n )
{
    int f=0 , s=1 , next;
    cout << f <<" ," << s<< " ,";
    for(int i=2;i<n;i++)
    {
        next = f+s;
        cout<<next<< " , ";
        f=s;
        s=next;
    } 
}

int main()
{
    int n;
    cout<< " Enter number of terms : ";
    cin>>n;
    fibo(n);
    return 0;
}