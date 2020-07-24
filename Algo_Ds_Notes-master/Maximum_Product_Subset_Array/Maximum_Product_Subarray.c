/*
    MAXIMUM PRODUCT SUBSET OF AN ARRAY

    Given an array of n elements. We need to find the maximum product possible
    with any subset of that array.
*/

#include <stdio.h>
#include <math.h>

int neg = 0, pos = 0, zero = 0, prod = 1, max_neg = -10000000;

/*
    Approach : Two negative numbers multiply together to form a positive number.
               Hence, the maximum product in case of even frequency of negative 
               numbers will be the product of entire array except zero.
               In case of odd frequency of negative numbers, we exclude the 
               smallest negative number from the product of the array to get our
               answer.
               Also, in case of single negative number and no positive number in 
               the array, the answer would be 0, if even a single 0 is present, 
               else it would be the negative number itself.
*/
int solve(int temp[], int num) {
    if (num == 1) {
        return temp[0];
    }
    if (zero == num || (neg == 1 && neg + zero == num && zero)) {
        return 0;
    }
    if (neg % 2 == 0) {
        return prod;
    }
    return prod / max_neg;
}

int main(){
    int num = 5;
    int temp[] = {5, -2, 4, -3, -1};
    for (int i = 0; i < num; i++ ) {
        if (temp[i] > 0) {
            pos++;
        }
        else if (temp[i] == 0) {
            zero++;
            continue;
        }
        else {
            neg++;
            if (temp[i] > max_neg) {
                max_neg = temp[i];
            }
        }
        prod = prod * temp[i];
    }
    int ans = solve(temp, num);
    printf("Maximum Product Subset is : %d", ans);
    return 0;
}

/*
    Input: Array : [5, -2, 4, -3, -1]
    Output: Maximum Product Subset is : 120
    Verification: The product of array is -120. Since, there are odd numbers of
                  negative numbers present in the array, we exclude the smallest
                  negative number (-1) from the product to get our desired answer.
                  (-120 / (-1) == 120)
*/
