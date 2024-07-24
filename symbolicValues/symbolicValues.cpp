#include <stdio.h>
#include <limits.h>
#include "ranges.h"

//Models a symbolic value in terms of ranges
struct symVal {
    int step; //The step to use for the ranges
    range *first_range; //points to the starting range
};

int main(){
    range test_range = makeRange(30, 40, 0);
    range test_range2 = makeRange(0, 10, &test_range);

    displayRange(test_range2);
    printf("Finished successfully\n");
    return 0;
}
