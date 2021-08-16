#include <iostream>
using namespace std;
struct comp
{
    float real,img;
};
comp add(comp x1,comp x2)
{
    comp result= {x1.real+x2.real,x1.img+x2.img};
    return result;

}
comp diff(comp x1,comp x2)
{
    comp result= {x1.real-x2.real,x1.img-x2.img};
    return result;

}
comp mul(comp x1,comp x2)
{
    comp result= {x1.real*x2.real-x1.img*x2.img,x1.real*x2.img+x1.img*x2.real};
    return result;

}
comp div(comp x1,comp x2)
{
    comp result= {x1.real*x2.img+x1.img*x2.img,x1.img*x2.real-x1.real*x2.img};
    return result;

}


int main()
{
    comp a= {1,2}, b= {2,3};
    comp sum=add(a,b);
    cout<<sum.real<<" + "<<"("<<sum.img<<")"<<"i\n";
    comp sub=diff(a,b);
    cout<<sub.real<<" + "<<"("<<sub.img<<")"<<"i\n";
    comp mult=mul(a,b);
    cout<<mult.real<<" + "<<"("<<mult.img<<")"<<"i\n";
    comp qua=div(a,b);
    cout<<sub.real<<" + "<<"("<<sub.img<<")"<<"i\n";



}
