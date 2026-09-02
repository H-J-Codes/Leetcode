class Solution {
public:
    void ps(vector<int>& arr, vector<int>& ans, vector<vector<int>>& result, int i) {
        if(i == arr.size()) {
            result.push_back(ans);
            return;
        }
        ans.push_back(arr[i]);
        ps(arr, ans, result, i + 1);
        int idx=i+1;
        while(idx<arr.size() && arr[idx]==arr[idx-1]){
            idx++;
        }
        ans.pop_back();
        ps(arr, ans, result, idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        ps(nums, ans, result, 0);
        return result;
    }
};
