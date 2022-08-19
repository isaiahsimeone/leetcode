class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int running_sum = 0;
        vector<int> sums = {};
        for (int i : nums) {
            running_sum += i;
            sums.push_back(running_sum);
        }
        return sums;
    }
};
