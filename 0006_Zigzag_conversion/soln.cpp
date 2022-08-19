class Solution {
public:
    string convert(string s, int numRows) {
        string res;
        int factor = 2 * (numRows - 1);
        
        if (numRows == 1 || s.length() < numRows)
            return s;
        
        // First row
        for (int i = 0; i < s.length(); i += factor)
            res += s[i];
        
        // In-between rows
        int j, k;
        for (int row = 1; row < numRows - 1; row++) {
            j = factor - row * 2;
            k = 2 * row;
            res += s[row];
            
            for (int i = row; i + j < s.length(); i += j + k) {
                res += s[i + j];
                if (i + j + k < s.length())
                    res += s[i + j + k];
            }
        }
        
        // Last row
        for (int i = numRows - 1; i < s.length(); i += factor)
            res += s[i];
        
        return res;
    }
};

 /* NUM_ROWS == 7
 *
 * 0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 
 * A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z  A  B  C  D  E  F  G  H  I  J  K  L  M  N 
 *
 * A     M     Y     K     W
 * B    LN    XZ    JL    VX
 * C   K O   W A   I M   U Y
 * D  J  P  V  B  H  N  T  Z
 * E I   Q U   C G   O S
 * FH    RT    DF    PR
 * G     S     E     Q
 *
 * 0 12 24 36 48								+12, +12, +12, +12
 * A  M  Y  K  W
 * 1 11 13 23 25 35 37 47 49					+10, +2, +10, +2 
 * B  L  N  X  Z  J  L  V  X
 * 2 10 14 22 26 34 38 47 50					 +8, +4, +8, +4	
 * C  K  O  W  A  I  M  U  Y
 * 3  9 15 21 27 33 39 45 51					 +6, +6, +6, +6	
 * D  J  P  V  B  H  N  T  Z
 * 4  8 16 20 28 32 40 44						 +4, +8, +4, +8	
 * E  I  Q  U  C  G  O  S
 * 5  7 17 19 29 31 41 43						 +2, +10, +2, +10
 * F  H  R  T  D  F  P  R
 * 6 18 30 42									+12, +12, +12, +12
 * G  S  E  Q
 */