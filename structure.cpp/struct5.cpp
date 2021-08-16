#include <iostream>
#include <iomanip>

using namespace std;
struct student{
int roll_no;
char name[20];
float marks[5];
void fun1();
void fun2();

}students[2];

void student::fun1(){
float total[2], average[2];
cout<<"\nthe students detail:\n";
for(int i=1;i<=2;++i){
cout<<"enter the "<<i<<"th student details roll number, name and marks respectively\n";
cin>>students[i].roll_no>>students[i].name;
for(int i2=1;i2<=5;++i2){
cout<<"enter the "<<i<<"th of the "<<i2<<"th subject mark:";
cin>>students[i].marks[i2];
total[i]+=students[i].marks[i2];
average[i]=total[i]/(sizeof(marks)/sizeof(marks[1]));
}
}
cout<<"the student's detail roll number, name and marks respectively is:\n";
cout<<"roll number | name     |average\n";
for(int i=1;i<=2;++i){
cout<<students[i].roll_no<<"\t\t"<<students[i].name<<"\t "<<fixed<<setprecision(2)<<average[i];
cout<<endl;
}

}


int main()
{
students[1].fun1();


return 0;
}
