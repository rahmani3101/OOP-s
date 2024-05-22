#include<iostream>
using namespace std;

class stover
{
	private: string msg;
	public: stover(string msg="OVERFLOW")
			{
				this->msg=msg;
			}

			string getMsg()
			{
				return msg;
			}
};

class stunder
{
	private: string msg;
	public: stunder(string msg="UNDERFLOW")
			{
				this->msg=msg;
			}

			string getMsg()
			{
				return msg;
			}
};

template <typename T> 
class stack
{
	private:	int size;
				int top;
				T *arr;
	public:		stack(int size);
				~stack();
				void push(T val);
				T pop();
				void display();
};

template <typename T> stack<T>::stack(int size)
{
	this->size=size;
	this->top=-1;
	this->arr=new T[this->size];
}

template <typename T> stack<T>::~stack()
{
	delete[] arr;
}

template <typename T> void stack<T>::push(T val)
{
	if(top==size-1)
	{
		stover s;
		throw s;
	}
	arr[++top]=val;
}

template <typename T> T stack<T>::pop()
{
	if(top<=-1)
	{
		stunder s;
		throw s;
	}
	return arr[top--];
}

template <typename T> void stack<T>::display()
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
	int n,data,ch;
	cout<<"ENTER SIZE:"<<endl;
	cin>>n;
	stack<int> *st=new stack<int>(n);
	while(1)
	{
		cout<<endl<<"ENTER CHOICE:"<<endl;
		cin>>ch;
		try
		{	
			switch(ch)
			{
				case 1: cout<<"ENTER DATA:"<<endl;
						cin>>data;
						st->push(data);
						break;
				case 2: data=st->pop();
						cout<<"DATA POPPED:"<<data<<endl;
						break;
				case 3: cout<<"DISPLAYING STACK:"<<endl;
						st->display();
						break;
				case 4: cout<<"EXITING PROGRAM"<<endl;
						exit(0);
						break;
				default: cout<<"INVALID CHOICE"<<endl;
						exit(0);
						break;
			}
		}
		catch(stover so)
		{
 			cout<<so.getMsg()<<endl;
		}
		catch(stunder su)
		{
 			cout<<su.getMsg()<<endl;
		}
	}
	return 0;
}

