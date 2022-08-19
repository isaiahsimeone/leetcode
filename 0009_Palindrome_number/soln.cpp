class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        int x1 = x;
        long reversed = 0;
        while (x1 != 0) {
            reversed *= 10;
            reversed += (int) (x1 % 10);
            x1 /= 10;
        }
        
        return (x == reversed);
    }
};
