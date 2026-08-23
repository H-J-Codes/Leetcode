// https://leetcode.com/problems/valid-palindrome/
// Approach: two pointers, skip non-alphanumeric chars, compare lowercase

class Solution {
public:
    bool is_alphanum(char ch){
        if(ch>='0' && ch<='9'||tolower(ch)>='a' && tolower(ch)<='z'){
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int n=s.size();
        int st=0,end=n;
        while(st<end){
            if(!is_alphanum(s[st])){
                st++;
                continue;
            }
            if(!is_alphanum(s[end])){
                end--;
                continue;
            }
            if(tolower(s[st])!=tolower(s[end])){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
};
