#include <iostream>
using namespace std;
struct phone
{
    int area_code;
    int exchange;
    int num;
};

struct  person
{
    char name[20];
    phone phone2;
} ;
int main()
{
    person p[10];
     for(int i=1; i<=10; ++i)

    {
        cout<<"enter the "<<i<<"th person info.\n";
        cout<<"enter the "<<i<<" th person name: ";
        cin>>p[i].name;
        cout<<"\nenter the "<<i<<" phone number: ";
        cout<<"enter the area code\n";
        cin>>p[i].phone2.area_code;
        cout<<"enter the exchange\n";
        cin>>p[i].phone2.exchange;
        cout<<"enter the number\n";
        cin>>p[i].phone2.num;

    }
    for(int i=1; i<=10; ++i)

    {
        cout<<"\n\nthe "<<i<<"th person info.\n";
        cout<<"-----------------------\nthe "<<i<<" name: ";
        cin>>p[i].name;
        cout<<"\nenter the "<<i<<"th phone number:\n";
        cout<<"enter the area code\n";
        cin>>p[i].phone2.area_code;
        cout<<"enter the exchange\n";
        cin>>p[i].phone2.exchange;
        cout<<"enter the number\n";
        cin>>p[i].phone2.num;
    }


    return 0;




}
