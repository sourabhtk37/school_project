//*****************************************************************
//HEADER FILES USED IN THE PROGRAM
//*****************************************************************

#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdio.h>
#include<iomanip.h>
#include<dos.h>

//*****************************************************************
//GLOBAL DECLARATION OF SOME FUNCTIONS USED IN THIS PROGRAM
//*****************************************************************

void func_goto();
void main_goto();
void avatar();

//*****************************************************************
//CLASS LIBRARY USED IN THIS PROGRAM
//*****************************************************************

class library
{
protected:

char bname[30];
char writer[30];
char bcode[10];
public:
void enterdata()
{
gotoxy(20,8);
 cout<<"ENTER BOOK CODE";
 gotoxy(26,9);
 cin>>bcode;
 gotoxy(20,12);
 cout<<"ENTER THE NAME OF THE BOOK";
 gotoxy(24,13);
 gets(bname);
 gotoxy(20,17);
 cout<<"ENTER WRITER'S NAME";
 gotoxy(24,18);
 gets(writer);

}

void display()
{
int m=32,k=53;
gotoxy(m,8);
cout<<"BOOK CODE :";
gotoxy(k,8);
cout<<bcode;
gotoxy(m,11);
cout<<"NAME OF THE BOOK :";
gotoxy(k,11);
cout<<bname;
gotoxy(m,14);
cout<<"NAME OF THE WRITER :";
gotoxy(k,14);
cout<<writer;
getch();
}
void display2()
{int m=32,k=35;
gotoxy(m,11);
cout<<"BOOK CODE";
gotoxy(k,12);
cout<<bcode;
gotoxy(m,14);
cout<<"NAME OF THE BOOK";
gotoxy(k,15);
cout<<bname;
gotoxy(m,17);
cout<<"NAME OF THE WRITER";
gotoxy(k,18);
cout<<writer;
}
void modifybook()
{gotoxy(8,13);
cout<<"BOOK NUMBER";
gotoxy(13,14);
cout<<bcode;
gotoxy(6,16);
cout<<"ENTER NEW BOOK NAME";
gotoxy(9,17);
gets(bname);
gotoxy(4,19);
cout<<"ENTER NEW AUTHOR'S NAME";
gotoxy(9,20);
gets(writer);
}
char* retbcode()
{return bcode;}
}lib;   //DECLARATION OF OBJECT OF CLASS LIBRARY

//*****************************************************************
//CLASS MEMBER USED IN THIS PROGRAM
//*****************************************************************

class member
{
char memno[10];
char memname[20];
char membkno[10];
int iss_depo;
public:

void dispmem()
{gotoxy(20,7);
cout<<"MEMBER NUMBER ";
gotoxy(22,8);
cout<<memno;
gotoxy(20,11);
cout<<"MEMBER NAME";
gotoxy(22,12);
cout<<memname;
if(iss_depo==1)
{gotoxy(20,15);
cout<<"The number of book issued is";
gotoxy(22,16);
cout<<membkno;
}
}

void addmem()
{
gotoxy(20,8);
cout<<"ENTER MEMBER NUMBER";
gotoxy(26,9);
cin>>memno;
gotoxy(20,12);
cout<<"ENTER THE NAME OF THE MEMBER";
gotoxy(26,13);
gets(memname);
iss_depo=0;
membkno[0]='/0';
gotoxy(20,17);
cout<<"NEW MEMBER CREATED";

}
void modifymem()
{gotoxy(8,12);
cout<<"MEMBER NUMBER";
gotoxy(13,13);
cout<<memno;
gotoxy(8,16);
cout<<"Enter new name";
gotoxy(10,17);
gets(memname);
}
void dispmem2()
{gotoxy(29,10);
cout<<"MEMBER NUMBER :";
gotoxy(45,10);
cout<<memno;
gotoxy(29,14);
cout<<"MEMBER NAME :";
gotoxy(43,14);
cout<<memname;
if(iss_depo==1)
{gotoxy(29,19);
cout<<"NUMBER OF BOOKS ISSUED :";
gotoxy(48,19);
cout<<membkno;
}
}
void addissue()
{iss_depo=1;
}
void deleteissue()
{iss_depo=0;
}
char* retmemno()
{return memno;
}
int retiss_depo()
{return iss_depo;}

void getmembkno(char bkno[])
{strcpy(membkno,bkno);
}
char* retmembkno()
{return membkno;
}
}mem;   //DECLARATION OF OBJECT USED IN CLASS MEMBER

//*****************************************************************
//FUNCTION TO CREATE BOOKS
//*****************************************************************

void add()
{
fstream lib1("library.dat",ios::out|ios::app);
char a;
while(1)
{clrscr();
func_goto();
avatar();gotoxy(22,3);
cout<<"/*************/";
gotoxy(24,4);
cout<<"CREATE BOOK";
gotoxy(22,5);
cout<<"/*************/";
lib.enterdata();
lib1.write((char*)&lib,sizeof(library));
gotoxy(15,21);
cout<<"WANT TO ENTER MORE BOOKS?(y/n)";
gotoxy(26,22);
cin>>a;
if(a=='N'||a=='n')
break;
}
lib1.close();
}

//*****************************************************************
//FUNCTION TO CREATE MEMBER
//*****************************************************************

void create_mem()
{
char ch;
fstream mem1("member.dat",ios::out|ios::app);
while(1)
{clrscr();
func_goto();
avatar();
gotoxy(22,3);
cout<<"/*************/";
gotoxy(23,4);
cout<<"CREATE MEMBER";
gotoxy(22,5);
cout<<"/*************/";
mem.addmem();
mem1.write((char*)&mem,sizeof(member));
gotoxy(12,21);
cout<<"DO YOU WANT TO ADD MORE RECORD..(Y/N?)";
gotoxy(26,22);
cin>>ch;
if(ch=='n'||ch=='N')
break;
}
mem1.close();
}

//*****************************************************************
//FUNCTION TO ISSUE BOOK
//*****************************************************************

void issue()
{clrscr();
func_goto();
 char mno[10],bno[10];
  int foundm=0,foundb=0;
gotoxy(30,3);
cout<<"/*************/";
gotoxy(32,4);
cout<<"BOOK ISSUE";
gotoxy(30,5);
cout<<"/*************/";
  for(int i=3;i<79;++i)
		{gotoxy(i,6);
		cout<<"=";
		}
		for(int j=7;j<24;++j)
		{gotoxy(30,j);
		cout<<"=";
		}
  gotoxy(6,8);
  cout<<"ENTER THE MEMBER NUMBER";
  gotoxy(16,9);
  cin>>mno;
  fstream mem1("member.dat",ios::in|ios::out);
  fstream lib6("library.dat",ios::in|ios::out);
  while(mem1.read((char*)&mem,sizeof(member))&&foundm==0)
  {
	if((strcmpi(mem.retmemno(),mno))==0)
	{
	foundm=1;
	 if((mem.retiss_depo())==0)
	 {gotoxy(6,12);
	 cout<<"ENTER THE BOOK CODE";
	  gotoxy(16,13);
	  cin>>bno;

	  while(lib6.read((char*)&lib,sizeof(library))&&foundb==0)
	  {if((strcmpi(lib.retbcode(),bno))==0)
		{
		lib.display();
		foundb=1;
		mem.addissue();
		mem.getmembkno(lib.retbcode());
		int pos=-1*sizeof(mem);
		mem1.seekp(pos,ios::cur);
		mem1.write((char*)&mem,sizeof(member));
		gotoxy(35,20);
		cout<<"BOOK ISSUED SUCCESSFULLY";
		gotoxy(38,22);
		cout<<"THANK YOU";
		}
	  }
	  if(foundb==0)
	  {gotoxy(8,15);
	  cout<<"BOOK DOESNT EXIST";}
	 }
	 else
	{gotoxy(5,14);
	cout<<"RETURN THE PREVIOUSLY ";
	gotoxy(7,15);
	cout<<"\tISSUED BOOK";}
	}
  }
 if(foundm==0)
  {gotoxy(8,13);
  cout<<"MEMBER DOESNT EXIST";
  }getch();
 lib6.close();
 mem1.close();
}

//*****************************************************************
//FUNCTION TO DEPOSIT BOOK
//*****************************************************************

void deposit()
{clrscr();
func_goto();
 char memno[10];//bkno[10];
  int foundm=0,foundb=0;
  gotoxy(30,3);
cout<<"/*************/";
gotoxy(32,4);
cout<<"BOOK DEPOSIT";
gotoxy(30,5);
cout<<"/*************/";
	for(int i=3;i<79;++i)
		{gotoxy(i,6);
		cout<<"=";
		}
		for(int j=7;j<24;++j)
		{gotoxy(30,j);
		cout<<"=";
		}
  gotoxy(6,8);
  cout<<"ENTER THE MEMBER NUMBER";
  gotoxy(16,9);
  cin>>memno;
  fstream mem1("member.dat",ios::in|ios::out);
  fstream lib6("library.dat",ios::in|ios::out);
  while(mem1.read((char*)&mem,sizeof(member))&&foundm==0)
  {
  if(strcmpi(mem.retmemno(),memno)==0)
	{
	foundm=1;
	 if(mem.retiss_depo()==1)
	 {
	  while(lib6.read((char*)&lib,sizeof(library))&&foundb==0)
	  {
	  if(strcmpi(lib.retbcode(),mem.retmembkno())==0)
		{foundb=1;
		lib.display();
		mem.deleteissue();
		int pos=-1*sizeof(mem);
		mem1.seekp(pos,ios::cur);
		mem1.write((char*)&mem,sizeof(member));
		gotoxy(35,20);
		cout<<"BOOK DEPOSITED SUCCESSFULLY";
		gotoxy(38,22);
		cout<<"THANK YOU";
		}
	  }

 if(foundb==0)
	  {gotoxy(6,15);
	  cout<<"BOOK DOESNT EXIST";
	  }
	  }
	  else
	  {gotoxy(5,13);
	  cout<<"NO BOOK HAS BEEN ISSUED";
	  }
	  }
	  }
	  if(foundm==0)
	  {gotoxy(7,13);
	  cout<<"MEMBER DOES NOT EXIST";
		}
 getch();
 lib6.close();
 mem1.close();
}
//*****************************************************************
//FUNCTION TO DISPLAY BOOKS
//*****************************************************************
void disp()
{
clrscr();
func_goto();
fstream lib4("library.dat",ios::in);
lib4.seekg(0);
while(lib4.read((char*)&lib,sizeof(library)))
{clrscr();
func_goto();
gotoxy(30,2);
cout<<"/*************/";
gotoxy(32,3);
cout<<"BOOK DETAILS";
gotoxy(30,4);
cout<<"/*************/";
lib.display();
}
lib4.close();
}

//*****************************************************************
//FUNCTION TO DISPLAY MEMBERS
//*****************************************************************

void displaymem()
{fstream mem1("member.dat",ios::in);
mem1.seekg(0);
while(mem1.read((char*)&mem,sizeof(member)))
{clrscr();
func_goto();
avatar();
gotoxy(20,2);
cout<<"/*************/";
gotoxy(21,3);
cout<<"MEMBER DETAILS";
gotoxy(20,4);
cout<<"/*************/";
mem.dispmem();
getch();
}
mem1.close();
}

//*****************************************************************
//FUNCTION TO MODIFY MEMBERS
//*****************************************************************

void modify_mem()
{clrscr();
func_goto();
avatar();
fstream mem1("member.dat",ios::in|ios::out);
char no[10];
int found=0;

for(int i=7;i<25;++i)  //boundary2
{gotoxy(27,i);
 cout<<"=";
}
for(i=3;i<52;++i)
{gotoxy(i,6);
cout<<"=";
}
gotoxy(20,2);
cout<<"/*************/";
gotoxy(21,3);
cout<<"MODIFY MEMBER";
gotoxy(20,4);
cout<<"/*************/";
gotoxy(3,8);
cout<<"ENTER THE MEMBER NUMBER";
gotoxy(13,9);
cin>>no;
while(mem1.read((char*)&mem,sizeof(member))&&found==0)
{
if(strcmp(mem.retmemno(),no)==0)
{
found=1;
mem.dispmem2();
mem.modifymem();
int pos=-1*sizeof(mem);
mem1.seekg(pos,ios::cur);
mem1.write((char*)&mem,sizeof(member));
gotoxy(6,20);
cout<<"RECORD HAS BEEN ";
gotoxy(4,21);
cout<<"SUCCCESFULLY MODIFIED";
break;
}
}

if(found==0)
{gotoxy(5,20);
cout<<"RECORD NOT FOUND";
}mem1.seekp(0);
while(mem1.read((char*)&mem,sizeof(member)))
{
gotoxy(30,8);
cout<<"NOW THE FILE CONTAINS";
if(strcmp(mem.retmemno(),no)==0)
{
mem.dispmem2();
break;
}
}
mem1.close();
getch();
}

//*****************************************************************
//FUNCTION TO MODIFY BOOKS
//*****************************************************************

void modify_book()
{
clrscr();
func_goto();
avatar();
char no[10];
int found=0;
fstream lib1("library.dat",ios::in|ios::out);

for(int i=7;i<25;++i)  //boundary2
{gotoxy(27,i);
 cout<<"=";
}
for(i=3;i<52;++i)
{gotoxy(i,6);
cout<<"=";
}
gotoxy(20,2);
cout<<"/*************/";
gotoxy(22,3);
cout<<"MODIFY BOOK";
gotoxy(20,4);
cout<<"/*************/";

gotoxy(5,7);
cout<<"ENTER THE BOOK NUMBER";
gotoxy(13,8);
cin>>no;
while(lib1.read((char*)&lib,sizeof(lib))&&found==0)
{
if(strcmp(lib.retbcode(),no)==0)
{
lib.display2();
gotoxy(5,10);
cout<<"Enter the new details";
gotoxy(8,11);
cout<<"of the book";
lib.modifybook();
int pos=-1*sizeof(lib);
lib1.seekp(pos,ios::cur);
lib1.write((char*)&lib,sizeof(library));
gotoxy(8,22);
cout<<"RECORD HAS BEEN ";
gotoxy(4,23);
cout<<"SUCCCESFULLY MODIFIED";
found=1;
}
}

if(!found)
{gotoxy(6,14);
cout<<"RECORD NOT FOUND";
}

lib1.seekp(0,ios::beg);
while(lib1.read((char*)&lib,sizeof(library)))
{
gotoxy(30,8);
cout<<"NOW THE FILE CONTAINS";
if(strcmp(lib.retbcode(),no)==0)
{
lib.display2();
break;
}
}
lib1.close();
getch();
}

//*****************************************************************
//FUNCTION TO DELETE MEMBERS
//*****************************************************************

void delete_mem()
{clrscr();
func_goto();
avatar();
char no[10],ch;
int flag=0;
fstream mem1("member.dat",ios::in|ios::out);
fstream temp("Temp.dat",ios::out);

for(int i=7;i<25;++i)  //boundary2
{gotoxy(27,i);
 cout<<"=";
}
for(i=3;i<52;++i)
{gotoxy(i,6);
cout<<"=";
}

gotoxy(22,3);
cout<<"/*************/";
gotoxy(23,4);
cout<<"DELETE MEMBER";
gotoxy(22,5);
cout<<"/*************/";
gotoxy(4,8);
cout<<"ENTER MEMBER NUMBER";
gotoxy(12,9);
cin>>no;
while(!mem1.eof())
{mem1.read((char*)&mem,sizeof(member));
 if(strcmp(mem.retmemno(),no)==0)
 {mem.dispmem2();
  sourabh:
  gotoxy(4,16);
  cout<<"CONFIRM DELETE(Y/N)";
  gotoxy(10,17);
  cin>>ch;
	if(ch=='n'||ch=='N')
	{flag=2;
	 break;
	}
	else if(ch=='y'||ch=='Y')
	 {flag=1;
	  break;
	 }
	 else{gotoxy(3,19); cout<<"WRONG CHOICE,ENTER AGAIN"; goto sourabh;}
 }
}
mem1.seekg(0,ios::beg);
if(flag==1)
{
 while(mem1.read((char*)&mem,sizeof(member)))
  {  if(strcmp(mem.retmemno(),no)!=0)
	  {
		temp.write((char*)&mem,sizeof(member));
	  }
  }
}
else
{mem1.seekg(0,ios::beg);
while(mem1.read((char*)&mem,sizeof(member)))
temp.write((char*)&mem,sizeof(member));
}
temp.close();
mem1.close();
remove("member.dat");
rename("Temp.dat","member.dat");
if(flag==1)
{gotoxy(5,22);
cout<<"RECORD DELETED";
}
else if(flag==2)
{gotoxy(5,22);
cout<<"RECORD NOT DELETED";
}
else
{gotoxy(7,18);
cout<<"RECORD NOT FOUND";
}
getch();
}

//*****************************************************************
//FUNCTION TO DELETE BOOKS
//*****************************************************************

void deletebook()
{clrscr();
func_goto();
avatar();
char no[10],ch;
int flag=0;
fstream lib1("library.dat",ios::out|ios::in);
fstream temp("Temp.dat",ios::out);

for(int i=7;i<25;++i)  //boundary2
{gotoxy(27,i);
 cout<<"=";
}
for(i=3;i<52;++i)
{gotoxy(i,6);
cout<<"=";
}

gotoxy(22,3);
cout<<"/*************/";
gotoxy(23,4);
cout<<"DELETE MEMBER";
gotoxy(22,5);
cout<<"/*************/";
gotoxy(4,8);
cout<<"ENTER THE BOOK NUMBER";
gotoxy(12,9);
cin>>no;

while(!lib1.eof())
{lib1.read((char*)&lib,sizeof(library));
 if(strcmp(lib.retbcode(),no)==0)
 {lib.display2();
  sourabh:
  gotoxy(4,16);
  cout<<"CONFIRM DELETE(Y/N)";
  gotoxy(10,17);
  cin>>ch;
	if(ch=='n'||ch=='N')
	{flag=2;
	 break;
	}
	else if(ch=='y'||ch=='Y')
	 {flag=1;
	  break;
	 }
	 else{gotoxy(3,19); cout<<"WRONG CHOICE,ENTER AGAIN"; goto sourabh;}
 }
}

lib1.seekg(0,ios::beg);
if(flag==1)
{while(lib1.read((char*)&lib,sizeof(library)))
 {
  if(strcmpi(lib.retbcode(),no)!=0)
  {
  temp.write((char*)&lib,sizeof(library));
  }
 }
}
else
{lib1.seekg(0,ios::beg);
while(lib1.read((char*)&lib,sizeof(library)))
temp.write((char*)&lib,sizeof(library));
}
temp.close();
lib1.close();
remove("library.dat");
rename("Temp.dat","library.dat");
if(flag==1)
{gotoxy(5,22);
cout<<"RECORD DELETED";
}
else if(flag==2)
{gotoxy(5,22);
cout<<"RECORD NOT DELETED";
}
else
{gotoxy(7,18);
cout<<"RECORD NOT FOUND";
}
getch();
}

//*****************************************************************
//FUNCTION TO CREATE BORDER FOR SOME FUNCTIONS
//*****************************************************************

void func_goto()
{int j=2;
for(int i=0;i<24;++i) //left corner
{gotoxy(1,j);
cout<<"((\n";
++j;
}
j=1;
for(i=0;i<24;++i)//right corner
{gotoxy(79,j);
cout<<"))\n";
++j;
}
j=1;
for(i=1;i<=80;++i)//top corner
{gotoxy(j,1);
cout<<"+";
++j;
}
j=1;
for(i=0;i<80;++i)//lower corner
{gotoxy(j,24);
cout<<"+";
++j;
}
}

//*****************************************************************
//FUNCTION TO CREATE BORDER FOR MAIN FUNCTIONS
//*****************************************************************

void main_goto()
{int j=8;
for(int i=0;i<17;++i) //left corner
{gotoxy(1,j);
cout<<"{{\n";
++j;
}
j=8;
for(i=0;i<17;++i)//right corner
{gotoxy(79,j);
cout<<"}}\n";
++j;
}
j=1;
for(i=1;i<=80;++i)//top corner
{gotoxy(j,7);
cout<<"=";
++j;
}
j=1;
for(i=0;i<80;++i)//lower corner
{gotoxy(j,25);
cout<<"=";
++j;
}
}

//*****************************************************************
//FUNCTION TO CREATE AVATAR FOR ADMINISTRATOR FUNCTIONS
//*****************************************************************

void avatar()
{char user[20]={'S','O','U','R','A','B','H','T','K'};
for(int i=2;i<25;++i)  //boundary
{gotoxy(52,i);
 cout<<"*";
}
gotoxy(59,3);
cout<<"USER : "<<user;
gotoxy(61,8);
cout<<"===========";
for(i=9;i<13;++i)  //left face
{gotoxy(61,i);
cout<<"+\n";
}
for(i=9;i<13;++i)  //right face
{gotoxy(71,i);
cout<<"+\n";
}
gotoxy(61,12);
cout<<"+++++++++++";
gotoxy(58,13);
cout<<"======     ======";
for(i=13;i<17;++i)  //left neckline
{gotoxy(50+i,i);
cout<<"=\n";
}
for(i=13;i<16;++i)  //right neckline
{gotoxy(82-i,i);
cout<<"=\n";
}
for(i=13;i<21;++i)  //outer left
{gotoxy(58,i);
cout<<"=\n";
}
for(i=15;i<20;++i)  //inner left
{gotoxy(61,i);
cout<<"=\n";
}
for(i=15;i<20;++i)  //inner right
{gotoxy(71,i);
cout<<"=\n";
}
for(i=13;i<21;++i)  //outer right
{gotoxy(74,i);
cout<<"=\n";
}

gotoxy(61,19);
cout<<"===========";

gotoxy(63,9);
cout<<"O";

gotoxy(69,9);
cout<<"O";

gotoxy(65,11);
cout<<"(_)";

}

//*****************************************************************
//FUNCTION FOR CREDITS (ON EXITING THE PROGRAM)
//*****************************************************************

void credits()
{clrscr();
char user[20]={'S','O','U','R','A','B','H','T','K'};
gotoxy(30,1);
cout<<"WAIT LOADING";
for(int i=0;i<3;++i)
{sleep(1);
cout<<" * ";
}

sleep(1);
gotoxy(19,5);   //left circle's first quadrant
cout<<" *";
gotoxy(22,6);
cout<<"*";
gotoxy(24,7);
cout<<"*";
gotoxy(25,8);
cout<<"*";
gotoxy(26,9);
cout<<"*";

gotoxy(59,5);   //right circle's first quadrant
cout<<" *";
gotoxy(62,6);
cout<<"*";
gotoxy(64,7);
cout<<"*";
gotoxy(65,8);
cout<<"*";
gotoxy(66,9);
cout<<"*";

sleep(1);
gotoxy(25,10);
cout<<"*";
gotoxy(24,11);
cout<<"*";
gotoxy(22,12);
cout<<"*";
gotoxy(19,13);
cout<<" *";

gotoxy(65,10);
cout<<"*";
gotoxy(64,11);
cout<<"*";
gotoxy(62,12);
cout<<"*";
gotoxy(59,13);
cout<<" *";

sleep(1);
gotoxy(13,9);
cout<<"*";
gotoxy(14,10);
cout<<"*";
gotoxy(15,11);
cout<<"*";
gotoxy(17,12);
cout<<"*";
gotoxy(19,13);
cout<<"*";

gotoxy(53,9);
cout<<"*";
gotoxy(54,10);
cout<<"*";
gotoxy(55,11);
cout<<"*";
gotoxy(57,12);
cout<<"*";
gotoxy(59,13);
cout<<"*";

sleep(1);
gotoxy(19,5);
cout<<"*";
gotoxy(17,6);
cout<<"*";
gotoxy(15,7);
cout<<"*";
gotoxy(14,8);
cout<<"*";

gotoxy(59,5);
cout<<"*";
gotoxy(57,6);
cout<<"*";
gotoxy(55,7);
cout<<"*";
gotoxy(54,8);
cout<<"*";

sleep(1);
gotoxy(22,20);
cout<<"PRESS ENTER TO CONTINUE TO CREDITS\n\n\n";
getch();

cout<<setw(45)<<"/*************/\n";
cout<<setw(41)<<"CREDITS\n";
cout<<setw(45)<<"/*************/\n";
sleep(1);
cout<<"\n\n\t\t\tLIBRARY MANAGEMENT PROGRAM\n\n\n";
cout<<setw(30)<<"\tMADE BY :\t";
sleep(1);
for(i=0;i<10;++i)
{
cout<<user[i];
}
sleep(1);
cout<<"\n\n\t\t\tCLASS   : ";
sleep(1);
cout<<setw(11)<<"XII-A";
sleep(1);
cout<<"\n\n\t\t\tSCHOOL  : ";
sleep(1);
cout<<setw(14)<<"K.V.TAGORE GARDEN";
delay(2000);
cout<<"\n\n\n\t\t\tUNDER THE GUIDANCE OF MY\n\n";
cout<<setw(40)<<"COMPUTER TEACHER : ";
sleep(1);
cout<<setw(10)<<"MRS.HARLEEN KAUR";
delay(2200);
cout<<"\n\n\n\t\t\tPRESS ENTER TO CONTINUE";
getch();
clrscr();
func_goto();
avatar();
sleep(1);
gotoxy(16,6);
cout<<"THANK YOU FOR SPENDING";
gotoxy(17,9);
cout<<"YOUR PRECIOUS TIME";
sleep(2);
gotoxy(17,16);
cout<<"PRESS ENTER TO EXIT";
getch();
}

//*****************************************************************
//FUNCTION TO CREATE "WELCOME"
//*****************************************************************

void welcome()
{gotoxy(1,3);
cout<<"**      **      ** ******** **        ********  ********  ****    **** ********\n" ;
cout<<" **    ****    **  **       **        **        **    **  ** **  ** ** **\n";
cout<<"  **  **  **  **   ******** **        **        **    **  **  ****  ** ********\n";
cout<<"   ****    ****    **       **        **        **    **  **   **   ** **\n";
cout<<"    **      **     ******** ********* ********  ********  **        ** ********\n";
}

//*****************************************************************
//ADMINISTRATOR FUNCTION ( WITH USERNAME AND PASSWORD )
//*****************************************************************

int admin()
{clrscr();
func_goto();
gotoxy(29,3);
cout<<"/*******************/";
gotoxy(30,4);
cout<<"ADMINISTRATOR LOGIN";
gotoxy(29,5);
cout<<"/*******************/";
int j=1;
char pass[8],passc[8],user[10],userc[10];
sourabh1:
gotoxy(31,8);
cout<<"================";   //upper username line
gotoxy(31,9);
cout<<"=";
gotoxy(46,9);
cout<<"=";
gotoxy(32,9);
cout<<"ENTER USERNAME";
gotoxy(31,10);
cout<<"================";   //lower username line
gotoxy(34,11);
gets(user);

gotoxy(31,13);
cout<<"================";   //upper username line
gotoxy(31,14);
cout<<"=";
gotoxy(46,14);
cout<<"=";
gotoxy(32,14);
cout<<"ENTER PASSWORD";
gotoxy(31,15);
cout<<"================";   //lower password line
gotoxy(35,16);
for(int i=0;i<7;++i)
{pass[i]=getch();
cout<<"*";
}
pass[7]='\0';
user[9]='\0';
fstream usern("username.txt",ios::in);
fstream passn("password.txt",ios::in);
usern.getline(userc,10);
passn.getline(passc,8);
if(((strcmp(user,userc))==0&&(strcmp(pass,passc))==0))
{
gotoxy(27,20);
cout<<"WELCOME BACK , SOURABH";
gotoxy(27,22);
cout<<"PRESS ENTER TO CONTINUE ";
getch();

int choice;
while(1)
{clrscr();
func_goto();
avatar();
gotoxy(10,3);
cout<<"PRESS '1' TO CREATE A MEMBER";
gotoxy(10,5);
cout<<"PRESS '2' TO DISPLAY MEMBER DETAILS";
gotoxy(10,7);
cout<<"PRESS '3' TO MODIFY MEMBER DETAILS";
gotoxy(10,9);
cout<<"PRESS '4' TO DELETE A MEMBER";
gotoxy(10,11);
cout<<"PRESS '5' TO CREATE A BOOK";
gotoxy(10,13);
cout<<"PRESS '6' TO MODIFY A BOOK";
gotoxy(10,15);
cout<<"PRESS '7' TO DELETE A BOOK";
gotoxy(10,17);
cout<<"PRESS '8' TO SEE THE LIST OF BOOKS";
gotoxy(10,19);
cout<<"PRESS '9' TO GO BACK TO THE PREVOIUS MENU";
gotoxy(10,21);
cout<<"ENTER YOUR CHOICE";
sourabh:
gotoxy(10,22);
cin>>choice;
switch(choice)
{case 1 : create_mem();
	  break;
 case 2 : displaymem();
	  break;
 case 3 : modify_mem();
	  break;
 case 4 : delete_mem();
	  break;
 case 5 : add();
	  break;
 case 6 : modify_book();
	  break;
 case 7 : deletebook();
	  break;
 case 8 : disp();
	  break;
 case 9 : return 0;

 default : gotoxy(2,20);
		cout<<"\nWRONG CHOICE.ENTER AGAIN";
		goto sourabh;

}
}
}
else
{clrscr();
func_goto();
gotoxy(10,4);
for(i=0;i<3;++i)
{gotoxy(10,2);
cout<<"INCORRECT PASSWORD OR USERNAME.TRY AGAIN";
++j;
if(j==4)
{gotoxy(5,10);
cout<<"YOU HAVE ENTERED WRONG PASSWORD OR USERNAME THREE TIMES";
sleep(2);
gotoxy(20,14);
cout<<"TERMINATING!!";
sleep(1);
gotoxy(20,17);
cout<<"TERMINATING!!!!!!";
sleep(2);
gotoxy(20,21);
cout<<"BYE BYEEEE : YOU ARE NOT SUPPOSED EVADE OTHERS PRIVACY";
sleep(2);
exit(0);
}
goto sourabh1;
}
}
getch();
return 0;
}

void main()
{clrscr();
int ch;
while(1)
{clrscr();
welcome();
main_goto();
gotoxy(3,7);
cout<<"\t\t\tLIBRARY MANAGEMENT PROGRAM\n\n";
gotoxy(3,9);
cout<<"\t\t\t\tMAIN MENU";
gotoxy(4,11);
cout<<"\t\t\tPRESS '1' TO ISSUE A COPY OF A BOOK.";
gotoxy(7,13);
cout<<"\t\t\tPRESS '2' TO DEPOSIT A COPY OF A BOOK.";
gotoxy(6,15);
cout<<"\t\t\tPRESS '3' TO SEE THE LIST OF BOOKS.";
gotoxy(6,17);
cout<<"\t\t\tPRESS '4' FOR ADMININSTRATOR'S MENU";
gotoxy(6,19);
cout<<"\t\t\tPRESS '5' TO EXIT THE PROGRAM.";
gotoxy(30,22);
cout<<"ENTER YOUR CHOICE";
sourabh:
gotoxy(37,23);
cin>>ch;

switch(ch)
{
case 1 : issue();
	 break;
case 2 : deposit();
	 break;
case 3 : disp();
	 break;
case 4 : admin();
	 break;
case 5 : clrscr();
			credits();
			exit(0);
	 break;
default: gotoxy(12,22);
	 cout<<"\tINVALID CHOICE , ENTER YOUR CHOICE AGAIN";
	 goto sourabh;

}
}
}

