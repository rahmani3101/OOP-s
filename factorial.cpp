
#include <iostream>
using namespace std;

int factorial(int n)
{
    int p = 1;
    for (int i = 1; i <= n; i++)
    {
        p = p * i;
    }
    return p;
}
int main()
{
    int a;
    cout << "Enter the number you want factorial of : ";
    cin >> a;
    int f = factorial(a);
    cout << " Factorial : " << f;
    return 0;
}
