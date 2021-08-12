#include <iostream>
#include <windows.h>//gotofy()
#include <conio.h>//use for delay
#include <string.h>//use for strcmp(),strcpy(),strlen(),etc.
#include <stdlib.h>
#include <type.h>/*to declares many more c string library functions that return non-zero value is the argument is true or zero if vise versa.
Following are the functions defined in the header ctype.h −

Sr.No.	Function & Description
1	int isalnum(int c)
This function checks whether the passed character is alphanumeric.

2	int isalpha(int c)
This function checks whether the passed character is alphabetic.

3	int iscntrl(int c)
This function checks whether the passed character is control character.

4	int isdigit(int c)
This function checks whether the passed character is decimal digit.

5	int isgraph(int c)
This function checks whether the passed character has graphical representation using locale.

6	int islower(int c)
This function checks whether the passed character is lowercase letter.

7	int isprint(int c)
This function checks whether the passed character is printable.

8	int ispunct(int c)
This function checks whether the passed character is a punctuation character.

9	int isspace(int c)
This function checks whether the passed character is white-space.

10	int isupper(int c)
This function checks whether the passed character is an uppercase letter.

11	int isxdigit(int c)
This function checks whether the passed character is a hexadecimal digit.

The library also contains two conversion functions that accepts and returns an "int".

Sr.No.	Function & Description
1	int tolower(int c)
This function converts uppercase letters to lowercase.

2	int toupper(int c)
This function converts lowercase letters to uppercase.*/
using namespace std;
char ans='0';
int ok;
int b,valid=0;
//function declaration
void welcome_screen(void);
void title(void);
void main_manu(void);
void login_screen(void);
void add_rec(void);
void func_list();//to list the patient detail
void search_rec();
void edit_rec();
void dlt_rec();
void exit_rec();
void gotoxy(short x, short y)
{
    COORD pos= {x,y}; //set co-ordinates in (x,y).
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//list of global variables
struct patient
{
    int age;
    char gender;
    char first_name[20];
    char last_name[20];
    char address[15];
    char contact_no[10];
    char email[30];
    char doctor_name[20];
    char problem[20];
};
struct patient p,temp_c;
main(void)
{
    welcome_screen();
    title();
    login_screen();//used to call main function
}/******************************WELL COME SCREEN **************************/
void welcome_screen()
{
    cout<<"\n\n\n\n\n\n\n\t\t\t####################################";
    cout<<"\n\t\t\t\t#\t\tWELCOME TO\t\t#";
    cout<<"\n\t\t\t\t# TESHOME GENERAL SPECIALIZED HOSPITAL   #";
    cout<<"\n\t\t\t\t########################################";
    cout<<"\n\n\n\n\n press any key to continue:\n";
    getch();/*The getch() is a predefined non-standard function that is defined in conio.h header file.
used to hold the screen until the user passes a single value to exit from the console screen.
It can also be used to read a single byte character or string from the keyboard and then print. It does not hold any parameters.
    It has no buffer area to store the input character in a program.
    We use a getch() function in a C/ C++ program to hold the output screen for some time until the user passes a key from the keyboard to exit the console screen. Using getch() function,
    we can hide the input character provided by the users in the ATM PIN, password, etc.
    Syntax:
int getch(void);
Parameters: The getch() function does not accept any parameter from the user.
Return value: It returns the ASCII value of the key pressed by the user as an input.*/
    system ("cls");
}
/************************************title screen *************************/
void title()
{
    cout<<"\n\n\t\t-----------------------------------------------";
    cout<<"\n\t\t\t\tTESHE";
    cout<<"\n\t\t--------------------------------------------------";
}
/************************************MAIN MANU FUNCTION **********************/
void main_manu()
{
    system("cls");
    title();
    cout<<"\n\n\n\n\n\n\\n\t\t\t\t1. add patient record\n";
    cout<<"\n\t\t\t\t2. list patient record\n";
    cout<<"\n\t\t\t\t3. search patient record\n";
    cout<<"\n\t\t\t\t4. edit patient record\n";
    cout<<"\n\t\t\t\t5. delete patient record\n";
    cout<<"\n\t\t\t\t6. exit\n";
    int choose;
    cin>>choose;
    switch(choose)
    {
    case 1:
        add_rec();
        break;
    case 2:
        func_list();
        break;
    case 3:
        search_rec();
        break;
    case 4:
        edit_rec();
        break;
    case 5:
        dlt_rec();
        break;
    case 6:
        exit_rec();
        break;
    default:
        cout<<"\t\t\t invalid entry. please try again:\n";
        getch();
    }
}
/**********************************exit screen *******************/
void exit_rec()
{
    system("cls");
    title();
    cout<<"\n\n\n\n\n\t\t\tTHANK YOU FOR VISITTING!";
    getch();
}
/***********************************login screen*********************/
void login_screen()
{
    int e=0;
    char user_name[20];
    char password[12];
    char original_user_name[30]="patient";
    char original_password[15]="1212";
    do
    {
        cout<<"\n\n\n\n\t\t\t\tenter your user name and password:";
        cout<<"\n\n\n\t\t\t\t\tuser name:";
        cin>>user_name;
        cout<<"\n\n\n\t\t\t\t\tpassword:";
        cin>>password;
        if(strcmp(user_name,original_user_name)==0&&(password,original_password)==0)
        {
            cout<<"login successful.";
            getch();
            main_manu();
            break;
        }
        else
        {
            cout<<"\n\t\t\tincorrect password";
            e++;
            getch();
        }
    }
    while(e<=2);
    if(e>2)
    {
        cout<<"you have try many times. try later";
        getch();
        exit_rec();
    }
    system("cls");

}
/*********************************add record *************************/
void add_rec()
{
    system("cls");
    title();
    char ans;
    FILE*ek;
    ek=fopen("record2.dat","a");
    cout<<"\n\n\t\t\t||||||||||||||||add patient record|||||||||||||||||\n";
    /*********************************FIRST NAME****************************/
a:
    cout<<"\n\t\t\tfirst name:";
    cin>>p.first_name;
    p.first_name[0]=toupper(p.first_name[0]);
    if(strlen(p.first_name)>20||strlen(p.first_name)<2)
    {
        cout<<"\n\t invalid : maximum range for the first name is 20 and minimum range is 2.";
        goto a;
    }
    else
    {
        for(b=0; b<strlen(p.first_name); b++)
        {
            if(isalpha(p.first_name[b]))//isalpha(char) return non zero value if alphabetic letters are passed to it.
            {
                valid=1;
            }
            else
            {
                valid =0;
                break;
            }
         }
    }
        if(!valid)
        {
            cout<<"\n\tthe first name contain invalid character";
goto a;
        }

    /***********************************LAST NAME******************************/
b:
    cout<<"\n\t\t\tlast name:\n ";
    cin>>p.last_name;
    p.last_name[0]=toupper(p.last_name[0]);/*toupper(chars) cstring function used to change the passed argument to
    it's equivalent upper case letters."type.h" included header file */
    if(strlen(p.last_name)>20||strlen(p.last_name)<2)
    {
        cout<<"invalid: the last name is in the range of 2 and 20.";
goto b;
    }
    else
    {
        for(b=0; b<strlen(p.last_name); b++)
            if(isalpha(p.last_name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
    }
    if(!valid)
    {
        cout<<"\n\t\t last name contain invslid character. try again.";
        goto b;
    }
}
/****************************GENDER***********************************/
do
{
    cout<<"\n\t\t\tGender[F,M]:";
    cin>>gender;
    if(toupper(p.gender)=='M'||toupper(p.gender)=='F')
    {
        ok=1;
    }
    else
    {
        ok=0;
    }
    if(!ok)
    {
        cout<<"gender contain invalid character.";
    }
}
while(!ok);
/*******************************************age*************************/
cout<<"\n\t\t\tage:";
cin>>age;
/********************************************8address**********************/
do
{
c:
    cout<<"\n\t\t\taddress:";
    cin>>address;
    p.address[0]=toupper(p.address[0]);
    if(strlen(p.address)>30||strlen(p.address)<4)
    {
        cout<<"\n\tinvalid:address is in the range of 4 and 20.";
        goto c;
    }
}
while(!valid);
/**********************************contct.no***************************/
do
{
d:
    cout<<"\n\t\t\tcontact no: ";
    cin>>contact_no;
    if(strlen(p.contact_no)>10||strlen(p.contact_no)!=10)
    {
        cout<<"\n\t\sorry:contact no must contain 10 numbers.Enter it again.";
goto d:
    }
    else
    {
        for(b=0; b<strlen(p.contact_no); b++)
        {
            if(!isalpha(p.contact_no[b]))
            {
                valid=1;
            }
            else
            {
                vslid=0;
                break;
            }
        }
        if(!valid)
        {
            cout<<"\n\t\tcontact no. contain invalid character.";
goto d:
        }
    }
}
while(!valid);
/***********************************EMAIL*********************************/
do
{
    cout<<"\n\t\tEmail:";
    cin>>email;
    if(strlen(p.email)>30||strlen(p.email)<8)
    {
        cout<<"invalid:email is the range of 8 and 30.";
    }
}
while(strlen(p.email)>30||strlen(p.email)<8);
/*************************PROBLEM*******************************************/
e:
cout<<"\n\t\tProblem: ";
cin>>problem;
p.problem[0]=toupper(p.problem[0]);
if(strlen(p.problem)>15||strlen(p.problem)<3)
{
    cout<<"\n\tinvalid:";
    goto e;
}
else
{
    for(b=0; b<strlen(p.problem); b++)
    {
        if(isalpha(p.problem[b]))
        {
            valid=1;
        }
        else
        {
            valid=0;
            break;
        }
    }
    if(!valid)
    {
        cout<<"\n\t\tproblem contain invslid character.";
        goto e;
    }
}
/*********************************************prescription doctor**********************/
f:
cout<<"\n\t\t\tprescribed doctor:";
cin>>p.doctor_name;
p.doctor_name[0]=toupper(p.doctor_name[0]);
if(strlen(p.doctor_name)>30||strlen(p.doctor_name)<3)
{
    cout<<"\n\t invalid:doctor name should in the range of 3 and 30.";
    goto f;
}
else
{
    for(b=0; b<strlen(p.doctor_name); b++)
    {
        if(isalpha(p.doctor_name[b]))
        {
            valid=1;
        }
        else
        {
            valid=0;
            break;
        }
    }
    if(!invalid)
    {
        cout<<"\n\t\tdoctor name contain invalid character.";
        goto f;
    }

    /*fprintf(ek,"fbdjsnackml;,");*/
    cout<<p.first_name<<p.last_name<<p.gender<<p.age<<p.address<<p.contact_no<<p.email<<p.problem;
    cout<<"\n\n\t\t\t...information record successful...";
    fclose(ek)
sd:
    getch();
    cout<<"\n\n\t\t\tDo you want to add more(Y/N)?";
    cin>>ans;
    if(toupper(ans)=='y')
    {
        add_rec();
    }
    else if(toupper(ans)=='n')
    {
        cout<<"\n\n\t\tThank you!!";
        getch();
        main_manu();
    }
    else
    {
        cout<<"\n\n\t\tinvalid input";
        goto sd;
    }
}
/**********************************VIEW RECORD*******************/
void func_list()
{
    int row;
    system("cls");
    title();
    FILE();
    ek=fopen("record2.dat","r");
    cout<<"\n\n\t\t\t|||||||||||||||||list patients record***************\n";
        gotoxy(1,15);
    cout<<"full name";
    gotoxy(20,15);
    cout<<"gender";
    gotoxy(32,15);
    cout<<"age";
    gotoxy(37,15);
    cout<<"address";
    gotoxy(49,15);
    cout<<"contact no";
    gotoxy(64,15);
    cout<<"email";
    gotoxy(88,15);
    cout<<"problem";
    gotoxy(98,15);
    cout<<"prescribed doctor";
    gotoxy(20,15);
    cout<<"======================================================";
    row=17;
    while(fstream(ek,p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem))
    {
        gotoxy(1,row);
        cout<<p.first_name,p.last_name;
        gotoxy(20,row);
        cout<<p.gender;
        gotoxy(32,row);
        cout<<p.age;
        gotoxy(37,row);
        cout<<p.address;
        gotoxy(49,row);
        cout<<p.contact_no;
        gotoxy(64,row);
        cout<<p.email;
        gotoxy(88,row);
        cout<<p.doctor_name;
        row++;
    }
    fclose(ek);
    getch();
    main_manu();
}
void search_rec()
{
    char name[20]
    system("cls");
    title();
    FILE *ek;
    ek=fopen("record2.dat","r");
    cout<<"\n\n\t\t\t||||||||||||||||search patient record|||||||||||||\n";
    gotoxy(12,8);
    cout<<"\nenter patient name to be viewed:";
    cin>>name;
    fflush(stdin);
    name[0]=toupper(name[0]);
    while(fstream(ek,"/n",p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.email,p.problem,p.doctor_name))
    {
        if(strcmp(p.first_name,name)==0)
        {
            gotoxy(1,15);
            cout<<"full name";
            gotoxy(25,15);
            cout<<"gender";
            gotoxy(32,15);
            cout<<"age";
            gotoxy(37,15);
            cout<<"address";
            gotoxy(52,15);
            cout<<"contact no";
            gotoxy(64,15);
            cout<<"email";
            gotoxy(80,15);
            cout<<"problem";
            gotoxy(95,15);
            cout<<"prescribed doctor";
            gotoxy(20,15);
            cout<<"======================================================";
            gotoxy(1,18);
            cout<<p.first_name<<endl<<p.last_name;
            gotoxy(25,18);
            cout<<p.gender;
            gotoxy(32,18);
            cout<<p.age;
            gotoxy(37,18);
            p.address;
            gotoxy(52,18);
            cout<<p.contact_no;
            gotoxy(64,18);
            cout<<p.email;
            gotoxy(80,18);
            cout<<p.problem;
            gotoxy(95,18);
            cout<<p.doctor_name;
            cout<<"\n";
            break;
        }
    }
    if(strcmp(p.first_name,name)!=0){
        gotoxy(5,10);
        cout<<"record not found";
        getch();
    }
    fclose(ek);
    l:
        getch();
        cout<<"\n\n\t\t\tdo you want to view more(y/n)";
        cin>>&ans;
        if(toupper(ans)=='y'){
            search_rec();
        }
        else if(toupper(ans)=='n'){
            cout<<"\n\t\t Thank you!!";
            getch();
            main_manu();
        }
        else{
            cout<<"\n\ninvalid input.\n";
            goto l:
        }
}
void edit_rec(){
    FILE *ek,*ft;
    int i,b,valid=0;
    char ch;
    char name[20];
    system("cls");
    title();
    ft=fopen("temp2.dat","w+");
    ek*fopen("record2.dat","r");
    if(ek==NULL){
        cout<<"\n\tcan not open the file.";
        getch();
        main_manu();
    }
    cout<<"\n\n\t\t\t|||||||||||||||||edit patient record|||||||||||||||||||";
    gotoxy(12,13);
    cout<<"enter the first name of the patient:\n";
    cin>>name;
    ffslush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12,15);
    if(ft==NULL){
        cout<<"\n can not open the file.";
        getch();
        main_manu();
    }
    while(fstream(ek,p.first_name,p.last_name,&p.gender,&p.age,p.address,p.contact_no,p.email,p.problem,p.doctor_name)){
        if(strcmp(p.first_name,name)==0){
            valid=1;
            gotoxy(25,17);
            cout<<"existing record...\n";
            gotoxy(10,19);
            cout<<"\n"<<p.first_name<<"\t"<<p.last_name<<"\t"<<p.gender<<"\t"<<p.age<<"\t"<<p.address<<"\t"<<p.contact_no<<"\t"<<p.email<<"\t"<<p.problem<<"\t"<<p.doctor_name;
            gotoxy(12,22);
            cout<<"enter new first name:\n";
            cin>>p.first_name;
            gotoxy(12,24);
            cout<<"enter new last name: \n";
            cin>>p.last_name;
            gotoxy(12,26);
            cout<<"enter gender\n";
            cin>>&p.gender;
            p.gender=toupper(p.gender);
            gotoxy(12,28);
            cout<<"enter age:\n";
            cin>>&p.age;
            gotoxy(12,30);
            cout<<"enter address\n";
            cin>>p.address;
            p.address[0]=toupper(p.address[0]);
            gotoxy(12,32);
            cout<<"enter contact no.:\n";
            cin>>p.contact_no;
            gotoxy(12,34);
            cout<<"enter new email:\n";
            cin>>p.email;
            gotoxy(12,36);
            cout<<"enter problem\n";
            cin>>p.problem;
            p.problem[0]=toupper(p.problem[0]);
            gotoxy(12,38);
            cout<<"enter doctor:\n";
            cin>>p.doctor_name;
            p.doctor_name[0]=toupper(p.doctor_name[0]);
            cout<<"\npress \'u\' for update operation.";
            ch=getch();
            if(ch=='u'||ch=='U'){
                fprintf(ft,"fgfhgjnk",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor_name);
                cout<<"\n\n\n\t\t\tpatient record updated successfully.\n";
            }
        }
        else{
            fprintf(ft,"gtjnkmsvd",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor_name);
        }
    }
    if(!valid){
        cout<<"\n\n\t\tno record found.";
    }
    fclose(ft);
    fclose(ek);
    remove("record2.dat");
    rename("temp2.dat","recoed2.dat");
    getch();
    main_manu();
}
void dlt_rec(){
char name[20];
int found=0;
system("cls");
title();
FILE *ek. *ft;
ft=fopen("temp_file2.dat",w++);
ek=fopen("\n\n\t\t\t||||||||||||||||||delete patients record|||||||||||\n");
gotoxy(12,8);
cout<<"inter patient name to delete:\n";
gotoxy(stdin);
gets(name);
name[0]=toupper(name[0]);
while(fscanf(ek,"iijjhjkl;\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor_name)){
    if(strcmp(p.first_name,name)!=0)
        fprintf(ft,"vuiohpj\n",p.first_name,p.last_name,p.gender,p.age,p.address,p.contact_no,p.email,p.problem,p.doctor_name);
        else{
            cout<<p.first_name<<"\t"<<p.last_name<<"\t"<<p.gender<<"\t"<<p.age<<"\t"<<p.address<<"\t"<<p.contact_no<<"\t"<<p.email<<"\t"<<p.problem<<"\t"<<p.prb
           found=1;
        }
}//while loop ends
if(found==0){
    cout<<"\n\n\t\t\t record not found.";
    getch();
    main_manu();
}
else{
    fclose(ek);
    fclose(ft);
    remove("record2.dat");
    rename("temp_file2.dat","record2.dat");
    cout<<"\n\n\t\t\t record deleted successfully.";
    getch();
    main_manu();
}
}
