#include<iostream>
using namespace std;
class complex{
    int a,b;
    public:
    void input(int x,int y){
        a=x;
        b=y;
    }
    void display(){
        cout<<"The complex number is "<<a<<"+"<<b<<"i"<<endl;
    }
    complex add(complex c){
        complex temp;
        temp.a=a+c.a;
        temp.b=b+c.b;
        return temp;
    }
};
int main(){
    complex c1,c2,c3;
    c1.input(1,2);
    c2.input(3,4);
    c3=c1.add(c2);
    c3.display();
    return 0;
}