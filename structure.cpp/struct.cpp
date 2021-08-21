#include <iostream>
using namespace std;
struct stdt
{ 
char name[20];
int stud_id,age;
float mark[5];
struct date{
int dd,mm,yy;
}dat;
};
int main()
{

stdt s1[2]; 
s1[0]={"belayneh",122,22,{89,89,89,78,87}};
s1[1]={12,32,{1,1,1,1,1}};
s1[0].dat={12,12,2021};
cout<<s1[0].dat.dd<<endl<<s1[0].dat.mm<<endl<<s1[0].dat.yy<<endl;
cout<<s1[1].stud_id<<endl<<s1[1].name<<endl<<s1[1].age<<endl;
for(int i=0;i<5;i++)
cout<<s1[1].mark[0]<<"\t";
}
