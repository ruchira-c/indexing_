
#include<fstream>    //for reading and writing files
#include<conio.h>      //for clrscr()
#include<string.h>     //for string characters
#include<stdio.h>      //for gets and puts function
#include<process.h>    //for exit function
#include<iomanip>    //for setw function
#include<dos.h>        //for delay and sleep function
#include<graphics.h>   //for textcolor & textbackground

      class consumer
		{
		int cno;
		char cname[20];
		char address[20];
		int a,b,c;
		float i;
		public:

      //FUNCTION TO ENTER THE VALUES

		public:

      void entry()
		{
		clrscr();
		textcolor(RED);
		gotoxy(32,4);
		cputs("P.H.O.E.N.I.X COMPUTERS");
		gotoxy(5,8);
		cputs("Customer ID :");
		gotoxy(5,10);
		cputs("Customer name :");
		gotoxy(5,12);
		cputs("Customer address :");
		gotoxy(5,14);
		cputs("Costumer Phone number :");
		gotoxy(45,8);
		cin>>cno;
		gotoxy(45,10);
		gets(cname);
		gotoxy(45,12);
		gets(address);
		gotoxy(45,14);
		}

      //FUNCTION TO DISPLAY THE VALUES

      void display()
		    {
		    cout<<"\n\n";
		    gotoxy(5,8);
		    cputs("Customer ID :");
		    cout<<cno;
		    gotoxy(5,10);
		    cputs("Customer name :");
		    puts(cname);
		    gotoxy(5,12);
		    cout<<"Customer address :"<<address;
		    gotoxy(5,14);
		    cout<<"Costumer Phone number :"<<c;
		    }
      int rcno()
      {
      return cno;
      }
      }c;

      //FUNCTION TO WRITE THE VALUES

      void write()
		{
		char ch;
		consumer c;
		fstream f1;
		c.entry();
		f1.open("main.dat",ios::app|ios::binary);
		cout<<"\n\n\tDO you want to save the record(y/n)\t";
		cin>>ch;
		if(ch=='y')
		{
		f1.write((char*)&c,sizeof(c));
		}
		f1.close();
		}

	  //FUNCTION TO READ THE VALUES

      void read()
		{
		consumer c;
		fstream f1;
		f1.open("main.dat",ios::in|ios::binary);
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		c.display();
		if(f1.eof())
		{
		cout<<"\n\n   End of the file reached\n\n";
		}
		}
		f1.close();
		}

      //FUNCTION FOR SEARCHING THE RECORD

      void search()
		{
		consumer c;
		int rn;
		char found='n';
		ifstream f1("main.dat",ios::in);
		cout<<"\n\n Enter Customer ID you want to SEARCH :\t";
		cin>>rn;
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		if(c.rcno()==rn)
		{
		c.display();
		found='y';
		break;
		}
		}
		if(found=='n')
		cout<<"\n\n\tRECORD NOT FOUND!!!!!!!!!!!!!\n"<<endl;
		f1.close();
		}

      //FUNCTION TO DELELTE THE RECORD

      void del()
		{
		ifstream f1("main.dat",ios::in);
		ofstream f2("temp.dat",ios::out);
		int rno;
		char found='f',confirm='n';
		cout<<"\n\n Enter Customer ID you want to DELETE :\t";
		cin>>rno;
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		if(c.rcno()==rno)
		{
		c.display();
		found='t';
		cout<<"\n\n Are you sure want to DELETE this record ? (y/n)\t";
		cin>>confirm;
		if(confirm=='n')
		f2.write((char*)&c,sizeof(c));
		}
		else
		f2.write((char*)&c,sizeof(c));
		}
		if(found=='f')
		cout<<"\n\n\tRECORD NOT FOUND\n";
		f1.close();
		f2.close();
		remove("main.dat");
		rename("temp.dat","main.dat");
		f1.open("main.dat",ios::in);
		clrscr();
		cout<<"\n\n\n Now the file contains\n\n\n";
		while(!f1.eof())
		{
		f1.read((char*)&c,sizeof(c));
		if(f1.eof())
		c.display();
		}
		f1.close();
		}

      //FUNCTION TO MODIFY THE RECORD

      void update()
		{
		fstream f1("main.dat",ios::in | ios::out | ios::binary);
		int rno;
		long pos;
		char found='f';
		cout<<"\n\n Enter the Customer ID you want to MODIFY :\t";
		cin>>rno;
		while(!f1.eof())
		{
		pos=f1.tellg();
		f1.read((char*)&c,sizeof(c));
		if(c.rcno()==rno)
		{
		c.entry();
		f1.seekg(pos);
		f1.write((char*)&c,sizeof(c));
		found='t';
		break;
		}
		}
		if(found=='f')
		cout<<"\n\n\tRECORD NOT FOUND\n";
		f1.seekg(0);
		clrscr();
		cout<<"\n Now the file contains\n\n";
		c.display();
		f1.close();
		getch();
		}

      //STARTING OF THE VOID MAIN

	void main()
		{
		textbackground(LIGHTBLUE);
		unsigned int sum,add,d,j,e,f,g,h,z,choice;
		int abis=0,apep=0,aden=0,amun=0,aree=0;
		unsigned int m=0,n=0,o=0,p=0,v=0;
		int pend=0,print=0,p1=0,p2=0,mo=0,mous=0,web=0,aweb=0,asc=0,scan=0,total=0;
		char pu,str[10],yes,et;
		clrscr();



// TO PURCHASE ,SEARCH ,MODIFY ,DELETE ,DISPLAY ALL RECORDS ,DETAILS ,NEW CUSTOMER

		again:;
		clrscr();
		textbackground(LIGHTBLUE);
		textcolor(GREEN);
		cout<<"\n\t\t\t    ^^^^^^^^^^^^^^^^^^^^^^^^^^^";
		cout<<"\n\t\t\t    !=========================!\n";
		cout<<"\n\t\t\t    !*****  PC PARADISE  *****!\n";
		cout<<"\n\t\t\t    !=========================!";
		cout<<"\n\t\t\t    ^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n\n\n\n";
		cout<<"  \t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
		cout<<"\n\n\t\t\t*     1.NEW CUSTOMER              *";
		cout<<"\n\n\t\t\t*     2.SEARCH A RECORD           *";
		cout<<"\n\n\t\t\t*     3.DELETE A RECORD           *";
		cout<<"\n\n\t\t\t*     4.MODIFY A RECORD           *";
		cout<<"\n\n\t\t\t*     5.QUANTITY AVAILABLE        *";
		cout<<"\n\n\t\t\t*     0.EXIT                      *\n";
		cout<<"\n\t\t\t$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$";
		cout<<"\n\n\n\n\t Enter your choice :\t";
		cin>>d;
		switch(d)
		{

	case 1:

		clrscr();
		textcolor(WHITE);
		cout<<"\n\n\n\t\t\t S.T.A.R  COMPUTERS";
		cout<<"\n\n\n\t\t\t CONSUMER INFORMATION";

	// TO ENTER THE DETAILS OF THE COSTUMER

		write();

	// ITEMS AND THIER RATES
		start:
		cout<<"\n\n\nDO YOU WANT TO PURCHASE(Y/N):\n\n";
		cin>>pu;
		if(pu=='Y'||pu=='y')
		{
		clrscr();

	// PURCHASE LIST

		items:;
		cout<<"\n\t\t\t\t*************";
		cout<<"\n\t\t\t\tPURCHASE LIST";
		cout<<"\n\t\t\t\t*************\n\n\n\n";
		cout<<"\n\n\t\t\t1.PENDRIVE";
		cout<<"\n\n\t\t\t2.SCANNER";
		cout<<"\n\n\t\t\t3.PRINTER";
		cout<<"\n\n\t\t\t4.WEBCAM";
		cout<<"\n\n\t\t\t5.MOUSE";
		cout<<"\n\n\n\t\t\tEnter your choice\t";
		cin>>choice;
		if(choice==1)
		{

	//ITEMS AND RATES

		bis:;
		clrscr();
		cout<<"\n\n\t\t\t\tPENDRIVES\n\n";
		cout<<"\n     ITEMS\t\t\t\t\tRATE\n";
		cout<<"\n  1. 2GB\t\t\t\t\t350\n";
		cout<<"    2. 4GB\t\t\t\t\t500\n";
		cout<<"    4. 8GB\t\t\t\t\t800\n";
		cout<<"    5. 16GB\t\t\t\t\t1800\n";
		cout<<"    6. 32GB\t\t\t\t\t2400\n";
		cout<<"    7. 64GB\t\t\t\t\t3000\n";
		cout<<"\n\n\tWhich PENDRIVE you want to purchase\t";
		cin>>p1;
		if(p1==1)
		{
		pend=350;
		}
		else if(p1==2)
		{
		pend=500;
		}
		
		else if (p1==4)
		{
		pend=800;
		}
		else if(p1==5)
		{
		pend=1800;
		}
		else if(p1==6)
		{
		pend=2400;
		}
		else if(p1==7)
		{
		pend=3000;
		}
		else if(p1==0)
		{
		goto items;
		}
		else if(p1!=1||p1!=2||p1!=4||p1!=5||p1!=6||p1!=7)
		{
		cout<<"\n\n\tOOPS!!!!!!!  Wrong choice\n\n";
		getch();
		goto bis;
		}
		cout<<"\n\tPENDRIVE(MAX 5): \t";
		cin>>m;
		if(m>5)
		{
		cout<<"\n\n\tEnter Quantity Smaller than 5";
		getch();
		goto items;
		}
		else
		abis=1000-m;
		cout<<"\n\tDO you want to purchase more(y/n)";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==2)
		{
		pep:;
		clrscr();
		cout<<"\n\n\t\t\t\tSCANNER\n\n";
		cout<<"\n    ITEMS\t\t\t\tRATE\n";
		cout<<"\n  1.FLATBED\t\t\t\t5000\n";
		cout<<"  2.SHETFED\t\t\t\t6000\n";
		cout<<"  3.PHOTO SCANNER\t\t\t4500\n";
		cout<<"  4.FILM SCANNER\t\t\t8000\n";
		cout<<"  5.PORTABLE SCANNER\t\t\t10000\n";
		cout<<"\n\n\tWhich SCANNER do you want to purchase\t";
		cin>>scan;
		if(scan==1)
		{
		asc=5000;
		}
		else if(scan==2)
		{
		asc=6000;
		}
		else if(scan==3)
		{
		asc=4500;
		}
		else if(scan==4)
		{
		asc=8000;
		}
		else if(scan==5)
		{
		asc=10000;
		}
		else if(scan==0)
		{
		goto items;
		}
		else if(scan!=1||scan!=2||scan!=3||scan!=4||p1!=5)
		{
		cout<<"\n\n\tOOPS!!!!!!!  Wrong choice\n\n";
		getch();
		goto pep;
		}
		cout<<"\n\n\tSCANNER(MAX 5):\t ";
		cin>>n;
		if(n>5)
		{
		cout<<"\n\n\tEnter Quantity Smaller than 5";
		getch();
      goto items;
		}
		else
		apep=1000-n;
		cout<<"\n\tDO you want to purchase more(y/n)";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==3)
		{
		den:;
		clrscr();
		cout<<"\n\n\t\t\t\tPRINTER\n\n";
		cout<<"\n     ITEMS\t\t\t\tRATE\n";
		cout<<"\n  1. HP Laser jet\t\t\t2000\n";
		cout<<"  2. DOT Matrix Printer\t\t\t500\n";
		cout<<"\n\n\tWhich PRINTER you want to purchase\t";
		cin>>p2;
		if(p2==1)
		{
		print=500;
		}
		else if(p2==2)
		{
		print=2000;
		}
		else if(p2==0)
		{
		goto items;
		}
		else if(p2!=1||p2!=2)
		{
		cout<<"\n\n\tOOPS!!!!!!!  Wrong choice\n\n";
		getch();
		goto den;
		}
		cout<<"\n\tPRINTER(MAX 5):\t ";
		cin>>o;
		if(o>5)
		{
		cout<<"\n\n\tEnter Quantity Smaller than 5";
      goto items;
		}
		else
		aden=110-o;
		cout<<"\n\tDO you want to purchase more(y/n)";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==4)
		{
		mun:;
		clrscr();
		cout<<"\n\n\t\t\t\tWEBCAM\n\n";
		cout<<"\n    ITEMS\t\t\t\t\tRATE\n";
		cout<<"\n  1.5 PIXEL\t\t\t\t\t1500\n";
		cout<<"  2.8 PIXEL\t\t\t\t\t6000\n";
		cout<<"  3.12 PIXEL\t\t\t\t\t12000\n";
		cout<<"\n\n\tWhich WEBCAM you want to purchase\t";
		cin>>web;
		if(web==1)
		{
		aweb=1500;
		}
		else if(web==2)
		{
		aweb=6000;
		}
		else if(web==3)
		{
		aweb=12000;
		}
		else if(web==0)
		{
		goto items;
		}
		else if(web!=1||web!=2||web!=3)
		{
		cout<<"\n\n\tOOPS!!!!!!!  Wrong choice\n\n";
		getch();
		goto mun;
		}
		cout<<"\n\n\tWEBCAM(MAX 5):\t ";
		cin>>p;
		if(p>5)
		{
		cout<<"\n\n\tEnter Quantity Smaller than 5";
		getch();
		goto items;

		}
		else
		amun=1000-p;
		cout<<"\n\tDO you want to purchase more(y/n)";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;
		}
		else
		{
		clrscr();
		goto cash;
		}
		}
		if(choice==5)
		{
		park:;
		clrscr();
		ree:;
		clrscr();
		cout<<"\n\n\t\t\t\tMOUSE\n\n";
		cout<<"\n    ITEMS\t\t\t\tRATE\n";
		cout<<"\n  1.BALL MOUSE\t\t\t\t150\n";
		cout<<"    2.LASER MOUSE\t\t\t\t300\n";
		cout<<"\n\n\tWhich MOUSE do you want to purchase\t";
		cin>>mous;
		if(mous==1)
		{
		mo=150;
		}
		else if(mous==2)
		{
		mo=300;
		}
		else if(mous==0)
		{
		goto items;
		}
		else if(mous!=1||mous!=2)
		{
		cout<<"\n\n\tOOPS!!!!!!!Wrong choice\n\n";
		getch();
		goto ree;
		}
		cout<<"\n\tMOUSE(MAX 2):\t ";
		cin>>v;
		if(v>2)
		{
		cout<<"\n\n\tEnter Quantity Smaller than 2";
		getch();
		goto items;
		}
		else
		aree=300-v;
		cout<<"\n\tDO you want to purchase more(y/n)";
		cin>>yes;
		if(yes=='y')
		{
		clrscr();
		goto items;   //GO BACK TO PURCHASE LIST
		}
		else
		{
		clrscr();
		goto cash;    //TO DISPLAY BILL
		}
		}
		cout<<"\n\n\n";
		clrscr();
		cash:;
		cout<<"\n\n\n\n\n\n\t\t\t\t S.T.A.R COMPUTERS\n";
		cout<<"\n\n\t\t\t\t    CASH MEMO\n";
		cout<<"\n\n\n\n\n\n\n\n";

      //TO DISPLAY THE INFORMATION OF THE CUSTOMER

		c.display();

	//TO DISPLAY THE CASH MEMO

		cout<<"\n\n\n\n";
		cout<<"===============================================================================";
		cout<<"\nITEMS"            <<setw(40)<<"QUANTITY"<<setw(35)<<"PRICE(Rs.)";
		cout<<"===============================================================================";
		if(m>0)
		cout<<"\n\nPENDRIVE"            <<setw(35)<<m<<setw(28)<<"Rs."<<m*pend;
		if(n>0)
		cout<<"\n\nSCANNER"             <<setw(36)<<n<<setw(28)<<"Rs."<<n*asc;
		if(o>0)
		cout<<"\n\nPRINTER"             <<setw(36)<<o<<setw(28)<<"Rs."<<o*print;
		if(p>0)
		cout<<"\n\nWEBCAM"              <<setw(37)<<p<<setw(28)<<"Rs."<<p*aweb;
		if(v>0)
		cout<<"\n\nMOUSE"                <<setw(38)<<v<<setw(28)<<"Rs."<<v*mo;
			e=m*pend;
			f=n*asc;
			g=o*print;
			h=p*aweb;
			z=v*mo;
		   sum=e+f+g+h+z;     //TOTAL BILL
		   add=m+n+o+p+v;     //QUANTITY OF ITEMS
		cout<<"\n===============================================================================";
		cout<<"\nTOTAL:"<<setw(38)<<add<<setw(27)<<"Rs."<<sum;
		money:;
		cout<<"\n\n\n\n\t\t\tEnter the cash paid\t";
		cin>>total;
		cout<<"\n\n\n\t\t\tCASH RECIEVED :"<<total;
		if(total<sum)
		{
		cout<<"\n\n\tThe money you paid is less !!!! Please pay more money";
		getch();
		goto money;
		}
		clrscr();

		cout<<"\n\n\n\n\n\t\tCASH RECEIVED :\t"<<total;
		cout<<"\n\n\t\tCASH AMOUNT :\t"<<sum;
		cout<<"\n\n\t\tBALANCE RETURNED :\t"<<total-sum;
		cout<<"\n\n\tTHANK YOU .\t\t\t\tVISIT US AGAIN\n";
		cout<<"\n\n\tTHANK YOU FOR USING OUR SERVICE\n\n";
		getch();
		goto again;
		}
		else
		{
		clrscr();
		getch();
		goto again;
		}

	 case 2:

		//TO SEARCH THE RECORDS

		clrscr();
		search();
		getch();
		goto again;

	 case 3:

		//TO DELETE THE RECORDS

		clrscr();
		del();
		getch();
		goto again;

	 case 4:

		//TO MODIFY THE RECORDS

		clrscr();
		update();
		getch();
		goto again;

	 case 5:

		//TO DISPLAY THE QUANTITY AVAILABLE IN THE SHOP

		clrscr();
		if(m>0||n>0||o>0||p>0||v>0)
		{
		cout<<"\n\t\t\tItems Avaliable in shop.\n\n\n";
		cout<<"===============================================================================";
		cout<<"\nITEMS"            <<setw(40)<<"QUANTITY";
		cout<<"\n===============================================================================";
		cout<<"\n\n\nPENDRIVE"            <<setw(37)<<abis;
		cout<<"\n\n\nSCANNER"             <<setw(38)<<apep;
		cout<<"\n\n\nPRINTER"             <<setw(38)<<aden;
		cout<<"\n\n\nWEBCAM"              <<setw(39)<<amun;
		cout<<"\n\n\nMOUSE"               <<setw(40)<<aree;
		cout<<"\n*******************************************************************************";
		getch();
		goto again;
		}
		else
		{
		{
		cout<<"\n\t\t\tItems Avaliable in shop.\n\n\n";
		cout<<"===============================================================================";
		cout<<"\nITEMS"            <<setw(40)<<"QUANTITY";
		cout<<"\n===============================================================================";
		cout<<"\n\n\nPENDRIVE"             <<setw(37)<<1000;
		cout<<"\n\n\nSCANNER"              <<setw(38)<<1000;
		cout<<"\n\n\nPRINTER"        	   <<setw(37)<<110;
		cout<<"\n\n\nWEBCAM"               <<setw(39)<<1000;
		cout<<"\n\n\nMOUSE"                <<setw(39)<<300;
		cout<<"\n\n*******************************************************************************";
		getch();
		goto again;
		}

	 case 0:

		//TO EXIT FROM THE PROGRAM
		clrscr();
		exit(0);
		default:
		cout<<"OOPS!!!!!!!! Your choice is WRONG";
		}
		}
		}





