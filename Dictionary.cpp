#include<iostream>
#include<conio.h>
#include<fstream>
#include<process.h>    //exit
//#include<unistd.h>     //sleep
#include<string.h>
#include<windows.h>
using namespace std;


void gotoxy(long x, long y) 
      {
           COORD pos = {x, y};
           SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
      }

layout()
{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED );
	int i;
	cout<<"\n\n\n";
	cout<<"\t    ****************************************************************************************\n";
	cout<<"\t   |\t\t                    LOVELY PROFESSIONAL UNIVERSITY                          |\n";
	cout<<"\t   |\t\t           Department Of Computer Science And Engineering                   |\n";
	cout<<"\t   |\t\t                                                                            |\n";
	cout<<"\t   |\t\t                       A MINI PROJECT ON                                    |\n";
	cout<<"\t   |\t\t                                                                            |\n";
	cout<<"\t   |\t\t                           Dictionary                                       |\n";
	cout<<"\t   |\t\t                                                                            |\n";
	cout<<"\t   |\t\t        BY:                                         GUIDE:                  |\n";
	cout<<"\t   |\t\t     -------------                                -----------               |\n";
	cout<<"\t   |\t\t   VIKRANT CHAUDHARY                                                        |\n";
	cout<<"\t   |\t\t   Reg No.-> 11703065                                                       |\n";
	cout<<"\t   |\t\t   Roll NO.->52                                                             |\n";
    cout<<"\t    ****************************************************************************************\n\n";
	
}

/////////////////////////////////

welcome_page()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
	    int n;
		cout<<" \n          ~~~~~~~~~~~~~~~~~Enter Your Choice~~~~~~~~~~~~~~~~~~\n\n";
		cout<<"                          ----------------------- \n";
		cout<<"                         |   1.Save Word         |\n";       //remove it
		cout<<"                         |   2.Word list         |\n";       //word list
		cout<<"                         |   3.Find Meaning      |\n";       //find word
		cout<<"                         |   4.Update Word       |\n";       //change word
		cout<<"                         |   5.Delete Word       |\n";           //delete word
		cout<<"                         |   6.Exit              |\n";
	    cout<<"                          ----------------------- \n\t\t";
		cin>>n;
		return (n);
}


class dictionary
{
	public:
	char word[20],meaning[20];
	void create_contact()
	{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3 );
            cout<<"Enter Word: ";
            cin.ignore();
            gets(word);
            
           // cin.ignore();
            cout<<"Enter Meaning: ";
            gets(meaning);
                                 
								                                     
            cout<<"\n";
	}
	
	void show_cust_list()
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6 );
	//	cout<<endl<<"\t|\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		cout<<endl<<"\t|\t"<<word<<" :"<<meaning;	
		//cout<<endl<<"\t|\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	}
};  
 
 
fstream fp;
dictionary piz;
 
void save_word()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1 );
	fp.open("contactBook.dat",ios::out|ios::app);
	piz.create_contact();
	fp.write((char*)&piz,sizeof(piz));
	fp.close();
	cout<<endl<<endl<<"Word Has Been Sucessfully Saved...";
	getchar();
}
 
void word_list()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5 );
//	system("cls");
	 cout<<"\n\t\t================================\n\t\t\tLIST OF Words\n\t\t================================\n";
	fp.open("contactBook.dat",ios::in);
	while(fp.read((char*)&piz,sizeof(piz)))
	{
		piz.show_cust_list();
		cout<<endl<<"=================================================\n"<<endl;
	}
	fp.close();
}
 

void show_word(char* num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4 );
	bool found;
	//int ch;
	
		 found=false;
	fp.open("contactBook.dat",ios::in);
	while(fp.read((char*)&piz,sizeof(piz)))
	{
		if(strcmp(piz.word,num)==0)
		{
			system("cls");
			piz.show_cust_list();
			found=true;
		}
	}
	
	fp.close();
	if(found == false){
	cout<<"\n\nNo Word found...";}   
	getchar();
}
 
 
void update_word(char *num)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7 );
	//char num[20];
	getch();
	bool found=false;
	system("cls");
	cout<<"..::Edit contact\n===============================\n\n";
//	cin.ignore();
//	gets(num);
	fp.open("contactBook.dat",ios::in|ios::out);
	while(fp.read((char*)&piz,sizeof(piz)) && found==false)
	{
		if(strcmp(piz.word,num)==0)
		{
			piz.show_cust_list();
            cout<<"\nPlease Enter The New Word Meaning "<<endl;
			piz.create_contact();
			int pos=-1*sizeof(piz);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&piz,sizeof(piz));
			cout<<endl<<endl<<"\t Word Successfully Updated...";
			found=true;
		}
	}
	fp.close();
	if(found==false)
		cout<<endl<<endl<<"Word Not Found...";
 
 
}
 
 
void delete_word()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED );
	char num[20];
	system("cls");
	cout<<endl<<endl<<"Please Enter The Word: ";
	cin>>num;
	fp.open("contactBook.dat",ios::in|ios::out);
	fstream fp2;
	fp2.open("Temp.dat",ios::out);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&piz,sizeof(piz)))
	{
		if(strcmp(piz.word,num)!=0)
		{
			fp2.write((char*)&piz,sizeof(piz));
		}
	}
	fp2.close();
	fp.close();
	remove("contactBook.dat");
	rename("Temp.dat","contactBook.dat");
	cout<<endl<<endl<<"\Order Deleted...";
}

//////////////////////////////////
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2 );
	char num[20];
	int k;
	layout();
	tx:
	k=welcome_page();
	switch(k)
	{
		case 1:
		//	piz.menu();
			save_word();
		    goto tx;
		case 2:
			system("cls");
			word_list();
		    goto tx;
		case 3:
			cout<<"Enter the Word \n";
			cin.ignore();
			gets(num);
			show_word(num);
			goto tx;
		case 4:
			cout<<"Enter the Word \n";
			cin.ignore();
			//gets(num);
			cin.getline(num,20);
		    update_word(num);
		    goto tx;
		case 5:
		    delete_word();
		    goto tx;
		    
		case 6:
		    exit (0);	
		default:
			printf("                               Enter Valid Option\n");
		    goto tx;	     	
	}
	return 0;
}
////////////////////////////////////////////////
