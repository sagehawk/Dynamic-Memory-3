#ifndef INPUT_LIBRARY_HEADER_INCLUDED
#define INPUT_LIBRARY_HEADER_INCLUDED

#include <iostream>

// Boundaries are assumed to be solid -- low <= value <= high.

// Enum to say which end is to be bounded...
//
enum BoundType { Low, High, Both };

// Bounded entry function for int integers...
//
int get_bounded(int low, int high, 
                 const char prompt[] = "Enter bounded value:  ",
                 BoundType which_end = Both,
                 const char errmsg[] = "\nYour input was invalid."
                                        "Please try again.\n\n"
                 );

// Overloaded for double data...
//
double get_bounded(double low, double high ,
                   const char prompt[] = "Enter bounded value:  ",
                   BoundType which_end = Both,
                   const char errmsg[] = "\nYour input was invalid."
                                        "Please try again.\n\n"
                   );

// Limiting a character entry to one of a few...
//
char get_in_set(const char set[] = "YyNn",
                const char prompt[] = "Shall we play a game?  ",
                const char errmsg[] = "\nYour input was invalid."
                                        "Please try again.\n\n");

// look at the next non-whitespace character
//
char peek(std::istream & in);

#endif