#include <iostream>
using namespace std;
struct stdt
{
int stud_id;
int age;
float mark[5];
   
};
int main()
{
stdt 
s1={0x122,22,{89,89,89,78,87}};
cout<<s1.stud_id<<endl<<s1.age<<endl<<s1.mark[0];
}
