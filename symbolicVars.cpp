#include <stdio.h>
#include <limits.h>

//Models the range: 0 <= x <= ULLONG_MAX. Has a pointer to the next range
struct range
{
    unsigned long long LTOE; //Less than or equals part of the range
    unsigned long long MTOE; //More than or equals part of the range
    struct range *next_range; // pointer to the next range in a set of ranges (if 0 then it is the last one)
};

//Models a symbolic value in terms of ranges
struct symVal {
    int step; //The step to use for the ranges
    struct range *first_range; //points to the starting range
};

//makes a new range
struct range makeRange(unsigned long long new_LTOE = 0, unsigned long long new_MTOE = ULLONG_MAX, struct range *new_next_range = 0){
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


//For testing
int main(){
    range test_range = makeRange(30, 40, 0);
    range test_range2 = makeRange(0, 10, &test_range);

    displayRange(test_range2);

    printf("Finished successfully\n");
    return 0;
}