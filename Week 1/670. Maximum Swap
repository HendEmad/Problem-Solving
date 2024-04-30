/* 
Approach: Swap from the right to the left to scan the digits from right to left, while keeping track of the current maximum.
Whenever we find a new digit that smaller than the maximum, we update the the maximum by swapping it with the found smaller one. 
The target is to put the greater digit towards the left of the digit.
*/

/*
 3  0
 l  r
 v  v
72636
    ^
    max

to swap left and right in a constant time: (convert 72636 to 76632)
72636 - 2000 + 6000 - 6 + 2
num   - (l-r)*10^3  +(l - r)*10^0
num - (l - r)*(10^3 - 10^0)
*/

class Solution {
public:
    int maximumSwap(int num) {
        int max_digit = -1, max_loc = -1, l_digit = -1, l_loc, r_digit, r_loc;
        // move one location every time from right to left
        for(int loc = 0, n = num; n; n /= 10, loc++){
            int curr_digit = n % 10;
            if (curr_digit > max_digit){
                max_digit = curr_digit;
                max_loc = loc;
            } else if (curr_digit < max_digit){
                l_digit = curr_digit;
                l_loc = loc;
                r_digit = max_digit;
                r_loc = max_loc;
            }
        }

        if (l_digit == -1)
            return num;
        else 
            return num - (l_digit - r_digit) * (int)(pow(10, l_loc) - pow(10, r_loc));
    }
};
