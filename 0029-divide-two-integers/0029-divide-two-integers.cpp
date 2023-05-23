class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT32_MIN && divisor == -1) return INT32_MAX; 
        return floor(dividend/divisor);
    }
};