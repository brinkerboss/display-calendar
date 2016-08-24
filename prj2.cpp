/***********************************************************************
* Program:
*    Project 2, Calender 
*    Brother Helfrich, CS124
* Author:
*    Jordan Brinkerhoff
* Summary: 
*    This program creates a calendar for any month of any year from  
*    1753 forward. It prompts the user for a month number and then a
*    year to be displayed.  The offset is then calculated and the 
*    correct table layout is created.
*
*    Estimated: 10.0 hrs   
*    Actual:     7.0 hrs
*      Understanding the computeOffset function and how to solve the
*      problem was the most difficult part.  
************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int getMonth();
int getYear();
int computeOffset(int month, int year);
void display(int month, int year, int offset);
int getDaysInYear(int year);
int getDaysInMonth(int month, int year);
void displayTable(int month, int year);
void displayHeader(int month, int year);
bool isLeapYear(int year);

/**********************************************************************
 * main() calls the functions getMonth(), getYear(), computeOffset(), 
 * and display() to prompt the user for a month and year, then display
 * the calender for that month.
 ***********************************************************************/
int main()
{
   int month   = getMonth();
   int year    =  getYear();  
   int offset  = computeOffset(month, year);
   
   display(month, year, offset); 

   return 0;
}

/**********************************************************************
 * This function prompts the user for a month number between 1 and 12.
 ***********************************************************************/
int getMonth()
{
   int month;
   cout << "Enter a month number: ";
   cin  >> month;

   if (month > 12 || month < 1)
   {
      cout << "Month must be between 1 and 12.\n";
      cout << "Enter a month number: ";
      month   = getMonth();
      //cin  >> month;

   }
   return month;
}

/**********************************************************************
 * This function prompts the user for a year after 1753.
 ***********************************************************************/
int getYear()
{
   int year;
   cout << "Enter year: ";
   cin  >> year;

   if (year < 1753)
   {
      cout << "Year must be 1753 or later.\n";
      cout << "Enter year: ";
      cin  >> year;
   }
   
   cout    << endl;
   
   return year;
}

/**********************************************************************
 * This function determines the offset for the given year and month
 * from the user. 
 ***********************************************************************/
int computeOffset(int month, int year)
{
   int numDays = 0;

   for (int yearCount = 1753; yearCount < year; yearCount++)
      numDays += getDaysInYear(yearCount);

   for (int monthCount = 1; monthCount < month; monthCount++)
      numDays += getDaysInMonth(monthCount, year);
   
   return numDays % 7;
}

/**********************************************************************
 * This function calls displayTable() and displayHeader() to output
 * the given month of the given year to the screen.
 ***********************************************************************/
void display(int month, int year, int offset)
{
   int numDaysInMonth = getDaysInMonth(month, year);
   displayHeader(month, year);
   displayTable(numDaysInMonth, offset);

}

/**********************************************************************
 * This function will display the month table based on the offset and
 * the number of days in that given month.
 ***********************************************************************/
void displayTable(int numDaysInMonth, int offset)
{

   cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

   offset = (offset + 1) % 7;
   
   for (int i = 0; i < offset; i++)
      cout << "    ";
      
   for (int i = 1; i <= numDaysInMonth; i++)
   {
      cout << setw(4)
           << i;
      
      if ((i + offset) % 7 == 0)
         cout << endl;    
   }
   
   if ((numDaysInMonth + offset) % 7 != 0)
      cout << endl;
   
}

/**********************************************************************
 * This function will display calender header with the month and year
 * given by the user.
 ***********************************************************************/
void displayHeader(int month, int year)
{

   if (month == 1)
      cout << "January";
   if (month == 2)
      cout << "February";
   if (month == 3)
      cout << "March";
   if (month == 4)
      cout << "April";
   if (month == 5)
      cout << "May";
   if (month == 6)
      cout << "June";
   if (month == 7)
      cout << "July";
   if (month == 8)
      cout << "August";
   if (month == 9)
      cout << "September";
   if (month == 10)
      cout << "October";
   if (month == 11)
      cout << "November";
   if (month == 12)
      cout << "December";

   cout << ", "
        << year
        << endl;
}

/**********************************************************************
 * This function determines the number of days in the given year
 * while taking into account leap years.
 ***********************************************************************/
int getDaysInYear(int year)
{
   int numDaysInYear;
   if (isLeapYear(year))
      return 366;
   else
      return 365;
         
}

/**********************************************************************
 * This function determines the number of days in the month inputted  
 * by the user taking into account leap years.
 ***********************************************************************/
int getDaysInMonth(int month, int year)
{
   int numDaysInMonth;

   if (month == 1 || month == 3 || month == 5 || month == 7
       || month == 8 || month == 10 || month == 12)
      return 31;
   if (month == 4 || month == 6 || month == 9 || month == 11)
      return 30;
   if (month == 2)
      if (isLeapYear(year))
         return 29;
      else
         return 28;   
   
}

/**********************************************************************
 * This function determines if the given year is a leap year.
 ***********************************************************************/
bool isLeapYear(int year)
{
   if (year % 4 != 0)
      return false;
   if (year % 100 != 0)
      return true;
   if (year % 400 == 0)
      return true;

   return false;
}
