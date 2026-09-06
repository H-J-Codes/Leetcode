class Solution {
public:
    set<vector<int>>s;
    void cs(vector<int>&arr,int i,vector<int>&combi,vector<vector<int>>&ans,int target){
        int n=arr.size();
        if(i==n || target<0){
            return;
        }
        if(target==0){
            if(s.find(combi)==s.end()){
                ans.push_back({combi});
                s.insert(combi);
            }
            return;
        }
        combi.push_back(arr[i]);
        cs(arr,i+1,combi,ans,target-arr[i]); //For single occurence
        cs(arr,i,combi,ans,target-arr[i]); //For multiple occurence
        combi.pop_back();
        cs(arr,i+1,combi,ans,target);//For no occurence
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>combi;
        vector<vector<int>>ans;
        cs(candidates,0,combi,ans,target);
        return ans;
    }
};
