#include <stdio.h>
#include <limits.h>
#include "ranges.h"

//makes a new range
range makeRange(unsigned long long new_LTOE = 0, unsigned long long new_MTOE = ULLONG_MAX, range *new_next_range = 0){
    struct range new_range;
    new_range.LTOE = new_LTOE;
    new_range.MTOE = new_MTOE;
    new_range.next_range = new_next_range;
    return new_range;
}

//displays a range in a nice way. Takes care of split ranges as well
void displayRange(struct range range_to_display){
    printf("displaying range\n");
    printf("%llu <= x <= %llu \n", range_to_display.LTOE, range_to_display.MTOE);
    range *next_range = range_to_display.next_range;
    while (next_range != 0)
    {
        range_to_display = *next_range;
        printf("%llu <= x <= %llu \n", range_to_display.LTOE, range_to_display.MTOE);
        next_range = range_to_display.next_range;
    }
}