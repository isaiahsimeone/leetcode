class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        // Load nums into hashmap
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
            map.insert({nums[i], i}); // insert number, and its index

		// Consider the list element by element
        int needed = 0;
        for (int i = 0; i < nums.size(); i++) {
            needed = target - nums[i];
            if (map.count(needed) && map.at(needed) != i)
                return vector<int> {i, map.at(needed)};
        }
        return vector<int> {}; // no solution
    }
};