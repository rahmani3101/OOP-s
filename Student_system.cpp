#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Student{
	string name;
	int id;
	public: 
		Student(string name, int id){
			this->name = name;
			this->id = id;
		}
		
		bool operator<(const Student std){
			return this->name < std.name;
		}
		friend ostream& operator<<(ostream& os, Student& s);
		int getId() const{return id;}
		string getName() const {return name;}
};

ostream& operator<<(ostream& os, Student& s){
	os<<"Name: "<<s.name<<endl<<"ID: "<<s.id<<endl;
	return os;
}

int main(){

	vector<Student> vs;
	int ch;
	do{
		cout<<"****** Student Mangement System ******"<<endl;
		cout<<"1. Add Student"<<endl;
		cout<<"2. print Students"<<endl;
		cout<<"3. sort Student data by Name"<<endl;;
		cout<<"4. sort Student data by id"<<endl;
		cout<<"5. search student by id"<<endl;
		cout<<"6. search student by name"<<endl;
		cout<<"0. Exit"<<endl;
		cout<<""<<endl;
		cout<<"enter your choice"<<endl;
		cin>>ch;
		switch(ch){
			case 1: {	
					string name;
					int id;
					cout<<"enter Student name: ";
					cin>>name;
					cout<<"enter Student id: ";
					cin>>id;
					vs.push_back(Student(name, id));
					cout<<name<<" is added in record"<<endl;
					break;
				}
			case 2: {
					cout<<"\n\n"<<endl;
					cout<<"print all student data"<<endl;
					for(Student s: vs){
						cout<<s;
					}
					cout<<"\n\n"<<endl;
					break;
				}
			case 3: {
					sort(vs.begin(),vs.end());
					cout<<"Student record sorted by Name"<<endl;
					break;
				}
			case 4: {
					sort(vs.begin(), vs.end(), [](const Student &a, const Student &b){
						return a.getId() < b.getId() ;
					});
					cout<<"Student record sorted by Id"<<endl;
					break;
				}
			case 5: {
					int targetId;
					cout<<"enter the student id you want to search: ";
					cin>>targetId;
					auto it = find_if(vs.begin(),vs.end(),[targetId](const Student &s){
						return s.getId() == targetId;
					});
					
					if(it != vs.end()){
						cout<<"Student Found"<<endl;
						cout<<*it;
					}else{
						cout<<"Student not found!!"<<endl;
					}
					break;
				}
			case 6: {
					string targetName;
					cout<<"enter the student name you want to search: ";
					cin>>targetName;
					auto it = find_if(vs.begin(), vs.end(), [targetName](const Student &s){
						return s.getName() == targetName;
					});
					if(it != vs.end()){
						cout<<"Student Found"<<endl;
						cout<<*it;
					}else{
						cout<<"Student not found!!"<<endl;
					}
					break;
				}
			case 0: {	
					exit(0);
					break;
				}
			default: {
					cout<<"enter valid choice"<<endl;
					break;
				}
		
		}
	}while(ch != 0);
	

	return 0;
}