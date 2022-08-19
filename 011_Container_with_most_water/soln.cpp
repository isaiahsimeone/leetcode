#define MIN(a,b) (a > b ? b : a)
class Solution {
public:
    int maxArea(vector<int>& h) {
        int currentMaxArea = 0;
        int i, j;
        for (i = 0, j = h.size() - 1; i < j; ) {
            currentMaxArea = ((j - i) * min(h[i], h[j]) > currentMaxArea ? 
                              (j - i) * min(h[i], h[j]) : currentMaxArea);
            if (h[i] > h[j])
                j--;
            else
                i++;
        }
        return currentMaxArea;
    }
};

