#include <iostream>
using namespace std;
struct phone
{
    int area_code;
    int exchange;
    int num;
};

int main()
{
    phone phone1= {212,767,8900},phone2;
      cout<<"enter the second phone number\n";
      cout<<"enter the area code\n";
      cin>>phone2.area_code;
      cout<<"enter the exchange\n";
      cin>>phone2.exchange;
      cout<<"enter the number\n";
      cin>>phone2.num;
      cout<<"the first phone number is: ";
      cout<<phone1.area_code<<" "<<phone1.exchange<<" "<<phone1.num<<endl;
    cout<<"the second phone number is: ";
      cout<<phone2.area_code<<" "<<phone2.exchange<<" "<<phone2.num;



    return 0;
}
