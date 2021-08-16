#include <iostream>
using namespace std;
struct vectr
{
    float x,y;

};
vectr add(vectr x1,vectr y1)
{
        vectr resultant1= {x1.x+y1.x,x1.y+y1.y};
        return resultant1;
}
vectr diff(vectr x1,vectr y1)
{
        vectr resultant2= {x1.x-y1.x,x1.y-y1.y};
        return resultant2;
}

int main()
{
    vectr v1,v2;
    cout<<"enter the first vector:\n";
    cin>>v1.x>>v1.y;
        cout<<"enter the second vector:\n";
    cin>>v2.x>>v2.y;
    vectr resultant1=add(v1,v2);
    cout<<endl<<"the sum of the two vectors will be: "<<resultant1.x<<"x + "<<resultant1.y<<"y";
    vectr resultant2=diff(v1,v2);
    cout<<endl<<"the difference of the two vectors will be: "<<resultant2.x<<"x + "<<resultant2.y<<"y\n";


}
