class Solution {
public:
    int getSum(int a, int b) {
        // a=a^b;
        // b=a^b;
        // a=a^b; this swaps the two numbers

        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;

    }
};
