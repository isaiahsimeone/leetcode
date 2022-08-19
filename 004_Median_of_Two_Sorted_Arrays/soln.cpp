class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> a;
        int nums1_idx = 0;
        int nums2_idx = 0;
        
        for (int i = 0; i < nums1.size() + nums2.size(); i++) {
            /* Elements remain in nums1 and nums2 */
            if (nums1.size() > nums1_idx && nums2.size() > nums2_idx) {
                /* nums1 has the smaller */
                if (nums1[nums1_idx] < nums2[nums2_idx])
                    a.push_back(nums1[nums1_idx++]);
                else /* nums2 has the smaller */
                    a.push_back(nums2[nums2_idx++]);
            }
            
            /* Just add the rest of the elements here to reduce instructions */
            else if (nums1.size() > nums1_idx) { // nums1 has leftover elements
                while (nums1.size() > nums1_idx)
                    a.push_back(nums1[nums1_idx++]);
                break;
            } else {
                while (nums2.size() > nums2_idx) // nums2 has leftover elements
                    a.push_back(nums2[nums2_idx++]);
                break;
            }
        }
        
        /* Calculate median of a */
        if (a.size() % 2 != 0)
            return (double)a[a.size() / 2];
        else
            return (double)(a[(a.size() - 1) / 2] + a[(a.size()) / 2]) / (double)2;
        
    }
};
