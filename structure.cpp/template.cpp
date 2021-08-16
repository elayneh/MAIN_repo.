/*#include <iostream>
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
if (i==2)
break;
cout<<"enter the item's value\nstock name, earning share, and it's estimated "; 
cout<<"price to earnings ration respectively.\n";
cin>>stocks[i].stock_name>>stocks[i].ern_share>>stocks[i].ratio;
stocks[i].anticipated_price = stocks[i].ern_share*stocks[i].ratio;
cout<<endl<<endl<<stocks[i].stock_name<<"\n"<<
stocks[i].ern_share<<"\n"<<stocks[i].ratio<<"\n"<<stocks[i].anticipated_price;
}


return 0;
}*/
/*
#include <iostream>
using namespace std;
struct student{
int roll_no;
char name[20];
float marks[5];
void fun1();
void fun2();

}students[10];

void student::fun1(){
float total, average;
cout<<"\n\nthe students detail:\n";
for(int i=1;i<=10;++i){
cout<<"enter the "<<i<<"th student details roll number, name and marks respectively\n";
cin>>students[i].roll_no>>students[i].name;
for(int i2=1;i2<=5;++i2){
cout<<"enter the "<<i<<"th of the "<<i2<<"th subject mark:";
cin>>students[i].marks[i2];
total+=students[i].marks[i2];
average=total/(sizeof(marks)/sizeof(marks[1]));
}
}
cout<<"the student's detail roll number, name and marks respectively is:\n";
cout<<"roll number\tame\t\taverage";
for(int i=1;i<=10;++i){
cout<<students[i].roll_no<<"\t\t"<<students[i].name<<"\t\t\t"<<average;
}

}


int main()
{
students[1].fun1();

}*/
#include <iostream>
using namespace std;
struct vector1{
double v1[2];
double vec_sum()

}vec1;
struct vector2{
double v2[2];
}vec2;
double sum_vec()
{

if()
return ()}
int main()
{
for(int i=1;i<=2;++i)
cin>>vec1.v1[i];
for(int j=1;j<=2;++j)
cin>>vec2.v2[j];
if(i==j)
{
for(int k=1;k<=2;++k)
v[k]=vec1.v1[i]+vec2.v2[j]
}




return 0;}