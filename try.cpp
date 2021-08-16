#include <iostream>
using namespace std;
int fun(int);
int main()
{
int n,a;
cin>>a;
fun(a);

return 0;
}
int fun(int x=1)
{
int n,pow;
cin>>n;
for(int i=1;i<=n;++i)
x*=x;
pow=x;
return pow;
}