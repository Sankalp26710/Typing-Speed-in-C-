#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<fstream.h>
#include<time.h>
#include<dos.h>
#include<stdlib.h>
class typing
{
   int v,age;
   int count,x,y;
   double time,lps,lpm;
   char ch[5000],name[50],bh[5000];
   public :
   void getfromfile();
   void check();
   void calspeed();
   void getinfo()
   {
      delay(1000);
      cout<<"Enter Your Name : ";
      gets(name);
      delay(1000);
      cout<<"Enter Your Age : ";
      cin>>age;
      delay(1000);
   }
   void instructions()
   {
     delay(1000);
     cout<<"\nGet Through These Instructions Before We Begin Your Typing Speed Test - \n";
     delay(2000);
     cout<<"\n1) There Is No Time Limit For This Test.\n";
     delay(2000);
     cout<<"2) You Will Get A Paragraph To Type In This Program.\n";
     delay(2000);
     cout<<"3) The Letter Or Words You Will Type , Only Those Words Will Be Counted.\n";
     delay(2000);
     cout<<"4) The Mistakes You Will Make In Your Test Will Be Counted.\n";
     delay(2000);
     cout<<"5) The Given Paragraph Is Case Sensitive.\n" ;
     delay(2000);
     cout<<"6) You Will Get Your Results In Letters Per Second And In Letters Per Minute.\n";
     delay(2000);
     cout<<"7) If You Enter An Extra Letter/Space Then All The Letters To Its Right Will Be Considered As Wrong.\n";
     delay(2000);
     cout<<"\n\n            Now You Will Get A Paragraph To Write in 10 Seconds." ;
     delay(1000);
     cout<<"\n\t\t\t\tALL THE BEST";
     delay(9000);

   }
   void entry()
   {
     clock_t start,end;
     delay(2000);
     cout<<"\n\nYou Have To Type The Above Paragraph \n";
     delay(1000);
     cout<<"\n\nYour";
     delay(1000);
     cout<<" Time";
     delay(1000);
     cout<<" Starts ";
     delay(1000);
     cout<<"Now!!! ";
     delay(500);
     cout<<"\nLet's Start :\n";
     start=clock();
     gets(ch);
     end=clock();
     time=(end-start)/CLK_TCK;
   }
   void dispspeed()
   {
     delay(1000);
     cout<<"The Paragraph You Entered Contains "<<x<<" Number of Letters "<<endl;
     delay(1000);
     cout<<"You Have Entered "<<count<<" Number Of Wrong Letters "<<endl;
     delay(1000);
     cout<<"Your Speed is "<<lps<<" Letters Per Second ";
     delay(1000);
     cout<<"And "<<lpm<<" Letters Per Minute "<<endl;
   }
   void remark()
   {
     delay(1000);
     cout<<"Your Remarks \n";
     if(lpm<50)
     {
       delay(1000);
       cout<<"Very Poor Speed , Please Improve !!";
     }
     else if(lpm>50&&lpm<=80)
     {
      delay(1000);
      cout<<"Average Speed , Please Try To Improve More !!";
     }
     else if(lpm>80&&lpm<120)
     {
      delay(1000);
      cout<<"Good Speed , But You Can Do Better !!";
     }
     else
     {
      delay(1000);
      cout<<"Impressive Speed , Keep it up !!";
     }
   }
   void dispinfo()
   {
      clrscr();
      cout<<"\nWait For A Second\n";
      delay(1000);
      cout<<"Calculating Your Results\n" ;
      delay(1000);
      cout<<"Your Name : "<<name<<endl;
      delay(1000);
      cout<<"Your Age : "<<age<<endl;
   }
};

void typing::getfromfile()
   {
      randomize();
      fstream f;
      v=1+random(4);
      clrscr();
      switch(v)
       {
	  case 1 : f.open ("Nature.txt",ios::in);
		   break;
	  case 2 : f.open ("Space.txt",ios::in);
		   break;
	  case 3 : f.open ("Humanity.txt",ios::in);
		   break;
	  case 4 : f.open ("GST.txt",ios::in);
		   break;
       }
	  char a[50];
	  while(f)
	  {
	    f>>a;
	    if(strcmpi(a,"0")==0)
	      break;
	    else
	      cout<<a<<" ";
	  }
   }
void typing::check()
   {
     count=0;
     fstream s;
      switch(v)
       {
	  case 1 : s.open ("Nature.txt",ios::in);
		   break;
	  case 2 : s.open ("Space.txt",ios::in);
		   break;
	  case 3 : s.open ("Humanity.txt",ios::in);
		   break;
	  case 4 : s.open ("GST.txt",ios::in);
		   break;
       }
     s.getline(bh,5000);
     int i=0;
     while(ch[i]!='\0')
     {
       if(ch[i]!=' ')
       {
	 if(ch[i]!=bh[i])
	 {
	   count++;
	 }
       }
       i++;
      }

   }
void typing::calspeed()
   {
     x=0;
     for(int l=0;ch[l]!='\0';l++)
     {
     if(ch[l]!=' ')
       {
	 x++;
       }
     }
     y=x-count;
     lps=y/time;
     cout<<y<<endl;
     lpm=60*(y/(time));
   }
void main()
{
   clrscr();
   typing obj;
   delay(1000);
   cout<<"\n\t\t    Welcome To The World Of C++ Programming\n";
   delay(1000);
   cout<<"\n\n\t\tIn This Program Your Typing Speed Will Be Checked. \n\n\n";
   obj.getinfo();
   obj.instructions();
   obj.getfromfile();
   obj.entry();
   obj.check();
   obj.calspeed();
   obj.dispinfo();
   obj.dispspeed();
   obj.remark();
   delay(1500);
   cout<<"\n\t\t\t\t  Thank You";
   getch();
}
