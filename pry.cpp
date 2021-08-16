//billing project in c++
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;

class bill
{
private://variables
    int p_code;
    float price,discount;
    string name;
public://functions
    void menu();
    void admin();
    void customer();
    void add();
    void search();
    void edit();
    void del();
    void show();
};
void bill::menu()//define function of bill class
{
p:
    system("cls");
    int choice;
    string e_mail,pass;
    char ch;
    cout<<"\n\n\tcontrol panel\n";
    cout<<"\t=============";
    cout<<"\n\n1. admin";
    cout<<"\n2. customer";
    cout<<"\n3. exit";
    cout<<"\n\nenter your choice:\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        system("cls");
        cout<<"\n\n\tlog in system";
        cout<<"\n\n e-mail: ";
        cin>>e_mail;
        cout<<"password: ";
        for(int i=1; i<=4; i++)
        {
            ch=getch();
            pass+=ch;
            cout<<"*";
        }
        if(e_mail=="bill@gmail.com"&&pass=="0000")
        {
            admin();
            break;
        }
        else
        {
            cout<<"evalid e-mail or password. ";
        }
    case 2:
        customer();
    case 3:
        exit(0);
    default:
        cout<<"invalid value try again.";
    }
    getch();
    goto p;
}
void bill::admin()//admin function of bill class
{
p:
    int choice;
    system ("cls");
    cout<<"\n\n\tAdmin panel";
    cout<<"\t===========";
    cout<<"\n\n1. add product";
    cout<<"\n2. search product";
    cout<<"\n3. edit product";
    cout<<"\n4. delete product";
    cout<<"\n5. show product";
    cout<<"\n6. go back";
    cout<<"\n\nenter your choice:\n";
    cin>>choice;
    switch(choice)
    {
    case 1:
        add();
        break;
    case 2:
        search();
        break;
    case 3:
        edit();
        break;
    case 4:
        del();
        break;
    case 5:
        show();
        break;
    case 6:
        menu();
        break;
    default:
        cout<<"\n\ninvalid choice please try again.";
    }
    getch();
    goto p;

}
void bill::customer()//customer function of bill class
{
p:
    system("cls");
    int choice;
    cout<<"\n\tcustomer panel";
    cout<<"\n\n1. sale product";
    cout<<"\n2. go back.\n";
    cout<<"enter your choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        break;
    case 2:
        menu();
    default:
        cout<<"invalid value please try again.";
    }
    getch();
    goto p;
}
void bill::add()
{
p:
    system("cls");
    fstream file;
    int c,found=0;
    float p,d;
    string n;
    cout<<"\n\n\tadd new product.";
    cout<<"\n\n\tEnter product code: ";
    cin>>p_code;
    cout<<"\nEnter product name: ";
    cin>>name;
    cout<<"\nEnter product price: ";
    cin>>price;
    cout<<"\nEnter discount in %: ";
    cin>>discount;
    file.open("product.txt",ios::in);
    if(!file)
    {
        file.open("product.txt",ios::app|ios::out);
        file<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
        file.close();
    }
    else
    {
        file>>c>>n>>p>>d;
        while(!file.eof())
        {
            if(c==p_code)
            {
                found++;
            }
            file>>c>>n>>p>>d;
        }
        file.close();
        if(found==1)
            goto p;
        else
        {
            file.open("product.txt",ios::app|ios::out);
            file<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
            file.close();
        }
    }
    cout<<"\n\n\trecord inserted successfully.";
}
void bill::search()//define the search function od bill class
{
    int pcode,found=0,d;
    float p;
    string n;
    system("cls");
    fstream file;
    cout<<"\n  search record... ";
    cout<<"\nproduct code: ";
    cin>>pcode;
    file.open("product.txt",ios::in);
    if(!file)
    {
        cout<<"file openning error!";
    }
    else
    {
        file>>pcode>>n>>p>>d;
        while (!file.eof())
        {
            if(pcode==p_code)
            {
                system("cls");
                cout<<"\nsearch record:";
                cout<<"\nproduct code:"<<p_code;
                cout<<"\nproduct name:"<<n;
                cout<<"\nproduct price:"<<p;
                cout<<"\nproduct discount:"<<d<<" %";
                found++;
            }
            file>>pcode>>n>>p>>d;
        }
        file.close();
        if(found==0);
        cout<<"\nrecord can't found";
    }
}
void bill::edit()
{
    system("cls");
    fstream file,file1;
    int pcode,found=0,c;
    float p,d;
    string n;
    cout<<"\n\tedit record ";
    cout<<"\nproduct code: ";
    cin>>pcode;
    file.open("product.txt",ios::in);
    if(!file)
    {
        cout<<"file openning error!";
    }
    else
    {
        file1.open("product.txt",ios::app|ios::out);
        file>>c>>n>>p>>d;
        while (!file.eof())
        {
            if(pcode==p_code)
            {
                system("cls");
                cout<<"\nproduct new code:";
                cin>>c;
                cout<<"\nproduct name:";
                cin>>n;
                cout<<"\nproduct price:";
                cin>>p;
                cout<<"\nproduct discount in percent: ";
                cin>>d;
                cout<<"\nrecord added succesfully.";
                file1<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                found++;
            }
            else
            {
                file1<<pcode<<" "<<name<<" "<<price<<" "<<discount<<"\n";
            }
            file>>c>>n>>p>>d;
        }
        file.close();
        file1.close();
        remove("product.txt");
        rename("product.txt","product_1.txt");
        if(found==0);
        cout<<"\nrecord can't found";
    }
}
void bill::del()
{
    system("cls");
    fstream file,file1;
    int found=0,dpcode;
    cout<<"\n\tdelete product. " ;
    cout<<"\n\t delete product code. ";
    cin>>dpcode;
    file.open("product.txt",ios::in);
    if(!file)
    {
        cout<<"file openning error.";
    }
    else
    {
        file1.open("product1.txt",ios::app|ios::out);
        file>>p_code>>name>>price>>discount;
        while(!file.eof())
        {
            if(p_code==dpcode)
            {
                cout<<"product deleted successfully.";
                found++;
            }
            else
            {
                file<<p_code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
            }
            file>>p_code>>name>>price>>discount;
        }
        file.close();
        file1.close();
        remove("product.txt");
        rename("product1.txt","product.txt");
        if(found==0)
            cout<<"\nrecord can't be found.";
    }
}
void bill::show()
{
    system("cls");
    fstream file;
    cout<<"\n\tshow product.";
    file.open("product.txt",ios::in);
    if(!file)
    {
        cout<<"\ncan't show the file.";
    }
    else
    {
        cout<<"\ncode\tname\t\tpice\t\tdiscount(%)";
        file>>p_code>>name>>price>>discount;
        while(!file.eof())
        {
            cout<<"\n"<<p_code<<"\t"<<name<<"\t\t"<<price<<"\t"<<discount;
            file>>p_code>>name>>price>>discount;
        }
        file.close();
    }
}

int main()//main function
{
    bill b;//define an object "b" of class bill.
    b.menu();

    return 0;
}
