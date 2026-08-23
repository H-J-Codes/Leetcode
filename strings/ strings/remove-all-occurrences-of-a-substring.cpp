 // https://leetcode.com/problems/remove-all-occurrences-of-a-substring/ 
// Approach: build result char by char, check if the tail matches 'part', erase if so (string used like a stack)
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string result;
        for(char ch:s){
            result+=ch;
            if(result.size()>=part.size() && result.compare(result.size()-part.size(),part.size(),part)==0){
                result.erase(result.size()-part.size());
            }
        }
        return result;
    }
};
