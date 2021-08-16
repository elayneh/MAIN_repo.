#include <iostream>
using namespace std;
 struct stock {
char stock_name[20];
float ern_share,ratio;
float anticipated_price;
}stocks[5];

int main()
{
for(int i=1;i<=5;i++)
{
cout<<"enter the item's value\nstock name, earning share, and it's estimated ";
cout<<"price to earnings ration respectively.\n";
cin>>stocks[i].stock_name>>stocks[i].ern_share>>stocks[i].ratio;
stocks[i].anticipated_price = stocks[i].ern_share*stocks[i].ratio;
cout<<endl<<endl<<stocks[i].stock_name<<"\n"<<
stocks[i].ern_share<<"\n"<<stocks[i].ratio<<"\n"<<stocks[i].anticipated_price;
}


return 0;
}
