#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <windows.h>
void menu();
void pass_code();
void cpass_code();


using namespace std;
class one {
public:
virtual void get()=0;
virtual void show()=0;

};
//////////////////class information
class info:public one
{
public:
char name[50],time[50];
int num,age;
void get()
{
system("cls");
cin.sync();
cout<<"\ninter the patient name:";
cin.getline(name,50);
cout<<"\ninter the appointment time:";
cin.getline(time,50);
cout<<"\nenter the patient age: ";
cin>>age;
cout<<"\nenter appointment number:";
cin>>num;

}
void show(){
cout<<"\nname: "<<name<<"\nage: "<<age<<"\nnumber: "
<<num<<"\ntime: "<<time;

}

};












/////////////////class rana//////////
class rana:public info{
public:
info a1;
void get(){
system("cls");
ofstream out("rana.txt",ios::app|ios::binary);
a1.get();
out.write((char*)&a1,sizeof(info));
out.close();
cout<<"your entry has been saved ";
getch();
menu();
}
void show(){
ifstream in("rana.txt");
if(in==NULL){
cout<<"\nno data in the file.";
cout<<"\n\n\t\tpress any key to continue:";
getch();
menu();
}
else{
while(!in.eof())
{in.read((char*)&a1,sizeof(a1));
a1.show();
}
in.close();
cout<<"press any key to continue.";
getch();
menu();
}
}
};









/////////////////class dr waqar//////////
class waqar:public info{
public:
info a1;
void get(){
system("cls");
ofstream out("waqar.txt",ios::app|ios::binary);
a1.get();
out.write((char*)&a1,sizeof(info));
out.close();
cout<<"your entry has been saved ";
getch();
menu();
}
void show(){
ifstream in("waqar.txt");
if(in==NULL){
cout<<"\nno data in the file.";
cout<<"\n\n\t\tpress any key to continue:";
getch();
menu();
}
else{
while(!in.eof())
{in.read((char*)&a1,sizeof(a1));
a1.show();
}
in.close();
cout<<"press enter to continue.";
getch();
menu();
}
}
};















///////class dr ahmed
class ahmed:public info{

public:
info a1;
void get(){
system("cls");
ofstream out("ahmed.txt",ios::app|ios::binary);
a1.get();
out.write((char*)&a1,sizeof(info));
out.close();
cout<<"your entry has been saved ";
getch();
menu();
}
void show(){
ifstream in("ahmed.txt");
if(in==NULL){
cout<<"\nno data in the file.";
cout<<"\n\n\t\tpress any key to continue:";
getch();
menu();
}
else{
while(!in.eof())
{in.read((char*)&a1,sizeof(a1));
a1.show();
}
in.close();
cout<<"press any key to continue.";
getch();
menu();
}
}
};
////



///////////////






class staff:public one{
public:
char all[999];
char name[50],age[20],sal[30],pos[20];
void get(){
ofstream out("staff.txt",ios::app);
{
system("cls");
cin.sync();
cout<<"\nenter name: ";
cin.getline(name,50);
cout<<"\nenter age: ";
cin.getline(age,20);
cout<<"\nenter salary: ";
cin.getline(sal,30);
cout<<"\nenter working position:";
cin.getline(pos,20);

}
cout<<"\nname: "<<name<<"\nage: "<<age<<"\nsallary: "
<<sal<<".";
out.close();
cout<<"\n\nyour information has been saved: \n\t\t\tpress any key to continue:";
getch();
menu();
}


void show(){
ifstream("staff.txt");
if(!n){
cout<<"file open error";
}
while(!(in.eof())){
cin.getline(all,999);
cout<<all<<endl;
}
in.close();
cout<<"\n\n\t\t\tpress any key to continue:";
getch();
menu();
}

 };











//////////////////class information
class information {
public:
void drinfo(){
system("cls");
system("color F3");
cout<<"\n====================================================================";
cout<<"\n\n\t\t(three doctors available)\n\n\t\t[information and timing are given below]\n";
cout<<"-------------------------------------------------------------------------";
cout<<"\t\tdr available:\n";
cout<<"\t\tdr.rana (skin specialist)\n\n";
cout<<"\t\t\t[[timing]]:\n\n";
cout<<"monday to friday\t\t9:00am - 5:00pm\n";
cout<<"saturday        \t\t9:00am - 1:00pm\n";
cout<<"sunday          \t\toff\n";
cout<<"-------------------------------------------------------------------------";
cout<<"\t\tdr.waqar(neurologist)\n\n";
cout<<"\t\t\t [[timing]]:\n\n";
cout<<"\tmonday to friday\t\t2:00pm - 10:00pm\n";
cout<<"saturday          \t\t8:00am - 1:00pm\n";
cout<<"sunday            \t\t12:00pm - 9:00pm\n";
cout<<"-------------------------------------------------------------------------";
cout<<"\t\tdr. ahmed(orthopedics)\n\n";
cout<<"\t\t\t[[timing]]:\n\n";
cout<<"\tmonday to friday\t\t8:00am - 5:00pm\n";
cout<<"saturday          \t\t10:00 - 1:00pm\n";
cout<<"\tsunday          \t\toff\n";
cout<<"\n-----------------------------------------------------------------------";
cout<<"\npress any key to continue: ";
getch();
menu();
}

};









void call_dr(){
system("cls");
int choice;
cout<<"\n\n\n\tpress 1 for dr rana \n\n\t\t press 2 for dr waqar "
"\n\n\t\tpress 3 for dr ahmed.";
cin>>choice;
one *ptr;
rana s3;
waqar s4;
ahmed s5;
if(choice==1)
{
ptr=&s3
ptr->get();
}
if(choice==2){
ptr=&s4;
ptr->get();
}
if(choice==3){
ptr=&s5;
ptr->get();
}
else {
cout<<"sorry invalid choice:";
}









}


void pinfshow(){
}


































void menu(){
system("cls");
system("color FC");
cout<<"\n\n";
cout<<"\t\t  | +++++++++MAIN MENU  +++++++++++++ | \n";
cout<<"\t\t  |         hospital management system| \n";
cout<<"\t\t  |===================================| \n";

cout<<"\n--------------------------------------------------------\n";
cout<<"\t\t       please select any option          \n ";
cout<<"\n\n\t1-\t\tpress 1 for available doctor information:\n\n";
cout<<"\n\n\t1-\t\tpress 2 for doctor appointment:\n\n";
cout<<"\n\n\t3-\t\tpress 3 for saving staff information:\n\n";
cout<<"\n\n\t4-\t\tpress 4 for checking patient appointment menu:\n\n";
cout<<"\n\n\t5-\t\tpress 5 for checking staff information menu:\n\n";
cout<<"\n\n\t6-\t\tpress 6 for change password or create password:\n\n";
cout<<"\n\n\t7-\t\t[   press 7 for logout:\n\n";
cout<<"=================================================================================\n\n\n";
cout<<"                please enter your choice: ";


};
/*
void call_dr(){
system("cls");
int choice;
cout<<"\n\n\n\t\tpress 1 for dr rana \n\n\t\t press 2 for "
"dr waqar \n\n\t\t press3 for dr ahmed.";
cin>>choice;
one *ptr;
rana s3
}*/
