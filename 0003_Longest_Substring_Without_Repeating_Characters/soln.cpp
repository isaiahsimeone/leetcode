#define MAX(a,b) (a > b ? a : b)

class Solution {
public:
    
	int lengthOfLongestSubstring(string s) {
			unordered_set<char> set;
			int max_len = 0;
			int j = 0;
			
			for (int i = 0; i + j < s.length(); i++) {
				// Not enough characters left to find better solution - exit early
				if (max_len >= s.length() - i) 
					return max_len;
				
				for (; i + j < s.length(); j++) {
					if (set.count(s[i + j]) == 0) {
						set.insert(s[i + j]);
						max_len = MAX(max_len, j + 1);
					} else {
						set.erase(s[i]); // drop the left most character
						j--;
						break;
					}
				}	
			}
			return max_len;
	}
};