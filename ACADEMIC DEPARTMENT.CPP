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

//STRUCTURE OF SUBJECT FOR CLASS 11 AND 12//
struct SUBJECT_11_12
{
  char name[20];
  int min_marks,max_marks;
};

//////////////////////////////////////////////////////////////////////////////

//STRUCTURE OF EXAM 11 AND 12//
struct EXAM_11_to_12
{
  SUBJECT_11_12 S1,S2,S3,S4,S5;
  float percent,total;
  int f;
  char result[5];
};

//////////////////////////////////////////////////////////////////////////////

//CLASS OF ACADEMIC 11 AND 12//
class academic_11_to_12:public student
{
private:
  long sadmission_no;
  char stream[30];
  EXAM_11_to_12 UT_1,UT_2,HALF_YEARLY,ANNUAL_EXAM,GRAND_TOTAL;

protected:
  int Check_Student_Record(long);
  int Check_Test(long,char[]);
  int Check_Student_Stream(long,char[]);
  int Check_Student_Subject(long,char[]);

public:
  academic_11_to_12();
  void Add_Record(long,char[],char[],SUBJECT_11_12,SUBJECT_11_12,SUBJECT_11_12,SUBJECT_11_12,SUBJECT_11_12);
  void View_Class_Result();
  void View_Student_Result();
  void Add_Marks_Of_Student();
};

/****************************************************************************/

//////////////////////////////////////////////////////////////////////////////
//////////////////////ACADEMIC 11 AND 12 CLASS FUNCTIONS//////////////////////
//////////////////////////////////////////////////////////////////////////////

//FUNCTION TO CHECK STUDENT (EXIST IN ACADEMIC_11_TO_12 FILE OR NOT)(CLASS ACADEMIC_11_TO_12)
int academic_11_to_12::Check_Student_Record(long admno)
{
  fstream file;
  file.open(ACADEMIC_11_12_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int found=0;
  while (file.read((char*)this,sizeof(academic_11_to_12)))
  {
    if (admno==sadmission_no)
    {
      found=1;
      break;
    }
  }
  file.close();
  return found;
}

//FUNCTION TO CHECK THAT MARKS ARE ALREADY ENTERED OR NOT(CLASS ACADEMIC_11_TO_12)
int academic_11_to_12::Check_Test(long admno,char testname[15])
{
  fstream file;
  file.open(ACADEMIC_11_12_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int found=0;
  while (file.read((char*)this,sizeof(academic_11_to_12)))
  {
    if (admno==sadmission_no)
    {
      if (strcmpi(testname,"UT_1")==0)
      {
	if (UT_1.f==1)
	found=1;
      }
      if (strcmpi(testname,"UT_2")==0)
      {
	if (UT_2.f==1)
	found=1;
      }
      if (strcmpi(testname,"HALF_YEARLY")==0)
      {
	if (HALF_YEARLY.f==1)
	found=1;
      }
      if (strcmpi(testname,"ANNUAL_EXAM")==0)
      {
	if (ANNUAL_EXAM.f==1)
	found=1;
      }
      break;
    }
  }
  file.close();
  return found;
}

//FUNCTION TO CHECK STUDENT STREAM(CLASS ACADEMIC_11_TO_12)
int academic_11_to_12::Check_Student_Stream(long admno,char sstream[30])
{
  fstream file;
  file.open(ACADEMIC_11_12_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int found=0;
  while (file.read((char*)this,sizeof(academic_11_to_12)))
  {
    if (admno==sadmission_no)
    {
      if (strcmpi(sstream,stream)==0)
      {
	found=1;
      }
      break;
    }
  }
  file.close();
  return found;
}

//FUNCTION TO CHECK STUDENT OPTIONAL SUBJECT(CLASS ACADEMIC_11_TO_12)
int academic_11_to_12::Check_Student_Subject(long admno,char name[30])
{
  fstream file;
  file.open(ACADEMIC_11_12_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  int found=1;
  while (file.read((char*)this,sizeof(academic_11_to_12)))
  {
    if (admno==sadmission_no)
    {
      if (UT_1.f==1)
	found=strcmpi(UT_1.S5.name,name);
      if (UT_2.f==1)
	found=strcmpi(UT_2.S5.name,name);
      if (HALF_YEARLY.f==1)
	found=strcmpi(HALF_YEARLY.S5.name,name);
      if (ANNUAL_EXAM.f==1)
	found=strcmpi(ANNUAL_EXAM.S5.name,name);
      break;
    }
  }
  file.close();
  return found;
}

//CONSTRUCTOR
academic_11_to_12::academic_11_to_12()
{
sadmission_no=NULL;
strcpy(stream,NULL);

strcpy(UT_1.S1.name,NULL);
UT_1.S1.min_marks=NULL;
UT_1.S1.max_marks=NULL;
strcpy(UT_1.S2.name,NULL);
UT_1.S2.min_marks=NULL;
UT_1.S2.max_marks=NULL;
strcpy(UT_1.S3.name,NULL);
UT_1.S3.min_marks=NULL;
UT_1.S3.max_marks=NULL;
strcpy(UT_1.S4.name,NULL);
UT_1.S4.min_marks=NULL;
UT_1.S4.max_marks=NULL;
strcpy(UT_1.S5.name,NULL);
UT_1.S5.min_marks=NULL;
UT_1.S5.max_marks=NULL;
UT_1.total=NULL;
UT_1.percent=NULL;
UT_1.f=NULL;
strcpy(UT_1.result,NULL);

strcpy(UT_2.S1.name,NULL);
UT_2.S1.min_marks=NULL;
UT_2.S1.max_marks=NULL;
strcpy(UT_2.S2.name,NULL);
UT_2.S2.min_marks=NULL;
UT_2.S2.max_marks=NULL;
strcpy(UT_2.S3.name,NULL);
UT_2.S3.min_marks=NULL;
UT_2.S3.max_marks=NULL;
strcpy(UT_2.S4.name,NULL);
UT_2.S4.min_marks=NULL;
UT_2.S4.max_marks=NULL;
strcpy(UT_2.S5.name,NULL);
UT_2.S5.min_marks=NULL;
UT_2.S5.max_marks=NULL;
UT_2.total=NULL;
UT_2.percent=NULL;
UT_2.f=NULL;
strcpy(UT_2.result,NULL);

strcpy(HALF_YEARLY.S1.name,NULL);
HALF_YEARLY.S1.min_marks=NULL;
HALF_YEARLY.S1.max_marks=NULL;
strcpy(HALF_YEARLY.S2.name,NULL);
HALF_YEARLY.S2.min_marks=NULL;
HALF_YEARLY.S2.max_marks=NULL;
strcpy(HALF_YEARLY.S3.name,NULL);
HALF_YEARLY.S3.min_marks=NULL;
HALF_YEARLY.S3.max_marks=NULL;
strcpy(HALF_YEARLY.S4.name,NULL);
HALF_YEARLY.S4.min_marks=NULL;
HALF_YEARLY.S4.max_marks=NULL;
strcpy(HALF_YEARLY.S5.name,NULL);
HALF_YEARLY.S5.min_marks=NULL;
HALF_YEARLY.S5.max_marks=NULL;
HALF_YEARLY.total=NULL;
HALF_YEARLY.percent=NULL;
HALF_YEARLY.f=NULL;
strcpy(HALF_YEARLY.result,NULL);

strcpy(ANNUAL_EXAM.S1.name,NULL);
ANNUAL_EXAM.S1.min_marks=NULL;
ANNUAL_EXAM.S1.max_marks=NULL;
strcpy(ANNUAL_EXAM.S2.name,NULL);
ANNUAL_EXAM.S2.min_marks=NULL;
ANNUAL_EXAM.S2.max_marks=NULL;
strcpy(ANNUAL_EXAM.S3.name,NULL);
ANNUAL_EXAM.S3.min_marks=NULL;
ANNUAL_EXAM.S3.max_marks=NULL;
strcpy(ANNUAL_EXAM.S4.name,NULL);
ANNUAL_EXAM.S4.min_marks=NULL;
ANNUAL_EXAM.S4.max_marks=NULL;
strcpy(ANNUAL_EXAM.S5.name,NULL);
ANNUAL_EXAM.S5.min_marks=NULL;
ANNUAL_EXAM.S5.max_marks=NULL;
ANNUAL_EXAM.total=NULL;
ANNUAL_EXAM.percent=NULL;
ANNUAL_EXAM.f=NULL;
strcpy(ANNUAL_EXAM.result,NULL);

strcpy(GRAND_TOTAL.S1.name,NULL);
GRAND_TOTAL.S1.min_marks=NULL;
GRAND_TOTAL.S1.max_marks=NULL;
strcpy(GRAND_TOTAL.S2.name,NULL);
GRAND_TOTAL.S2.min_marks=NULL;
GRAND_TOTAL.S2.max_marks=NULL;
strcpy(GRAND_TOTAL.S3.name,NULL);
GRAND_TOTAL.S3.min_marks=NULL;
GRAND_TOTAL.S3.max_marks=NULL;
strcpy(GRAND_TOTAL.S4.name,NULL);
GRAND_TOTAL.S4.min_marks=NULL;
GRAND_TOTAL.S4.max_marks=NULL;
strcpy(GRAND_TOTAL.S5.name,NULL);
GRAND_TOTAL.S5.min_marks=NULL;
GRAND_TOTAL.S5.max_marks=NULL;
GRAND_TOTAL.total=NULL;
GRAND_TOTAL.percent=NULL;
GRAND_TOTAL.f=NULL;
strcpy(GRAND_TOTAL.result,NULL);
}

//FUNCTION TO ADD RECORD OF STUDENT IN ACADEMIC_11_TO_12 FILE(CLASS ACADEMIC_11_TO_12)
void academic_11_to_12::Add_Record(long admno,char testname[15],char sstream[30],SUBJECT_11_12 s1,SUBJECT_11_12 s2,SUBJECT_11_12 s3,SUBJECT_11_12 s4,SUBJECT_11_12 s5)
{
  if (Check_Student_Record(admno)==0)
  {
    fstream file;
    file.open(ACADEMIC_11_12_FILE_NAME,ios::app|ios::binary);
    sadmission_no=admno;
    strcpy(stream,sstream);
    if (strcmpi(testname,"UT_1")==0)
    {
      strcpy(UT_1.S1.name,s1.name);
      UT_1.S1.min_marks=s1.min_marks;
      UT_1.S1.max_marks=s1.max_marks;
      strcpy(UT_1.S2.name,s2.name);
      UT_1.S2.min_marks=s2.min_marks;
      UT_1.S2.max_marks=s2.max_marks;
      strcpy(UT_1.S3.name,s3.name);
      UT_1.S3.min_marks=s3.min_marks;
      UT_1.S3.max_marks=s3.max_marks;
      strcpy(UT_1.S4.name,s4.name);
      UT_1.S4.min_marks=s4.min_marks;
      UT_1.S4.max_marks=s4.max_marks;
      strcpy(UT_1.S5.name,s5.name);
      UT_1.S5.min_marks=s5.min_marks;
      UT_1.S5.max_marks=s5.max_marks;
      UT_1.total=UT_1.S1.min_marks+UT_1.S2.min_marks+UT_1.S3.min_marks+UT_1.S4.min_marks+UT_1.S5.min_marks;
      UT_1.percent=(UT_1.total*100)/(UT_1.S1.max_marks+UT_1.S2.max_marks+UT_1.S3.max_marks+UT_1.S4.max_marks+UT_1.S5.max_marks);
      UT_1.f=1;
      if (UT_1.percent>33)
	strcpy(UT_1.result,"PASS");
      else
	strcpy(UT_1.result,"FAIL");
    }
    if (strcmpi(testname,"UT_2")==0)
    {
      strcpy(UT_2.S1.name,s1.name);
      UT_2.S1.min_marks=s1.min_marks;
      UT_2.S1.max_marks=s1.max_marks;
      strcpy(UT_2.S2.name,s2.name);
      UT_2.S2.min_marks=s2.min_marks;
      UT_2.S2.max_marks=s2.max_marks;
      strcpy(UT_2.S3.name,s3.name);
      UT_2.S3.min_marks=s3.min_marks;
      UT_2.S3.max_marks=s3.max_marks;
      strcpy(UT_2.S4.name,s4.name);
      UT_2.S4.min_marks=s4.min_marks;
      UT_2.S4.max_marks=s4.max_marks;
      strcpy(UT_2.S5.name,s5.name);
      UT_2.S5.min_marks=s5.min_marks;
      UT_2.S5.max_marks=s5.max_marks;
      UT_2.total=UT_2.S1.min_marks+UT_2.S2.min_marks+UT_2.S3.min_marks+UT_2.S4.min_marks+UT_2.S5.min_marks;
      UT_2.percent=(UT_2.total*100)/(UT_2.S1.max_marks+UT_2.S2.max_marks+UT_2.S3.max_marks+UT_2.S4.max_marks+UT_2.S5.max_marks);
      UT_2.f=1;
      if (UT_2.percent>33)
	strcpy(UT_2.result,"PASS");
      else
	strcpy(UT_2.result,"FAIL");
    }
    if (strcmpi(testname,"HALF_YEARLY")==0)
    {
      strcpy(HALF_YEARLY.S1.name,s1.name);
      HALF_YEARLY.S1.min_marks=s1.min_marks;
      HALF_YEARLY.S1.max_marks=s1.max_marks;
      strcpy(HALF_YEARLY.S2.name,s2.name);
      HALF_YEARLY.S2.min_marks=s2.min_marks;
      HALF_YEARLY.S2.max_marks=s2.max_marks;
      strcpy(HALF_YEARLY.S3.name,s3.name);
      HALF_YEARLY.S3.min_marks=s3.min_marks;
      HALF_YEARLY.S3.max_marks=s3.max_marks;
      strcpy(HALF_YEARLY.S4.name,s4.name);
      HALF_YEARLY.S4.min_marks=s4.min_marks;
      HALF_YEARLY.S4.max_marks=s4.max_marks;
      strcpy(HALF_YEARLY.S5.name,s5.name);
      HALF_YEARLY.S5.min_marks=s5.min_marks;
      HALF_YEARLY.S5.max_marks=s5.max_marks;
      HALF_YEARLY.total=HALF_YEARLY.S1.min_marks+HALF_YEARLY.S2.min_marks+HALF_YEARLY.S3.min_marks+HALF_YEARLY.S4.min_marks+HALF_YEARLY.S5.min_marks;
      HALF_YEARLY.percent=(HALF_YEARLY.total*100)/(HALF_YEARLY.S1.max_marks+HALF_YEARLY.S2.max_marks+HALF_YEARLY.S3.max_marks+HALF_YEARLY.S4.max_marks+HALF_YEARLY.S5.max_marks);
      HALF_YEARLY.f=1;
      if (HALF_YEARLY.percent>33)
	strcpy(HALF_YEARLY.result,"PASS");
      else
	strcpy(HALF_YEARLY.result,"FAIL");
    }
    if (strcmpi(testname,"ANNUAL_EXAM")==0)
    {
      strcpy(ANNUAL_EXAM.S1.name,s1.name);
      ANNUAL_EXAM.S1.min_marks=s1.min_marks;
      ANNUAL_EXAM.S1.max_marks=s1.max_marks;
      strcpy(ANNUAL_EXAM.S2.name,s2.name);
      ANNUAL_EXAM.S2.min_marks=s2.min_marks;
      ANNUAL_EXAM.S2.max_marks=s2.max_marks;
      strcpy(ANNUAL_EXAM.S3.name,s3.name);
      ANNUAL_EXAM.S3.min_marks=s3.min_marks;
      ANNUAL_EXAM.S3.max_marks=s3.max_marks;
      strcpy(ANNUAL_EXAM.S4.name,s4.name);
      ANNUAL_EXAM.S4.min_marks=s4.min_marks;
      ANNUAL_EXAM.S4.max_marks=s4.max_marks;
      strcpy(ANNUAL_EXAM.S5.name,s5.name);
      ANNUAL_EXAM.S5.min_marks=s5.min_marks;
      ANNUAL_EXAM.S5.max_marks=s5.max_marks;
      ANNUAL_EXAM.total=ANNUAL_EXAM.S1.min_marks+ANNUAL_EXAM.S2.min_marks+ANNUAL_EXAM.S3.min_marks+ANNUAL_EXAM.S4.min_marks+ANNUAL_EXAM.S5.min_marks;
      ANNUAL_EXAM.percent=(ANNUAL_EXAM.total*100)/(ANNUAL_EXAM.S1.max_marks+ANNUAL_EXAM.S2.max_marks+ANNUAL_EXAM.S3.max_marks+ANNUAL_EXAM.S4.max_marks+ANNUAL_EXAM.S5.max_marks);
      ANNUAL_EXAM.f=1;
      if (ANNUAL_EXAM.percent>33)
	strcpy(ANNUAL_EXAM.result,"PASS");
      else
	strcpy(ANNUAL_EXAM.result,"FAIL");
    }
    file.write((char*)this,sizeof(academic_11_to_12));
    file.close();
  }
  else
  {
    fstream file;
    file.open(ACADEMIC_11_12_FILE_NAME,ios::in|ios::binary);
    fstream temp;
    temp.open("temp",ios::out|ios::binary);
    file.seekg(0,ios::beg);
    while (!file.eof())
    {
      file.read((char*)this,sizeof(academic_11_to_12));
      if (file.eof())
	break;
      if (sadmission_no==admno)
      {
	if (strcmpi(testname,"UT_1")==0)
	{
	  strcpy(UT_1.S1.name,s1.name);
	  UT_1.S1.min_marks=s1.min_marks;
	  UT_1.S1.max_marks=s1.max_marks;
	  strcpy(UT_1.S2.name,s2.name);
	  UT_1.S2.min_marks=s2.min_marks;
	  UT_1.S2.max_marks=s2.max_marks;
	  strcpy(UT_1.S3.name,s3.name);
	  UT_1.S3.min_marks=s3.min_marks;
	  UT_1.S3.max_marks=s3.max_marks;
	  strcpy(UT_1.S4.name,s4.name);
	  UT_1.S4.min_marks=s4.min_marks;
	  UT_1.S4.max_marks=s4.max_marks;
	  strcpy(UT_1.S5.name,s5.name);
	  UT_1.S5.min_marks=s5.min_marks;
	  UT_1.S5.max_marks=s5.max_marks;
	  UT_1.total=UT_1.S1.min_marks+UT_1.S2.min_marks+UT_1.S3.min_marks+UT_1.S4.min_marks+UT_1.S5.min_marks;
	  UT_1.percent=(UT_1.total*100)/(UT_1.S1.max_marks+UT_1.S2.max_marks+UT_1.S3.max_marks+UT_1.S4.max_marks+UT_1.S5.max_marks);
	  UT_1.f=1;
	  if (UT_1.percent>33)
	    strcpy(UT_1.result,"PASS");
	  else
	    strcpy(UT_1.result,"FAIL");
	}
	if (strcmpi(testname,"UT_2")==0)
	{
	  strcpy(UT_2.S1.name,s1.name);
	  UT_2.S1.min_marks=s1.min_marks;
	  UT_2.S1.max_marks=s1.max_marks;
	  strcpy(UT_2.S2.name,s2.name);
	  UT_2.S2.min_marks=s2.min_marks;
	  UT_2.S2.max_marks=s2.max_marks;
	  strcpy(UT_2.S3.name,s3.name);
	  UT_2.S3.min_marks=s3.min_marks;
	  UT_2.S3.max_marks=s3.max_marks;
	  strcpy(UT_2.S4.name,s4.name);
	  UT_2.S4.min_marks=s4.min_marks;
	  UT_2.S4.max_marks=s4.max_marks;
	  strcpy(UT_2.S5.name,s5.name);
	  UT_2.S5.min_marks=s5.min_marks;
	  UT_2.S5.max_marks=s5.max_marks;
	  UT_2.total=UT_2.S1.min_marks+UT_2.S2.min_marks+UT_2.S3.min_marks+UT_2.S4.min_marks+UT_2.S5.min_marks;
	  UT_2.percent=(UT_2.total*100)/(UT_2.S1.max_marks+UT_2.S2.max_marks+UT_2.S3.max_marks+UT_2.S4.max_marks+UT_2.S5.max_marks);
	  UT_2.f=1;
	  if (UT_2.percent>33)
	    strcpy(UT_2.result,"PASS");
	  else
	    strcpy(UT_2.result,"FAIL");
	}
	if (strcmpi(testname,"HALF_YEARLY")==0)
	{
	  strcpy(HALF_YEARLY.S1.name,s1.name);
	  HALF_YEARLY.S1.min_marks=s1.min_marks;
	  HALF_YEARLY.S1.max_marks=s1.max_marks;
	  strcpy(HALF_YEARLY.S2.name,s2.name);
	  HALF_YEARLY.S2.min_marks=s2.min_marks;
	  HALF_YEARLY.S2.max_marks=s2.max_marks;
	  strcpy(HALF_YEARLY.S3.name,s3.name);
	  HALF_YEARLY.S3.min_marks=s3.min_marks;
	  HALF_YEARLY.S3.max_marks=s3.max_marks;
	  strcpy(HALF_YEARLY.S4.name,s4.name);
	  HALF_YEARLY.S4.min_marks=s4.min_marks;
	  HALF_YEARLY.S4.max_marks=s4.max_marks;
	  strcpy(HALF_YEARLY.S5.name,s5.name);
	  HALF_YEARLY.S5.min_marks=s5.min_marks;
	  HALF_YEARLY.S5.max_marks=s5.max_marks;
	  HALF_YEARLY.total=HALF_YEARLY.S1.min_marks+HALF_YEARLY.S2.min_marks+HALF_YEARLY.S3.min_marks+HALF_YEARLY.S4.min_marks+HALF_YEARLY.S5.min_marks;
	  HALF_YEARLY.percent=(HALF_YEARLY.total*100)/(HALF_YEARLY.S1.max_marks+HALF_YEARLY.S2.max_marks+HALF_YEARLY.S3.max_marks+HALF_YEARLY.S4.max_marks+HALF_YEARLY.S5.max_marks);
	  HALF_YEARLY.f=1;
	  if (HALF_YEARLY.percent>33)
	    strcpy(HALF_YEARLY.result,"PASS");
	  else
	    strcpy(HALF_YEARLY.result,"FAIL");
	}
	if (strcmpi(testname,"ANNUAL_EXAM")==0)
	{
	  strcpy(ANNUAL_EXAM.S1.name,s1.name);
	  ANNUAL_EXAM.S1.min_marks=s1.min_marks;
	  ANNUAL_EXAM.S1.max_marks=s1.max_marks;
	  strcpy(ANNUAL_EXAM.S2.name,s2.name);
	  ANNUAL_EXAM.S2.min_marks=s2.min_marks;
	  ANNUAL_EXAM.S2.max_marks=s2.max_marks;
	  strcpy(ANNUAL_EXAM.S3.name,s3.name);
	  ANNUAL_EXAM.S3.min_marks=s3.min_marks;
	  ANNUAL_EXAM.S3.max_marks=s3.max_marks;
	  strcpy(ANNUAL_EXAM.S4.name,s4.name);
	  ANNUAL_EXAM.S4.min_marks=s4.min_marks;
	  ANNUAL_EXAM.S4.max_marks=s4.max_marks;
	  strcpy(ANNUAL_EXAM.S5.name,s5.name);
	  ANNUAL_EXAM.S5.min_marks=s5.min_marks;
	  ANNUAL_EXAM.S5.max_marks=s5.max_marks;
	  ANNUAL_EXAM.total=ANNUAL_EXAM.S1.min_marks+ANNUAL_EXAM.S2.min_marks+ANNUAL_EXAM.S3.min_marks+ANNUAL_EXAM.S4.min_marks+ANNUAL_EXAM.S5.min_marks;
	  ANNUAL_EXAM.percent=(ANNUAL_EXAM.total*100)/(ANNUAL_EXAM.S1.max_marks+ANNUAL_EXAM.S2.max_marks+ANNUAL_EXAM.S3.max_marks+ANNUAL_EXAM.S4.max_marks+ANNUAL_EXAM.S5.max_marks);
	  ANNUAL_EXAM.f=1;
	  if (ANNUAL_EXAM.percent>33)
	    strcpy(ANNUAL_EXAM.result,"PASS");
	  else
	    strcpy(ANNUAL_EXAM.result,"FAIL");
	}
	if (UT_1.f==1&&UT_2.f==1&&HALF_YEARLY.f==1&&ANNUAL_EXAM.f==1)
	{
	  strcpy(GRAND_TOTAL.S1.name,UT_1.S1.name);
	  GRAND_TOTAL.S1.min_marks=UT_1.S1.min_marks+UT_2.S1.min_marks+HALF_YEARLY.S1.min_marks+ANNUAL_EXAM.S1.min_marks;
	  GRAND_TOTAL.S1.max_marks=UT_1.S1.max_marks+UT_2.S1.max_marks+HALF_YEARLY.S1.max_marks+ANNUAL_EXAM.S1.max_marks;
	  strcpy(GRAND_TOTAL.S2.name,UT_1.S2.name);
	  GRAND_TOTAL.S2.min_marks=UT_1.S2.min_marks+UT_2.S2.min_marks+HALF_YEARLY.S2.min_marks+ANNUAL_EXAM.S2.min_marks;
	  GRAND_TOTAL.S2.max_marks=UT_1.S2.max_marks+UT_2.S2.max_marks+HALF_YEARLY.S2.max_marks+ANNUAL_EXAM.S2.max_marks;
	  strcpy(GRAND_TOTAL.S3.name,UT_1.S3.name);
	  GRAND_TOTAL.S3.min_marks=UT_1.S3.min_marks+UT_2.S3.min_marks+HALF_YEARLY.S3.min_marks+ANNUAL_EXAM.S3.min_marks;
	  GRAND_TOTAL.S3.max_marks=UT_1.S3.max_marks+UT_2.S3.max_marks+HALF_YEARLY.S3.max_marks+ANNUAL_EXAM.S3.max_marks;
	  strcpy(GRAND_TOTAL.S4.name,UT_1.S4.name);
	  GRAND_TOTAL.S4.min_marks=UT_1.S4.min_marks+UT_2.S4.min_marks+HALF_YEARLY.S4.min_marks+ANNUAL_EXAM.S4.min_marks;
	  GRAND_TOTAL.S4.max_marks=UT_1.S4.max_marks+UT_2.S4.max_marks+HALF_YEARLY.S4.max_marks+ANNUAL_EXAM.S4.max_marks;
	  strcpy(GRAND_TOTAL.S5.name,UT_1.S5.name);
	  GRAND_TOTAL.S5.min_marks=UT_1.S5.min_marks+UT_2.S5.min_marks+HALF_YEARLY.S5.min_marks+ANNUAL_EXAM.S5.min_marks;
	  GRAND_TOTAL.S5.max_marks=UT_1.S5.max_marks+UT_2.S5.max_marks+HALF_YEARLY.S5.max_marks+ANNUAL_EXAM.S5.max_marks;
	  GRAND_TOTAL.total=GRAND_TOTAL.S1.min_marks+GRAND_TOTAL.S2.min_marks+GRAND_TOTAL.S3.min_marks+GRAND_TOTAL.S4.min_marks+GRAND_TOTAL.S5.min_marks;
	  GRAND_TOTAL.percent=(GRAND_TOTAL.total*100)/(GRAND_TOTAL.S1.max_marks+GRAND_TOTAL.S2.max_marks+GRAND_TOTAL.S3.max_marks+GRAND_TOTAL.S4.max_marks+GRAND_TOTAL.S5.max_marks);
	  GRAND_TOTAL.f=1;
	  if (GRAND_TOTAL.percent>33)
	    strcpy(GRAND_TOTAL.result,"PASS");
	  else
	    strcpy(GRAND_TOTAL.result,"FAIL");
	}
	temp.write((char*)this,sizeof(academic_11_to_12));
      }
      else
	temp.write((char*)this,sizeof(academic_11_to_12)) ;
    }
    file.close();
    temp.close();
    remove(ACADEMIC_11_12_FILE_NAME);
    rename("temp",ACADEMIC_11_12_FILE_NAME);
  }
}

//FUNCTION TO VIEW STUDENT RESULT(CLASS ACADEMIC_11_TO_12)
void academic_11_to_12::View_Student_Result()
{
  char t1code[10],ch;
  long t2code,admno;
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
      gotoxy(5,4);
      cout<<"(Press <ENTER> for help)";
      gotoxy(3,3);
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
    admno=t2code;
    if ((admno==0)||(admno!=0&&!Check_Student_Record(admno))||(Student_Class(admno)!=11&&Student_Class(admno)!=12))
    {
      if (admno==0)
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
      else if(admno!=0&&!Check_Student_Record(admno))
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
      else
      {
	valid=0;
	gotoxy(5,10);
	cout<<"Student class is not 11 or 12......";
	gotoxy(5,12);
	cout<<"Press <ESC> to exit or any other key to continue......";
	ch=getch();
	if (ch==27)
	  return;
      }
    }
  }while(!valid);

  gotoxy(19,6);clreol();
  cout<<Student_Name(admno);
  gotoxy(19,7);clreol();
  cout<<Student_Class(admno)<<"-"<<Student_Section(admno);
  gotoxy(5,6);
  cout<<"Student Name: ";
  gotoxy(5,7);
  cout<<"Class       : ";
  gotoxy(5,8);
  cout<<"Stream      : ";

  gotoxy(33,10);
  cout<<"REPORT CARD";
  gotoxy(32,11) ;
  cout<<"~~~~~~~~~~~~~";
  gotoxy(1,13);
  cout<<"SUBJECT   | UNIT TEST 1 | UNIT TEST 2 | HALF YEARLY | ANNUAL EXAM | GRAND TOTAL";
  gotoxy(1,14);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  gotoxy(1,15);
  cout<<"          |             |             |             |             |            ";
  gotoxy(1,16);
  cout<<"          |             |             |             |             |            ";
  gotoxy(1,17);
  cout<<"          |             |             |             |             |            ";
  gotoxy(1,18);
  cout<<"          |             |             |             |             |            ";
  gotoxy(1,19);
  cout<<"          |             |             |             |             |            ";
  gotoxy(1,20);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  gotoxy(1,21);
  cout<<"          |             |             |             |             |            ";
  gotoxy(1,22);
  cout<<"          |             |             |             |             |            ";
  gotoxy(1,23);
  cout<<"          |             |             |             |             |            ";
  gotoxy(1,24);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  fstream file;
  file.open(ACADEMIC_11_12_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  while (file.read((char *)this,sizeof(academic_11_to_12)))
  {
    if (sadmission_no==admno)
    {
      gotoxy(19,8);clreol();cout<<stream;

      gotoxy(1,15);cout<<UT_1.S1.name;
      gotoxy(15,15);cout<<UT_1.S1.min_marks;gotoxy(18,15);cout<<"/";gotoxy(19,15);cout<<UT_1.S1.max_marks;
      gotoxy(29,15);cout<<UT_2.S1.min_marks;gotoxy(32,15);cout<<"/";gotoxy(33,15);cout<<UT_2.S1.max_marks;
      gotoxy(43,15);cout<<HALF_YEARLY.S1.min_marks;gotoxy(46,15);cout<<"/";gotoxy(47,15);cout<<HALF_YEARLY.S1.max_marks;
      gotoxy(57,15);cout<<ANNUAL_EXAM.S1.min_marks;gotoxy(60,15);cout<<"/";gotoxy(61,15);cout<<ANNUAL_EXAM.S1.max_marks;
      gotoxy(71,15);cout<<GRAND_TOTAL.S1.min_marks;gotoxy(74,15);cout<<"/";gotoxy(75,15);cout<<GRAND_TOTAL.S1.max_marks;

      gotoxy(1,16);cout<<UT_1.S2.name;
      gotoxy(15,16);cout<<UT_1.S2.min_marks;gotoxy(18,16);cout<<"/";gotoxy(19,16);cout<<UT_1.S2.max_marks;
      gotoxy(29,16);cout<<UT_2.S2.min_marks;gotoxy(32,16);cout<<"/";gotoxy(33,16);cout<<UT_2.S2.max_marks;
      gotoxy(43,16);cout<<HALF_YEARLY.S2.min_marks;gotoxy(46,16);cout<<"/";gotoxy(47,16);cout<<HALF_YEARLY.S2.max_marks;
      gotoxy(57,16);cout<<ANNUAL_EXAM.S2.min_marks;gotoxy(60,16);cout<<"/";gotoxy(61,16);cout<<ANNUAL_EXAM.S2.max_marks;
      gotoxy(71,16);cout<<GRAND_TOTAL.S2.min_marks;gotoxy(74,16);cout<<"/";gotoxy(75,16);cout<<GRAND_TOTAL.S2.max_marks;

      gotoxy(1,17);cout<<UT_1.S3.name;
      gotoxy(15,17);cout<<UT_1.S3.min_marks;gotoxy(18,17);cout<<"/";gotoxy(19,17);cout<<UT_1.S3.max_marks;
      gotoxy(29,17);cout<<UT_2.S3.min_marks;gotoxy(32,17);cout<<"/";gotoxy(33,17);cout<<UT_2.S3.max_marks;
      gotoxy(43,17);cout<<HALF_YEARLY.S3.min_marks;gotoxy(46,17);cout<<"/";gotoxy(47,17);cout<<HALF_YEARLY.S3.max_marks;
      gotoxy(57,17);cout<<ANNUAL_EXAM.S3.min_marks;gotoxy(60,17);cout<<"/";gotoxy(61,17);cout<<ANNUAL_EXAM.S3.max_marks;
      gotoxy(71,17);cout<<GRAND_TOTAL.S3.min_marks;gotoxy(74,17);cout<<"/";gotoxy(75,17);cout<<GRAND_TOTAL.S3.max_marks;

      gotoxy(1,18);cout<<UT_1.S4.name;
      gotoxy(15,18);cout<<UT_1.S4.min_marks;gotoxy(18,18);cout<<"/";gotoxy(19,18);cout<<UT_1.S4.max_marks;
      gotoxy(29,18);cout<<UT_2.S4.min_marks;gotoxy(32,18);cout<<"/";gotoxy(33,18);cout<<UT_2.S4.max_marks;
      gotoxy(43,18);cout<<HALF_YEARLY.S4.min_marks;gotoxy(46,18);cout<<"/";gotoxy(47,18);cout<<HALF_YEARLY.S4.max_marks;
      gotoxy(57,18);cout<<ANNUAL_EXAM.S4.min_marks;gotoxy(60,18);cout<<"/";gotoxy(61,18);cout<<ANNUAL_EXAM.S4.max_marks;
      gotoxy(71,18);cout<<GRAND_TOTAL.S4.min_marks;gotoxy(74,18);cout<<"/";gotoxy(75,18);cout<<GRAND_TOTAL.S4.max_marks;

      gotoxy(1,19);cout<<UT_1.S5.name;
      gotoxy(15,19);cout<<UT_1.S5.min_marks;gotoxy(18,19);cout<<"/";gotoxy(19,19);cout<<UT_1.S5.max_marks;
      gotoxy(29,19);cout<<UT_2.S5.min_marks;gotoxy(32,19);cout<<"/";gotoxy(33,19);cout<<UT_2.S5.max_marks;
      gotoxy(43,19);cout<<HALF_YEARLY.S5.min_marks;gotoxy(46,19);cout<<"/";gotoxy(47,19);cout<<HALF_YEARLY.S5.max_marks;
      gotoxy(57,19);cout<<ANNUAL_EXAM.S5.min_marks;gotoxy(60,19);cout<<"/";gotoxy(61,19);cout<<ANNUAL_EXAM.S5.max_marks;
      gotoxy(71,19);cout<<GRAND_TOTAL.S5.min_marks;gotoxy(74,19);cout<<"/";gotoxy(75,19);cout<<GRAND_TOTAL.S5.max_marks;

      gotoxy(1,21);cout<<"TOTAL";
      gotoxy(15,21);cout<<UT_1.total;gotoxy(18,21);cout<<"/";gotoxy(19,21);
      cout<<UT_1.S1.max_marks+UT_1.S2.max_marks+UT_1.S3.max_marks+UT_1.S4.max_marks+UT_1.S5.max_marks;
      gotoxy(29,21);cout<<UT_2.total;gotoxy(32,21);cout<<"/";gotoxy(33,21);
      cout<<UT_2.S1.max_marks+UT_2.S2.max_marks+UT_2.S3.max_marks+UT_2.S4.max_marks+UT_2.S5.max_marks;
      gotoxy(43,21);cout<<HALF_YEARLY.total;gotoxy(46,21);cout<<"/";gotoxy(47,21);
      cout<<HALF_YEARLY.S1.max_marks+HALF_YEARLY.S2.max_marks+HALF_YEARLY.S3.max_marks+HALF_YEARLY.S4.max_marks+HALF_YEARLY.S5.max_marks;
      gotoxy(57,21);cout<<ANNUAL_EXAM.total;gotoxy(60,21);cout<<"/";gotoxy(61,21);
      cout<<ANNUAL_EXAM.S1.max_marks+ANNUAL_EXAM.S2.max_marks+ANNUAL_EXAM.S3.max_marks+ANNUAL_EXAM.S4.max_marks+ANNUAL_EXAM.S5.max_marks;
      gotoxy(71,21);cout<<GRAND_TOTAL.total;gotoxy(74,21);cout<<"/";gotoxy(75,21);
      cout<<GRAND_TOTAL.S1.max_marks+GRAND_TOTAL.S2.max_marks+GRAND_TOTAL.S3.max_marks+GRAND_TOTAL.S4.max_marks+GRAND_TOTAL.S5.max_marks;

      gotoxy(1,22);cout<<"PERCENTAGE";
      gotoxy(15,22);cout<<setprecision(2)<<UT_1.percent<<"%";
      gotoxy(29,22);cout<<setprecision(2)<<UT_2.percent<<"%";
      gotoxy(43,22);cout<<setprecision(2)<<HALF_YEARLY.percent<<"%";
      gotoxy(57,22);cout<<setprecision(2)<<ANNUAL_EXAM.percent<<"%";
      gotoxy(71,22);cout<<setprecision(2)<<GRAND_TOTAL.percent<<"%";

      gotoxy(1,23);cout<<"RESULT";
      gotoxy(15,23);cout<<UT_1.result;
      gotoxy(29,23);cout<<UT_2.result;
      gotoxy(43,23);cout<<HALF_YEARLY.result;
      gotoxy(57,23);cout<<ANNUAL_EXAM.result;
      gotoxy(71,23);cout<<GRAND_TOTAL.result;

      break;
    }
  }
  file.close();
  gotoxy(15,25);
  cout<<"Press any key to exit......";
  getch();
  return;
}

//FUNCTION TO VIEW CLASS RESULT(CLASS ACADEMIC_11_TO_12)
void academic_11_to_12::View_Class_Result()
{
  clrscr();
  char sstream[30],ename[20];
  int tclass;
  gotoxy(60,1);clreol();
  cprintf("[Enter <0> to return]");
  gotoxy(5,3);
  cout<<"Enter the class    :";
  gotoxy(5,4);
  cout<<"Enter the stream   :";
  gotoxy(5,5);
  cout<<"Enter name of exam :";
  int valid=0;
  while (!valid)
  {
    valid=1;
    gotoxy(15,22);
    cprintf("(Enter class (11 or 12))");
    gotoxy(26,3);clreol();
    cin>>tclass;
    if (tclass==0)
      return;
    if (tclass!=11&&tclass!=12)
    {
      valid=0;
      gotoxy(15,22);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid)
  {
    valid=1;
    gotoxy(10,22);
    cprintf("(Enter SM(Science Math),SB(Science Bio),C(Commerce),H(Humanites))");
    gotoxy(26,4);clreol();
    cin>>sstream;
    strupr(sstream);
    if (strcmpi(sstream,"SM")==0)
      strcpy(sstream,"SCIENCE MATH");
    if (strcmpi(sstream,"SB")==0)
      strcpy(sstream,"SCIENCE BIOLOGY");
    if (strcmpi(sstream,"C")==0)
      strcpy(sstream,"COMMERCE");
    if (strcmpi(sstream,"H")==0)
      strcpy(sstream,"HUMANITIES");
    if (sstream[0]=='0')
      return;
    if (strcmpi(sstream,"SCIENCE MATH")!=0&&strcmpi(sstream,"SCIENCE BIOLOGY")!=0&&strcmpi(sstream,"COMMERCE")!=0&&strcmpi(sstream,"HUMANITIES")!=0)
    {
      valid=0;
      gotoxy(10,22);clreol();
      gotoxy(15,22);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }

  valid=0;
  while (!valid)
  {
    valid=1;
    gotoxy(10,22);
    cprintf("(Enter name of exam(UT 1,UT 2,HALF YEARLY,ANNUAL EXAM,GRAND TOTAL))");
    gotoxy(26,5);clreol();
    gets(ename);
    if (ename[0]=='0')
      return;
    if (strcmp(ename,"UT 1")!=0&&strcmp(ename,"UT 2")!=0&&strcmp(ename,"HALF YEARLY")!=0&&strcmp(ename,"ANNUAL EXAM")!=0&&strcmp(ename,"GRAND TOTAL")!=0)
    {
      valid=0;
      gotoxy(13,22);clreol();
      gotoxy(15,22);clreol();
      cprintf("Enter correctly......");
      getch();
    }
  }
  clrscr();
  int row=11,found=0,flag=0;
  char ch;
  gotoxy(28,2);
  cout<<"LIST OF MARKS OF STUDENTS";
  gotoxy(10,4);
  cout<<"CLASS -      STREAM -                   EXAM NAME -";
  gotoxy(18,4);cout<<tclass;gotoxy(32,4);cout<<sstream;gotoxy(62,4);cout<<ename;
  gotoxy(1,5) ;
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  gotoxy(1,6);
  if (strcmpi(sstream,"SCIENCE MATH")==0)
    cout<<"         |                         | E | P | C |  M  | OP | TOTAL |            ";
  if (strcmpi(sstream,"SCIENCE BIOLOGY")==0)
    cout<<"         |                         | E | P | C |  B  | OP | TOTAL |            ";
  if (strcmpi(sstream,"COMMERCE")==0)
    cout<<"         |                         | E | A |BSt| ECO | OP | TOTAL |            ";
  if (strcmpi(sstream,"HUMANITIES")==0)
    cout<<"         |                         | E | H |PS | ECO | OP | TOTAL |            ";
  gotoxy(1,7);
  cout<<"         |                         |~~~|~~~|~~~|~~~~~|~~~~|~~~~~~~|";
  gotoxy(1,8);
  cout<<"ADM. NO. |          NAME           |MAX|MAX|MAX| MAX |MAX |  MAX  | PERCENTAGE ";
  gotoxy(1,9);
  cout<<"         |                         |   |   |   |     |    |       |            ";
  gotoxy(1,10);
  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
  fstream file;
  file.open(ACADEMIC_11_12_FILE_NAME,ios::in|ios::binary);
  file.seekg(0,ios::beg);
  while (file.read((char *)this,sizeof(academic_11_to_12)))
  {
    if (tclass==Student_Class(sadmission_no)&&strcmpi(stream,sstream)==0)
    {
      flag=0;
      delay(20);
      found=1;
      if (strcmpi(ename,"UT 1")==0)
      {
	gotoxy(37,9);cout<<UT_1.S1.max_marks;
	gotoxy(41,9);cout<<UT_1.S2.max_marks;
	gotoxy(45,9);cout<<UT_1.S3.max_marks;
	gotoxy(50,9);cout<<UT_1.S4.max_marks;
	gotoxy(55,9);cout<<UT_1.S5.max_marks;
	gotoxy(62,9);cout<<UT_1.S1.max_marks+UT_1.S2.max_marks+UT_1.S3.max_marks+UT_1.S4.max_marks+UT_1.S5.max_marks;

	gotoxy(1,row);
	cout<<"         |                         |   |   |   |     |    |       |            ";
	gotoxy(3,row);cout<<sadmission_no;
	gotoxy(11,row);cout<<Student_Name(sadmission_no)<<" ["<<UT_1.S5.name<<"]";
	gotoxy(37,row);cout<<UT_1.S1.min_marks;
	gotoxy(41,row);cout<<UT_1.S2.min_marks;
	gotoxy(45,row);cout<<UT_1.S3.min_marks;
	gotoxy(50,row);cout<<UT_1.S4.min_marks;
	gotoxy(55,row);cout<<UT_1.S5.min_marks;
	gotoxy(62,row);cout<<UT_1.total;
	gotoxy(70,row);cout<<setprecision(2)<<UT_1.percent<<"%";

	if (row==22)
	{
	  flag=1;
	  row=11;
	  gotoxy(1,25);
	  cout<<"Press any key to continue or Press <ESC> to exit";
	  ch=getch();
	  if (ch==27)
	    break;
	  clrscr();
	  gotoxy(28,2);
	  cout<<"LIST OF MARKS OF STUDENTS";
	  gotoxy(10,4);
	  cout<<"CLASS -      STREAM -                   EXAM NAME -";
	  gotoxy(18,4);cout<<tclass;gotoxy(32,4);cout<<sstream;gotoxy(62,4);cout<<ename;
	  gotoxy(1,5) ;
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(1,6);
	  if (strcmpi(sstream,"SCIENCE MATH")==0)
	    cout<<"         |                         | E | P | C |  M  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"SCIENCE BIOLOGY")==0)
	    cout<<"         |                         | E | P | C |  B  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"COMMERCE")==0)
	    cout<<"         |                         | E | A |BSt| ECO | OP | TOTAL |            ";
	  if (strcmpi(sstream,"HUMANITIES")==0)
	    cout<<"         |                         | E | H |PS | ECO | OP | TOTAL |            ";
	  gotoxy(1,7);
	  cout<<"         |                         |~~~|~~~|~~~|~~~~~|~~~~|~~~~~~~|";
	  gotoxy(1,8);
	  cout<<"ADM. NO. |          NAME           |MAX|MAX|MAX| MAX |MAX |  MAX  | PERCENTAGE ";
	  gotoxy(1,9);
	  cout<<"         |                         |   |   |   |     |    |       |            ";
	  gotoxy(1,10);
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	}
	else
	  row=row+1;
      }
      if (strcmpi(ename,"UT 2")==0)
      {
	gotoxy(37,9);cout<<UT_2.S1.max_marks;
	gotoxy(41,9);cout<<UT_2.S2.max_marks;
	gotoxy(45,9);cout<<UT_2.S3.max_marks;
	gotoxy(50,9);cout<<UT_2.S4.max_marks;
	gotoxy(55,9);cout<<UT_2.S5.max_marks;
	gotoxy(62,9);cout<<UT_2.S1.max_marks+UT_2.S2.max_marks+UT_2.S3.max_marks+UT_2.S4.max_marks+UT_2.S5.max_marks;

	gotoxy(1,row);
	cout<<"         |                         |   |   |   |     |    |       |            ";
	gotoxy(3,row);cout<<sadmission_no;
	gotoxy(11,row);cout<<Student_Name(sadmission_no)<<" ["<<UT_1.S5.name<<"]";
	gotoxy(37,row);cout<<UT_2.S1.min_marks;
	gotoxy(41,row);cout<<UT_2.S2.min_marks;
	gotoxy(45,row);cout<<UT_2.S3.min_marks;
	gotoxy(50,row);cout<<UT_2.S4.min_marks;
	gotoxy(55,row);cout<<UT_2.S5.min_marks;
	gotoxy(62,row);cout<<UT_2.total;
	gotoxy(70,row);cout<<setprecision(2)<<UT_2.percent<<"%";

	if (row==22)
	{
	  flag=1;
	  row=11;
	  gotoxy(1,25);
	  cout<<"Press any key to continue or Press <ESC> to exit";
	  ch=getch();
	  if (ch==27)
	    break;
	  clrscr();
	  gotoxy(28,2);
	  cout<<"LIST OF MARKS OF STUDENTS";
	  gotoxy(10,4);
	  cout<<"CLASS -      STREAM -                   EXAM NAME -";
	  gotoxy(18,4);cout<<tclass;gotoxy(32,4);cout<<sstream;gotoxy(62,4);cout<<ename;
	  gotoxy(1,5) ;
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(1,6);
	  if (strcmpi(sstream,"SCIENCE MATH")==0)
	    cout<<"         |                         | E | P | C |  M  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"SCIENCE BIOLOGY")==0)
	    cout<<"         |                         | E | P | C |  B  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"COMMERCE")==0)
	    cout<<"         |                         | E | A |BSt| ECO | OP | TOTAL |            ";
	  if (strcmpi(sstream,"HUMANITIES")==0)
	    cout<<"         |                         | E | H |PS | ECO | OP | TOTAL |            ";
	  gotoxy(1,7);
	  cout<<"         |                         |~~~|~~~|~~~|~~~~~|~~~~|~~~~~~~|";
	  gotoxy(1,8);
	  cout<<"ADM. NO. |          NAME           |MAX|MAX|MAX| MAX |MAX |  MAX  | PERCENTAGE ";
	  gotoxy(1,9);
	  cout<<"         |                         |   |   |   |     |    |       |            ";
	  gotoxy(1,10);
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	}
	else
	  row=row+1;
      }
      if (strcmpi(ename,"HALF YEARLY")==0)
      {
	gotoxy(37,9);cout<<HALF_YEARLY.S1.max_marks;
	gotoxy(41,9);cout<<HALF_YEARLY.S2.max_marks;
	gotoxy(45,9);cout<<HALF_YEARLY.S3.max_marks;
	gotoxy(50,9);cout<<HALF_YEARLY.S4.max_marks;
	gotoxy(55,9);cout<<HALF_YEARLY.S5.max_marks;
	gotoxy(62,9);cout<<HALF_YEARLY.S1.max_marks+HALF_YEARLY.S2.max_marks+HALF_YEARLY.S3.max_marks+HALF_YEARLY.S4.max_marks+HALF_YEARLY.S5.max_marks;

	gotoxy(1,row);
	cout<<"         |                         |   |   |   |     |    |       |            ";
	gotoxy(3,row);cout<<sadmission_no;
	gotoxy(11,row);cout<<Student_Name(sadmission_no)<<" ["<<UT_1.S5.name<<"]";
	gotoxy(37,row);cout<<HALF_YEARLY.S1.min_marks;
	gotoxy(41,row);cout<<HALF_YEARLY.S2.min_marks;
	gotoxy(45,row);cout<<HALF_YEARLY.S3.min_marks;
	gotoxy(50,row);cout<<HALF_YEARLY.S4.min_marks;
	gotoxy(55,row);cout<<HALF_YEARLY.S5.min_marks;
	gotoxy(62,row);cout<<HALF_YEARLY.total;
	gotoxy(70,row);cout<<setprecision(2)<<HALF_YEARLY.percent<<"%";

	if (row==22)
	{
	  flag=1;
	  row=11;
	  gotoxy(1,25);
	  cout<<"Press any key to continue or Press <ESC> to exit";
	  ch=getch();
	  if (ch==27)
	    break;
	  clrscr();
	  gotoxy(28,2);
	  cout<<"LIST OF MARKS OF STUDENTS";
	  gotoxy(10,4);
	  cout<<"CLASS -      STREAM -                   EXAM NAME -";
	  gotoxy(18,4);cout<<tclass;gotoxy(32,4);cout<<sstream;gotoxy(62,4);cout<<ename;
	  gotoxy(1,5) ;
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(1,6);
	  if (strcmpi(sstream,"SCIENCE MATH")==0)
	    cout<<"         |                         | E | P | C |  M  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"SCIENCE BIOLOGY")==0)
	    cout<<"         |                         | E | P | C |  B  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"COMMERCE")==0)
	    cout<<"         |                         | E | A |BSt| ECO | OP | TOTAL |            ";
	  if (strcmpi(sstream,"HUMANITIES")==0)
	    cout<<"         |                         | E | H |PS | ECO | OP | TOTAL |            ";
	  gotoxy(1,7);
	  cout<<"         |                         |~~~|~~~|~~~|~~~~~|~~~~|~~~~~~~|";
	  gotoxy(1,8);
	  cout<<"ADM. NO. |          NAME           |MAX|MAX|MAX| MAX |MAX |  MAX  | PERCENTAGE ";
	  gotoxy(1,9);
	  cout<<"         |                         |   |   |   |     |    |       |            ";
	  gotoxy(1,10);
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	}
	else
	  row=row+1;
      }
      if (strcmpi(ename,"ANNUAL EXAM")==0)
      {
	gotoxy(37,9);cout<<ANNUAL_EXAM.S1.max_marks;
	gotoxy(41,9);cout<<ANNUAL_EXAM.S2.max_marks;
	gotoxy(45,9);cout<<ANNUAL_EXAM.S3.max_marks;
	gotoxy(50,9);cout<<ANNUAL_EXAM.S4.max_marks;
	gotoxy(55,9);cout<<ANNUAL_EXAM.S5.max_marks;
	gotoxy(62,9);cout<<ANNUAL_EXAM.S1.max_marks+ANNUAL_EXAM.S2.max_marks+ANNUAL_EXAM.S3.max_marks+ANNUAL_EXAM.S4.max_marks+ANNUAL_EXAM.S5.max_marks;

	gotoxy(1,row);
	cout<<"         |                         |   |   |   |     |    |       |            ";
	gotoxy(3,row);cout<<sadmission_no;
	gotoxy(11,row);cout<<Student_Name(sadmission_no)<<" ["<<UT_1.S5.name<<"]";
	gotoxy(37,row);cout<<ANNUAL_EXAM.S1.min_marks;
	gotoxy(41,row);cout<<ANNUAL_EXAM.S2.min_marks;
	gotoxy(45,row);cout<<ANNUAL_EXAM.S3.min_marks;
	gotoxy(50,row);cout<<ANNUAL_EXAM.S4.min_marks;
	gotoxy(55,row);cout<<ANNUAL_EXAM.S5.min_marks;
	gotoxy(62,row);cout<<ANNUAL_EXAM.total;
	gotoxy(70,row);cout<<setprecision(2)<<ANNUAL_EXAM.percent<<"%";

	if (row==22)
	{
	  flag=1;
	  row=11;
	  gotoxy(1,25);
	  cout<<"Press any key to continue or Press <ESC> to exit";
	  ch=getch();
	  if (ch==27)
	    break;
	  clrscr();
	  gotoxy(28,2);
	  cout<<"LIST OF MARKS OF STUDENTS";
	  gotoxy(10,4);
	  cout<<"CLASS -      STREAM -                   EXAM NAME -";
	  gotoxy(18,4);cout<<tclass;gotoxy(32,4);cout<<sstream;gotoxy(62,4);cout<<ename;
	  gotoxy(1,5) ;
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(1,6);
	  if (strcmpi(sstream,"SCIENCE MATH")==0)
	    cout<<"         |                         | E | P | C |  M  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"SCIENCE BIOLOGY")==0)
	    cout<<"         |                         | E | P | C |  B  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"COMMERCE")==0)
	    cout<<"         |                         | E | A |BSt| ECO | OP | TOTAL |            ";
	  if (strcmpi(sstream,"HUMANITIES")==0)
	    cout<<"         |                         | E | H |PS | ECO | OP | TOTAL |            ";
	  gotoxy(1,7);
	  cout<<"         |                         |~~~|~~~|~~~|~~~~~|~~~~|~~~~~~~|";
	  gotoxy(1,8);
	  cout<<"ADM. NO. |          NAME           |MAX|MAX|MAX| MAX |MAX |  MAX  | PERCENTAGE ";
	  gotoxy(1,9);
	  cout<<"         |                         |   |   |   |     |    |       |            ";
	  gotoxy(1,10);
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	}
	else
	  row=row+1;
      }
      if (strcmpi(ename,"GRAND TOTAL")==0)
      {
	gotoxy(37,9);cout<<GRAND_TOTAL.S1.max_marks;
	gotoxy(41,9);cout<<GRAND_TOTAL.S2.max_marks;
	gotoxy(45,9);cout<<GRAND_TOTAL.S3.max_marks;
	gotoxy(50,9);cout<<GRAND_TOTAL.S4.max_marks;
	gotoxy(55,9);cout<<GRAND_TOTAL.S5.max_marks;
	gotoxy(62,9);cout<<GRAND_TOTAL.S1.max_marks+GRAND_TOTAL.S2.max_marks+GRAND_TOTAL.S3.max_marks+GRAND_TOTAL.S4.max_marks+GRAND_TOTAL.S5.max_marks;

	gotoxy(1,row);
	cout<<"         |                         |   |   |   |     |    |       |            ";
	gotoxy(3,row);cout<<sadmission_no;
	gotoxy(11,row);cout<<Student_Name(sadmission_no)<<" ["<<UT_1.S5.name<<"]";
	gotoxy(37,row);cout<<GRAND_TOTAL.S1.min_marks;
	gotoxy(41,row);cout<<GRAND_TOTAL.S2.min_marks;
	gotoxy(45,row);cout<<GRAND_TOTAL.S3.min_marks;
	gotoxy(50,row);cout<<GRAND_TOTAL.S4.min_marks;
	gotoxy(55,row);cout<<GRAND_TOTAL.S5.min_marks;
	gotoxy(62,row);cout<<GRAND_TOTAL.total;
	gotoxy(70,row);cout<<setprecision(2)<<GRAND_TOTAL.percent<<"%";

	if (row==22)
	{
	  flag=1;
	  row=11;
	  gotoxy(1,25);
	  cout<<"Press any key to continue or Press <ESC> to exit";
	  ch=getch();
	  if (ch==27)
	    break;
	  clrscr();
	  gotoxy(28,2);
	  cout<<"LIST OF MARKS OF STUDENTS";
	  gotoxy(10,4);
	  cout<<"CLASS -      STREAM -                   EXAM NAME -";
	  gotoxy(18,4);cout<<tclass;gotoxy(32,4);cout<<sstream;gotoxy(62,4);cout<<ename;
	  gotoxy(1,5) ;
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	  gotoxy(1,6);
	  if (strcmpi(sstream,"SCIENCE MATH")==0)
	    cout<<"         |                         | E | P | C |  M  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"SCIENCE BIOLOGY")==0)
	    cout<<"         |                         | E | P | C |  B  | OP | TOTAL |            ";
	  if (strcmpi(sstream,"COMMERCE")==0)
	    cout<<"         |                         | E | A |BSt| ECO | OP | TOTAL |            ";
	  if (strcmpi(sstream,"HUMANITIES")==0)
	    cout<<"         |                         | E | H |PS | ECO | OP | TOTAL |            ";
	  gotoxy(1,7);
	  cout<<"         |                         |~~~|~~~|~~~|~~~~~|~~~~|~~~~~~~|";
	  gotoxy(1,8);
	  cout<<"ADM. NO. |          NAME           |MAX|MAX|MAX| MAX |MAX |  MAX  | PERCENTAGE ";
	  gotoxy(1,9);
	  cout<<"         |                         |   |   |   |     |    |       |            ";
	  gotoxy(1,10);
	  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	}
	else
	  row=row+1;
      }
    }
  }
  if (!found)
  {
     gotoxy(8,15);
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

//FUNCTION TO ADD MARKS OF STUDENT(CLASS ACADEMIC_11_TO_12)
void academic_11_to_12::Add_Marks_Of_Student()
{
  long admno;
  student S;
  char sstream[30],testname[15],ch;
  SUBJECT_11_12 s1,s2,s3,s4,s5;
  int found=0,valid=0,tc;
  long td;
  char t[50],t1[50];
  do
  {
    valid=1;
    while(1)
    {
      clrscr();
      gotoxy(60,1);clreol();
      cprintf("[Enter <0> to return]");
      gotoxy(5,4);
      cout<<"(Press <ENTER> for help)";
      gotoxy(3,3);clreol();
      cout<<"Enter Admission Number of the Student:";
      gets(t);
      td=atoi(t);
      admno=td;
      if (t[0]=='0')
	return;
      if (strlen(t)==0)
	S.Show_List_Of_Student();
      else
	break;
    }
    if(!Check_Student(admno)||td==0||(Student_Class(admno)!=11&&Student_Class(admno)!=12))
    {
      if (!Check_Student(admno)||td==0)
      {
	found=1;
	gotoxy(3,6);clreol();
	cprintf("You have entered invalid admission number......");
	gotoxy(3,8);clreol();
	cprintf("Press any key to exit......");
	getch();
	return;
      }
      else
      {
	found=1;
	gotoxy(3,6);clreol();
	cout<<"Student class is not 11 or 12......";
	gotoxy(3,8);clreol();
	cprintf("Press any key to exit......");
	getch();
	return;
      }
    }
    else
    {
      gotoxy(19,4);clreol();
      cout<<Student_Name(admno);
      gotoxy(19,5);clreol();
      cout<<Student_Class(admno)<<"-"<<Student_Section(admno);
      gotoxy(5,4);
      cout<<"Student Name: ";
      gotoxy(5,5);
      cout<<"Class       : ";
      gotoxy(5,8);clreol();
      cout<<"Check student name and class......";
      gotoxy(5,9);clreol();
      cout<<"Press <ESC> to exit or any other key to continue......";
      ch=getch();
      if (ch==27)
	return;
      gotoxy(3,9);clreol();
      gotoxy(3,8);clreol();
      cout<<"Enter stream of student: ";

      valid=0;
      while (!valid)
      {
	valid=1;
	gotoxy(10,22);
	cprintf("(Enter SM(Science Math),SB(Science Bio),C(Commerce),H(Humanites))");
	gotoxy(28,8);clreol();
	cin>>sstream;
	strupr(sstream);
	if (strcmpi(sstream,"SM")==0)
	  strcpy(sstream,"SCIENCE MATH");
	if (strcmpi(sstream,"SB")==0)
	  strcpy(sstream,"SCIENCE BIOLOGY");
	if (strcmpi(sstream,"C")==0)
	  strcpy(sstream,"COMMERCE");
	if (strcmpi(sstream,"H")==0)
	  strcpy(sstream,"HUMANITIES");
	if (sstream[0]=='0')
	  return;
	if (Check_Student_Record(admno)!=0&&Check_Student_Stream(admno,sstream)==0)
	{
	    valid=0;
	    gotoxy(10,22);clreol();
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly......");
	    getch();
	}
	if (strcmpi(sstream,"SCIENCE MATH")!=0&&strcmpi(sstream,"SCIENCE BIOLOGY")!=0&&strcmpi(sstream,"COMMERCE")!=0&&strcmpi(sstream,"HUMANITIES")!=0)
	{
	  valid=0;
	  gotoxy(10,22);clreol();
	  gotoxy(15,22);clreol();
	  cprintf("Enter correctly......");
	  getch();
	}
      }
      gotoxy(10,22);clreol();

      if (strcmpi(sstream,"SCIENCE MATH")==0)
      {
	strcpy(sstream,"SCIENCE MATH");
	gotoxy(3,8);clreol();
	cout<<"Enter name of test: ";
	valid=0;
	while (!valid)
	{
	  valid=1;
	  gotoxy(15,22);
	  cprintf("(Enter UT_1,UT_2,HALF_YEARLY,ANNUAL_EXAM)");
	  gotoxy(25,8);clreol();
	  cin>>testname;
	  strupr(testname);
	  if (testname[0]=='0')
	    return;
	  if (strcmpi(testname,"UT_1")!=0&&strcmpi(testname,"UT_2")!=0&&strcmpi(testname,"HALF_YEARLY")!=0&&strcmpi(testname,"ANNUAL_EXAM")!=0)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly......");
	    getch();
	  }
	}
	gotoxy(15,22);clreol();
	if (Check_Test(admno,testname)==1)
	{
	  gotoxy(5,10);clreol();
	  cprintf("Marks are already entered......");
	  gotoxy(5,12);clreol();
	  cprintf("Press any key to exit......");
	  getch();
	  return;
	}
	gotoxy(3,10);clreol();
	cprintf("Enter marks in  English   : MAX.=      MIN.=");
	gotoxy(3,11);clreol();
	cprintf("Enter marks in  Physic    : MAX.=      MIN.=");
	gotoxy(3,12);clreol();
	cprintf("Enter marks in  Chemistry : MAX.=      MIN.=");
	gotoxy(3,13);clreol();
	cprintf("Enter marks in  Math      : MAX.=      MIN.=");
	gotoxy(3,14);clreol();
	cprintf("Enter marks in  Optional  : NAME-      MAX.=      MIN.=");

	strcpy(s1.name,"ENGLISH");
	valid=0;
	while (!valid)
	{
	  gotoxy(3,10);clreol();
	  cprintf("Enter marks in  English   : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in english)");
	  gotoxy(37,10);
	  gets(t);
	  tc=atoi(t);
	  s1.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s1.max_marks<1||s1.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in english)");
	  gotoxy(48,10);clreol();
	  gets(t);
	  tc=atoi(t);
	  s1.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s1.min_marks<1||s1.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s2.name,"PHYSIC");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,11);clreol();
	  cprintf("Enter marks in  Physic    : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in physic)");
	  gotoxy(37,11);
	  gets(t);
	  tc=atoi(t);
	  s2.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s2.max_marks<1||s2.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in physic)");
	  gotoxy(48,11);clreol();
	  gets(t);
	  tc=atoi(t);
	  s2.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s2.min_marks<1||s2.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s3.name,"CHEMISTRY");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,12);clreol();
	  cprintf("Enter marks in  Chemistry : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in chemistry)");
	  gotoxy(37,12);
	  gets(t);
	  tc=atoi(t);
	  s3.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s3.max_marks<1||s3.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in chemistry)");
	  gotoxy(48,12);clreol();
	  gets(t);
	  tc=atoi(t);
	  s3.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s3.min_marks<1||s3.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s4.name,"MATH");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,13);clreol();
	  cprintf("Enter marks in  Math      : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in math)");
	  gotoxy(37,13);
	  gets(t);
	  tc=atoi(t);
	  s4.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s4.max_marks<1||s4.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in math)");
	  gotoxy(48,13);clreol();
	  gets(t);
	  tc=atoi(t);
	  s4.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s4.min_marks<1||s4.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,14);clreol();
	  cprintf("Enter marks in  Optional  : NAME-      MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter name of optional subject(CS,IP,PE,HINDI))");
	  gotoxy(37,14);
	  gets(s5.name);
	  strupr(s5.name);
	  if (s5.name[0]=='0')
	    return;
	  if (Check_Student_Record(admno)!=0)
	  {
	    if(Check_Student_Subject(admno,s5.name)!=0)
	    {
	      valid=0;
	      gotoxy(15,22);clreol();
	      cprintf("Enter correctly......");
	      getch();
	    }
	  }
	  if (strcmpi(s5.name,"CS")!=0&&strcmpi(s5.name,"IP")!=0&&strcmpi(s5.name,"HINDI")!=0&&strcmpi(s5.name,"PE")!=0)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(42,14);clreol();
	  cprintf("MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in %s)",s5.name);
	  gotoxy(48,14);
	  gets(t);
	  tc=atoi(t);
	  s5.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s5.max_marks<1||s5.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in %s)",s5.name);
	  gotoxy(59,14);clreol();
	  gets(t);
	  tc=atoi(t);
	  s5.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s5.min_marks<1||s5.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}
      }

      if (strcmpi(sstream,"SCIENCE BIOLOGY")==0)
      {
	strcpy(sstream,"SCIENCE BIOLOGY");
	gotoxy(3,8);clreol();
	cout<<"Enter name of test: ";
	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);
	  cprintf("(Enter UT_1,UT_2,HALF_YEARLY,ANNUAL_EXAM)");
	  gotoxy(25,8);
	  cin>>testname;
	  strupr(testname);
	  if (testname[0]=='0')
	    return;
	  if (strcmpi(testname,"UT_1")!=0&&strcmpi(testname,"UT_2")!=0&&strcmpi(testname,"HALF_YEARLY")!=0&&strcmpi(testname,"ANNUAL_EXAM")!=0)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly......");
	    getch();
	  }
	}
	gotoxy(15,22);clreol();
	if (Check_Test(admno,testname)==1)
	{
	  gotoxy(5,10);clreol();
	  cprintf("Marks are already entered......");
	  gotoxy(5,12);clreol();
	  cprintf("Press any key to exit......");
	  getch();
	  return;
	}
	gotoxy(3,10);clreol();
	cprintf("Enter marks in  English   : MAX.=      MIN.=");
	gotoxy(3,11);clreol();
	cprintf("Enter marks in  Physic    : MAX.=      MIN.=");
	gotoxy(3,12);clreol();
	cprintf("Enter marks in  Chemistry : MAX.=      MIN.=");
	gotoxy(3,13);clreol();
	cprintf("Enter marks in  Biology   : MAX.=      MIN.=");
	gotoxy(3,14);clreol();
	cprintf("Enter marks in  Optional  : NAME-      MAX.=      MIN.=");

	strcpy(s1.name,"ENGLISH");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,10);clreol();
	  cprintf("Enter marks in  English   : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in english)");
	  gotoxy(37,10);
	  gets(t);
	  tc=atoi(t);
	  s1.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s1.max_marks<1||s1.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in english)");
	  gotoxy(48,10);clreol();
	  gets(t);
	  tc=atoi(t);
	  s1.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s1.min_marks<1||s1.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s2.name,"PHYSIC");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,11);clreol();
	  cprintf("Enter marks in  Physic    : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in physic)");
	  gotoxy(37,11);
	  gets(t);
	  tc=atoi(t);
	  s2.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s2.max_marks<1||s2.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in physic)");
	  gotoxy(48,11);clreol();
	  gets(t);
	  tc=atoi(t);
	  s2.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s2.min_marks<1||s2.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s3.name,"CHEMISTRY");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,12);clreol();
	  cprintf("Enter marks in  Chemistry : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in chemistry)");
	  gotoxy(37,12);
	  gets(t);
	  tc=atoi(t);
	  s3.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s3.max_marks<1||s3.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in chemistry)");
	  gotoxy(48,12);clreol();
	  gets(t);
	  tc=atoi(t);
	  s3.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s3.min_marks<1||s3.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s4.name,"BIOLOGY");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,13);clreol();
	  cprintf("Enter marks in  Biology   : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in biology)");
	  gotoxy(37,13);
	  gets(t);
	  tc=atoi(t);
	  s4.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s4.max_marks<1||s4.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in biology)");
	  gotoxy(48,13);clreol();
	  gets(t);
	  tc=atoi(t);
	  s4.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s4.min_marks<1||s4.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,14);clreol();
	  cprintf("Enter marks in  Optional  : NAME-      MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter name of optional subject(CS,IP,PE,HINDI))");
	  gotoxy(37,14);
	  gets(s5.name);
	  strupr(s5.name);
	  if (s5.name[0]=='0')
	    return;
	  if (Check_Student_Record(admno)==1)
	  {
	    if(Check_Student_Subject(admno,s5.name)!=0)
	    {
	      valid=0;
	      gotoxy(15,22);clreol();
	      cprintf("Enter correctly......");
	      getch();
	    }
	  }
	  if (strcmpi(s5.name,"CS")!=0&&strcmpi(s5.name,"IP")!=0&&strcmpi(s5.name,"HINDI")!=0&&strcmpi(s5.name,"PE")!=0)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(42,14);clreol();
	  cprintf("MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in %s)",s5.name);
	  gotoxy(48,14);
	  gets(t);
	  tc=atoi(t);
	  s5.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s5.max_marks<1||s5.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in %s)",s5.name);
	  gotoxy(59,14);clreol();
	  gets(t);
	  tc=atoi(t);
	  s5.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s5.min_marks<1||s5.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}
      }

      if (strcmpi(sstream,"COMMERCE")==0)
      {
	strcpy(sstream,"COMMERCE");
	gotoxy(3,8);clreol();
	cout<<"Enter name of test: ";
	valid=0;
	while (!valid)
	{
	  valid=1;
	  gotoxy(15,22);
	  cprintf("(Enter UT_1,UT_2,HALF_YEARLY,ANNUAL_EXAM)");
	  gotoxy(25,8);clreol();
	  cin>>testname;
	  strupr(testname);
	  if (testname[0]=='0')
	    return;
	  if (strcmpi(testname,"UT_1")!=0&&strcmpi(testname,"UT_2")!=0&&strcmpi(testname,"HALF_YEARLY")!=0&&strcmpi(testname,"ANNUAL_EXAM")!=0)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly......");
	    getch();
	  }
	}
	gotoxy(15,22);clreol();
	if (Check_Test(admno,testname)==1)
	{
	  gotoxy(5,10);clreol();
	  cprintf("Marks are already entered......");
	  gotoxy(5,12);clreol();
	  cprintf("Press any key to exit......");
	  getch();
	  return;
	}
	gotoxy(3,10);clreol();
	cprintf("Enter marks in  English   : MAX.=      MIN.=");
	gotoxy(3,11);clreol();
	cprintf("Enter marks in  Accounts  : MAX.=      MIN.=");
	gotoxy(3,12);clreol();
	cprintf("Enter marks in  B.St.     : MAX.=      MIN.=");
	gotoxy(3,13);clreol();
	cprintf("Enter marks in  Economic  : MAX.=      MIN.=");
	gotoxy(3,14);clreol();
	cprintf("Enter marks in  Optional  : NAME-      MAX.=      MIN.=");

	strcpy(s1.name,"ENGLISH");
	valid=0;
	while (!valid)
	{
	  gotoxy(3,10);clreol();
	  cprintf("Enter marks in  English   : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in english)");
	  gotoxy(37,10);
	  gets(t);
	  tc=atoi(t);
	  s1.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s1.max_marks<1||s1.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in english)");
	  gotoxy(48,10);clreol();
	  gets(t);
	  tc=atoi(t);
	  s1.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s1.min_marks<1||s1.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s2.name,"ACCOUNTS");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,11);clreol();
	  cprintf("Enter marks in  Accounts  : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in accounts)");
	  gotoxy(37,11);
	  gets(t);
	  tc=atoi(t);
	  s2.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s2.max_marks<1||s2.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in accounts)");
	  gotoxy(48,11);clreol();
	  gets(t);
	  tc=atoi(t);
	  s2.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s2.min_marks<1||s2.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s3.name,"B.St.");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,12);clreol();
	  cprintf("Enter marks in  B.St.     : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in B.St.)");
	  gotoxy(37,12);
	  gets(t);
	  tc=atoi(t);
	  s3.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s3.max_marks<1||s3.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in B.St.)");
	  gotoxy(48,12);clreol();
	  gets(t);
	  tc=atoi(t);
	  s3.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s3.min_marks<1||s3.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s4.name,"ECONOMIC");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,13);clreol();
	  cprintf("Enter marks in  Economic  : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in economic)");
	  gotoxy(37,13);
	  gets(t);
	  tc=atoi(t);
	  s4.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s4.max_marks<1||s4.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in economic)");
	  gotoxy(48,13);clreol();
	  gets(t);
	  tc=atoi(t);
	  s4.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s4.min_marks<1||s4.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,14);clreol();
	  cprintf("Enter marks in  Optional  : NAME-      MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter name of optional subject(MATH,IP,PE,HINDI))");
	  gotoxy(37,14);
	  gets(s5.name);
	  strupr(s5.name);
	  if (s5.name[0]=='0')
	    return;
	  if (Check_Student_Record(admno)!=0)
	  {
	    if(Check_Student_Subject(admno,s5.name)!=0)
	    {
	      valid=0;
	      gotoxy(15,22);clreol();
	      cprintf("Enter correctly......");
	      getch();
	    }
	  }
	  if (strcmpi(s5.name,"MATH")!=0&&strcmpi(s5.name,"IP")!=0&&strcmpi(s5.name,"HINDI")!=0&&strcmpi(s5.name,"PE")!=0)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(42,14);clreol();
	  cprintf("MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in %s)",s5.name);
	  gotoxy(48,14);
	  gets(t);
	  tc=atoi(t);
	  s5.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s5.max_marks<1||s5.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in %s)",s5.name);
	  gotoxy(59,14);clreol();
	  gets(t);
	  tc=atoi(t);
	  s5.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s5.min_marks<1||s5.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}
      }

      if (strcmpi(sstream,"HUMANITIES")==0)
      {
	strcpy(sstream,"HUMANITIES");
	gotoxy(3,8);clreol();
	cout<<"Enter name of test: ";
	valid=0;
	while (!valid)
	{
	  valid=1;
	  gotoxy(15,22);
	  cprintf("(Enter UT_1,UT_2,HALF_YEARLY,ANNUAL_EXAM)");
	  gotoxy(25,8);clreol();
	  cin>>testname;
	  strupr(testname);
	  if (testname[0]=='0')
	    return;
	  if (strcmpi(testname,"UT_1")!=0&&strcmpi(testname,"UT_2")!=0&&strcmpi(testname,"HALF_YEARLY")!=0&&strcmpi(testname,"ANNUAL_EXAM")!=0)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly......");
	    getch();
	  }
	}
	gotoxy(15,22);clreol();
	if (Check_Test(admno,testname)==1)
	{
	  gotoxy(5,10);clreol();
	  cprintf("Marks are already entered......");
	  gotoxy(5,12);clreol();
	  cprintf("Press any key to exit......");
	  getch();
	  return;
	}
	gotoxy(3,10);clreol();
	cprintf("Enter marks in  English   : MAX.=      MIN.=");
	gotoxy(3,11);clreol();
	cprintf("Enter marks in  History   : MAX.=      MIN.=");
	gotoxy(3,12);clreol();
	cprintf("Enter marks in  Pol. Sci. : MAX.=      MIN.=");
	gotoxy(3,13);clreol();
	cprintf("Enter marks in  Economic  : MAX.=      MIN.=");
	gotoxy(3,14);clreol();
	cprintf("Enter marks in  Optional  : NAME-      MAX.=      MIN.=");

	strcpy(s1.name,"ENGLISH");
	valid=0;
	while (!valid)
	{
	  gotoxy(3,10);clreol();
	  cprintf("Enter marks in  English   : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in english)");
	  gotoxy(37,10);
	  gets(t);
	  tc=atoi(t);
	  s1.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s1.max_marks<1||s1.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in english)");
	  gotoxy(48,10);clreol();
	  gets(t);
	  tc=atoi(t);
	  s1.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s1.min_marks<1||s1.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s2.name,"HISTORY");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,11);clreol();
	  cprintf("Enter marks in  History   : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in history)");
	  gotoxy(37,11);
	  gets(t);
	  tc=atoi(t);
	  s2.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s2.max_marks<1||s2.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in history)");
	  gotoxy(48,11);clreol();
	  gets(t);
	  tc=atoi(t);
	  s2.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s2.min_marks<1||s2.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s3.name,"POL.SCI.");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,12);clreol();
	  cprintf("Enter marks in  Pol. Sci. : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in political science)");
	  gotoxy(37,12);
	  gets(t);
	  tc=atoi(t);
	  s3.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s3.max_marks<1||s3.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in political science)");
	  gotoxy(48,12);clreol();
	  gets(t);
	  tc=atoi(t);
	  s3.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s3.min_marks<1||s3.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	strcpy(s4.name,"ECONOMIC");
	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,13);clreol();
	  cprintf("Enter marks in  Economic  : MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in economic)");
	  gotoxy(37,13);
	  gets(t);
	  tc=atoi(t);
	  s4.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s4.max_marks<1||s4.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in economic)");
	  gotoxy(48,13);clreol();
	  gets(t);
	  tc=atoi(t);
	  s4.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s4.min_marks<1||s4.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(3,14);clreol();
	  cprintf("Enter marks in  Optional  : NAME-      MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter name of optional subject(PE,HINDI))");
	  gotoxy(37,14);
	  gets(s5.name);
	  strupr(s5.name);
	  if (s5.name[0]=='0')
	    return;
	  if (Check_Student_Record(admno)!=0)
	  {
	    if(Check_Student_Subject(admno,s5.name)!=0)
	    {
	      valid=0;
	      gotoxy(15,22);clreol();
	      cprintf("Enter correctly......");
	      getch();
	    }
	  }
	  if (strcmpi(s5.name,"HINDI")!=0&&strcmpi(s5.name,"PE")!=0)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  gotoxy(42,14);clreol();
	  cprintf("MAX.=      MIN.=");
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter maximum marks in %s)",s5.name);
	  gotoxy(48,14);
	  gets(t);
	  tc=atoi(t);
	  s5.max_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s5.max_marks<1||s5.max_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}

	valid=0;
	while (!valid&&!found)
	{
	  valid=1;
	  gotoxy(15,22);clreol();
	  cprintf("(Enter minimum marks in %s)",s5.name);
	  gotoxy(59,14);clreol();
	  gets(t);
	  tc=atoi(t);
	  s5.min_marks=tc;
	  if (t[0]=='0')
	    return;
	  if (s5.min_marks<1||s5.min_marks>100)
	  {
	    valid=0;
	    gotoxy(15,22);clreol();
	    cprintf("Enter correctly (Range: 1..100)......");
	    getch();
	  }
	}
      }

      do
      {
	gotoxy(5,22);clreol();
	cprintf("Do you want to save (Y/N):");
	ch=getche();
	ch=toupper(ch);
      }while(ch!='Y'&&ch!='N');
      if (ch=='Y')
      {
	Add_Record(admno,testname,sstream,s1,s2,s3,s4,s5);
      }
      else
	return;
      gotoxy(5,22);clreol();
      cout<<"Marks saved......";
      getch();
      do
      {
	gotoxy(5,22);clreol();
	cprintf("Do you want to enter more (Y/N):");
	ch=getche();
	ch=toupper(ch);
      }while (ch!='Y'&&ch!='N');
    }
  }while(ch=='Y');
}

/****************************************************************************/

void ACADEMIC_DEPARTMENT()
{
 clrscr();
 while(1)
 {
   clrscr();
   int ch;
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
   cout<<"ACADEMIC DEPARTMENT";
   gotoxy(30,10);
   cout<<"1.View Class Result.";
   gotoxy(30,11);
   cout<<"2.View Student Result.";
   gotoxy(30,12);
   cout<<"3.Add Marks Of Student.";
   gotoxy(30,13);
   cout<<"4.Back to main menu.";
   gotoxy(30,15);
   cout<<"Enter your choice:";
   ch=getche();
   if(ch=='1')
   {
     academic_11_to_12 A;
     A.View_Class_Result();
   }
   else if(ch=='2')
   {
     academic_11_to_12 A;
     A.View_Student_Result();
   }
   else if(ch=='3')
   {
     academic_11_to_12 A;
     A.Add_Marks_Of_Student();
   }
   else if(ch=='4')
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
   ACADEMIC_DEPARTMENT();
 }
}

/****************************************************************************/

void main()
{
MAIN();
}

/****************************************************************************/