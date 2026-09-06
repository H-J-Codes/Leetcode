class Solution {
public:
    bool isPalin(string s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;j--;
        }
        return true;
    }
    // Get All Part
    void GAP(string s,vector<string>&parti,vector<vector<string>>&ans){
        if(s.size()==0){
            ans.push_back(parti);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part=s.substr(0,i+1);
            if(isPalin(part)){
                parti.push_back(part);
                GAP(s.substr(i+1),parti,ans);
                parti.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>parti;
        vector<vector<string>>ans;
        GAP(s,parti,ans);
        return ans;
    }
};
