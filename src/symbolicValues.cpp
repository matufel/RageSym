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
            printf("Created symbolic value with start at: %p\n", first_range);
        }

        //Displays a symobolic value
        void displaySymValue(){
            printf("Displaying symbolic value:\n");
            displayRange(first_range);
        }

        //Adjust ranges to complie with a not equals
        void notEquals(unsigned long long not_equals){
            //find part of the range where this number is located
            range *containing_range_ptr = locate_part_containing(first_range, not_equals);
            if ((*containing_range_ptr).function_success = 1){
                //check for the case where it is only the edge of the range
                if( (*containing_range_ptr).LTOE == not_equals){
                    (*containing_range_ptr).LTOE++;
                }
                else if ((*containing_range_ptr).MTOE == not_equals)
                {
                    (*containing_range_ptr).MTOE--;
                }else{
                    range* new_range = makeRange(not_equals + 1, (*containing_range_ptr).MTOE, (*containing_range_ptr).next_range);
                    (*containing_range_ptr).MTOE = not_equals - 1;
                    (*containing_range_ptr).next_range = new_range;
                }
            }
        }
};

int main(){
    symVal testValue(0, 100);

    testValue.displaySymValue();

    testValue.notEquals(50);
    testValue.notEquals(60);
    testValue.notEquals(61);
    testValue.notEquals(100);

    testValue.displaySymValue();

    printf("Finished successfully\n");
    return 0;
}
