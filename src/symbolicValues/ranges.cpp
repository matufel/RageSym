#include <stdio.h>
#include <limits.h>
#include "ranges.h"

//makes a new range
range makeRange(unsigned long long new_LTOE = 0, unsigned long long new_MTOE = ULLONG_MAX, range *new_next_range = 0){
    struct range new_range;
    new_range.LTOE = new_LTOE;
    new_range.MTOE = new_MTOE;
    new_range.next_range = new_next_range;
    new_range.function_success = 1;
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

//locates a part of the range containing the given num to search for. Returns a range with success 0 if it failed
range locate_part_containing(range search_range, unsigned long long num){
    range original_search_range = search_range;
    //check current range
    if (search_range.LTOE <= num && search_range.MTOE >= num){
        search_range.function_success = 1;
        return search_range;
    }
    //otherwise loop through the rest of the ranges trying to find one
    range *next_range = search_range.next_range;
    while (next_range != 0) // also returns if the range was found
    {
        search_range = *next_range;
        if (search_range.LTOE <= num && search_range.MTOE >= num){ //check if found
            search_range.function_success = 1;
            return search_range;
        }
        next_range = search_range.next_range;
    }
    //if have not returned by now it means that the given number does not exist in the range
    original_search_range.function_success = 0;
    return original_search_range;
}