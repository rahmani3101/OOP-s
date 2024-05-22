#include <iostream>
using namespace std;

class Node
{
	private:int data;
			Node *next;
			
	public:	Node(int data,Node *next=NULL)
			{
				this->data=data;
				this->next=next;
			}
			
			int getData()
			{
				return data;
			}
			
			Node *getNext()
			{
				return next;
			}
			
			void setData(int data)
			{
				this->data=data;
			}
			
			void setNext(Node *next)
			{
				this->next=next;
			}
};

class LL
{
	private:Node *head;
	
	public:	LL()
			{
				head=NULL;
			}
			
			~LL()
			{
				while(head!=NULL)
				{
					Node *temp=head;
					head=head->getNext();
					delete temp;
				}
			}
			
			void addBeg(int data)
			{
				head=new Node(data,head);
			}
			
			void addEnd(int data)
			{
				if(head==NULL)
					addBeg(data);
				else
				{
					Node *temp=head;
					while(temp->getNext()!=NULL)
						temp=temp->getNext();
					temp->setNext(new Node(data));
				}
			}
			
			void delBeg()
			{
				Node *temp=head;
				if(head==NULL)
                {
                    cout<<"EMPTY LIST"<<endl;
                }
                else
                {
                    head=head->getNext();
				    cout<<"DELETED DATA:"<<temp->getData()<<endl;
				    delete temp;
                }
			}
			
			void delEnd()
			{
			    if(head==NULL)
                {
                    cout<<"EMPTY LIST"<<endl;
                }
                else
                {
                    if(head->getNext()==NULL)
                    {
                        delete head;
                    }
                    Node *temp=head;
                    while(temp->getNext()->getNext()!=NULL)
                        temp=temp->getNext();
                    cout<<"DELETED DATA:"<<temp->getNext()->getData()<<endl;
                    temp->setNext(NULL);
                    delete temp->getNext();
                }
			}
			
			void print()	
			{
				Node *temp=head;
				if(temp==NULL)
				    cout<<endl<<"EMPTY LIST"<<endl;
				else
				{
				    while(temp!=NULL)
				    {
					    cout<< temp->getData()<<" -> ";
					    temp=temp->getNext();
				    }
				    cout<<"NULL"<<endl;
				}
			}
};

int main()
{
LL list;
int ch,data;
cout<<"MENU:"<<endl<<"1.ADD FROM BEGINNING"<<endl<<"2.ADD FROM END"<<endl<<"3.DISPLAY LIST"<<endl<<"4.DELETE FROM BEGINNING"<<endl<<"5.DELETE FROM END"<<endl<<"6.EXIT PROGRAM"<<endl;
while(1)
{
	cout<<endl<<"ENTER CHOICE:"<<endl;
	cin>>ch;
	switch(ch)
	{
	    case 1:	cout<<"ENTER DATA TO ADD FROM BEGINNING:"<<endl;
			cin>>data;
			list.addBeg(data);
			break;
	    case 2: cout<<"ENTER DATA TO ADD FROM END:"<<endl;
			    cin>>data;
			    list.addEnd(data);
			    break;
	    case 3: cout<<"DISPLAYING LIST: ";
                list.print();
			    break;
	    case 4: list.delBeg();
			    break;
        case 5: list.delEnd();
                break;
        case 6: cout<<"EXITING PROGRAM."<<endl;
		    	exit(0);
			    break;
	    default: cout<<"INVALID CHOICE"<<endl;
			    break;
	}
}
return 0;
}
