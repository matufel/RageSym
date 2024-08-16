#include <stdio.h>
#include <limits.h>
#include "./../incldue/ranges.h"

using namespace std;

//Models a symbolic value in terms of ranges
class symVal {
    public:
        int step; //The step to use for the ranges
        range* first_range; //points to the starting range
        bool reachable; //says if it is possible to reach the current branch

        //Constructor which initializes the symbolic value with a single range. Defaults are given although it is possible to specify the limits of the range.
        symVal(unsigned long long LTOE = 0, unsigned long long MTOE = ULLONG_MAX){
            step = 1;
            first_range = makeRange(LTOE, MTOE, 0);
            printf("Created symbolic value with start at: %p\n", first_range);
        }

        //Displays a symobolic value
        void displaySymValue(){
            printf("=============Displaying symbolic value=============\n");
            displayRange(first_range);
            printf("Reachable: %s\n", reachable ? "True": "False");
            printf("Step: %d\n", step);
            printf("========================END========================\n");
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

        //Adjust range when presented with an equals
        void equals(unsigned long long equals){
            range* containing_range_ptr = locate_part_containing(first_range, equals);
            if (containing_range_ptr->function_success == 1){
                //since now the range can be equal
                //TODO: memory cleanup
                first_range = makeRange(equals, equals, 0);
            }
            else{
                reachable = false;
            }
        }

        //adjust range for multiplication
        void multiply(unsigned long long num){
            //increases the step of the range
            step = step*num;
            //loop through range multiplying the lower and upper bound accordingly
            range* next_range = first_range;
            while (next_range != 0)
            {
                next_range->LTOE = next_range->LTOE*num;
                next_range->MTOE = next_range->MTOE*num;
                next_range = next_range->next_range;
            }
            //TODO: combine ranges if possible
        }

        //adjust range for division
        void divide(unsigned long long num){
            //increases the step of the range
            step = step/num;
            //loop through range multiplying the lower and upper bound accordingly
            range* next_range = first_range;
            while (next_range != 0)
            {
                next_range->LTOE = next_range->LTOE/num;
                next_range->MTOE = next_range->MTOE/num;
                next_range = next_range->next_range;
            }
            //TODO: combine ranges if possible
        }

        //adjust range for modulo
        void modulo(unsigned long long num){
            
        }

        //adjust range addition
        void add(unsigned long long num){
            //Adjust upper and lower bound accordingly
            range* next_range = first_range;
            while (next_range != 0)
            {
                next_range->LTOE = next_range->LTOE + num;
                next_range->MTOE = next_range->MTOE + num;
                next_range = next_range->next_range;
            }
        }

        //adjust range for subtraction
        void subtract(unsigned long long num){
            //Adjust upper and lower bound accordingly
            range* next_range = first_range;
            while (next_range != 0)
            {
                next_range->LTOE = next_range->LTOE - num;
                next_range->MTOE = next_range->MTOE - num;
                next_range = next_range->next_range;
            }
        }
};

int main(){
    symVal testValue(0, 100);

    testValue.notEquals(50);

    testValue.displaySymValue();

    testValue.divide(5);

    testValue.displaySymValue();

    printf("Finished successfully\n");
    return 0;
}
