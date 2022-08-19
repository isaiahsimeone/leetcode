class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string longest_common_prefix = "";
        
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != strs[0][i])
                    return longest_common_prefix;
            }
            
            longest_common_prefix += strs[0][i];
        }
        return longest_common_prefix;
    }
};
