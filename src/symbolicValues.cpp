#include <stdio.h>
#include <limits.h>
#include "./../incldue/ranges.h"

using namespace std;

//Models a symbolic value in terms of ranges
class symVal {
    public:
        int step; //The step to use for the ranges
        range* first_range; //points to the starting range

        //Constructor which initializes the symbolic value with a single range. Defaults are given although it is possible to specify the limits of the range.
        symVal(unsigned long long LTOE = 0, unsigned long long MTOE = ULLONG_MAX){
            first_range = makeRange(LTOE, MTOE, 0);
        }

        //Displays a symobolic value
        void displaySymValue(){
            displayRange(*first_range);
        }

        //Adjust ranges to complie with a not equals
        void notEquals(unsigned long long not_equals){
            //find part of the range where this number is located
            range *containing_range = locate_part_containing(first_range, not_equals);
            if ((*containing_range).function_success = 1){
                printf("%p\n",containing_range);
                printf("%p\n",first_range);
                displayRange(*containing_range);
                printf("found containing range");
                // containing_range.MTOE = not_equals - 1;
                // range new_range = makeRange(not_equals + 1, containing_range.MTOE, containing_range.next_range);
                // containing_range.next_range = &new_range;
            }
        }
};

int main(){
    symVal testValue(0, 100);

    testValue.displaySymValue();

    testValue.notEquals(50);

    testValue.displaySymValue();

    printf("Finished successfully\n");
    return 0;
}
