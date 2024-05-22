#include<iostream>
using namespace std;

class MyClass
{
    private:int a;
    public: MyClass(int a)
            {
                this->a=a;
            }
            friend class MyFriend;
};

class MyFriend
{
public: void printMyClass(MyClass &obj)
        {
            cout<<"a: "<<obj.a<<endl;
        }
};

int main()
{
    MyClass obj1(10);
    MyFriend obj2;
    obj2.printMyClass(obj1);
    return 0;
}