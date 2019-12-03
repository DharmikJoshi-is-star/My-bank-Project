///////////////////////////////////MYBANK/////////////////
//////
#include<dos.h>
#include<graphics.h>
/*  setviewport(1,125-12,maxx-1,maxy-1,1);
  clearviewport();

  setviewport(0,0,maxx,maxy,1);
  setcolor(WHITE);
  settextstyle(DEFAULT_FONT,0,2);    */
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#define size 100


void print_passbook(struct customer *temp);
void delete_account(struct customer *r);
void menu_customer(struct customer *w);
void withdraw(struct customer *r);
void deposit(struct customer *r);
void create_account();
void deposit();
void withdraw();
void Account_info(struct customer *q);
//void All_account_info();
void remove_my_account();
void last_transection();
void my_balance();
int choice_menu(char);
void log_in();
int string_compare(char d[30],char e[30]);
void setup();
//operation that can be performed in my bank

struct customer{

 char name[30];
 double balance;
 char contact_number[30];
 char password[20];

 struct{
 char entry[20];
 double balance_passbook;
 char date[20];
 char time[20];
 }passbook[100];

 int top;

 struct customer *link;
};

struct customer *customer_link;
struct customer variable;

/*struct queue{
int front;
int rarer;
struct customer **customer_queue[size];
};

struct queue pointer; */

 void main()
{
 /* float octave[7]={130.81,146.83,164.81,174.61,
			196,220,246.94};*/
 int gd=0,gm,i,n;
 int midx,midy,j,pass;
 char choice;
 clrscr();
 midx=getmaxx()/2;
 midy=getmaxy()/2;
       customer_link=NULL;
       /*pointer.front=-1;
       pointer.rarer=-1;
       variable.passbook.top=-1;*/

       initgraph (&gd,&gm,"C:\\TC\\bgi");     //INITIALIZING GRAPHIC SCREEN

	do{
	clrscr();
	cleardevice();
	settextstyle(8,0,6);
	outtextxy(90,100,"BANK IS OPENING");       //90,100
		setcolor(WHITE);
	for(pass=1;pass<=9;pass++)
		for(j=0/*-90*/;j<=90;j=j+30)
		{
		setcolor(WHITE);
		setfillstyle(SOLID_FILL,WHITE);
	       circle(100+j+160,100+100,12);	//circle(midx+j,midy+100,12);
	       circle(100+j+160,100+100,10); //	circle(midx+j,midy+100,10);
	       floodfill(100+j+160,100+100,WHITE); //	floodfill(midx+j,midy+100,GREEN);
		setcolor(BLACK);

		setfillstyle(SOLID_FILL,BLACK);
		delay(150);
	       floodfill(100+j+160,100+100,BLACK);	//floodfill(midx+j,midy+100,BLACK);
		}




/*	 for(i=0;i<7;i++)
	 {
		 sound(octave[i]*8);
		 delay(30);
	 }
	 nosound();
  */
       /*	 for(i=0;i<100;i++)
	 {
		n=random(7);
		sound(octave[n]*4);
		delay(100);
	 }
	 nosound();
	 break;
	 while(1)
	 {
	  if(kbhit())
	   goto jump;
		n=random(7);
		sound(octave[n]*4);
		delay(1000);
	 }
	 nosound();



	jump:*/
	//delay(50);
	start:
	clrscr();
	cleardevice();
	setbkcolor(8);
	setcolor(BLACK);
	setup();
	setcolor(WHITE);
	settextstyle(8,HORIZ_DIR,7);  //8 6
	outtext(" MYBANK PROJECT ");
	line(0,80,getmaxx(),80);

	setcolor(BLUE);
	settextstyle(1,0,1);
	outtextxy(200,100,"welcome to my bamk");
	setcolor(WHITE);
	outtextxy(350,getmaxy()-50,"-Created by dharmik joshi");

	setcolor(WHITE);
	line(0,getmaxy()-60,getmaxx(),getmaxy()-60);
	 /////hi
	//	gotoxy(350,getmaxy()-50);//changed
       //	printf("Dharmik");

	for(i=1;i<25;i++)
	 printf("\n");
	printf("\t\t\t\t\t\t   %s\t",__DATE__);
	printf("%s",__TIME__);
	line(0,0,0,getmaxy()-60) ;
	line(getmaxx(),0,getmaxx(),getmaxy()-60);
	setcolor(WHITE);
	settextstyle(6,0,1);
	outtextxy(50,220,"LOG_IN(l)");
	outtextxy(50,250,"CREATE_NEW ACCOUNT(c)");
	outtextxy(50,280,"EXIT(e)");
	 choice=getch();
	switch(choice_menu(choice))
	{
	 case 1:
	  create_account();
	 break;
	 case 2:
	  log_in();
	 break;
	 case 3:
	  printf("EXIT");
	  exit(0);
	 break;
	  goto start;
	}
	}while(choice!='e'||choice!='E');
	getch();
	closegraph();

}

void setup()
{
	cleardevice();
	line(0,0,getmaxx(),0);
	line(0,0,0,getmaxy());
	line(getmaxx(),0,getmaxx(),getmaxy());
	line(0,getmaxy(),getmaxx(),getmaxy());
}


int choice_menu(char c)
{
    if(c=='c'||c=='C')
	 return 1;
    else if (c=='l'||c=='L')
	 return 2;
    else if (c=='e'||c=='E')
	 return 3;
}


void create_account()
{
 double bal;
 struct customer *temp,*p;
 clrscr();

 cleardevice();
 setup();

 settextstyle(DEFAULT_FONT,0,2);
 outtext("          Please Fill the form");
 temp=(struct customer *)malloc(sizeof(struct customer));
 temp->link=NULL;
 temp->top=-1;
 temp->balance=0.0;
 printf("\n\n");
 outtextxy(30,50,"ENTER YOUR FULL NAME");
 printf("\n\n\n\t\t");
 scanf("%s",&temp->name);
 outtextxy(30,100,"ENTER YOUR CONTACT NUMBER");
 printf("\n\n\t\t");
 scanf("%s",&(temp->contact_number)) ;
 outtextxy(30,150,"ENTER YOUR PASSWORD");
 printf("\n\n\t\t");
 scanf("%s",&(temp->password));
 outtextxy(30,200,"ENTER THE STARTING DEPOSITE");
 printf("\n\n\t\t");
 scanf("%lf",&bal);
 temp->balance=bal;
 printf("%lf",temp->balance);
 if(customer_link==NULL)
 {
  customer_link=temp;
  printf("hi");
  printf(" Account is Created successfully\n");
 }
 else{
  p=customer_link;
  while(p->link!=NULL)
  {
   p=p->link;
  }
  p->link=temp;
  printf("Account is Created successfully\n");
 }
 ///////remyove
 Account_info(temp);
}

void  Account_info(struct customer *q)
{
   clrscr();
   cleardevice();
   setup();
    settextstyle(DEFAULT_FONT,0,2);
    printf("\n\n\n\n\n\t\t ");
    puts(q->name);
    printf("\n\n\t\t\t\t    ");
    puts(q->contact_number);
    printf("\n\n\t\t\t\t\t\t\t     ");
    printf("%lf",q->balance);
   outtextxy(30,50,"ACCOUNT INFROMATION IS GIVEN BELOW");
   outtextxy(30,80,"NAME:- ");
  // printf("\n\n\n\n\n\n\t\t");
  // puts(q->name);
   outtextxy(30,125,"CONTACT NUMBER:- ");
 //  printf("\n\n\t\t\t\t");
 //  puts(q->contact_number);
   outtextxy(30,175,"BALANCE OF YOUR ACCOUNT IS:- ");
  // printf("\n\n\t\t\t\t\t");
 //  printf("%lf",q->balance);
   getch();
}

void log_in()
{

int found=0;
char check_name[30],check_password[20];
struct customer *q;
clrscr();
cleardevice();
setup();
 settextstyle(DEFAULT_FONT,0,2);
 outtextxy(100,5,"ENTER YOUR ID AND PASSWORD");
 printf("\n\n\n\n\t\t\t\t     ");
outtextxy(30,50,"Enter your name: ");           //check here
scanf("%s",&(check_name));
 printf("\n\t\t\t\t\t   ");
outtextxy(30,80,"Enter your password:");
scanf("%s",&(check_password));

q=customer_link;
do
{
if((string_compare(q->name,check_name)==1)&&(string_compare(q->password,check_password)==1))
{found=1;}
else
{q=q->link;}
printf("hi");          ///remove
printf("%s",q->name);
getch();
}while(string_compare(q->name,check_name)!=1&&string_compare(q->password,check_password)!=1&&q->link!=NULL&&found!=1);
if(found==1)
 { printf("YOUR ACCOUNT IS OPEN\n");   //go to menu section
   getch();
   menu_customer(q);
  }
else
printf("CHECK YOUR ID OR PASSWORD\n");

getch();
}

int string_compare(char d[30],char e[30])
{
 if(strcmp(d,e)==0)
  return 1;
}

void menu_customer(struct customer *w)
{
 char option;
 int a;
 start:

 clrscr();
 cleardevice();
 setup();

printf("%s\n",w->name);

settextstyle(DEFAULT_FONT,0,2);
 outtextxy(30,50,"Do you want to deposit or withdraw or want account information ?");
 outtextxy(30,80,"Deposit(d)");
 outtextxy(30,110,"Withdraw(w)");
 outtextxy(30,140,"Print my passbook(p)");
 outtextxy(30,170,"Information(i)");
 outtextxy(30,200,"Delete My account(y)");
 outtextxy(30,230,"Exit(e)");

 option=getch();
 if(option=='d'||option=='D')  a=1;
 if(option=='w'||option=='W')  a=2;
 if(option=='i'||option=='I')  a=3;
 if(option=='y'||option=='Y')  a=4;
 if(option=='e'||option=='E')  a=5;
 if(option=='p'||option=='P')  a=6;
 switch(a)
 {
  case 1:
   deposit(w);
  break;
  case 2:
   withdraw(w);
  break;
  case 3:
   Account_info(w);
  break;
  case 4:
   delete_account(w);
  break;
  case 5:
   exit(0);
  break;
  case 6:
   print_passbook(w);
 }
 if(option!='e'||option!='E')
 {clrscr();cleardevice(); goto start;}
}

void deposit(struct customer *r){       //change the return type void to structure pointer
//struct customer* deposite(struct customer *r){
double ent_bal;
clrscr();
cleardevice();
 printf("\n\n");
  settextstyle(DEFAULT_FONT,0,2);
 outtextxy(30,50,"ADD THE BALANCE");
 printf("\n\n\n\t\t");
 scanf("%lf",&ent_bal);
 r->balance=r->balance+ent_bal;
 outtextxy(30,100,"BALANCE iS ADDED SUCCESSFULLY");
 printf("\n\n\t\t");
 printf("YOUR NEW BALANCE IS = %lf",r->balance) ;
/* outtextxy(30,150,"ENTER YOUR PASSWORD");
 printf("\n\n\t\t");
 scanf("%s",&(temp->password));

printf("Add the balance\n");
scanf("%lf",&ent_bal);



printf("Balamce is added successfully\n");
printf("YOUR NEW BALANCE IS= %lf",r->balance);     */
(r->top)++;
r->passbook[r->top].balance_passbook=ent_bal;
strcpy(r->passbook[r->top].entry,"Deposit");
strcpy(r->passbook[r->top].date,__DATE__);
strcpy(r->passbook[r->top].time,__TIME__);
getch();

}

void withdraw(struct customer *r){          //change the return type void to structure pointer
//struct customer* withdraw(struct customer *r){

double ent_bal;
clrscr();
cleardevice();
 settextstyle(DEFAULT_FONT,0,2);
if(r->balance!=0.0)
{

  printf("Enter the withdraw balance\n");
  scanf("%lf",&ent_bal);
   if(r->balance>=ent_bal)
    {
	r->balance=r->balance-ent_bal;
	printf("Balance is withdraw successfully\n");
	printf("YOUR NEW BALANCE IS= %lf",r->balance);
	(r->top)++;
r->passbook[r->top].balance_passbook=ent_bal;
strcpy(r->passbook[r->top].entry,"Withdraw");
strcpy(r->passbook[r->top].date,__DATE__);
strcpy(r->passbook[r->top].time,__TIME__);

    }
    else
    {
	printf("Insufficient balance");
    }
}
else{
	printf("Insufficient balance");
}
getch();

}

void delete_account(struct customer *r)
{
 struct customer *pre,*q;
  settextstyle(DEFAULT_FONT,0,2);
 q=customer_link;
 while((string_compare(q->name,r->name)!=1)||(q->link!=NULL))
 {
  pre=q;
  q=q->link;
 }
 printf("Your final trnsaction is %lf\n",q->balance);
 q->balance=0.0;
 pre->link=q->link;
 printf("YOUR ACCOUNT IS DELTED\n");
 free(q);
 getch();
 exit(0);
}

void print_passbook(struct customer *temp)
{

 int j;
 clrscr();cleardevice();
 if(temp->top==-1)
 {
  printf("your passbook has no entry\n");
 }
 else{
 printf("Transection  \t\t  Amount\t\t  date\t\t\t Time\n");
 for(j=0;j<=temp->top;j++)
 {
 if(string_compare(temp->passbook[j].entry,"Deposit"))
  {
   printf("%s \t\t%lf\t\t%s\t\t%s\n",temp->passbook[j].entry,temp->passbook[j].balance_passbook,__DATE__,__TIME__);
  }
 else
  {
   printf("%s\t\t%lf\t\t%s\t\t%s\n",temp->passbook[j].entry,temp->passbook[j].balance_passbook,__DATE__,__TIME__);
  }
 }
 }
  getch();
}


