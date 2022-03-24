#define CHAR2INT(c) (c - '0')
#define ISDIGIT(c) ('0' <= c && c <= '9')
class Solution {
public:
    string buffer;
    int buffer_idx;
    char getNext() {
        return buffer[buffer_idx++];
    }

    int myAtoi(string s) {
        int sign = 1; // positive by default
        long result = 0;
        buffer = s;
        buffer_idx = 0;
        
        while (getNext() == ' '); // skip whitespace
        buffer_idx--; // unget
        
        char first = getNext();
        
        if (first == '-')
            sign = -1;
        else if (first == '+')
            sign = 1;
        else
            buffer_idx--; // unget
        
        
        for (char c = getNext(); buffer_idx <= s.length() && ISDIGIT(c); c = getNext()) {

            result *= 10;

            if (result > INT_MAX || result < INT_MIN)
                return (sign == 1 ? INT_MAX : INT_MIN);

            result += CHAR2INT(c);
        
        }
        
        result *= sign;
        
        if (result > INT_MAX)
            return INT_MAX;
        if (result < INT_MIN)
            return INT_MIN;
        
        return result;
        
    };
};
