#include<iostream>
using namespace std;

class student{
    public:
    int roll;
    char name[20];
    void get(){
        cout<<"Enter Roll no of student \n";
        cin>>roll;
        cout<<"Enter Name of Student: \n";
        cin>>name;
    }
    void show(){
        cout<<"Roll No: "<<roll<<"\t Name : "<<name;
        cout<<"\n";
    }
};

int main(){
    student obj;
    obj.get();
    obj.show();
    return 0;
}
