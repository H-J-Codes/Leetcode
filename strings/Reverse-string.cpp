// https://leetcode.com/problems/reverse-string/
// Approach: two pointers from both ends, swap and move inward
class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0,end=s.size()-1;
        while(st<end){
            swap(s[st++],s[end--]);
        }
    }
};
