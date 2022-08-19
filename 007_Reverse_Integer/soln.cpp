#define MULTIPLICATION_WILL_OVERFLOW(a,b) (a > INT_MAX / b)
#define MULTIPLICATION_WILL_UNDERFLOW(a,b) (a < INT_MIN / b)

class Solution {
public:
    int reverse(int x) {
        int sign = (x < 0 ? -1 : 1);
        int result = 0;
        
        while (x != 0) {
            if (sign && MULTIPLICATION_WILL_OVERFLOW(result, 10))
                return 0;
            if (sign == -1 && MULTIPLICATION_WILL_UNDERFLOW(result, 10))
                return 0;
            
            result *= 10;
            result += (int)(x % 10);
            x /= 10;
        }

        if (sign == -1 && result > 0)
            result = -result;
        
        return result;       
        
    }
};