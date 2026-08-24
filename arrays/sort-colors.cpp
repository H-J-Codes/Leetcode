// https://leetcode.com/problems/sort-colors/ 
// Approach: Dutch National Flag - three pointers (low, mid, high) to sort 0s, 1s, 2s in one pass
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0, mid = 0, h = n - 1;
        while (mid <= h) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++, mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[h], nums[mid]);
                h--;
            }
        }
    }
};
