#include <stdio.h>
#include <limits.h>
#include "ranges.h"

//Models a symbolic value in terms of ranges
class symVal {
    public:
        int step; //The step to use for the ranges
        range first_range; //points to the starting range

        //Constructor which initializes the symbolic value with a single range. Defaults are given although it is possible to specify the limits of the range.
        symVal(unsigned long long LTOE = 0, unsigned long long MTOE = ULLONG_MAX){
            first_range = makeRange(LTOE, MTOE, 0);
        }

        //Displays a symobolic value
        void displaySymValue(){
            displayRange(first_range);
        }

        //Adjust ranges to complie with a not equals
        void notEquals(unsigned long long not_equals){
            //find part of the range where this number is located
            
        }
};

int main(){
    symVal testValue(0, 100);

    testValue.displaySymValue();

    printf("Finished successfully\n");
    return 0;
}
