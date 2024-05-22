#include<iostream>
using namespace std;

class stoverflow
{
    private: string msg;
    public: stoverflow(string msg="STACK OVERFLOW. CANNOT ADD ELEMENTS TO FULL STACK.")
            {
                this->msg=msg;
            }
            
            string getMsg()
            {
                return msg;
            }
};

class stunderflow
{
    private: string msg;
    public: stunderflow(string msg="STACK UNDERFLOW. CANNOT DELETE ELEMENTS FROM EMPTY STACK.")
            {
                this->msg=msg;
            }
            
            string getMsg()
            {
                return msg;
            }
};

class stack
{
    private:    int size;
                int top;
                int *arr;
    public: stack(int size);
            ~stack();
            void push(int val);
            int pop();
            void display();
};

stack::stack(int size)
{
    this->size=size;
    this->top=-1;
    this->arr=new int[this->size];
}

stack::~stack()
{
    delete[] arr;
}

void stack::push(int val)
{
    if(top==size-1)
    {
        stoverflow s;
        throw s;
    }
    arr[++top]=val;
}

int stack::pop()
{
    if(top<=-1)
    {
        stunderflow s;
        throw s;
    }
    return arr[top--];
}

void stack::display()
{
    if(top<=-1)
        cout<<"EMPTY STACK"<<endl;
    else
    {
        for(int i=top;i>=0;i--)
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main()
{
    int size,data,ch;
    cout<<"ENTER SIZE OF STACK:"<<endl;
    cin>>size;
    stack *st=new stack(size);
    cout<<"MENU:"<<endl<<"1.PUSH ELEMENT TO STACK"<<endl<<"2. POP ELEMENT FROM STACK"<<endl<<"3. DISPLAY STACK"<<endl<<"4.EXIT PROGRAM"<<endl;
    while(1)
    {
        cout<<endl<<"ENTER CHOICE:"<<endl;
        cin>>ch;
        try
        {
            switch(ch)
            {
                case 1: cout<<"ENTER ELEMENT TO BE PUSHED TO STACK:"<<endl;
                        cin>>data;
                        st->push(data);
                        break;
                case 2: data=st->pop();
                        cout<<"ELEMENT POPPED FROM STACK:"<<endl<<data<<endl;
                        break;
                case 3: cout<<"DISPLAYING STACK:"<<endl;
                        st->display();
                        break;
                case 4: cout<<"EXITING PROGRAM"<<endl;
                        exit(0);
                        break;
                default:cout<<"INVALID CHOICE"<<endl;
                        break;
            }
        }
        catch(stoverflow s)
        {
            cout<<s.getMsg()<<endl;
        }
        catch(stunderflow s)
        {
            cout<<s.getMsg()<<endl;
        }
    }
    return 0;
}
