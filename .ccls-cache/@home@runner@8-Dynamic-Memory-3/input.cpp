#include "input.h"

#include <iostream>
#include <cstring>
#include <cctype>
#include <limits>       // std::numeric_limits

using namespace std;

// Boundaries are assumed to be solid -- low <= value <= high.

// Enum to say which end is to be bounded...
//
// enum BoundType { Low, High, Both };

// Bounded entry function for int integers...
//
int get_bounded(int low,
                 int high,
                 const char prompt[] /* = "Enter bounded value:  " */,
                 BoundType which_end /* = Both */,
                 const char errmsg[])
{
   int value;
   cout << prompt;
   cin >> value;
  
    if (cin.fail()) //input validation
  {
    while (cin.fail())
      { //clear buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << errmsg << prompt;
        cin >> value;
       // cout << "Your input was invalid. Please try again.\n" <<
       // "How many words will you be adding to your container?: ";
       // cin >> value; 
      } 
  }
   while ((((which_end == Low) || (which_end == Both)) && (low > value)) ||
          (((which_end == High) || (which_end == Both)) && (value > high)))
   {
      cout << "Please enter a value ";
      if (which_end == Both) {
         cout << "between " << low << " and " << high << " inclusive!";
      }
      else if (which_end == Low) {
         cout << "greater than or equal to " << low << "!";
      }
      else {
         cout << "less than or equal to " << high << "!";
      }
      cout << endl << prompt;
      cin >> value;
   }
   return value;
}

// Overloaded for double data...
//
double get_bounded(double low,
                   double high,
                   const char prompt[] /* = "Enter bounded value:  " */,
                   BoundType which_end /* = Both */,
                    const char errmsg[])
{
   double value;
   cout << prompt;
   cin >> value;

     if (cin.fail()) //input validation
  {
    while (cin.fail())
      { //clear buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << errmsg << prompt;
        cin >> value;
      } 
  }
   while ((((which_end == Low) || (which_end == Both)) && (low > value)) ||
          (((which_end == High) || (which_end == Both)) && (value > high)))
   {
      cout << "Please enter a value ";
      if (which_end == Both) {
         cout << "between " << low << " and " << high << " inclusive!";
      }
      else if (which_end == Low) {
         cout << "greater than or equal to " << low << "!";
      }
      else {
         cout << "less than or equal to " << high << "!";
      }
      cout << endl << prompt;
      cin >> value;
   }
   return value;
}

// Limiting a character entry to one of a few...
//
char get_in_set(const char set[]    /* = "YyNn" */,
                const char prompt[] /* = "Shall we play a game?  " */,
                const char errmsg[] /* = "\nInvalid entry..."
                                         "try again, schmuck!\n\n" */)
{
   char response;
   cout << prompt;
   cin >> response;
   while (strchr(set, response) == nullptr) //invalid input logic
   {
     //clear buffer
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << errmsg << prompt;
      cin >> response;
   }
   return response;
}

// look at the next non-whitespace character
//
char peek(istream & in)
{
    while (isspace(in.peek()))
    {
        in.ignore();
    }
    return (char)in.peek();
}