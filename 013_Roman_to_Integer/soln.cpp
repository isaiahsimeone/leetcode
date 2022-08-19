class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        
        for (int i = 0; i < s.length(); i++) {
            switch(s[i]) {

                case 'I':
                    if (s[i + 1] == 'V') {
                        res += 4;
                        i++;
                    } else if (s[i + 1] == 'X') {
                        res += 9;
                        i++;
                    } else {
                        res += 1;
                    }
                    continue;
                case 'X':
                    if (s[i + 1] == 'L') {
                        res += 40;
                        i++;
                    } else if (s[i + 1] == 'C') {
                        res += 90;
                        i++;
                    } else {
                        res += 10;
                    }
                    continue;
                case 'C':
                    if (s[i + 1] == 'D') {
                        res += 400;
                        i++;
                    } else if (s[i + 1] == 'M') {
                        res += 900;
                        i++;
                    } else {
                        res += 100;
                    }
                    continue;
                case 'V':
                    res += 5;
                    continue;
                case 'L':
                    res += 50;
                    continue;                
                case 'D':
                    res += 500;
                    continue;
                case 'M':
                    res += 1000;
                    continue;

            }
        }
        return res;
    }
};
