#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include<process.h>
#include<fstream.h>
#include<iomanip.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void MAIN();
#include<student.cpp>

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////CLASSES & STRUCTURES/////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//CLASS OF STUDENT DEPARTMENT//
class student_department:public student
{
public:
  void Add_New_Record_Of_Student();
  void Modify_Record_Of_Student();
  void Delete_Record_Of_Student();
  void Search_Record_Of_Student();
};

/****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
//////////////////////STUDENT DEPARTMENT CLASS FUNCTIONS//////////////////////
//////////////////////////////////////////////////////////////////////////////

//FUNCTION TO ADD NEW RECORD OF STUDENT(CLASS STUDENT_DEPARTMENT)
void student_department::Add_New_Record_Of_Student()
{
  char ch;
  char tname[50],tsection,thouse[20],tm_name[50],tf_name[50];
  char tprofession[50],te_mail[50];
  char tbloodgroup[5],tmode_of_transport[20];
  int tclas;
  long tadmission_no;
  char tphoneno[11],tmobileno[11];
  DATEE tdob;
  ADDRESS tadd;
  RELATIVE tr;
  do
  {
    int found=0,valid=0;
    int tc;
    long td;
    char t[50],t1[50];
    clrscr();
    gotoxy(60,1);clreol();
    cprintf("[Enter <0> to return]");
    gotoxy(15,25);clreol();
    cprintf("(Enter admission no. of the student)");
    gotoxy(3,2);clreol();
    cprintf("Admission Number:");
    gets(t);
    td=atoi(t);
    tadmission_no=td;
    if (tadmission_no==0)
      return;
    if(Check_Student(tadmission_no))
    {
      found=1;
      gotoxy(19,4);clreol();
      cout<<Student_Name(tadmission_no);
      gotoxy(19,5);clreol();
      cout<<Student_Class(tadmission_no)<<"-"<<Student_Section(tadmission_no);
      gotoxy(5,4);
      cout<<"Student Name: ";
      gotoxy(5,5);
      cout<<"Class       : ";
      gotoxy(5,10);clreol();
      cout<<"Student already exist......";
      gotoxy(5,11);clreol();
      cout<<"Press any key to exit......";
      getche();
      return;
    }
    else
    {
      gotoxy(3,3);clreol();
      cprintf("Student Name             : ");
      gotoxy(3,4);clreol();
      cprintf("Class (eg:1-C)           : ");
      gotoxy(3,5);clreol();
      cprintf("Date of Birth(dd/mm/yyyy): ");
      gotoxy(3,6);clreol();
      cprintf("Father's Name            : ");
      gotoxy(3,7);clreol();
      cprintf("Mother's Name            : ");
      gotoxy(3,8);clreol();
      cprintf("Profession               : ");
      gotoxy(3,9);clreol();
      cprintf("House                    : ");
      gotoxy(3,10);clreol();
      cprintf("Address:- Line 1         : ");
      gotoxy(3,11);clreol();
      cprintf("          Line 2         : ");
      gotoxy(3,12);clreol();
      cprintf("          Line 3         : ");
      gotoxy(3,13);clreol();
      cprintf("          City           : ");
      gotoxy(3,14);clreol();
      cprintf("          State          : ");
      gotoxy(3,15);clreol();
      cprintf("          Pincode        : ");
      gotoxy(3,16);clreol();
      cprintf("Phone Number             : ");
      gotoxy(3,17);clreol();
      cprintf("Mobile Number            : ");
      gotoxy(3,18);clreol();
      cprintf("E-mail                   : ");
      gotoxy(3,19);clreol();
      cprintf("Blood Group              : ");
      gotoxy(3,20);clreol();
      cprintf("Mode of Transport        : ");
      gotoxy(3,21);clreol();
      cprintf("Name of Brother/Sister           : ");
      gotoxy(3,22);clreol();
      cprintf("Class of Brother/Sister (eg:1-C) : ");
      gotoxy(3,23);clreol();
      cprintf("House of Brother/Sister          : ");

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter the name of the student)");
	gotoxy(30,3);clreol();
	gets(tname);
	strupr(tname);
	tc=atoi(tname);
	if (tname[0]=='0')
	  return;
	if (strlen(tname)<1||strlen(tname)>50||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..50)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter class of student)");
	gotoxy(30,4);clreol();
	gets(t);
	tc=atoi(t);
	tclas=tc;
	if (t[0]=='0')
	  return;
	if (tclas<1||tclas>12)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter section of student)");
	gotoxy(33,4);clreol();
	cin>>tsection;
	tsection=toupper(tsection);
	if (tsection=='0')
	  return;
	if (isalpha(tsection)==0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter the date of date of birth of student)");
	gotoxy(30,5);clreol();
	gets(t);
	tc=atoi(t);
	tdob.date=tc;
	if (t[0]=='0')
	  return;
	if (tdob.date<1||tdob.date>31)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter the month of date of birth of student)");
	gotoxy(33,5);clreol();
	gets(t);
	tc=atoi(t);
	tdob.month=tc;
	if (t[0]=='0')
	  return;
	if (tdob.month<1||tdob.month>12)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter the year of date of birth of student)");
	gotoxy(36,5);clreol();
	gets(t);
	td=atoi(t);
	tdob.year=td;
	if (t[0]=='0')
	  return;
	if (tdob.year<1990||tdob.year>2013)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter father's name of student)");
	gotoxy(30,6);clreol();
	gets(tf_name);
	strupr(tf_name);
	tc=atoi(tf_name);
	if (tf_name[0]=='0')
	  return;
	if (strlen(tf_name)<1||strlen(tf_name)>50||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..50)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter mother's name of student)");
	gotoxy(30,7);clreol();
	gets(tm_name);
	strupr(tm_name);
	tc=atoi(tm_name);
	if (tm_name[0]=='0')
	  return;
	if (strlen(tm_name)<1||strlen(tm_name)>50||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..50)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter profession of student's father or mother)");
	gotoxy(30,8);clreol();
	gets(tprofession);
	strupr(tprofession);
	tc=atoi(tprofession);
	if (tprofession[0]=='0')
	  return;
	if (strlen(tprofession)<1||strlen(tprofession)>50||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..50)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter house of student)");
	gotoxy(30,9);clreol();
	gets(thouse);
	strupr(thouse);
	tc=atoi(thouse);
	if (thouse[0]=='0')
	  return;
	if (strlen(thouse)<1||strlen(thouse)>20||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..20)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter line 1 of student's address)");
	gotoxy(30,10);clreol();
	gets(tadd.line1);
	strupr(tadd.line1);
	tc=atoi(tadd.line1);
	if (tadd.line1[0]=='0')
	  return;
	if (strlen(tadd.line1)<1||strlen(tadd.line1)>50||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..50)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter line 2 of student's address)");
	gotoxy(30,11);clreol();
	gets(tadd.line2);
	strupr(tadd.line2);
	tc=atoi(tadd.line2);
	if (tadd.line2[0]=='0')
	  return;
	if (strlen(tadd.line2)<1||strlen(tadd.line2)>50||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..50)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter line 3 of student's address)");
	gotoxy(30,12);clreol();
	gets(tadd.line3);
	strupr(tadd.line3);
	tc=atoi(tadd.line3);
	if (tadd.line3[0]=='0')
	  return;
	if (strlen(tadd.line3)<1||strlen(tadd.line3)>50||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..50)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter city of student)");
	gotoxy(30,13);clreol();
	gets(tadd.city);
	strupr(tadd.city);
	tc=atoi(tadd.city);
	if (tadd.city[0]=='0')
	  return;
	if (strlen(tadd.city)<1||strlen(tadd.city)>20||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..20)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter state of student)");
	gotoxy(30,14);clreol();
	gets(tadd.state);
	strupr(tadd.state);
	tc=atoi(tadd.state);
	if (tadd.state[0]=='0')
	  return;
	if (strlen(tadd.state)<1||strlen(tadd.state)>20||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..20)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter pincode of student)");
	gotoxy(30,15);clreol();
	gets(t);
	tc=atoi(t);
	strcpy(tadd.pincode,t);
	if (t[0]=='0')
	  return;
	if (tc==0||(strlen(t)<6||strlen(t)>7))
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter phone number of student)");
	gotoxy(30,16);clreol();
	gets(t);
	tc=atoi(t);
	strcpy(tphoneno,t);
	if (t[0]=='0')
	  return;
	if (tc==0||(strlen(t)<10||strlen(t)>11))
	{
	  valid=0;
	  gotoxy(15,25);
	  clreol();
	  cprintf("Enter correctly......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter mobile number of student)");
	gotoxy(30,17);clreol();
	gets(t);
	tc=atoi(t);
	strcpy(tmobileno,t);
	if (t[0]=='0')
	  return;
	if (tc==0||(strlen(t)<7||strlen(t)>12))
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter E-mail address of student)");
	gotoxy(30,18);clreol();
	gets(te_mail);
	tc=atoi(te_mail);
	if (te_mail[0]=='0')
	  return;
	if (strlen(te_mail)<1||strlen(te_mail)>50||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..50)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter blood group of student)");
	gotoxy(30,19);clreol();
	gets(tbloodgroup);
	strupr(tbloodgroup);
	tc=atoi(tbloodgroup);
	if (tbloodgroup[0]=='0')
	  return;
	if (strlen(tbloodgroup)<1||strlen(tbloodgroup)>4||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..4)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(15,25);clreol();
	cprintf("(Enter mode of transport of student)");
	gotoxy(30,20);clreol();
	gets(tmode_of_transport);
	strupr(tmode_of_transport);
	tc=atoi(tmode_of_transport);
	if (tmode_of_transport[0]=='0')
	  return;
	if (strlen(tmode_of_transport)<1||strlen(tmode_of_transport)>20||tc!=0)
	{
	  valid=0;
	  gotoxy(15,25);clreol();
	  cprintf("Enter correctly (Range: 1..20)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(5,25);clreol();
	cprintf("(Enter the name of the student's brother/sister (if not enter *))");
	gotoxy(39,21);clreol();
	gets(tr.rname);
	strupr(tr.rname);
	tc=atoi(tr.rname);
	if (tr.rname[0]=='0')
	  return;
	if (strlen(tr.rname)<1||strlen(tr.rname)>50||tc!=0)
	{
	  valid=0;
	  gotoxy(5,25);clreol();
	  cprintf("Enter correctly (Range: 1..50)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(5,25);clreol();
	cprintf("(Enter class of student's brother/sister (if not enter -1))");
	gotoxy(39,22);clreol();
	gets(t);
	tc=atoi(t);
	tr.rclass=tc;
	if (t[0]=='0')
	  return;
	if ((tr.rclass<-1||tr.rclass>12)||tc==0)
	{
	  valid=0;
	  gotoxy(5,25);clreol();
	  cprintf("Enter correctly......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(5,25);clreol();
	cprintf("(Enter section of student's brother/sister (if not enter *))");
	gotoxy(42,22);clreol();
	cin>>tr.rsection;
	tr.rsection=toupper(tr.rsection);
	if (tr.rsection=='0')
	  return;
	if (isalpha(tr.rsection)==0&&tr.rsection!='*')
	{
	  valid=0;
	  gotoxy(5,25);clreol();
	  cprintf("Enter correctly (Range: 1)......");
	  getch();
	}
      }

      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(5,25);clreol();
	cprintf("(Enter house of student's brother/sister (if not enter *))");
	gotoxy(39,23);clreol();
	gets(tr.rhouse);
	strupr(tr.rhouse);
	tc=atoi(tr.rhouse);
	if (tr.rhouse[0]=='0')
	  return;
	if (strlen(tr.rhouse)<1||strlen(tr.rhouse)>20||tc!=0)
	{
	  valid=0;
	  gotoxy(5,25);clreol();
	  cprintf("Enter correctly (Range: 1..20)......");
	  getch();
	}
      }

      if (!strcmpi(tr.rname,"*"))
	strcpy(tr.rname,NULL);
      if (tr.rclass==-1)
	tr.rclass=NULL;
      if (tr.rsection=='*')
	tr.rsection=NULL;
      if (!strcmpi(tr.rhouse,"*"))
	strcpy(tr.rhouse,NULL);

      do
      {
	gotoxy(5,25);
	clreol();
	cprintf("Do you want to save (Y/N):");
	ch=getche();
	ch=toupper(ch);
      }while(ch!='Y'&&ch!='N');

      if (ch=='Y')
      {
	Add_New_Student(tname,tsection,thouse,tm_name,tf_name,tprofession,te_mail,tbloodgroup,tmode_of_transport,tclas,tadmission_no,tphoneno,tmobileno,tdob,tadd,tr);
      }
      else
	return;

      gotoxy(5,25);
      clreol();
      cout<<"Record saved......";
      getch();

      do
      {
       gotoxy(5,25);
       clreol();
       cprintf("Do you want to add more (Y/N):");
       ch=getche();
       ch=toupper(ch);
      }while (ch!='Y'&&ch!='N');
    }
  }while(ch=='Y');
}

//FUNCTION TO MODIFY RECORD OF STUDENT(CLASS STUDENT_DEPARTMENT)  COMPLETE
void student_department::Modify_Record_Of_Student()
{
  char tname[50],tsection,thouse[20],tm_name[50],tf_name[50];
  char tprofession[50],te_mail[50];
  char tbloodgroup[5],tmode_of_transport[20];
  int tclas;
  long tadmission_no;
  char tphoneno[10],tmobileno[10];
  DATEE tdob;
  ADDRESS tadd;
  RELATIVE tr;
  student S;
  int found=0,valid=0,tc;
  long td;
  long double te;
  char t[50],t1[50];
  char t1code[20],ch;
  long t2code=0;
  do
  {
    valid=1;
    while(1)
    {
      clrscr();
      gotoxy(60,1);
      cprintf("[Enter <0> to return]");
      gotoxy(5,3);
      cout<<"(Press <ENTER> for help)";
      gotoxy(3,2);
      cout<<"Enter Admission Number of the Student to be modified:";
      gets(t1code);
      if (t1code[0]=='0')
	return;
      if (strlen(t1code)==0)
	S.Show_List_Of_Student();
      else
	break;
    }
    t2code=atoi(t1code);
    tadmission_no=t2code;
    if ((tadmission_no==0)||(tadmission_no!=0&&!Check_Student(tadmission_no)))
    {
      if (tadmission_no==0)
      {
	valid=0;
	gotoxy(5,10);
	cout<<"Enter correctly......";
	gotoxy(5,12);
	cout<<"Press <ESC> to exit or any other key to continue......";
	ch=getch();
	if (ch==27)
	  return;
      }
      else
      {
	valid=0;
	gotoxy(5,10);
	cout<<"Record not found......";
	gotoxy(5,12);
	cout<<"Press <ESC> to exit or any other key to continue......";
	ch=getch();
	if (ch==27)
	  return;
      }
    }
  }while(!valid);
  clrscr();
  gotoxy(60,1);
  cprintf("[Enter <0> to return]");
  Display_Student(tadmission_no);
  do
  {
    gotoxy(5,23);clreol();
    cout<<"Do you want to modify this record (y/n):";
    ch=getche();
    ch=toupper(ch);
    if (ch=='0')
      return;
  }while(ch!='Y'&&ch!='N');
  if (ch=='N')
    return;
  clrscr();
  gotoxy(3,3);clreol();
  cout<<"Student Name             : ";
  gotoxy(3,4);clreol();
  cout<<"Class (eg:1-C)           : ";
  gotoxy(3,5);clreol();
  cout<<"Date of Birth(dd/mm/yyyy): ";
  gotoxy(3,6);clreol();
  cout<<"Father's Name            : ";
  gotoxy(3,7);clreol();
  cout<<"Mother's Name            : ";
  gotoxy(3,8);clreol();
  cout<<"Profession               : ";
  gotoxy(3,9);clreol();
  cout<<"House                    : ";
  gotoxy(3,10);clreol();
  cout<<"Address:- Line 1         : ";
  gotoxy(3,11);clreol();
  cout<<"          Line 2         : ";
  gotoxy(3,12);clreol();
  cout<<"          Line 3         : ";
  gotoxy(3,13);clreol();
  cout<<"          City           : ";
  gotoxy(3,14);clreol();
  cout<<"          State          : ";
  gotoxy(3,15);clreol();
  cout<<"          Pincode        : ";
  gotoxy(3,16);clreol();
  cout<<"Phone Number             : ";
  gotoxy(3,17);clreol();
  cout<<"Mobile Number            : ";
  gotoxy(3,18);clreol();
  cout<<"E-mail                   : ";
  gotoxy(3,19);clreol();
  cout<<"Blood Group              : ";
  gotoxy(3,20);clreol();
  cout<<"Mode of Transport        : ";
  gotoxy(3,21);clreol();
  cout<<"Name of Brother/Sister           : ";
  gotoxy(3,22);clreol();
  cout<<"Class of Brother/Sister (eg:1-C) : ";
  gotoxy(3,23);clreol();
  cout<<"House of Brother/Sister          : ";

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter the name of the student)");
    gotoxy(30,3);clreol();
    gets(tname);
    strupr(tname);
    tc=atoi(tname);
    if (tname[0]=='0')
      return;
    if (strlen(tname)<1||strlen(tname)>50||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter class of student)");
    gotoxy(30,4);clreol();
    gets(t);
    tc=atoi(t);
    tclas=tc;
    if (t[0]=='0')
      return;
    if (tclas<1||tclas>12)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter section of student)");
    gotoxy(33,4);clreol();
    cin>>tsection;
    tsection=toupper(tsection);
    if (tsection=='0')
      return;
    if (isalpha(tsection)==0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter the date of date of birth of student)");
    gotoxy(30,5);clreol();
    gets(t);
    tc=atoi(t);
    tdob.date=tc;
    if (t[0]=='0')
      return;
    if (tdob.date<1||tdob.date>31)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter the month of date of birth of student)");
    gotoxy(33,5);clreol();
    gets(t);
    tc=atoi(t);
    tdob.month=tc;
    if (t[0]=='0')
      return;
    if (tdob.month<1||tdob.month>12)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter the year of date of birth of student)");
    gotoxy(36,5);clreol();
    gets(t);
    td=atoi(t);
    tdob.year=td;
    if (t[0]=='0')
      return;
    if (tdob.year<1990||tdob.year>2013)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter father's name of student)");
    gotoxy(30,6);clreol();
    gets(tf_name);
    strupr(tf_name);
    tc=atoi(tf_name);
    if (tf_name[0]=='0')
      return;
    if (strlen(tf_name)<1||strlen(tf_name)>50||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter mother's name of student)");
    gotoxy(30,7);clreol();
    gets(tm_name);
    strupr(tm_name);
    tc=atoi(tm_name);
    if (tm_name[0]=='0')
      return;
    if (strlen(tm_name)<1||strlen(tm_name)>50||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter profession of student's father or mother)");
    gotoxy(30,8);clreol();
    gets(tprofession);
    strupr(tprofession);
    tc=atoi(tprofession);
    if (tprofession[0]=='0')
      return;
    if (strlen(tprofession)<1||strlen(tprofession)>50||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter house of student)");
    gotoxy(30,9);clreol();
    gets(thouse);
    strupr(thouse);
    tc=atoi(thouse);
    if (thouse[0]=='0')
      return;
    if (strlen(thouse)<1||strlen(thouse)>20||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..20)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter line 1 of student's address)");
    gotoxy(30,10);clreol();
    gets(tadd.line1);
    strupr(tadd.line1);
    tc=atoi(tadd.line1);
    if (tadd.line1[0]=='0')
      return;
    if (strlen(tadd.line1)<1||strlen(tadd.line1)>50||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter line 2 of student's address)");
    gotoxy(30,11);clreol();
    gets(tadd.line2);
    strupr(tadd.line2);
    tc=atoi(tadd.line2);
    if (tadd.line2[0]=='0')
      return;
    if (strlen(tadd.line2)<1||strlen(tadd.line2)>50||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter line 3 of student's address)");
    gotoxy(30,12);clreol();
    gets(tadd.line3);
    strupr(tadd.line3);
    tc=atoi(tadd.line3);
    if (tadd.line3[0]=='0')
      return;
    if (strlen(tadd.line3)<1||strlen(tadd.line3)>50||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter city of student)");
    gotoxy(30,13);clreol();
    gets(tadd.city);
    strupr(tadd.city);
    tc=atoi(tadd.city);
    if (tadd.city[0]=='0')
      return;
    if (strlen(tadd.city)<1||strlen(tadd.city)>20||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..20)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter state of student)");
    gotoxy(30,14);clreol();
    gets(tadd.state);
    strupr(tadd.state);
    tc=atoi(tadd.state);
    if (tadd.state[0]=='0')
      return;
    if (strlen(tadd.state)<1||strlen(tadd.state)>20||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..20)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter pincode of student)");
    gotoxy(30,15);clreol();
    gets(t);
    tc=atoi(t);
    strcpy(tadd.pincode,t);
    if (t[0]=='0')
      return;
    if (tc==0||(strlen(t)<6||strlen(t)>7))
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter phone number of student)");
    gotoxy(30,16);clreol();
    gets(t);
    tc=atoi(t);
    strcpy(tphoneno,t);
    if (t[0]=='0')
      return;
    if (tc==0||(strlen(t)<10||strlen(t)>11))
    {
      valid=0;
      gotoxy(15,25);
      clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter mobile number of student)");
    gotoxy(30,17);clreol();
    gets(t);
    tc=atoi(t);
    strcpy(tmobileno,t);
    if (t[0]=='0')
      return;
    if (tc==0||(strlen(t)<7||strlen(t)>12))
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter E-mail address of student)");
    gotoxy(30,18);clreol();
    gets(te_mail);
    tc=atoi(te_mail);
    if (te_mail[0]=='0')
      return;
    if (strlen(te_mail)<1||strlen(te_mail)>50||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter blood group of student)");
    gotoxy(30,19);clreol();
    gets(tbloodgroup);
    strupr(tbloodgroup);
    tc=atoi(tbloodgroup);
    if (tbloodgroup[0]=='0')
      return;
    if (strlen(tbloodgroup)<1||strlen(tbloodgroup)>4||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..4)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter mode of transport of student)");
    gotoxy(30,20);clreol();
    gets(tmode_of_transport);
    strupr(tmode_of_transport);
    tc=atoi(tmode_of_transport);
    if (tmode_of_transport[0]=='0')
      return;
    if (strlen(tmode_of_transport)<1||strlen(tmode_of_transport)>20||tc!=0)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..20)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(5,25);clreol();
    cprintf("(Enter the name of the student's brother/sister (if not enter *))");
    gotoxy(39,21);clreol();
    gets(tr.rname);
    strupr(tr.rname);
    tc=atoi(tr.rname);
    if (tr.rname[0]=='0')
      return;
    if (strlen(tr.rname)<1||strlen(tr.rname)>50||tc!=0)
    {
      valid=0;
      gotoxy(5,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(5,25);clreol();
    cprintf("(Enter class of student's brother/sister (if not enter -1))");
    gotoxy(39,22);clreol();
    gets(t);
    tc=atoi(t);
    tr.rclass=tc;
    if (t[0]=='0')
      return;
    if ((tr.rclass<-1||tr.rclass>12)||tc==0)
    {
      valid=0;
      gotoxy(5,25);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(5,25);clreol();
    cprintf("(Enter section of student's brother/sister (if not enter *))");
    gotoxy(42,22);clreol();
    cin>>tr.rsection;
    tr.rsection=toupper(tr.rsection);
    if (tr.rsection=='0')
      return;
    if (isalpha(tr.rsection)==0&&tr.rsection!='*')
    {
      valid=0;
      gotoxy(5,25);clreol();
      cprintf("Enter correctly (Range: 1)......");
      getch();
    }
  }

  valid=0;
  while (!valid&&!found)
  {
    valid=1;
    gotoxy(5,25);clreol();
    cprintf("(Enter house of student's brother/sister (if not enter *))");
    gotoxy(39,23);clreol();
    gets(tr.rhouse);
    strupr(tr.rhouse);
    tc=atoi(tr.rhouse);
    if (tr.rhouse[0]=='0')
      return;
    if (strlen(tr.rhouse)<1||strlen(tr.rhouse)>20||tc!=0)
    {
      valid=0;
      gotoxy(5,25);clreol();
      cprintf("Enter correctly (Range: 1..20)......");
      getch();
    }
  }

  if (!strcmpi(tr.rname,"*"))
    strcpy(tr.rname,NULL);
  if (tr.rclass==-1)
    tr.rclass=NULL;
  if (tr.rsection=='*')
    tr.rsection=NULL;
  if (!strcmpi(tr.rhouse,"*"))
    strcpy(tr.rhouse,NULL);

  do
  {
    gotoxy(5,25);clreol();
    cout<<"Do you want to save changes (y/n):";
    ch=getche();
    ch=toupper(ch);
    if (ch=='0')
      return;
  }while(ch!='Y'&&ch!='N');
  if (ch=='N')
    return;
  Modify_Student(tname,tsection,thouse,tm_name,tf_name,tprofession,te_mail,tbloodgroup,tmode_of_transport,tclas,tadmission_no,tphoneno,tmobileno,tdob,tadd,tr);
  gotoxy(5,25);clreol();
  cout<<"Record Modified......";
  getch();
}

//FUNCTION TO DELETE RECORD OF STUDENT(CLASS STUDENT_DEPARTMENT)  COMPLETE
void student_department::Delete_Record_Of_Student()
{
  student S;
  char t1code[15],ch;
  long t2code=0,tadmission_no;
  int valid;
  do
  {
    valid=1;
    while (1)
    {
      clrscr();
      gotoxy(60,1);
      cprintf("[Enter <0> to return]");
      gotoxy(5,3);
      cout<<"(Press <ENTER> for help)";
      gotoxy(3,2);
      cout<<"Enter Admission Number of the Student to be deleted:";
      gets(t1code);
      if (t1code[0]=='0')
	return;
      if (strlen(t1code)==0)
	S.Show_List_Of_Student();
      else
	break;
    }
    t2code=atoi(t1code);
    tadmission_no=t2code;
    if ((tadmission_no==0)||(tadmission_no!=0&&!Check_Student(tadmission_no)))
    {
      if (tadmission_no==0)
      {
	valid=0;
	gotoxy(5,10);
	cout<<"Enter correctly......";
	gotoxy(5,12);
	cout<<"Press <ESC> to exit or any other key to continue......";
	ch=getch();
	if (ch==27)
	  return;
      }
      else
      {
	valid=0;
	gotoxy(5,10);
	cout<<"Record not found......";
	gotoxy(5,12);
	cout<<"Press <ESC> to exit or any other key to continue......";
	ch=getch();
	if (ch==27)
	  return;
      }
    }
  }while(!valid);
  clrscr();
  gotoxy(60,1);
  cprintf("[Enter <0> to return]");
  Display_Student(tadmission_no);

  do
  {
    gotoxy(5,23);clreol();
    cout<<"Do you want to delete this record (y/n):";
    ch=getche();
    ch=toupper(ch);
    if (ch=='0')
      return;
  }while(ch!='Y'&&ch!='N');

  if (ch=='N')
    return;
  int t=Had_Student_Issue_Book(tadmission_no);
  if (t!=0)
  {
    gotoxy(5,23);clreol();
    cout<<"Record cannot be deleted. Student had issued a book.";
    getch();
    return;
  }
  Delete_Student(tadmission_no);
  gotoxy(5,23);clreol();
  cout<<"Record Deleted......";
  getch();
}

//FUNCTION TO SEARCH RECORD OF STUDENT(CLASS STUDENT_DEPARTMENT)  COMPLETE
void student_department::Search_Record_Of_Student()
{
 int ch;
 clrscr();
 while(1)
 {
   clrscr();
   int j=strlen(SNAME),i=80-j,l=0,row=i/2;
   gotoxy(row,6);
   cprintf("%s",SNAME);
   while(l<j)
   {
     gotoxy(row+l,7);
     cprintf("~");
     l++;
   }
   gotoxy(31,8);
   cout<<"STUDENT DEPARTMENT";
   gotoxy(28,10);
   cout<<"1.View Class Record.";
   gotoxy(28,11);
   cout<<"2.View Student Record.";
   gotoxy(28,12);
   cout<<"3.Back to previous menu.";
   gotoxy(28,14);
   cout<<"Enter your choice:";
   ch=getche();
   if(ch=='1')
   {
     student S;
     S.Show_List_Of_Student();
   }
   else if(ch=='2')
   {
     student S;
     S.View_Student_Record();
   }
   else if(ch=='3')
     break;
 }
}

/****************************************************************************/

void STUDENT_DEPARTMENT()
{
 int ch;
 clrscr();
 while(1)
 {
   clrscr();
   int j=strlen(SNAME),i=80-j,l=0,row=i/2;
   gotoxy(row,6);
   cprintf("%s",SNAME);
   while(l<j)
   {
     gotoxy(row+l,7);
     cprintf("~");
     l++;
   }
   gotoxy(31,8);
   cout<<"STUDENT DEPARTMENT";
   gotoxy(24,10);
   cout<<"1.Make New Entry Of Student.";
   gotoxy(24,11);
   cout<<"2.Modify Record Of Student.";
   gotoxy(24,12);
   cout<<"3.Search/View Record Of Student.";
   gotoxy(24,13);
   cout<<"4.Delete Record Of Student.";
   gotoxy(24,14);
   cout<<"5.Back to main menu.";
   gotoxy(24,16);
   cout<<"Enter your choice:";
   ch=getche();
   if(ch=='1')
   {
     student_department S;
     S.Add_New_Record_Of_Student();
   }
   else if(ch=='2')
   {
     student_department S;
     S.Modify_Record_Of_Student();
   }
   else if(ch=='3')
   {
     student_department S;
     S.Search_Record_Of_Student();
   }
   else if(ch=='4')
   {
     student_department S;
     S.Delete_Record_Of_Student();
   }
   else if(ch=='5')
     MAIN();
 }
}

/****************************************************************************/

//MAIN FUNCTION//
void MAIN()
{
 while(1)
 {
   school S;
   S.INTRODUCTION_1();
   S.INTRODUCTION_2();
   STUDENT_DEPARTMENT();
 }
}

/****************************************************************************/

void main()
{
MAIN();
}

/****************************************************************************/