#include<iostream>
using namespace std;

class rectangle{
    public:
        int l,b;
        rectangle(){
            cout<<"Enter the Width of Rectangle"<<endl;
            cin>>b;
            cout<<"Enter The length of Rectangle"<<endl;
            cin>>l;


        }

        void area(){
            cout<<"Area Of Rectangle:"<<l*b<<endl;
        }

        ~rectangle(){
            cout<<"\n This is Distructor";
        }

};

int main(){
    rectangle obj;
    obj.area();
    return 0;
}