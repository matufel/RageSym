#ifndef __MYCLASS_H_INCLUDED__
#define __MYCLASS_H_INCLUDED__


#include <stdio.h>
#include <limits.h>

//Models the range: 0 <= x <= ULLONG_MAX. Has a pointer to the next range
struct range
{
    unsigned long long LTOE; 
    unsigned long long MTOE;
    struct range *next_range; 
};

//makes a new range
range makeRange(unsigned long long, unsigned long long new_MTOE, range *new_next_range);
//displays a range in a nice way. Takes care of split ranges as well
void displayRange(struct range range_to_display);


#endif // __MYCLASS_H_INCLUDED__ 