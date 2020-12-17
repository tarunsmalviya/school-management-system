//GLOBAL VARIABLE//
char SNAME[100],SYEAR[5],SPASSWORD[20];
char STUDENT_FILE_NAME[9],BOOK_FILE_NAME[9];
char ACADEMIC_6_10_FILE_NAME[9],ACADEMIC_11_12_FILE_NAME[9];

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////CLASSES & STRUCTURES/////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//STRUCTURE OF DATE//
struct DATEE
{
  int date,month;
  long year;
};

//////////////////////////////////////////////////////////////////////////////

//STRUCTURE OF ADDRESS//
struct ADDRESS
{
  char line1[50],line2[50],line3[50],city[20],state[20],pincode[7];
};

//////////////////////////////////////////////////////////////////////////////

//STRUCTURE OF RELATIVE//
struct RELATIVE
{
  char rname[50],rsection,rhouse[20];
  int rclass;
};

//////////////////////////////////////////////////////////////////////////////

//CLASS OF SCHOOL//
class school
{
private:
  char name[100],password[20],phoneno[11];
  ADDRESS ad;

public:
  void Display(char[]);
  void INTRODUCTION_1();
  void INTRODUCTION_2();
  void Create_School();
  int Check_School_Password(char[],char[]);
  int Check_School_Name(char[]);
};

//////////////////////////////////////////////////////////////////////////////

//CLASS OF DATE//
class datee
{
public:
  void Extend_Date(int,int,long,int);
  int Difference_Between_Dates(int,int,long,int,int,long);
  DATEE td;
};

//////////////////////////////////////////////////////////////////////////////

//CLASS OF BOOK//
class book
{
private:
  int book_code,book_copies;
  char book_name[50],book_author[50];
  float book_price;
  int available;

protected:
  void Add_New_Book(int,char[],char[],float,int,int);
  void Update_Book_Copies(int,int,int);
  void Modify_Book(int,char[],char[],float,int);
  int Check_Book_Code(int);
  int Check_Book_Name(char []);
  int Give_No_Of_Copies_Available(int);
  char *Book_Author_Name(int);
  float Book_Price(int);
  int No_Of_Copies_Of_Book(int);
  int Book_Code_Of(char[]);
  void Display_Book(int);
  void Delete_Book(int);

public:
  void Show_List_Of_Book();
  char *Book_Name(int);
};

//////////////////////////////////////////////////////////////////////////////

//CLASS OF STUDENT//
class student
{
private:
  char name[50],section,house[20],m_name[50],f_name[50];
  char profession[50],e_mail[50];
  char bloodgroup[5],mode_of_transport[20];
  int clas,sbook_code;
  long admission_no;
  char phoneno[11],mobileno[11];
  DATEE dob,return_date;
  ADDRESS add;
  RELATIVE r;

protected:
  int Check_Student(long);
  void Update_Student_Book_Code_And_Date_Of_Return(long,int,int,int,int);
  char *Student_Name(long);
  int Had_Student_Issue_Book(long);
  int Calculate_Fine(long);
  int Student_Class(long);
  char Student_Section(long);
  void Display_Student(long);
  void Add_New_Student(char[],char,char[],char[],char[],char[],char[],char[],char[],int,long,char[],char[],DATEE,ADDRESS,RELATIVE);
  void Modify_Student(char[],char,char[],char[],char[],char[],char[],char[],char[],int,long,char[],char[],DATEE,ADDRESS,RELATIVE);
  void Delete_Student(long);
  long admno();

public:
  student();
  void Show_List_Of_Student_For_Book();
  void Show_List_Of_Student();
  void View_Student_Record();
};

/****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
////////////////////////////SCHOOL CLASS FUNCTION/////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//FUNCTION TO CHECK SCHOOL PASSWORD(CLASS SCHOOL)
int school::Check_School_Password(char s[100],char p[20])
{
  fstream file;
  file.open("SCHOOL.DATA",ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int found=0;
  while (file.read((char*)this,sizeof(school)))
  {
    if (strcmp(name,s)==0)
    {
      if (strcmp(password,p)==0)
      {
	found=1;
	break;
      }
    }
  }
  file.close();
  return found;
}

//FUNCTION TO CHECK SCHOOL NAME(CLASS SCHOOL)
int school::Check_School_Name(char s[100])
{
  fstream file;
  file.open("SCHOOL.DATA",ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int found=0;
  while (file.read((char*)this,sizeof(school)))
  {
    if (strcmp(name,s)==0)
    {
      found=1;
      break;
    }
  }
  file.close();
  return found;
}

//FUNCTION TO ADD RECORD OF SCHOOL(CLASS SCHOOL)
void school::Create_School()
{
  ADDRESS tadd;
  char tname[50],tpassword[20],tphoneno[11],t[100];
  int valid=0,tc;
  clrscr();
  textmode(C80);
  gotoxy(60,1);
  cprintf("[Enter <0> to return]");
  gotoxy(33,6);
  cout<<"CREATE ACCOUNT";
  gotoxy(33,7);
  cout<<"~~~~~~~~~~~~~~";
  gotoxy(15,8);
  cout<<"Name              :";
  gotoxy(15,9);
  cout<<"Address:- Line 1  :";
  gotoxy(15,10);
  cout<<"          Line 2  :";
  gotoxy(15,11);
  cout<<"          Line 3  :";
  gotoxy(15,12);
  cout<<"          City    :";
  gotoxy(15,13);
  cout<<"          State   :";
  gotoxy(15,14);
  cout<<"          Pincode :";
  gotoxy(15,15);
  cout<<"Contact No.       :";
  gotoxy(15,16);
  cout<<"Password          :";

  valid=0;
  while (!valid)
  {
    valid=1;
    gotoxy(15,24);clreol();
    cprintf("(Enter name of school)");
    gotoxy(15,25);clreol();
    cprintf("(Use '_' for <space>)");
    gotoxy(35,8);clreol();
    gets(tname);
    strupr(tname);
    int tc=atoi(tname);
    if (tname[0]=='0')
      return;
    if ((strlen(tname)<1||strlen(tname)>50||tc!=0)&&(Check_School_Name(tname)==0))
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly (Range: 1..50)......");
      getch();
    }
  }
  gotoxy(15,24);clreol();
  valid=0;
  while (!valid)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter line 1 of school's address)");
    gotoxy(35,9);clreol();
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
  while (!valid)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter line 2 of school's address)");
    gotoxy(35,10);clreol();
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
  while (!valid)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter line 3 of school's address)");
    gotoxy(35,11);clreol();
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
  while (!valid)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter city of school)");
    gotoxy(35,12);clreol();
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
  while (!valid)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter state of school)");
    gotoxy(35,13);clreol();
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
  while (!valid)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter pincode of school)");
    gotoxy(35,14);clreol();
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
  while (!valid)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter contact number of school)");
    gotoxy(35,15);clreol();
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
  while (!valid)
  {
    valid=1;
    gotoxy(15,25);clreol();
    cprintf("(Enter password)");
    gotoxy(35,16);clreol();
    gets(tpassword);
    if (t[0]=='0')
      return;
    if (strlen(tpassword)<1||strlen(tpassword)>20)
    {
      valid=0;
      gotoxy(15,25);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  fstream file;
  file.open("SCHOOL.DATA",ios::app|ios::binary);
  strcpy(name,tname);
  strcpy(phoneno,tphoneno);
  strcpy(ad.line1,tadd.line1);
  strcpy(ad.line2,tadd.line2);
  strcpy(ad.line3,tadd.line3);
  strcpy(ad.city,tadd.city);
  strcpy(ad.state,tadd.state);
  strcpy(ad.pincode,tadd.pincode);
  strcpy(password,tpassword);
  file.write((char*)this,sizeof(school));
  file.close();
  gotoxy(15,25);
  cout<<"Account Created......";
  getch();
}

//FUNCTION TO DISPLAY SCHOOL DETAIL(CLASS SCHOOL)
void school::Display(char s[100])
{
  fstream file;
  file.open("SCHOOL.DATA",ios::in|ios::binary);
  file.seekg(0,ios::beg);
  while(!file.eof())
  {
    file.read((char*)this,sizeof(school));
    if (file.eof())
      break;
    if (strcmpi(s,name)==0)
    {
      int j=strlen(s),i=80-j,l=0,row=i/2;
      gotoxy(row,6);
      cprintf("%s",name);
      while(l<j)
      {
	gotoxy(row+l,7);
	cprintf("~");
	l++;
      }

      j=strlen(ad.line1);i=80-j;l=0;row=i/2;
      gotoxy(row,8);
      cprintf("%s",ad.line1);

      j=strlen(ad.line2);i=80-j;l=0;row=i/2;
      gotoxy(row,9);
      cprintf("%s",ad.line2);

      j=strlen(ad.line3);i=80-j;l=0;row=i/2;
      gotoxy(row,10);
      cprintf("%s",ad.line3);

      j=strlen(ad.city)+strlen(ad.state)+strlen(ad.pincode)+4;i=80-j;l=0;row=i/2;
      gotoxy(row,11);
      cprintf("%s,%s (%s)",ad.city,ad.state,ad.pincode);

      j=strlen(phoneno)+13;i=80-j;l=0;row=i/2;
      gotoxy(row,12);
      cprintf("Contact No.: %s",phoneno);

      break;
    }
  }
}

//PAGE 1(CLASS SCHOOL)
void school::INTRODUCTION_1()
{
 clrscr();
 strcpy(STUDENT_FILE_NAME,NULL);
 strcpy(BOOK_FILE_NAME,NULL);
 strcpy(ACADEMIC_6_10_FILE_NAME,NULL);
 strcpy(ACADEMIC_11_12_FILE_NAME,NULL);
 strcpy(SYEAR,NULL);
 strcpy(SNAME,NULL);
 strcpy(SPASSWORD,NULL);

 while(1)
 {
   clrscr();
   textmode(C80);
   gotoxy(60,1);
   cprintf("[Enter <0> to exit]");
   textcolor(LIGHTGREEN);
   gotoxy(28,7);
   cprintf("SCHOOL MANAGEMENT SYSTEM");
   textcolor(LIGHTGRAY);
   gotoxy(25,9);
   cprintf("NAME     :");
   gotoxy(25,10);
   cprintf("PASSWORD :");

   int valid=0;
   while (!valid)
   {
     valid=1;
     gotoxy(26,13);
     cprintf("<Press Enter To Create An Account>");
     gotoxy(15,24);clreol();
     cprintf("(Enter name of school)");
     gotoxy(15,25);clreol();
     cprintf("(Use '_' for <space>)");
     gotoxy(35,9);clreol();
     gets(SNAME);
     strupr(SNAME);
     if (SNAME[0]=='0')
       exit(0);
     if (strlen(SNAME)==0)
     {
       Create_School();
       MAIN();
     }
     if (Check_School_Name(SNAME)==0)
     {
       valid=0;
       gotoxy(15,24);clreol();
       gotoxy(15,25);clreol();
       cprintf("Incorrect School Name......");
       getch();
     }
   }
   gotoxy(26,13);clreol();
   gotoxy(15,25);clreol();
   valid=0;
   while (!valid)
   {
     valid=1;
     gotoxy(15,24);clreol();
     cprintf("(Enter password)");
     gotoxy(35,10);clreol();
     gets(SPASSWORD);
     if (SPASSWORD[0]=='0')
       exit(0);
     if (Check_School_Password(SNAME,SPASSWORD)==0)
     {
       valid=0;
       gotoxy(15,24);clreol();
       cprintf("Incorrect Password......");
       getch();
     }
   }
   break;
 }
}

//PAGE 2(CLASS SCHOOL)
void school::INTRODUCTION_2()
{
 char ch[2];
 int t1,t2;
 clrscr();
 while(1)
 {
   clrscr();
   textmode(C80);
   textcolor(CYAN);
   Display(SNAME);
   textcolor(YELLOW);
   gotoxy(33,14);
   cprintf("YEAR:20  -20  ");
   int valid=0;
   while (!valid)
   {
     valid=1;
     gotoxy(40,14);clreol();
     gotoxy(42,14);
     cprintf("-20");
     gotoxy(40,14);
     cin>>ch;
     t1=atoi(ch);
     if (t1==0)
     {
       valid=0;
       gotoxy(15,25);clreol();
       cprintf("Enter Correctly......");
       getch();
       gotoxy(15,25);clreol();
     }
   }
   SYEAR[0]=ch[0];
   SYEAR[1]=ch[1];
   valid=0;
   while (!valid)
   {
     valid=1;
     gotoxy(45,14);clreol();
     cin>>ch;
     t2=atoi(ch);
     if (t2==0||t2!=(t1+1))
     {
       valid=0;
       gotoxy(15,25);clreol();
       cprintf("Enter Correctly......");
       getch();
       gotoxy(15,25);clreol();
     }
   }
   SYEAR[2]=ch[0];
   SYEAR[3]=ch[1];

   STUDENT_FILE_NAME[0]=SNAME[0];
   STUDENT_FILE_NAME[1]=SNAME[1];
   STUDENT_FILE_NAME[2]=SNAME[2];
   STUDENT_FILE_NAME[3]='S';
   STUDENT_FILE_NAME[4]=SYEAR[0];
   STUDENT_FILE_NAME[5]=SYEAR[1];
   STUDENT_FILE_NAME[6]=SYEAR[2];
   STUDENT_FILE_NAME[7]=SYEAR[3];
   STUDENT_FILE_NAME[8]=NULL;

   BOOK_FILE_NAME[0]=SNAME[0];
   BOOK_FILE_NAME[1]=SNAME[1];
   BOOK_FILE_NAME[2]=SNAME[2];
   BOOK_FILE_NAME[3]=SNAME[3];
   BOOK_FILE_NAME[4]='B';
   BOOK_FILE_NAME[5]='O';
   BOOK_FILE_NAME[6]='O';
   BOOK_FILE_NAME[7]='K';
   BOOK_FILE_NAME[8]=NULL;

   ACADEMIC_6_10_FILE_NAME[0]=SNAME[0];
   ACADEMIC_6_10_FILE_NAME[1]=SNAME[2];
   ACADEMIC_6_10_FILE_NAME[2]='A';
   ACADEMIC_6_10_FILE_NAME[3]='1';
   ACADEMIC_6_10_FILE_NAME[4]=SYEAR[0];
   ACADEMIC_6_10_FILE_NAME[5]=SYEAR[1];
   ACADEMIC_6_10_FILE_NAME[6]=SYEAR[2];
   ACADEMIC_6_10_FILE_NAME[7]=SYEAR[3];
   ACADEMIC_6_10_FILE_NAME[8]=NULL;

   ACADEMIC_11_12_FILE_NAME[0]=SNAME[0];
   ACADEMIC_11_12_FILE_NAME[1]=SNAME[1];
   ACADEMIC_11_12_FILE_NAME[2]='A';
   ACADEMIC_11_12_FILE_NAME[3]='2';
   ACADEMIC_11_12_FILE_NAME[4]=SYEAR[0];
   ACADEMIC_11_12_FILE_NAME[5]=SYEAR[1];
   ACADEMIC_11_12_FILE_NAME[6]=SYEAR[2];
   ACADEMIC_11_12_FILE_NAME[7]=SYEAR[3];
   ACADEMIC_11_12_FILE_NAME[8]=NULL;

   textcolor(LIGHTGRAY);
   break;
 }
}

/****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////DATE CLASS FUNCTIONS/////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//FUNCTION TO EXTEND DATE(CLASS DATE)
void datee::Extend_Date(int d1,int m1,long y1,int days)
{
  static int month[]={31,29,31,30,31,30,31,31,30,31,30,31};
  for (int i=1;i<=days;i++)
  {
    d1++;
    if ((d1>month[m1-1])||(y1%4!=0&&m1==2&&d1>28))
    {
      d1=1;
      m1++;
    }
    if (m1>12)
    {
      m1=1;
      y1++;
    }
  }
  td.date=d1;
  td.month=m1;
  td.year=y1;
}

//FUNCTION TO RETURN THE DIFFERENCE BETWEEN TWO GIVEN DATES(CLASS DATE)
int datee::Difference_Between_Dates(int d1,int m1,long y1,int d2,int m2,long y2)
{
  int days=0;
  if ((y2<y1)||(y2==y1&&m2<m1)||(y2==y1&&m2==m1&&d2<d1))
    return days;
  static int month[]={31,29,31,30,31,30,31,31,30,31,30,31};
  while (d1!=d2||m1!=m2||y1!=y2)
  {
    days++;
    d1++;
    if ((d1>month[m1-1])||(y1%4!=0&&m1==2&&d1>28))
    {
      d1=1;
      m1++;
    }
    if (m1>12)
    {
      m1=1;
      y1++;
    }
  }
  return days;
}

/****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////BOOK CLASS FUNCTIONS/////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//FUNCTION TO ADD NEW BOOK IN BOOK.DATA FILE(CLASS BOOK)
void book::Add_New_Book(int tcode,char tname[50],char tauthor[50],float tprice,int tcopies,int tavailable)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::app|ios::binary);
  book_code=tcode;
  strcpy(book_name,tname);
  strcpy(book_author,tauthor);
  book_price=tprice;
  book_copies=tcopies;
  available=tavailable;
  file.write((char*)this,sizeof(book));
  file.close();
}

//FUNCTION TO UPDATE BOOK COPIES(CLASS BOOK)
void book::Update_Book_Copies(int tcode,int tcopies,int tavailable)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  fstream temp;
  temp.open("temp",ios::out|ios::binary);
  file.seekg(0,ios::beg);
  while (!file.eof())
  {
    file.read((char*)this,sizeof(book));
    if (file.eof())
      break;
    if (book_code==tcode)
    {
      book_copies=tcopies;
      available=tavailable;
      temp.write((char*)this,sizeof(book));
    }
    else
      temp.write((char*)this,sizeof(book));
  }
  file.close();
  temp.close();
  remove(BOOK_FILE_NAME);
  rename("temp",BOOK_FILE_NAME);
}

//FUNCTION TO MODIFY BOOK RECORD(CLASS BOOK)
void book::Modify_Book(int tcode,char tname[50],char tauthor[50],float tprice,int tcopies)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  fstream temp;
  temp.open("temp",ios::out|ios::binary);
  file.seekg(0,ios::beg);
  while (!file.eof())
  {
    file.read((char*)this,sizeof(book)) ;
    if (file.eof())
      break;
    if (book_code==tcode)
    {
      int t=book_copies-available;
      book_copies=tcopies;
      available=book_copies-t;
      strcpy(book_name,tname);
      strcpy(book_author,tauthor);
      book_price=tprice;
      temp.write((char*)this,sizeof(book));
    }
    else
      temp.write((char*)this,sizeof(book)) ;
  }
  file.close();
  temp.close();
  remove(BOOK_FILE_NAME);
  rename("temp",BOOK_FILE_NAME);
}

//FUNCTION TO CHECK BOOK CODE(CLASS BOOK)
int book::Check_Book_Code(int tcode)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int found=0;
  while (file.read((char *)this,sizeof(book)))
  {
    if (book_code==tcode)
    {
      found=1;
      break;
    }
  }
  file.close();
  return found;
}

//FUNCTION TO CHECK BOOK NAME(CLASS BOOK)
int book::Check_Book_Name(char t1code[50])
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int found=0;
  while (file.read((char*)this,sizeof(book)))
  {
    if (!strcmpi(book_name,t1code))
    {
      found=1;
      break;
    }
  }
  file.close();
  return found;
}

//FUNCTION TO CHECK AVAILABILITY OF BOOK(CLASS BOOK)
int book::Give_No_Of_Copies_Available(int tcode)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int tavail=0;
  while (file.read((char*)this,sizeof(book)))
  {
    if (book_code==tcode)
    {
      tavail=available;
      break;
    }
  }
  file.close();
  return tavail;
}

//FUNCTION TO RETURN BOOK AUTHER NAME(CLASS BOOK)
char *book::Book_Author_Name(int tcode)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  char tauthor[50];
  while (file.read((char*)this,sizeof(book)))
  {
    if (book_code==tcode)
    {
      strcpy(tauthor,book_author);
      break;
    }
  }
  file.close();
  return tauthor;
}

//FUNCTION TO RETURN BOOK PRICE(CLASS BOOK)
float book::Book_Price(int tcode)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  float tprice=0.0;
  while (file.read((char*)this,sizeof(book)))
  {
    if (book_code==tcode)
    {
      tprice=book_price;
      break;
    }
  }
  file.close();
  return tprice;
}

//FUNCTION TO RETURN NO. OF COPIES OF BOOK(CLASS BOOK)
int book::No_Of_Copies_Of_Book(int tcode)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int tcopies=0;
  while (file.read((char*)this,sizeof(book)))
  {
    if (book_code==tcode)
    {
      tcopies=book_copies;
      break;
    }
  }
  file.close();
  return tcopies;
}

//FUNCTION TO RETURN BOOK CODE WHEN BOOK NAME IS PASSED(CLASS BOOK)
int book::Book_Code_Of(char t1code[50])
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int tcode=0;
  while (file.read((char*)this,sizeof(book)))
  {
    if (!strcmpi(book_name,t1code))
    {
      tcode=book_code;
      break;
    }
  }
  file.close();
  return tcode;
}

//FUNCTION TO DISPLAY DETAIL OF BOOK(CLASS BOOK)
void book::Display_Book(int tcode)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  while (file.read((char*)this,sizeof(book)))
  {
    if (book_code==tcode)
    {
      gotoxy(5,5) ;
      cout<<"Book Code   : "<<book_code;
      gotoxy(5,7) ;
      cout<<"Book Name   : "<<book_name;
      gotoxy(5,8) ;
      cout<<"Author Name : "<<book_author;
      gotoxy(5,9) ;
      cout<<"Price       : Rs."<<book_price;
      gotoxy(5,10) ;
      cout<<"Copies      : "<<book_copies;
      gotoxy(5,11) ;
      cout<<"Available   : "<<available;
      break;
    }
  }
  file.close();
}

//FUNCTION TO DELETE BOOK RECORD(CLASS BOOK)
void book::Delete_Book(int tcode)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  fstream temp;
  temp.open("temp",ios::out);
  file.seekg(0,ios::beg);
  while (!file.eof())
  {
    file.read((char*)this,sizeof(book));
    if (file.eof())
      break ;
    if (book_code!=tcode)
      temp.write((char*)this,sizeof(book));
  }
  file.close();
  temp.close();
  remove(BOOK_FILE_NAME);
  rename("temp",BOOK_FILE_NAME);
}

//FUNCTION TO SHOW LIST OF BOOK(CLASS BOOK)
void book::Show_List_Of_Book()
{
  clrscr();
  int row=6,found=0,flag=0;
  char ch;
  gotoxy(33,2);
  cout<<"LIST OF BOOKS";
  gotoxy(32,3);
  cout<<"~~~~~~~~~~~~~~~";
  gotoxy(1,4);
  cout<<"CODE  BOOK NAME                      AUTHOR                       PRICE   COPIES";
  gotoxy(1,5);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  while (file.read((char*)this,sizeof(book)))
  {
   flag=0;
   delay(20);
   found=1;
   gotoxy(2,row);
   cout<<book_code;
   gotoxy(7,row);
   cout<<book_name;
   gotoxy(38,row);
   cout<<book_author;
   gotoxy(69,row);
   cout<<book_price;
   gotoxy(77,row);
   cout<<book_copies;
   textbackground(WHITE);
   textcolor(BLACK);
   gotoxy(40,row+1);
   cprintf("STATUS:");
   textcolor(BLACK+BLINK);
   cprintf("%d copies available",available);
   textbackground(BLACK);
   textcolor(LIGHTGRAY);
   if (row==22)
    {
      flag=1;
      row=6;
      gotoxy(1,25);
      cout<<"Press any key to continue or Press <ESC> to exit";
      ch=getch();
      if (ch==27)
       break;
      clrscr();
      gotoxy(33,2);
      cout<<"LIST OF BOOKS";
      gotoxy(32,3);
      cout<<"~~~~~~~~~~~~~~~";
      gotoxy(1,4);
      cout<<"CODE  BOOK NAME                        AUTHOR                    PRICE  COPIES";
      gotoxy(1,5);
      cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    }
   else
    row=row+2;
  }
  if (!found)
  {
    gotoxy(5,10);
    cout<<"Records not found";
  }
  if (!flag)
  {
    gotoxy(1,25);
    cout<<"Press any key to continue......";
    getche();
  }
  file.close();
}

//FUNCTION TO RETURN BOOK NAME(CLASS BOOK)
char *book::Book_Name(int tcode)
{
  fstream file;
  file.open(BOOK_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  char tname[50];
  while (file.read((char*)this,sizeof(book)))
  {
    if (book_code==tcode)
    {
	strcpy(tname,book_name);
	break;
    }
  }
  file.close();
  return tname;
}

/****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
////////////////////////////STUDENT CLASS FUNCTIONS///////////////////////////
//////////////////////////////////////////////////////////////////////////////

//FUNCTION TO CHECK STUDENT (EXIST IN FILE OR NOT)(CLASS STUDENT)
int student::Check_Student(long admno)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int found=0;
  while (file.read((char*)this,sizeof(student)))
  {
    if (admno==admission_no)
    {
      found=1;
      break;
    }
  }
  file.close();
  return found;
}

//FUNCTION TO UPDATE STUDENT BOOK CODE AND DATE OF RETURN(CLASS STUDENT)
void student::Update_Student_Book_Code_And_Date_Of_Return(long admno,int tcode,int d1,int m1,int y1)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  fstream temp;
  temp.open("temp",ios::out|ios::binary);
  file.seekg(0,ios::beg);
  while (!file.eof())
  {
    file.read((char*)this,sizeof(student));
    if (file.eof())
      break;
    if (admission_no==admno)
    {
      sbook_code=tcode;
      return_date.date=d1;
      return_date.month=m1;
      return_date.year=y1;
      temp.write((char*)this,sizeof(student));
    }
    else
      temp.write((char*)this,sizeof(student));
  }
  file.close();
  temp.close();
  remove(STUDENT_FILE_NAME);
  rename("temp",STUDENT_FILE_NAME);
}

//FUNCTION TO RETURN STUDENT NAME(CLASS STUDENT)
char *student::Student_Name(long admno)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  char sname[50];
  while (file.read((char*)this,sizeof(student)))
  {
    if (admission_no==admno)
    {
      strcpy(sname,name);
      break;
    }
  }
  file.close();
  return sname;
}

//FUNCTION TO PUT BOOK CODE ON ISSUE OF BOOK BY STUDENT(CLASS STUDENT)
int student::Had_Student_Issue_Book(long admno)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int issue=0;
  while (file.read((char*)this,sizeof(student)))
  {
    if (admission_no==admno)
    {
      issue=sbook_code;
      break;
    }
  }
  file.close();
  return issue;
}

//FUNCTION TO CALCULATE FINE ON LATE SUBMISSION(CLASS STUDENT)
int student::Calculate_Fine(long admno)
{
  datee D;
  DATEE f;
  struct date d;
  getdate(&d);
  f.date=d.da_day;
  f.month=d.da_mon;
  f.year=d.da_year;
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int days,fine;
  while (file.read((char*)this,sizeof(student)))
  {
    if (admission_no==admno)
    {
      days=D.Difference_Between_Dates(return_date.date,return_date.month,return_date.year,f.date,f.month,f.year);
      fine=days*2;
      break;
    }
  }
  file.close();
  return fine;
}

//FUNCTION TO RETURN STUDENT CLASS(CLASS STUDENT)
int student::Student_Class(long admno)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int s;
  while (file.read((char*)this,sizeof(student)))
  {
    if (admission_no==admno)
    {
      s=clas;
      break;
    }
  }
  file.close();
  return s;
}

//FUNCTION TO RETURN STUDENT SECTION(CLASS STUDENT)
char student::Student_Section(long admno)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  char s;
  while (file.read((char*)this,sizeof(student)))
  {
    if (admission_no==admno)
    {
      s=section;
      break;
    }
  }
  file.close();
  return s;
}

//FUNCTION TO DISPLAY DETAIL OF STUDENT(CLASS STUDENT)
void student::Display_Student(long admno)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  while (file.read((char*)this,sizeof(student)))
  {
    if (admission_no==admno)
    {
      gotoxy(3,3);clreol();
      cout<<"Student Name            : "<<name;
      gotoxy(3,4);clreol();
      cout<<"Class                   : "<<clas<<"-"<<section;
      gotoxy(3,5);clreol();
      cout<<"Date of Birth           : "<<dob.date<<"/"<<dob.month<<"/"<<dob.year;
      gotoxy(3,6);clreol();
      cout<<"Father's Name           : "<<f_name;
      gotoxy(3,7);clreol();
      cout<<"Mother's Name           : "<<m_name;
      gotoxy(3,8);clreol();
      cout<<"Profession              : "<<profession;
      gotoxy(3,9);clreol();
      cout<<"House                   : "<<house;
      gotoxy(3,10);clreol();
      cout<<"Address                 : "<<add.line1;
      gotoxy(3,11);clreol();
      cout<<"                          "<<add.line2;
      gotoxy(3,12);clreol();
      cout<<"                          "<<add.line3;
      gotoxy(3,13);clreol();
      cout<<"                          "<<add.city<<", "<<add.state<<" ("<<add.pincode<<")";
      gotoxy(3,14);clreol();
      cout<<"Phone Number            : "<<phoneno;
      gotoxy(3,15);clreol();
      cout<<"Mobile Number           : "<<mobileno;
      gotoxy(3,16);clreol();
      cout<<"E-mail                  : "<<e_mail;
      gotoxy(3,17);clreol();
      cout<<"Blood Group             : "<<bloodgroup;
      gotoxy(3,18);clreol();
      cout<<"Mode of Transport       : "<<mode_of_transport;
      gotoxy(3,19);clreol();
      cout<<"Name of Brother/Sister  : "<<r.rname;
      gotoxy(3,20);clreol();
      cout<<"Class of Brother/Sister : "<<r.rclass<<"-"<<r.rsection;
      gotoxy(3,21);clreol();
      cout<<"House of Brother/Sister : "<<r.rhouse;
      break;
    }
  }
  file.close();
}

//CONSTRUCTOR
student::student()
{
strcpy(name,NULL);
section=NULL;
strcpy(house,NULL);
strcpy(m_name,NULL);
strcpy(f_name,NULL);
strcpy(profession,NULL);
strcpy(e_mail,NULL);
strcpy(bloodgroup,NULL);
strcpy(mode_of_transport,NULL);
clas=NULL;
admission_no=NULL;
strcpy(phoneno,NULL);
strcpy(mobileno,NULL);
dob.date=NULL;
dob.year=NULL;
dob.month=NULL;
return_date.date=NULL;
return_date.month=NULL;
return_date.year=NULL;
sbook_code=NULL;
strcpy(add.line1,NULL);
strcpy(add.line2,NULL);
strcpy(add.line3,NULL);
strcpy(add.city,NULL);
strcpy(add.state,NULL);
strcpy(add.pincode,NULL);
strcpy(r.rname,NULL);
r.rclass=NULL;
r.rsection=NULL;
strcpy(r.rhouse,NULL);
}

//FUNCTION TO ADD NEW STUDENT RECORD(CLASS STUDENT)
void student::Add_New_Student(char tname[50],char tsection,char thouse[20],char tm_name[50],char tf_name[50],char tprofession[50],char te_mail[50],char tbloodgroup[5],char tmode_of_transport[20],int tclas,long tadmission_no,char tphoneno[10],char tmobileno[10],DATEE tdob,ADDRESS tadd,RELATIVE tr)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::app|ios::binary);
  strcpy(name,tname);
  section=tsection;
  strcpy(house,thouse);
  strcpy(m_name,tm_name);
  strcpy(f_name,tf_name);
  strcpy(profession,tprofession);
  strcpy(e_mail,te_mail);
  strcpy(bloodgroup,tbloodgroup);
  strcpy(mode_of_transport,tmode_of_transport);
  clas=tclas;
  admission_no=tadmission_no;
  strcpy(phoneno,tphoneno);
  strcpy(mobileno,tmobileno);
  dob.date=tdob.date;
  dob.year=tdob.year;
  dob.month=tdob.month;
  strcpy(add.line1,tadd.line1);
  strcpy(add.line2,tadd.line2);
  strcpy(add.line3,tadd.line3);
  strcpy(add.city,tadd.city);
  strcpy(add.state,tadd.state);
  strcpy(add.pincode,tadd.pincode);
  strcpy(r.rname,tr.rname);
  r.rclass=tr.rclass;
  r.rsection=tr.rsection;
  strcpy(r.rhouse,tr.rhouse);
  file.write((char*)this,sizeof(student));
  file.close();
}

//FUNCTION TO MODIFY STUDENT RECORD(CLASS STUDENT)
void student::Modify_Student(char tname[50],char tsection,char thouse[20],char tm_name[50],char tf_name[50],char tprofession[50],char te_mail[50],char tbloodgroup[5],char tmode_of_transport[20],int tclas,long tadmission_no,char tphoneno[10],char tmobileno[10],DATEE tdob,ADDRESS tadd,RELATIVE tr)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  fstream temp;
  temp.open("temp",ios::out|ios::binary);
  file.seekg(0,ios::beg);
  while (!file.eof())
  {
    file.read((char*)this,sizeof(student));
    if (file.eof())
      break;
    if (admission_no==tadmission_no)
    {
      strcpy(name,tname);
      section=tsection;
      strcpy(house,thouse);
      strcpy(m_name,tm_name);
      strcpy(f_name,tf_name);
      strcpy(profession,tprofession);
      strcpy(e_mail,te_mail);
      strcpy(bloodgroup,tbloodgroup);
      strcpy(mode_of_transport,tmode_of_transport);
      clas=tclas;
      admission_no=tadmission_no;
      strcpy(phoneno,tphoneno);
      strcpy(mobileno,tmobileno);
      dob.date=tdob.date;
      dob.year=tdob.year;
      dob.month=tdob.month;
      strcpy(add.line1,tadd.line1);
      strcpy(add.line2,tadd.line2);
      strcpy(add.line3,tadd.line3);
      strcpy(add.city,tadd.city);
      strcpy(add.state,tadd.state);
      strcpy(add.pincode,tadd.pincode);
      strcpy(r.rname,tr.rname);
      r.rclass=tr.rclass;
      r.rsection=tr.rsection;
      strcpy(r.rhouse,tr.rhouse);
      temp.write((char*)this,sizeof(student));
    }
    else
      temp.write((char*)this,sizeof(student)) ;
  }
  file.close();
  temp.close();
  remove(STUDENT_FILE_NAME);
  rename("temp",STUDENT_FILE_NAME);
}

//FUNCTION TO DELETE STUDENT RECORD(CLASS STUDENT)
void student::Delete_Student(long tadmission_no)
{
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  fstream temp;
  temp.open("temp",ios::out|ios::binary);
  file.seekg(0,ios::beg);
  while (!file.eof())
  {
    file.read((char*)this,sizeof(student));
    if (file.eof())
      break;
    if (admission_no!=tadmission_no)
      temp.write((char*)this,sizeof(student));
  }
  file.close();
  temp.close();
  remove(STUDENT_FILE_NAME);
  rename("temp",STUDENT_FILE_NAME);
}

//FUNCTION TO RETURN ADMISSION NO. OF STUDENT(CLASS STUDENT)
long student::admno()
{
return admission_no;
}

//FUNCTION TO SHOW LIST OF STUDENT FOR BOOK(CLASS STUDENT)
void student::Show_List_Of_Student_For_Book()
{
  clrscr();
  book B;
  char tsection;
  int tclass;
  gotoxy(5,3);
  cout<<"Enter the class:";
  cin>>tclass;
  gotoxy(5,4);
  cout<<"Enter the section:";
  cin>>tsection;
  tsection=toupper(tsection);
  clrscr();
  int row=6,found=0,flag=0;
  char ch;
  gotoxy(31,2);
  cout<<"LIST OF STUDENTS";
  gotoxy(30,3) ;
  cout<<"~~~~~~~~~~~~~~~~~~";
  gotoxy(1,4);
  cout<<"ADMISSION NO.  BOOK CODE   NAME                         CLASS";
  gotoxy(1,5);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  while (file.read((char *)this,sizeof(student)))
  {
    if (tclass==clas&&tsection==section)
    {
      flag=0;
      delay(20);
      found=1;
      gotoxy(4,row);
      cout<<admission_no;
      gotoxy(18,row);
      cout<<sbook_code;
      gotoxy(28,row);
      cout<<name;
      gotoxy(57,row);
      cout<<clas<<"-"<<section;
      textbackground(WHITE);
      textcolor(BLACK);
      gotoxy(7,row+1);
      if (sbook_code==0)
	cprintf("BOOK NAME:(Not Issued)");
      else
      {
	cprintf("BOOK NAME:%s",B.Book_Name(sbook_code));
	gotoxy(42,row+1);
	cprintf("Date of return:");
	textcolor(BLACK+BLINK);
	cprintf("%d/%d/%d",return_date.date,return_date.month,return_date.year);
      }
      textbackground(BLACK);
      textcolor(LIGHTGRAY);
      if (row==22)
      {
	flag=1;
	row=6;
	gotoxy(1,25);
	cout<<"Press any key to continue or Press <ESC> to exit";
	ch=getch();
	if (ch==27)
	  break;
	clrscr();
	gotoxy(31,2);
	cout<<"LIST OF STUDENTS";
	gotoxy(30,3) ;
	cout<<"~~~~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout<<"ADMISSION NO.  BOOK CODE   NAME                         CLASS";
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
      }
      else
	row=row+2;
    }
  }
  if (!found)
  {
     gotoxy(5,10);
     cout<<"Records not found";
  }
  if (!flag)
  {
     gotoxy(1,25);
     cout<<"Press any key to continue......";
     getche();
  }
  file.close();
}

//FUNCTION TO SHOW LIST OF STUDENT(CLASS STUDENT)
void student::Show_List_Of_Student()
{
  clrscr();
  char tsection;
  int tclass;
  gotoxy(5,3);
  cout<<"Enter the class:";
  cin>>tclass;
  gotoxy(5,4);
  cout<<"Enter the section:";
  cin>>tsection;
  tsection=toupper(tsection);
  clrscr();
  int row=6,found=0,flag=0;
  char ch;
  gotoxy(32,2);
  cout<<"LIST OF STUDENTS";
  gotoxy(31,3) ;
  cout<<"~~~~~~~~~~~~~~~~~~";
  gotoxy(1,4);
  cout<<"ADMISSION NO.   CLASS      NAME                         ";
  gotoxy(1,5);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  fstream file;
  file.open(STUDENT_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  while (file.read((char *)this,sizeof(student)))
  {
    if (tclass==clas&&tsection==section)
    {
      flag=0;
      delay(20);
      found=1;
      gotoxy(4,row);
      cout<<admission_no;
      gotoxy(18,row);
      cout<<clas<<"-"<<section;
      gotoxy(28,row);
      cout<<name;
      if (row==22)
      {
	flag=1;
	row=6;
	gotoxy(1,25);
	cout<<"Press any key to continue or Press <ESC> to exit";
	ch=getch();
	if (ch==27)
	  break;
	clrscr();
	gotoxy(32,2);
	cout<<"LIST OF STUDENTS";
	gotoxy(31,3) ;
	cout<<"~~~~~~~~~~~~~~~~~~";
	gotoxy(1,4);
	cout<<"ADMISSION NO.   CLASS      NAME                         ";
	gotoxy(1,5);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
      }
      else
	row=row+1;
    }
  }
  if (!found)
  {
     gotoxy(5,10);
     cout<<"Records not found";
  }
  if (!flag)
  {
     gotoxy(1,25);
     cout<<"Press any key to continue......";
     getche();
  }
  file.close();
}

//FUNCTION TO VIEW STUDENT RECORD(CLASS STUDENT)
void student::View_Student_Record()
{
  char t1code[10],ch;
  long t2code,tadmission_no;
  int valid;
  student S;
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
      cout<<"Enter Admission Number of the Student:";
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
  Display_Student(tadmission_no);
  getch();
}

/****************************************************************************/