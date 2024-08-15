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
    int function_success; //used for functions to say if they were successful in completing a certain operation on the range. 1 = successful, 0 otherwise
};

//makes a new range
range* makeRange(unsigned long long new_LTOE, unsigned long long new_MTOE, range *new_next_range);
//displays a range in a nice way. Takes care of split ranges as well
void displayRange(struct range range_to_display);
//locates a part of the range containing the given num to search for. Returns a range with success 0 if it failed
range *locate_part_containing(range *search_range, unsigned long long num);

#endif // __MYCLASS_H_INCLUDED__ 