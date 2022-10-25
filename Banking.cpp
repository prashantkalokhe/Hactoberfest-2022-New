

//****************************************************************
//PROJECT BANKING SYSTEM 
//****************************************************************
//INCLUDES HEADER FILES
//****************************************************************
 
#include<iostream.h>
#include<fstream.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<iomanip.h>
#include<graphics.h>
 
 
typedef char option[15];
const int ROW = 10,COL = 10;
 
int scan;    // To hold the special characters for moving the prompt in menu
int ascii;
//****************************************************************
// To display the main menu options
//****************************************************************
option a[]= {
			 "NewAccount",
			 "ListofAccounts",
			 "IndAccount",
			 "DailyTrans",
			 "MonthlyReport",
			 "EditAccount",
			 "Exit"};
 
// Displays the modify menu options
option b[] = {
				"Modify Account",
				"Closeaccount",
				"Quit"
			};
 
// Function used to do screening
class main_menu
{
	int i,done;
 
	public:
		void normalvideo(int x,int y,char *str);
		void reversevideo(int x,int y,char *str);
		void box(int x1,int y1,int x2,int y2);
		char menu();
		void control_menu();
		char e_menu();
		void edit_menu();
		void help(void);
};
 
 
 
 
//****************************************************************
/* Class member functions for drawing boxes */
//****************************************************************
 
class shape
{
	public:
		void line_hor(int, int, int, char);
		void line_ver(int, int, int, char);
		void box(int, int, int, int, char);
};
 
 
// Class contains the initial deposit of customers
class initial
{
 public:
     void add_to_file(int, char t_name[30], char t_address[30], float);
	    // For initial deposits in customers account
     void display_list(void); // Displaying customers account list
     void delete_account(int); // Deleting customers account
     void update_balance(int, char t_name[30], char t_address[30], float);
	    // For updating the customer account
     void modify(void);      // To modify the customer account information
     int last_accno(void); // To know the last account number
     int found_account(int);
	    // To found the account is in "INITIAL.dat" or not
     char *return_name(int);
	    // Function for validation entry of customer name
     char *return_address(int);
	    // Function for validation entry of customer address
     float give_balance(int);
	    // To print the balance amount of a particular customer
     int recordno(int);
     void display(int); // To display the customer account
 
 private:
     void modify_account(int, char t_name[30], char t_address[30]);
	    // Function to modify the customer account
     int accno;
     char name[30], address[30];
     float balance;
};
 
// Class contains the customers daily transaction entry
class account
{
 public:
     void new_account(void);    // Function to create a new account
     void close_account(void);  // Function to close an account
     void display_account(void);// Function to display the accounts
     void transaction(void);    // To display the transaction process
     void clear(int, int);      // Function to perform a clear screen function
     void month_report(void);   // Function to list monthly transaction report
 
 private:
     void add_to_file(int,int,int,int,char,char t_type[10],float,float,float);
	    // Function to add transaction records
     void delete_account(int);  // Function to delete a transaction record
     int no_of_days(int, int, int, int, int, int);
	    // Function to find the total days
     float calculate_interest(int, float);
	    // Function for calculating interest of an account
     void display(int);         // Function to display a transaction account
     void box_for_display(int); // Function for displaying box
     int accno;
     char type[10];             // Account type as Cheque or Cash
     int dd, mm, yy;            // To store the system date/ Enter date
     char tran;                 // As the account type is Deposit or Withdraw
     float interest, amount, balance;
};
 
// Function to displays all the menu prompt messages from the pointer array of
// option a[]
void main_menu::normalvideo(int x,int y,char *str)
{
     gotoxy(x,y);
     cprintf("%s",str);
}
 
// Function to move the cursor on the menu prompt with a reverse video color
void main_menu::reversevideo(int x,int y,char *str)
{
     textcolor(5+143);
     textbackground(WHITE);
     gotoxy(x,y);
     cprintf("%s",str);
     textcolor(GREEN);
     textbackground(BLACK);
}
 
void main_menu::box(int x1,int y1,int x2,int y2)
{
     for(int col=x1;col<x2 ;col++)
     {
      gotoxy(col,y1);
      cprintf("%c",196);
      gotoxy(col,y2);
      cprintf("%c",196);
      }
 
     for(int row=y1;row<y2;row++)
     {
      gotoxy(x1,row);
      cprintf("%c",179);
      gotoxy(x2,row);
      cprintf("%c",179);
      }
     gotoxy(x1,y1);
     cprintf("%c",218);
     gotoxy(x1,y2);
     cprintf("%c",192);
     gotoxy(x2,y1);
     cprintf("%c",191);
     gotoxy(x2,y2);
     cprintf("%c",217);
}
 
char main_menu::menu()
{
     clrscr();
     textcolor(22);
     box(20, 6, 65, 20);
     box(18, 4, 67, 22);
     textcolor(5+143);
     gotoxy(36, 5);
     textbackground(BLUE);
     cprintf("B A N K I N G");
     textbackground(BLACK);
     textcolor(22);
     for(i = 1; i < 7; i++)
     normalvideo(32, i+10, a[i]);
     reversevideo(32, 10, a[0]);
     i = done = 0;
     _setcursortype(_NOCURSOR);
     do
     {
      int key = getch();
      switch (key)
      {
       case 00:
	       key = getch();
	       switch (key)
	       {
		case 72:
		  normalvideo(32, i+10, a[i]);
		  i--;
		  if (i == -1)
		  i = 6;
		  reversevideo(32,i+10,a[i]);
		  break;
		case 80:
		  normalvideo(32, i+10, a[i]);
		  i++;
		  if (i == 7)
		  i = 0;
		  reversevideo(32, i+10, a[i]);
		  break;
		  }
	       break;
       case 13:
	       done = 1;
       }
      }
     while (!done);
     _setcursortype(_NOCURSOR);
     return(i+49);
}
 
// The function main_menu() is used to display the main menu of banking system
void main_menu::control_menu()
{
     char choice;
     account a;
     do
     {
      choice = menu();
      clrscr();
      switch (choice)
      {
       case '1':
		_setcursortype(_NORMALCURSOR);
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		a.new_account(); // New account member function
		break;
       case '2':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		initial ini;
		ini.display_list(); // Global list of account function
		break;
       case '3':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		_setcursortype(_NORMALCURSOR);
		a.display_account();
		// Displaying individual accounts all transactions
		break;
       case '4':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		account a;
		_setcursortype(_NORMALCURSOR);
		a.transaction(); // Daily transaction for individual account
		break;
       case '5':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		_setcursortype(_NORMALCURSOR);
		a.month_report(); // Monthly report for any account
		break;
       case '6':
		box(3, 1, 75, 24);
		box(5, 2, 73, 23);
		gotoxy(10,10);
		edit_menu();// Sub menu for modifying or deleting any account
		break;
       case '7' :exit(0);
       }
      } while (choice != 6);
}
 
// This function is used to return the cursor position to the edit menu
// function where the menu prompt will valid
char main_menu::e_menu()
{
      clrscr();
      textcolor(22);
      box(25,6,60,15);
      box(23,4,62,17);
      textcolor(5+143);
      gotoxy(34,5);
      textbackground(GREEN);
      cprintf("E D I T  -  M E N U");
      textcolor(22);
      textbackground(BLACK);
      for (i = 1;i < 3; i++)
      normalvideo(32, i+10, b[i]);
      reversevideo(32, 10, b[0]);
      i = done = 0;
      _setcursortype(_NOCURSOR);
      do
      {
       int key = getch();
       switch (key)
       {
	case 00:
		key = getch();
		switch (key)
		{
		 case 72:
		   normalvideo(32, i+10, b[i]);
		   i--;
		   if (i == -1)
		   i = 2;
		   reversevideo(32, i+10, b[i]);
		   break;
	case 80:
		normalvideo(32, i+10, b[i]);
		i++;
		if (i == 3)
		i=0;
		reversevideo(32, i+10, b[i]);
		break;
	}
	break;
	case 13:
		done = 1;
	}
       }while (!done);
       _setcursortype(_NOCURSOR);
       return(i+49);
}
 
/* Function for edit menu with account modification and close */
void main_menu::edit_menu()
{
      char choice;
      account a;
      do
      {
       choice = e_menu();
       clrscr();
       switch (choice)
       {
	case '1':
		 box(3, 1, 75, 24);
		 box(5, 2, 73, 23);
		 initial ini;
		 _setcursortype(_NORMALCURSOR);
		 ini.modify();
		 break;
	case '2':
		 box(3, 1, 75, 24);
		 box(5, 2, 73, 23);
		 account a;
		 _setcursortype(_NORMALCURSOR);
		 a.close_account();
		 break;
	case '3':
		 return;
	}
       } while (choice != 6);
}
 
/* Function to draw horizontal line */
void shape::line_hor(int column1, int column2, int row, char c)
{
      for (column1; column1 <= column2; column1++)
      {
       gotoxy(column1, row);
       cout<< c;
       }
}
 
/* Function to draw vertical line */
void shape::line_ver(int row1, int row2, int column, char c)
{
      for (row1; row1 <= row2; row1++)
      {
       gotoxy(column, row1);
       cout<< c;
       }
}
 
/* function for drawing box */
void shape::box(int column1, int row1, int column2, int row2, char c)
{
      char ch = 218;
      char c1, c2, c3, c4;
      char l1 = 196, l2 = 179;
      if (c == ch)
      {
       c1 = 218;
       c2 = 191;
       c3 = 217;
       c4 = 217;
       l1 = 196;
       l2 = 179;
       }
      else
      {
       c1 = c;
       c2 = c;
       c3 = c;
       c4 = c;
       l1 = c;
       c2 = c;
       }
      gotoxy(column1, row1);
      cout<< c1;
      gotoxy(column2, row1);
      cout<< c2;
      gotoxy(column1, row2);
      cout<< c3;
      gotoxy(column2, row2);
      cout<< c4;
      column1++;
      column2--;
      line_hor(column1, column2, row1, l1); //Horizontal line
      line_hor(column1, column2, row2, l1);
      column1--;
      column2++;
      row1++;
      row2--;
      line_ver(row1, row2, column1, l2); // Vertical line
      line_ver(row1, row2, column2, l2);
}
 
 
/* Function to display help about this project */
void main_menu::help(void)
{
      clrscr();
      setbkcolor(7);
      settextstyle(7,HORIZ_DIR,4);
      outtextxy(70,20,"Welcome to Banking System");
      settextstyle(2,HORIZ_DIR,5);
      outtextxy(60,100,"You can keep record of daily banking transaction");
      delay(2);
      outtextxy(60,130,"This program is capable of holding any no. of A/c");
      delay(2);
      outtextxy(60,160,"-In first option you can open new A/c");
      delay(2);
      outtextxy(60,190,"-In second option you can see the list of all A/c's");
      delay(2);
      outtextxy(60,220,"-In third option you can see all trans. of ind. A/c");
      delay(2);
      outtextxy(60,250,"-In fourth optiion you can do banking transactions");
      delay(2);
      outtextxy(60,280,"(Deposit/Withdraw)");
      delay(2);
      outtextxy(60,310,"-In fifth opt. you can take monthly ind. A/c report");
      delay(2);
      outtextxy(60,340,"-In sixth opt. you can modify or delete any account");
      delay(2);
      outtextxy(60,370,"Note-:Opening amount should not less that Rs. 500/-");
      delay(2);
      outtextxy(60,400,"-And last option is Quit (Exit to Window)");
      delay(2);
      settextstyle(7,HORIZ_DIR,4);
      outtextxy(80,420,"Press any key to continue...");
      getch();
}
 
/* Function for modifying the existing accounts */
void initial::modify(void)
{
      clrscr();
      int j;
      char t_acc[10];
      int t, t_accno;
      gotoxy(17, 1);
      cout<< "&lt;0>=Exit";
      gotoxy(5,5);
      cout<< "Enter the account no. ";
      gets(t_acc);
      t = atoi(t_acc);
      t_accno = t;
      if (t_accno == 0)
      return;
      clrscr();
      if (!found_account(t_accno))
      {
       gotoxy(5, 5);
       cout<< "\7Account not found";
       getch();
       return;
       }
      gotoxy(71, 1);
      cout<< "&lt;0>=Exit";
      textbackground(WHITE);
      gotoxy(3, 3);
      for(j=1;j<=76; j++)
      cprintf(" ");
      textbackground(BLACK);
      textcolor(BLACK+BLINK);
      textbackground(WHITE);
      gotoxy(30, 3);
      cprintf("Modify Account Screen");
      textcolor(LIGHTGRAY);
      textbackground(BLACK);
      int d1, m1, y1;
      struct date d;          // For extracting system date
      getdate(&d);
      d1 = d.da_day;
      m1 = d.da_mon;
      y1 = d.da_year;
      gotoxy(4, 2);
      cout<< "Date: " << d1 << "/" << m1 << "/" << y1;
      char ch;
      display(t_accno);
      account a;
      do
      {
       a.clear(5, 13);
       gotoxy(5, 13);
       cout<< "Modify this account <y/n>: ";
       ch = getche();
       if (ch == '0')
       return;
       ch = toupper(ch);
       }while (ch != 'N' && ch != 'Y');
      if (ch == 'N')
      return;
      int modified = 0, valid;
      char t_name[30], t_address[30];
      gotoxy(5, 15);
      cout<<"Name : ";
      gotoxy(5, 16);
      cout<< "Address : ";
      do
      {
       a.clear(15, 15);
       a.clear(5, 23);
       gotoxy(5, 23);
       cout<< "Enter Name or Press Enter for No Change";
       valid = 1;
       gotoxy(15, 15);
       gets(t_name);
       strupr(t_name);
       if (t_name[0] == '0')
       return;
       if (strlen(t_name) > 25)
       {
	valid = 0;
	gotoxy(5, 23);
	cprintf("\7Name should not greater than 25");
	getch();
	}
       } while (!valid);
      do
      {
       a.clear(15, 16);
       a.clear(5, 23);
       gotoxy(5, 23);
       cout<<"Enter Address or press enter for no Change";
       valid = 1;
       gotoxy(15, 16);
       gets(t_address);
       strupr(t_address);
       if (t_address[0] == '0')
       return;
       if (strlen(t_address) > 25)
       {
	valid = 0;
	gotoxy(5, 23);
	cprintf("\7Address should not greater than 25");
	getch();
	}
       }while (!valid);
      if (strlen(t_address) > 0)
      modified = 1;
      if (!modified)
      return;
      // clears the screen at 23rd row and from 5th column
      a.clear(5,23);
      do
      {
       a.clear(5, 23);
       gotoxy(5, 18);
       cout<<"Do you want to save Changes <Y/N>: ";
       ch = getche();
       if (ch == '0')
       return;
       ch = toupper(ch);
       }while (ch != 'N' && ch != 'Y');
      if (ch == 'N')
      return;
      // Passes the parameter to add in data file
      modify_account(t_accno, t_name, t_address);
      gotoxy(5, 21);
      cout<<"\7Record modified";
      gotoxy(5, 23);
      cout<< "Press any key to continue...";
      getch();
}
 
/* Function for displaying an account when modified */
void initial::display(int t_accno)
{
      fstream file;
      file.open("INITIAL.dat", ios::in);
      file.seekg(0, ios::beg);
      // Displays the record contents matching with t_accno from
      // INITIAL.dat data file
      while (file.read((char *)this, sizeof(initial)))
      {
       if (t_accno == accno)
       {
	gotoxy(8, 5);
	cout<< "Account no. " << accno;
	gotoxy(10, 8);
	cout<< "Name : ";
	puts(name);
	gotoxy(10, 9);
	cout<< "Address : ";
	puts(address);
	gotoxy(10, 10);
	cout<< "Balance : " << setw(15)    // setwidth
	<< setprecision(2)    // set position of decimal point
	<< setiosflags(ios::left)   // set left justified output
	<< setiosflags(ios::showpoint)  // always show decimal point
	<< setiosflags(ios::fixed)<< balance;// set fixed notation for display
	break;
	}
       }
      file.close();
}
 
/* Function for updating the modified account into INITIAL.dat file */
void initial::modify_account(int t_accno,char t_name[30],char t_address[30])
{
     int recno;
     recno = recordno(t_accno);
     fstream file;
     file.open("INITIAL.dat", ios::out|ios::ate);
     strcpy(name, t_name);
     strcpy(address, t_address);
     int location;
     // finds the position in data file
     location = (recno-1) * sizeof(initial);
     file.seekp(location);
     // Overwrites the modified record into INITIAL.dat data file
     file.write((char *)this, sizeof(initial));
     file.close();
     return;
}
 
/* Function to find the last account number */
int initial::last_accno(void)
{
     fstream file;
     file.open("INITIAL.dat", ios::in);
     file.seekg(0, ios::beg);
     int count = 0;
     // Founds the last account no.
     while (file.read((char *)this, sizeof(initial)))
     count = accno;
     file.close();
     return count;
}
 
//This function add_to_file() is used to create new/fresh record in data file
void initial::add_to_file(int t_accno,char t_name[30],char t_address[30],float t_balance)
{
     accno = t_accno;
     strcpy(name, t_name);
     strcpy(address, t_address);
     balance = t_balance;
     fstream file;
     // Appends new account record with the balance into INITIAL.dat data file
     file.open("INITIAL.dat", ios::out|ios::app);
     file.write((char *)this, sizeof(initial));
     file.close();
}
 
// Function for deleting a account from INITIAL.dat file
void initial::delete_account(int t_accno)
{
     fstream file;
     file.open("INITIAL.dat", ios::in);
     fstream temp;
     temp.open("TEMP.dat", ios::out);
     file.seekg(0,ios::beg);
     // Uses a copy method to delete the account from INTITAL.dat data file
     while (!file.eof())
     {
      file.read((char *)this, sizeof(initial));
      if (file.eof())
      break;
      if (accno != t_accno)
      temp.write((char *)this, sizeof(initial));
      }
     file.close();
     temp.close();
     file.open("INITIAL.dat", ios::out);
     temp.open("TEMP.dat", ios::in);
     temp.seekg(0, ios::beg);
     // Copy the TEMP.dat contents into INTITAL.dat data file
     while (!temp.eof())
     {
      temp.read((char *)this, sizeof(initial));
      if (temp.eof())
      break;
      if (accno != t_accno)
      file.write((char *)this, sizeof(initial));
      }
     file.close();
     temp.close();
}
 
// Function for adding account details of daily tranaction into BANKING.dat file
 
void account::add_to_file(int t_accno,int d1,int m1,int y1,char t_tran,char t_type[10],float t_interest,float t_amount,float t_balance)
{
     fstream file;
     file.open("BANKING.dat", ios::app);
     accno = t_accno;
     getch();
     dd = d1;
     mm = m1;
     yy = y1;
     tran = t_tran;
     strcpy(type, t_type);
     interest = t_interest;
     amount = t_amount;
     balance = t_balance;
     // Appends the transaction record into BANKING.dat data file
     file.write((char *)this, sizeof(account));
     file.close();
}
 
/* Function for deleting an account from BANKING.dat file. */
void account::delete_account(int t_accno)
{
     fstream file;
     file.open("BANKING.dat", ios::in); // Open to read records
     fstream temp;
     temp.open("TEMP.dat", ios::out); // Open to write records
     file.seekg(0, ios::beg);        // Positioned from begining of the file
     // Uses the copy method for deleting the transaction record from
     // BANKING.dat data file
     while (!file.eof())
     {
      file.read((char *)this, sizeof(account));
      if (file.eof())
      break;
      if (accno != t_accno)
      temp.write((char *)this, sizeof(account));
      }
     file.close();
     temp.close();
     file.open("BANKING.dat", ios::out);
     temp.open("TEMP.dat", ios::in);
     temp.seekg(0, ios::beg);
     // Uses copy method to transfer the record from TEMP.dat file to
     // BANKING.dat data file
     while (!temp.eof())
     {
      temp.read((char *)this, sizeof(account));
      if (temp.eof())
      break;
      if (accno != t_accno)
      file.write((char *)this, sizeof(account));
      }
     file.close();
     temp.close();
}
 
/* Function for displaying an account from "INITIAL.dat". */
void initial::display_list(void)
{
     clrscr();
     int flag;
     float t_bal = 0.0;
     fstream file;
     gotoxy(25,2);
     cout<< "Accounts List in Bank";
     gotoxy(25, 3);
     cout<< "=====================";
     int d1, m1, y1;
     struct date d;          // For extracting system date
     getdate(&d);
     d1 = d.da_day;
     m1 = d.da_mon;
     y1 = d.da_year;
     gotoxy(62, 3);
     cout<< "Date: " << d1 << "/" << m1 << "/" << y1;
     gotoxy(1, 4);
     for (int j = 1; j <= 79; j++)
     cout<< "=";
     gotoxy(1, 5);
     cout<< "Accno#";
     gotoxy(10,5);
     cout<< "Name";
     gotoxy(30,5);
     cout<< "Address";
     gotoxy(65,5);
     cout<< "Balance";
     gotoxy(1, 6);
     for (j = 1; j <= 79; j++)
     cout<< "=";
     file.open("INITIAL.dat", ios::in);
     file.seekg(0,ios::beg);
     int row = 7;
     // Reads all the records to display on the screen
     while (file.read((char *)this, sizeof(initial)))
     {
      flag = 0;
      delay(2);
      gotoxy(3, row);
      cout<< accno;
      gotoxy(10, row);
      puts(name);
      gotoxy(30, row);
      puts(address);
      gotoxy(65, row);
      cout<<setw(15)<<setprecision(2)<<setiosflags(ios::left)
	   <<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)<<balance;
      t_bal = t_bal + balance;
      row++;
      if (row > 23)
      {
       flag = 1;
       row = 6;
       gotoxy(4, 24);
       cout<<"Press any key to continue.... ";
       getch();
       clrscr();
      }
     }
    gotoxy(1, row);
    for (j = 1; j <= 79; j++)
    cout<< "=";
    row++;
    gotoxy(3, row);
    cout<< "Total Balance in Bank is : ";
    gotoxy(65, row);
    cout<<setw(15)<<setprecision(2)<<setiosflags(ios::left)
	 <<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)<<t_bal;
    file.close();
    if (!flag)
    {
     gotoxy(4, 24);
     cout<< "Press any key to continue...";
     getch();
     }
}
 
/* Function for clearing specified row and column. */
void account::clear(int col, int row)
{
    for (int j = col; j <= 79; j++)
    {
     gotoxy(j, row);
     cout<< " ";
     }
}
 
/* Function to found an account for display account function. */
int initial::found_account(int t_accno)
{
     fstream file;
     file.open("INITIAL.dat", ios::in);
     file.seekg(0, ios::beg);
     int found = 0;
     // Searches the specified record in INITIAL.dat data file
     while (file.read((char *)this, sizeof(initial)))
     {
      if (accno == t_accno)
      {
       found = 1;
       break;
       }
      }
     file.close();
     return found;
}
 
/* Function for return name of the account holder from INITIAL.dat. */
char *initial::return_name(int t_accno)
{
     fstream file;
     file.open("INITIAL.dat", ios::in);
     file.seekg(0, ios::beg);
     char t_name[30];
     // Return the name to display at report screen if found
     while (file.read((char *)this, sizeof(initial)))
     {
      if (accno == t_accno)
      {
       strcpy(t_name, name);
       break;
       }
      }
     file.close();
     return t_name;
}
 
/* Function for return address of the account holder from INITIAL.dat. */
char *initial::return_address(int t_accno)
{
     fstream file;
     file.open("INITIAL.dat", ios::in);
     file.seekg(0, ios::beg);
     char t_address[30];
     // Return the address to display at report screen if found
     while (file.read((char *)this, sizeof(initial)))
     {
      if (accno == t_accno)
      {
       strcpy(t_address, address);
       break;
       }
      }
     file.close();
     return t_address;
}
 
/* Function for display account details */
void account::box_for_display(int t_accno)
{
     int d1, m1, y1;
     struct date d;
     getdate(&d);
     d1 = d.da_day;
     m1 = d.da_mon;
     y1 = d.da_year;
     gotoxy(63, 2);
     cout<< "Date: " << d1 << "/" << m1 << "/" << y1;
     gotoxy(4, 2);
     cout<< "Account No. " << t_accno;
     initial ini;
     char t_name[30];
     strcpy(t_name, ini.return_name(t_accno));
     char t_address[30];
     strcpy(t_address, ini.return_address(t_accno));
     gotoxy(25, 2);
     cout<< t_name;
     gotoxy(25, 3);
     cout<< t_address;
     gotoxy(4, 5);
     cout<< "Global Report of Account";
     textbackground(WHITE);
     textcolor(BLACK);
     textbackground(WHITE);
     gotoxy(1, 6);
     for (int i = 1; i <=79; i++)
     cout<< "=";
     gotoxy(4, 7);
     cprintf("Date       Particular   Deposit      Withdraw                Balance");
     gotoxy(1, 8);
     for (i = 1; i <=79; i++)
     cout<< "=";
     textcolor(LIGHTGRAY);
     textbackground(BLACK);
}
 
/* Function for display an account from BANKING.dat file. */
void account::display_account(void)
{
     clrscr();
     char t_acc[10];
     int j;
     int tamt = 0, damt = 0, wamt = 0;
     int t, t_accno;
     gotoxy(71, 1);
     cout<< "&lt;0>=Exit";
     gotoxy(5, 5);
     cout<<"Enter account no. ";
     gets(t_acc);
     t = atoi(t_acc);
     t_accno = t;
     if (t_accno == 0)
     return;
     clrscr();
     initial ini;
     if (!ini.found_account(t_accno))
     {
      gotoxy(5, 5);
      cout<< "\7Account not found";
      getch();
      return;
      }
     // Display the heading from this function
     box_for_display(t_accno);
     int row = 9, flag;
     fstream file;
     file.open("BANKING.dat", ios::in);
     while (file.read((char *)this, sizeof(account)))
     {
      if (accno == t_accno)
      {
       flag = 0;
       delay(2);
       gotoxy(4, row);
       cout<< dd << "-" << mm << "-" << yy;
       gotoxy(16, row);
       puts(type);
       if (tran == 'D')
       {
	damt = damt + amount;
	tamt = tamt + amount;
	gotoxy(30, row);
	}
       else
       {
	wamt = wamt + amount;
	tamt = tamt - amount;
	gotoxy(42, row);
	}
       cout<<  setw(15)<< setprecision(2)<< setiosflags(ios::left)
	    << setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< amount;
       gotoxy(66, row);
       cout<< setw(15)<< setprecision(2)<< setiosflags(ios::left)
	    << setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<<balance;
       row++;
       if (row > 23)
       {
	flag = 1;
	row = 7;
	gotoxy(4, 24);
	cout<<"Press any key to continue";
	getch();
	clrscr();
	box_for_display(t_accno);
	}
       }
      }
     file.close();
     gotoxy(1, row);
     for (j = 1; j <= 79; j++)
     cout<< "=";
     row++;
     gotoxy(4, row);
     cout<< "Total-->:";
     gotoxy(30, row);
     cout<<setw(15)<< setprecision(2)<< setiosflags(ios::left)
	  << setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< damt;
     gotoxy(42, row);
     cout<< setw(15)<< setprecision(2)<< setiosflags(ios::left)
	  << setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< wamt;
     gotoxy(66, row);
     cout<< setw(15)<< setprecision(2)<< setiosflags(ios::left)
	  << setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< tamt;
     if (!flag)
     {
      gotoxy(4, 24);
      cout<< "Press any key to continue...";
      getch();
      }
}
 
/* Function to list monthWise transaction report. */
void account::month_report(void)
{
    int dd1, mm1, yy1;
    clrscr();
    gotoxy(10, 5);
    cout<< "Enter any date of a month ";
    gotoxy(38, 5);
    cin >> dd1;
    gotoxy(40, 5);
    cout<<"-";
    gotoxy(41, 5);
    cin >> mm1;
    gotoxy(43, 5);
    cout<<"-";
    gotoxy(44, 5);
    cin >> yy1;
    clrscr();
    char t_acc[10];
    int j;
    int tamt = 0, damt = 0, wamt = 0;
    int t, t_accno;
    gotoxy(71, 1);
    cout<<"&lt;0>=Exit";
    gotoxy(5, 5);
    cout<<"Enter account no. ";
    gets(t_acc);
    t = atoi(t_acc);
    t_accno = t;
    if (t_accno == 0)
    return;
    clrscr();
    initial ini;
    if (!ini.found_account(t_accno))
    {
     gotoxy(5, 5);
     cout<< "\7Account not found";
     getch();
     return;
     }
    box_for_display(t_accno);
    gotoxy(4, 5);
    cout<< "Statement Month: " << dd1 << "/" << mm1 << "/" << yy1;
    getch();
    int row = 9, flag;
    fstream file;
    file.open("BANKING.dat", ios::in);
    float pre_balance = 0.0; // Previous balance amount
    // The loop finds the last months balance
    while (file.read((char *)this, sizeof(account)))
    {
    //Checks the account no. and till the previous month and till current year
     if((accno == t_accno) && ((mm < mm1 && yy <= yy1) || (mm1 < mm && yy < yy1)))
     {
      pre_balance = balance;
      }
     }
     file.close();
     file.open("BANKING.dat", ios::in);
     gotoxy(54, row);
     cout<<"B/F ....    " <<setw(15)<<setprecision(2)<<setiosflags(ios::left)
	 <<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)<<pre_balance;
     row++;
     // The loop displays the current months transaction after previous month
     while (file.read((char *)this, sizeof(account)))
     {
      if ((accno == t_accno) && (mm1 == mm && yy1 <= yy))
      {
       flag = 0;
       delay(2);
       gotoxy(4, row);
       cout<< dd << "-" << mm << "-" << yy;
       gotoxy(16, row);
       puts(type);
       if (tran == 'D')
       {
	damt = damt + amount;
	tamt = tamt + amount;
	gotoxy(30, row);
	}
       else
       {
	wamt = wamt + amount;
	tamt = tamt - amount;
	gotoxy(42, row);
	}
       cout<<setw(15)<<setprecision(2)<<setiosflags(ios::left)
	    <<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)<<amount;
       gotoxy(66, row);
       cout<<setw(15)<<setprecision(2)<<setiosflags(ios::left)
	    <<setiosflags(ios::showpoint)<<setiosflags(ios::fixed)<<balance;
       row++;
       // If row increases 23 then the next screen continues
       if (row > 23)
       {
	flag = 1;
	row = 7;
	gotoxy(4, 24);
	cout<<"Press any key to continue";
	getch();
	clrscr();
	box_for_display(t_accno);
	}
       }
      }
     file.close();
     gotoxy(1, row);
     for (j = 1; j <= 79; j++)
     cout<< "=";
     row++;
     gotoxy(4, row);
     cout<< "Total-->:";
     gotoxy(30, row);
     // Deposited amount
     cout <<setw(15)                   // setwidth
	  << setprecision(2)            // set position of decimal point
	  << setiosflags(ios::left)     // set left justified output
	  << setiosflags(ios::showpoint)// always show decimal point
	  << setiosflags(ios::fixed)    // set fixed notation for display
	  << damt;
     gotoxy(42, row);
     // Withdraw amount
     cout<< setw(15)<< setprecision(2)<< setiosflags(ios::left)
	  << setiosflags(ios::showpoint)<<setiosflags(ios::fixed)<< wamt;
     gotoxy(66, row);
     tamt = tamt + pre_balance;
     // Balance amount
     cout<< setw(15)<< setprecision(2)<< setiosflags(ios::left)
	  << setiosflags(ios::showpoint)<< setiosflags(ios::fixed)<< tamt;
     if (!flag)
     {
      gotoxy(4, 24);
      cout<< "Press any key to continue...";
      getch();
      }
 }
 
/* Function for creating new account for new customer. */
void account::new_account(void)
{
    char ch;
    int i, valid;
    clrscr();
    initial ini;
    shape s;
    s.box(2, 1, 79, 25, 218);
    s.box(25, 2, 54, 4, 219);
    gotoxy(65, 2);
    cout<< "&lt;0>=Exit";
    gotoxy(3,3);
    for (i=1; i<=76; i++)
    cprintf(" ");
    textbackground(BLACK);
    textcolor(BLACK+BLINK);
    textbackground(WHITE);
    gotoxy(30, 3);
    cprintf("Open New Account");
    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    int d1, m1, y1;
    struct date d;          // For extracting system date
    getdate(&d);
    d1 = d.da_day;
    m1 = d.da_mon;
    y1 = d.da_year;
    int t_accno;
    t_accno = ini.last_accno();
    t_accno++;
    //Appends and deletes false record to create primary position in data files
    if (t_accno == 1)
    {
     ini.add_to_file(t_accno, "abc", "xyz", 1.1);
     ini.delete_account(t_accno);
     cout<< "Press xxxxxxx";
     getch();
     add_to_file(t_accno, 1, 1, 1997, 'D', "INITIAL", 1.1, 1.1, 1.1);
     delete_account(t_accno);
     }
    char t_name[30], t[10], t_address[30];
    float t_bal = 0.0, t_balance = 0.0;
    gotoxy(5, 6);
    cout<< "Date: " << d1 << '/' << m1 << '/' << y1;
    gotoxy(5, 8);
    cout<< "Account No # " << t_accno;
    gotoxy(5, 10);
    cout<< "Name : ";
    gotoxy(5, 11);
    cout<< "Address : ";
    gotoxy(5, 12);
    cout<< "Name of verifying Person : ";
    gotoxy(5, 14);
    cout<< "Initial Deposit : ";
    do
    {
     clear(15, 10);
     clear(5, 23);
     gotoxy(5, 23);
     cout<< "Enter Name of the Person";
     valid = 1;
     gotoxy(15, 10);
     gets(t_name);
     strupr(t_name);
     if (t_name[0] == '0')
     return;
     if (strlen(t_name) == 0 || strlen(t_name) > 25)
     {
      valid = 0;
      gotoxy(5, 23);
      cprintf("\7Name should not greater than 25");
      getch();
      }
     }while (!valid);
    do
    {
     clear(25, 15);
     clear(5, 23);
     gotoxy(5, 23);
     cout<<"Enter Address of the Person ";
     valid = 1;
     gotoxy(15, 11);
     gets(t_address);
     strupr(t_address);
     if (t_address[0] == '0')
     return;
     if (strlen(t_address) == 0 || strlen(t_address) > 25)
     {
      valid = 0;
      gotoxy(5, 23);
      cprintf("\7Address should not greater than 25");
      getch();
      }
     }while (!valid);
    do
    {
     char vari[30];
     clear(13, 12);
     clear(5, 23);
     gotoxy(5, 23);
     cout<<"Enter name of the verifying Person ";
     valid = 1;
     gotoxy(31, 12);
     gets(vari);
     strupr(vari);
     if (vari[0] == '0')
     return;
     if (strlen(vari) == 0 || strlen(vari) > 25)
     {
      valid = 0;
      gotoxy(5, 23);
      cprintf("Should not blank or greater than 25");
      getch();
      }
     }while (!valid);
    do
    {
     clear(13, 12);
     clear(5, 23);
     gotoxy(5, 23);
     cout<<"Enter initial amount to be deposit ";
     valid = 1;
     gotoxy(23, 14);
     gets(t);
     t_bal = atof(t);
     t_balance = t_bal;
     if (t[0] == '0')
     {
      valid = 0;
      gotoxy(5, 23);
      cprintf("\7Should not less than 500");
      getch();
      }
     }while (!valid);
    clear(5, 23);
    do
    {
     clear(5, 17);
     valid = 1;
     gotoxy(5, 17);
     cout<< "Do you want to save the record <Y/N>: ";
     ch = getche();
     if (ch == '0')
     return;
     ch = toupper(ch);
     }while (ch != 'N' && ch != 'Y');
    if (ch == 'N')
    return;
    float t_amount, t_interest;
    t_amount = t_balance;
    t_interest = 0.0;
    char t_tran, t_type[10];
    t_tran = 'D';
    strcpy(t_type, "INITIAL");
    //Appends records contents into both INITIAL.dat and BANKING.dat data files
    ini.add_to_file(t_accno, t_name, t_address, t_balance);
    add_to_file(t_accno, d1, m1, y1, t_tran, t_type, t_interest, t_amount, t_balance);
}
 
/* Function for returning balance amount of an account. */
float initial::give_balance(int t_accno)
{
    fstream file;
    file.open("INITIAL.dat", ios::in);
    file.seekg(0, ios::beg);
    float t_balance;
    // Gives the last balance of an individual account
    while (file.read((char *)this, sizeof(initial)))
    {
     if (accno == t_accno)
     {
      t_balance = balance;
      break;
      }
     }
    file.close();
    return t_balance;
}
 
/* Function for returning the record no. for updating balance */
int initial::recordno(int t_accno)
{
    fstream file;
    file.open("INITIAL.dat", ios::in);
    file.seekg(0, ios::beg);
    int count = 0;
 
    // Finds the record position in INITIAL.dat data file
    while (file.read((char *)this, sizeof(initial)))
    {
     count++;
     if (t_accno == accno)
     break;
     }
    file.close();
    return count;
}
 
/* Function for updating the balance for the given account no. */
void initial::update_balance(int t_accno,char t_name[30],char t_address[30],float t_balance)
{
    int recno;
    recno = recordno(t_accno);
    fstream file;
    file.open("INITIAL.dat", ios::out|ios::ate);
    strcpy(name, t_name);
    strcpy(address, t_address);
    balance = t_balance;
    int location;
    location = (recno-1) * sizeof(initial); // Find the location in file
    file.seekp(location);   // Searches the insertion position in data file
    // Updates the balance amount in INITIAL.dat data file
    file.write((char *)this, sizeof(initial));
    file.close();
}
 
/* Function to return no. days between two dates. */
int account::no_of_days(int d1, int m1, int y1, int d2, int m2, int y2)
{
    static int month[] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30};
    int days = 0;
   while (d1 != d2 || m1 != m2 || y1 != y2)
    {
     days++;
     d1++;
     if (d1 > month[m1-1])
     {
      d1 = 1;
      m1++;
      }
     if (m1 > m2)
     {
      m1 = 1;
      y1++;
      }
     }
    return days;
}
 
/* Function for calculates interest */
float account::calculate_interest(int t_accno, float t_balance)
{
    fstream file;
    file.open("BANKING.dat", ios::in);
    file.seekg(0, ios::beg);
    int d1, m1, y1, days;
    while (file.read((char *)this, sizeof(account)))
    {
     if (accno == t_accno)
     {
      d1 = dd;
      m1 = mm;
      y1 = yy;
      break;
      }
     }
    int d2, m2, y2;
    struct date d;
    getdate(&d);
    d2 = d.da_day;
    m2 = d.da_mon;
    y2 = d.da_year;
    float t_interest = 0.0;
    if((y2 < y1) || (y2==y1 && m2 < m1) || (y2==y1 && m2 == m1) && (d2 < d1))
    return t_interest;
    days = no_of_days(d1, m1, y1, d2, m2, y2);
    int months = 0;
    if (days > 30)
    {
     months = days / 30;
     t_interest = ((t_balance*2)/100 * months);
     }
    file.close();
    return t_interest;
}
 
/* Function for making daily transaction (Deposit 'D'/Withdraw 'W'. */
void account::transaction(void)
{
    clrscr();
    char t_acc[10];
    int t, t_accno, valid;
    gotoxy(71,1);
    cout<<"&lt;0>=Exit";
    gotoxy(5, 5);
    cout<<"Enter the account no. ";
    gets(t_acc);
    t = atoi(t_acc);
    t_accno = t;
    if (t_accno == 0)
    return;
    clrscr();
    initial ini;
    if (!ini.found_account(t_accno))
    {
     gotoxy(5, 5);
     cout<< "\7Account not found";
     getch();
     return;
     }
    gotoxy(71, 1);
    cout<< "&lt;0>=Exit";
    gotoxy(3, 3);
    for (int i=1; i<=76; i++)
    cprintf(" ");
    textbackground(BLACK);
    textcolor(BLACK+BLINK);
    textbackground(WHITE);
    gotoxy(29, 3);
    cprintf ("Transaction in Account");
    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    int d1, m1, y1;
    struct date d;
    getdate(&d);
    d1 = d.da_day;
    m1 = d.da_mon;
    y1 = d.da_year;
    gotoxy(5, 6);
    cout<< "Date: " << d1 << "/" << m1 << "/" << y1;
    gotoxy(5, 8);
    cout<< "Accnount no. " << t_accno;
    char t_name[30];
    char t_address[30];
    float t_balance;
    strcpy(t_name, ini.return_name(t_accno));
    strcpy(t_address, ini.return_address(t_accno));
    t_balance = ini.give_balance(t_accno);
    gotoxy(27, 11);
    cout<< "Name : " << t_name;
    gotoxy(27, 12);
    cout<< "Address : " << t_address;
    gotoxy(5, 15);
    cout<<"Last balance Rs. "<< setw(15)<< setprecision(2)
	<<setiosflags(ios::left)<<setiosflags(ios::showpoint)
	<<setiosflags(ios::fixed)<<t_balance;
    char t_tran, t_type[10], tm[10];
    float t_amount, t_amt;
    do
    {
     clear(5, 10);
     valid = 1;
     gotoxy(5, 10);
     cout<< "Deposit or Withdraw (D/W) : ";
     t_tran = getch();
     if (t_tran == '0')
     return;
     t_tran = toupper(t_tran);
     }while (t_tran != 'D' && t_tran != 'W');
    do
    {
     clear(5, 19);
     clear(5, 23);
     gotoxy(5, 23);
     cout<< "Enter Transaction by Cash or Cheque ";
     valid = 1;
     gotoxy(5, 19);
     cout<< "Cash/Cheque : ";
     gets(t_type);
     strupr(t_type);
     if (t_type[0] == '0')
     return;
     if (strcmp(t_type, "CASH") && strcmp(t_type, "CHEQUE"))
     {
      valid = 0;
      gotoxy(5, 23);
      cprintf("\7Enter correctly");
      getch();
      }
     }while (!valid);
    do
    {
     clear(5, 21);
     clear(5, 23);
     gotoxy(5, 23);
     cout<< "Enter Amount for Transaction ";
     valid = 1;
     gotoxy(5, 21);
     cout<< "Amount Rs. ";
     gets(tm);
     t_amt = atof(tm);
     t_amount = t_amt;
     if (tm[0] == '0')
     return;
     if ((t_tran == 'W' && t_amount > t_balance) || (t_amount < 1))
     {
      valid = 0;
      gotoxy(5, 23);
      cprintf("\7Invalid Data entered");
      getch();
      }
     }while (!valid);
    char ch;
    clear(5, 23);
    do
    {
     clear(20, 23);
     valid = 1;
     gotoxy(40, 20);
     cout<< "Save Transaction <Y/N> : ";
     ch = getche();
     if (ch == '0')
     return;
     ch = toupper(ch);
     }while (ch != 'N' && ch != 'Y');
    if (ch == 'N')
    return;
    float t_interest;
    t_interest = calculate_interest(t_accno, t_balance);
    if (t_tran == 'D')
    t_balance = t_balance + t_amount + t_interest;
    else
    t_balance = (t_balance - t_amount) + t_interest;
    // Modified records are updated in data bases.
    ini.update_balance(t_accno, t_name, t_address, t_balance);
    add_to_file(t_accno,d1,m1,y1,t_tran,t_type,t_interest,t_amount,t_balance);
}
 
/* Function for closing any account after inputing account number. */
void account::close_account(void)
{
    clrscr();
    char t_acc[10];
    int t, t_accno;
    gotoxy(71, 1);
    cout<<"&lt;0>=Exit";
    gotoxy(5, 5);
    cout<<"Enter the account no. ";
    gets(t_acc);
    t = atoi(t_acc);
    t_accno = t;
    if (t_accno == 0)
    return;
    clrscr();
    initial ini;
    if (!ini.found_account(t_accno))
    {
     gotoxy(5, 5);
     cout<< "\7Account not found ";
     getch();
     return;
     }
    gotoxy(71, 1);
    cout<< "&lt;0>=Exit";
    gotoxy(3, 3);
    textbackground(WHITE);
    for (int i=1; i<=76; i++)
    cprintf(" ");
    textbackground(BLACK);
    textcolor(BLACK+BLINK);
    textbackground(WHITE);
    gotoxy(30, 3);
    cprintf("Close account screen");
    textcolor(LIGHTGRAY);
    textbackground(BLACK);
    int d1, m1, y1;
    struct date d;
    getdate(&d);
    d1 = d.da_day;
    m1 = d.da_mon;
    y1 = d.da_year;
    gotoxy(5, 6);
    cout<< "Date: " << d1 << "/" << m1 << "/" << y1;
    char ch;
    ini. display(t_accno);
    do
    {
     clear(5, 15);
     gotoxy(5, 15);
     cout<< "Close this account <y/n> ";
     ch = getche();
     if (ch == '0')
     return;
     ch = toupper(ch);
     }while (ch != 'N' && ch != 'Y');
    if (ch == 'N')
    return;
    // Function calls to delete the existing account no.
    ini.delete_account(t_accno);
    delete_account(t_accno);
    gotoxy(5, 20);
    cout<<"\7Account Deleted";
    gotoxy(5, 23);
    cout<< "Press any key to continue...";
    getch();
}
 
// Main program logic which control the class members and member functions.
void main(void)
{
    main_menu  m_menu;
    int gdriver = DETECT, gmode, errorcode;
    initgraph(&gdriver, &gmode,"c:\\turboc3\\bgi");
    m_menu.help();
    closegraph();
    m_menu.control_menu();
}
