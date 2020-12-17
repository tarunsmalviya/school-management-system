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

//CLASS OF LIBRARY DEPARTMENT//
class library_department:public book,public student
{
public:
  void Issue_Book();
  void Return_Book();
  void Add_New_Record_Of_Book();
  void Modify_Record_Of_Book();
  void Delete_Record_Of_Book();
};

/****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
///////////////////////LIBRARY DEPARTMENT CLASS FUNCTIONS/////////////////////
//////////////////////////////////////////////////////////////////////////////

//FUNCTION OF ISSUING BOOK(CLASS LIBRARY DEPARTMENT)
void library_department::Issue_Book()
{
  book B;
  student S;
  datee D;
  char t1code[50],ch;
  int t2code=0,tcode=0;
  long sadmno=0;
  int valid;
  DATEE cd;
  struct date d;
  getdate(&d);
  cd.date= d.da_day;
  cd.month= d.da_mon;
  cd.year=d.da_year;
  do
  {
    valid=1;
    while(1)
    {
      clrscr();
      gotoxy(5,3);
      cout<<"Date:"<<cd.date<<"/"<<cd.month<<"/"<<cd.year;
      gotoxy(60,1);
      cprintf("[Enter <0> to return]");
      gotoxy(5,5);
      cout<<"Enter Code or Name of the Book to be issued(Press <ENTER> for help):";
      gets(t1code);
      if (t1code[0]=='0')
	return;
      if (strlen(t1code)==0)
	B.Show_List_Of_Book();
      else
	break;
    }
    t2code=atoi(t1code);
    tcode=t2code;
    if ((tcode==0&&!Check_Book_Name(t1code))||(tcode!=0&&!Check_Book_Code(tcode)))
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
  }while(!valid);
  if (tcode==0)
    tcode=Book_Code_Of(t1code);
  if (!Give_No_Of_Copies_Available(tcode))
  {
    gotoxy(5,10);
    cout<<"Sorry! Book ("<<Book_Name(tcode)<<") is not available......";
    gotoxy(5,11);
    cout<<"Kindly issue any other Book......";
    gotoxy(5,12);
    cout<<"See list of books which are available......";
    getch();
    return;
  }
  do
  {
    valid=1;
    while(1)
    {
      clrscr();
      gotoxy(5,3);
      cout<<"Date:"<<cd.date<<"/"<<cd.month<<"/"<<cd.year;
      gotoxy(60,1);
      cprintf("[Enter <0> to return]");
      gotoxy(5,5);
      cout<<"Book Name:"<<Book_Name(tcode);
      gotoxy(5,7);
      cout<<"Enter Admission no. of Student(Press <ENTER> for help):";
      gets(t1code);
      if (t1code[0]=='0')
	return;
      if (strlen(t1code)==0)
	S.Show_List_Of_Student_For_Book();
      else
	break;
    }
    t2code=atoi(t1code);
    sadmno=(long)t2code;
    if (sadmno==0)
    {
      valid=0;
      gotoxy(5,25);
      cout<<"Enter Correctly......";
      getch();
    }
    if (!Check_Student(sadmno)&&valid)
    {
      valid=0;
      gotoxy(5,13);
      cout<<"Record not found......";
      gotoxy(5,14);
      cout<<"Press <ESC> to exit or any other key to continue......";
      ch=getch();
      if (ch==27)
	return;
    }
    if (Had_Student_Issue_Book(sadmno)!=0)
    {
      valid=0;
      gotoxy(5,13);
      cout<<"Student had already issued a book......";
      gotoxy(5,14);
      cout<<"Press <ESC> to exit or any other key to continue......";
      ch=getch();
      if (ch==27)
	return;
    }
  }while(!valid);
  int tcopies,tavail;
  tcopies=No_Of_Copies_Of_Book(tcode);
  tavail=Give_No_Of_Copies_Available(tcode)-1;
  Update_Book_Copies(tcode,tcopies,tavail);
  D.Extend_Date(cd.date,cd.month,cd.year,15);
  cd.date=D.td.date;
  cd.month=D.td.month;
  cd.year=D.td.year;
  Update_Student_Book_Code_And_Date_Of_Return(sadmno,tcode,cd.date,cd.month,cd.year);  // member function of MEMBER
  gotoxy(5,13);
  cout<<"Book is issued to "<<Student_Name(sadmno)<<" for 15 days.";
  gotoxy(5,14);
  cout<<"If you fail to return book on date of returning book as mentioned below,";
  gotoxy(5,15);
  cout<<"fine of Rs.2 will be charged.";
  gotoxy(5,17);
  cout<<"Date of Returning Book:"<<cd.date<<"/"<<cd.month<<"/"<<cd.year;
  getch();
}

//FUNCTION OF RETURNING BOOK(CLASS LIBRARY DEPARTMENT)
void library_department::Return_Book()
{
  student S;
  char t1code[5],ch;
  int t2code=0,valid;
  long sadmno=0;
  DATEE cd;
  struct date d;
  getdate(&d);
  cd.date=d.da_day;
  cd.month=d.da_mon;
  cd.year=d.da_year;
  do
  {
    valid=1;
    while (1)
    {
      clrscr();
      gotoxy(60,1);
      cprintf("[Enter <0> to return]");
      gotoxy(5,3);
      cout<<"Date:"<<cd.date<<"/"<<cd.month<<"/"<<cd.year;
      gotoxy(5,5);
      cout<<"Enter Admission no. of Student(Press <ENTER> for help):";
      gets(t1code);
      if (t1code[0]=='0')
	return;
      if (strlen(t1code)==0)
	S.Show_List_Of_Student_For_Book();
      else
	break;
    }
    t2code=atoi(t1code);
    sadmno=(long)t2code;
    if (sadmno==0)
    {
      valid=0;
      gotoxy(5,25);
      cout<<"Enter Correctly......";
      getch();
    }
    if (!Check_Student(sadmno)&&valid)
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
    if (!Had_Student_Issue_Book(sadmno)&&valid)
    {
      valid=0;
      gotoxy(5,14);
      cout<<"Student have no book to return......";
      gotoxy(5,15) ;
      cout<<"Press <ESC> to exit or any other key to continue......";
      ch=getch();
      if (ch==27)
	return;
    }
  }while(!valid);
  int bcode,tcopies,tavail;
  bcode=Had_Student_Issue_Book(sadmno);
  gotoxy(5,13);
  cout<<"Book Code:"<<bcode;
  gotoxy(5,14);
  cout<<"Book Name:"<<Book_Name(bcode);
  tcopies=No_Of_Copies_Of_Book(bcode);
  tavail=Give_No_Of_Copies_Available(bcode)+1;
  int f;
  f=Calculate_Fine(sadmno);
  if (f!=0)
  {
    gotoxy(5,16);
    cout<<"You have to pay a fine of Rs." <<f;
    gotoxy(5,17);
    cout<<"Please do not delay the Return of Book again......" ;
  }
  Update_Book_Copies(bcode,tcopies,tavail);
  Update_Student_Book_Code_And_Date_Of_Return(sadmno,0,0,0,0);
  gotoxy(5,19);
  cout<<"Book has been returned......";
  getch();
}

//FUNCTION TO ADD NEW BOOK(CLASS LIBRARY DEPARTMENT)
void library_department::Add_New_Record_Of_Book()
{
  char ch;
  int tcode,tcopies,tavail;
  char tname[50],tauthor[50];
  float tprice=0.0;
  do
  {
    int found=0,valid=0;
    int tc;
    float t2=0.0;
    char t[10],t1[10];
    clrscr();
    gotoxy(60,1);
    cprintf("[Enter <0> to return]");
    gotoxy(5,25);
    cout<<"(Enter code no. of the book)";
    gotoxy(5,5);
    cout<<"Book Code:";
    gets(t);
    tc=atoi(t);
    tcode=tc;
    if (tcode==0)
      return;
    if(Check_Book_Code(tcode))
    {
      found=1;
      gotoxy(19,8);
      cout<<Book_Name(tcode);
      gotoxy(19,9);
      cout<<Book_Author_Name(tcode);
      gotoxy(22,10);
      cout<<Book_Price(tcode);
      gotoxy(5,8);
      cout<<"Book Name   : ";
      gotoxy(5,9);
      cout<<"Author Name : ";
      gotoxy(5,10);
      cout<<"Price       : Rs.";
      gotoxy(5,12);
      cout<<"Book already exist......";
      gotoxy(5,13);
      cout<<"Press any key to exit......";
      getche();
      return;
    }
    else
    {
      gotoxy(5,8);
      cout<<"Book Name   : ";
      gotoxy(5,9);
      cout<<"Author Name : ";
      gotoxy(5,10);
      cout<<"Price       : Rs.";
      gotoxy(5,11);
      cout<<"Copies      : ";
      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(5,25);
	clreol();
	cout<<"(Enter the name of the book)";
	gotoxy(19,8);
	clreol();
	gets(tname);
	strupr(tname);
	if (tname[0]=='0')
	  return;
	if (strlen(tname)<1||strlen(tname)>50)
	{
	  valid=0;
	  gotoxy(5,25);
	  clreol();
	  cout<<"Enter correctly (Range: 1..50)......";
	  getch();
	}
      }
      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(5,25);
	clreol();
	cout<<"(Enter the author's name of the book)";
	gotoxy(19,9);
	clreol();
	gets(tauthor);
	strupr(tauthor);
	if (tauthor[0]=='0')
	  return;
	if (strlen(tauthor)<1||strlen(tauthor)>50)
	{
	  valid=0;
	  gotoxy(5,25);
	  clreol();
	  cout<<"Enter correctly (Range: 1..50)......";
	  getch();
	}
      }
      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(5,25);
	clreol();
	cout<<"(Enter the price of the book)";
	gotoxy(22,10);
	clreol();
	gets(t1);
	t2=atof(t1);
	tprice=t2;
	if (t1[0]=='0')
	  return;
	if (tprice<1||tprice>20000)
	{
	  valid=0;
	  gotoxy(5,25);
	  clreol();
	  cout<<"Enter correctly......";
	  getch();
	}
      }
      valid=0;
      while (!valid&&!found)
      {
	valid=1;
	gotoxy(5,25);
	clreol();
	cout<<"(Enter no. of copies of book)";
	gotoxy(19,11);
	clreol();
	gets(t);
	tc=atoi(t);
	tcopies=tc;
	if (t[0]=='0')
	  return;
	if (tcopies<1||tcopies>50)
	{
	  valid=0;
	  gotoxy(5,25);
	  clreol();
	  cout<<"Enter correctly......";
	  getch();
	}
      }
     tavail=tcopies;
     gotoxy(5,25);
     clreol();
     do
     {
       gotoxy(5,15);
       clreol();
       cout<<"Do you want to save (Y/N):";
       ch=getche();
       ch=toupper(ch);
     }while(ch!='Y'&&ch!='N');
     if (ch=='Y')
     {
       Add_New_Book(tcode,tname,tauthor,tprice,tcopies,tavail);
     }
     do
     {
      gotoxy(5,17);
      clreol();
      cout <<"Do you want to add more (Y/N):";
      ch=getche();
      ch=toupper(ch);
     }while (ch!='Y'&&ch!='N');
    }
  }while(ch=='Y');
}

//FUNCTION TO MODIFY BOOK(CLASS LIBRARY DEPARTMENT)
void library_department::Modify_Record_Of_Book()
{
  book B;
  char t1code[50],tname[50],tauthor[50],*t1,ch;
  int t2code=0,tcode=0,tcopies=0;
  float t2=0.0,tprice=0.0;
  int valid;
  do
  {
    valid=1;
    while(1)
    {
      clrscr();
      gotoxy(60,1);
      cprintf("[Enter <0> to return]");
      gotoxy(5,5);
      cout<<"Enter Code or Name of the Book to be modified(Press <ENTER> for help):";
      gets(t1code);
      if (t1code[0]=='0')
	return;
      if (strlen(t1code)==0)
	B.Show_List_Of_Book();
      else
	break;
    }
    t2code=atoi(t1code);
    tcode=t2code;
    if ((tcode==0&&!Check_Book_Name(t1code))||(tcode!=0&&!Check_Book_Code(tcode)))
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
  }while(!valid);
  if (tcode==0)
    tcode=Book_Code_Of(t1code);
  clrscr();
  gotoxy(60,1);
  cprintf("[Enter <0> to return]");
  Display_Book(tcode);

  int tavaili,tcopiesi;
  tavaili=Give_No_Of_Copies_Available(tcode);
  tcopiesi=No_Of_Copies_Of_Book(tcode);
  if (tavaili!=tcopiesi)
  {
    gotoxy(5,16);
    cout<<"Record cannot be modified. This book is issued.";
    getch();
    return;
  }
  else
  {
    do
    {
      gotoxy(5,14);
      clreol();
      cout<<"Do you want to modify this record (y/n):";
      ch=getche();
      ch=toupper(ch);
      if (ch=='0')
	return;
    }while(ch!='Y'&&ch!='N');
  }
  if (ch=='N')
    return;
  gotoxy(5,16);
  cout<<"Book Name   : ";
  gotoxy(5,17);
  cout<<"Author Name : ";
  gotoxy(5,18);
  cout<<"Price       : Rs.";
  gotoxy(5,19);
  cout<<"Copies      : ";
  do
  {
    valid=1;
    gotoxy(5,25);
    clreol();
    cout<<"(Enter the name of the book or <ENTER> for no change)" ;
    gotoxy(19,16);
    clreol();
    gets(tname);
    strupr(tname);
    if (tname[0]=='0')
      return;
    if (strlen(tname)>50)
    {
      valid=0;
      gotoxy(5,25);
      clreol();
      cout<<"Enter correctly (Range: 1..50)......";
      getch();
    }
  }while(!valid);
  if (strlen(tname)==0)
    strcpy(tname,Book_Name(tcode));
  do
  {
    valid=1;
    gotoxy(5,25);
    clreol();
    cout<<"(Enter the author's name or <ENTER> for no change)";
    gotoxy(19,17);
    clreol();
    gets(tauthor);
    strupr(tauthor);
    if (tauthor[0]=='0')
      return;
    if (strlen(tauthor)>50)
    {
      valid=0;
      gotoxy(5,25);
      clreol();
      cout<<"Enter correctly (Range: 1..50)......";
      getch() ;
    }
  }while(!valid);
  if (strlen(tauthor)==0)
    strcpy(tauthor,Book_Author_Name(tcode));
  do
  {
    valid=1;
    gotoxy(5,25);
    clreol();
    cout<<"(Enter price or <ENTER> for no change)";
    gotoxy(22,18);
    clreol();
    gets(t1);
    t2=atof(t1);
    tprice=t2;
    if (t1[0]=='0')
      return;
    if (strlen(t1)==0)
      break;
    if (tprice<1||tprice>20000)
    {
      valid=0;
      gotoxy(5,25);
      clreol();
      cout<<"Enter correctly......";
      getch();
    }
  }while(!valid);
  if (strlen(t1)==0)
    tprice=Book_Price(tcode);
  do
  {
    valid=1;
    gotoxy(5,25);
    clreol();
    cout<<"(Enter copies or <ENTER> for no change)";
    gotoxy(19,19);
    clreol();
    gets(t1);
    t2=atof(t1);
    tcopies=t2;
    if (t1[0]=='0')
      return;
    if (strlen(t1)==0)
      break;
    if (tcopies<1||tcopies>50)
    {
      valid=0;
      gotoxy(5,25);
      clreol();
      cout<<"Enter correctly......";
      getch();
    }
  }while(!valid);
  if (strlen(t1)==0)
    tcopies=No_Of_Copies_Of_Book(tcode);
  gotoxy(5,25);
  clreol();
  do
  {
    gotoxy(5,20);
    clreol();
    cout<<"Do you want to save changes (y/n):";
    ch=getche();
    ch=toupper(ch);
    if (ch=='0')
      return;
  }while(ch!='Y'&&ch!='N');
  if (ch=='N')
    return;
  Modify_Book(tcode,tname,tauthor,tprice,tcopies);
  gotoxy(5,23);
  cout<<"Record Modified......";
  getch();
}

//FUNCTION TO DELETE BOOK(CLASS LIBRARY DEPARTMENT)
void library_department::Delete_Record_Of_Book()
{
  book B;
  char t1code[5],tname[50],tauthor[50],ch;
  int t2code=0,tcode=0;
  int valid;
  do
  {
    valid=1;
    while (1)
    {
      clrscr();
      gotoxy(60,1);
      cprintf("[Enter <0> to return]");
      gotoxy(5,5);
      cout<<"Enter Code or Name of the Book to be deleted(Press <ENTER> for help):";
      gets(t1code);
      if (t1code[0]=='0')
	return;
      if (strlen(t1code)==0)
	B.Show_List_Of_Book();
      else
	break;
    }
    t2code=atoi(t1code);
    tcode=t2code;
    if ((tcode==0&&!Check_Book_Name(t1code))||(tcode!=0&&!Check_Book_Code(tcode)))
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
  }while(!valid);
  if (tcode==0)
    tcode=Book_Code_Of(t1code);
  clrscr();
  gotoxy(60,1);
  cprintf("[Enter <0> to return]");
  Display_Book(tcode);
  do
  {
    gotoxy(5,14);
    clreol();
    cout<<"Do you want to delete this record (y/n):";
    ch=getche();
    ch=toupper(ch);
    if (ch=='0')
      return;
  }while(ch!='Y'&&ch!='N');
  if (ch=='N')
    return;
  int tavail,tcopies;
  tavail=Give_No_Of_Copies_Available(tcode);
  tcopies=No_Of_Copies_Of_Book(tcode);
  if (tavail!=tcopies)
  {
    gotoxy(5,16);
    cout<<"Record cannot be deleted. This book is issued.";
    getch();
    return;
  }
  Delete_Book(tcode);
  gotoxy(5,23);
  cout<<"Record Deleted......";
  getch();
}

/****************************************************************************/

void LIBRARY_DEPARTMENT()
{
 clrscr();
 while(1)
 {
   clrscr();
   char ch;
   int j=strlen(SNAME),i=80-j,l=0;
   int row=i/2;
   gotoxy(row,6);
   cprintf("%s",SNAME);
   while(l<j)
   {
     gotoxy(row+l,7);
     cprintf("~");
     l++;
   }
   gotoxy(32,8);
   cout<<"LIBRARY DEPARTMENT";
   gotoxy(31,10);
   cout<<"1.Issue Book.";
   gotoxy(31,11);
   cout<<"2.Return Book.";
   gotoxy(31,12);
   cout<<"3.Show List Of Book.";
   gotoxy(31,13);
   cout<<"4.Add New Book.";
   gotoxy(31,14);
   cout<<"5.Modify Book.";
   gotoxy(31,15);
   cout<<"6.Delete Book.";
   gotoxy(31,16);
   cout<<"7.Back to main menu.";
   gotoxy(31,18);
   cout<<"Enter your choice:";
   ch=getche();
   if(ch=='1')
   {
     library_department L;
     L.Issue_Book();
   }
   else if(ch=='2')
   {
     library_department L;
     L.Return_Book();
   }
   else if(ch=='3')
   {
     book B;
     B.Show_List_Of_Book();
   }
   else if(ch=='4')
   {
     library_department L;
     L.Add_New_Record_Of_Book();
   }
   else if(ch=='5')
   {
     library_department L;
     L.Modify_Record_Of_Book();
   }
   else if(ch=='6')
   {
     library_department L;
     L.Delete_Record_Of_Book();  //complete
   }
   else if(ch=='7')
     MAIN();
 }
}

/****************************************************************************//****************************************************************************/

//MAIN FUNCTION//
void MAIN()
{
 while(1)
 {
   school S;
   S.INTRODUCTION_1();
   S.INTRODUCTION_2();
   LIBRARY_DEPARTMENT();
 }
}

/****************************************************************************/

void main()
{
MAIN();
}

/****************************************************************************/