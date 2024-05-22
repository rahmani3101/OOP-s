#include<iostream>
using namespace std;

template <typename T> 
class array
{
	private:	int size;
				T *arr;
	public:		array(int size)
				{
					this->size=size;
					this->arr=new T[this->size];
				}
				void input();
				void display();
				void sort(int size);
};

template <typename T> void array<T>::input()
{
	cout<<"ENTER ELEMENTS OF ARRAY:"<<endl;
	for(int i=0;i<size;i++)
		cin>>arr[i];
}

template <typename T> void array<T>::display()
{
	for(int i=0;i<size;i++)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

template <typename T> void array<T>::sort(int size)
{
	for(int i=0;i<size-1;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main()
{
	int n;
	cout<<"ENTER SIZE:"<<endl;
	cin>>n;
	array<int> *arr = new array<int>(n);
	arr->input();
	cout<<"DISPLAYING ELEMENTS OF ARRAY:"<<endl;
	arr->display();
	arr->sort(n);
	cout<<"DISPLAYING ELEMENTS OF ARRAY AFTER SORTING:"<<endl;
	arr->display();
	return 0;
}