class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        string s;
        vector<int> ans;

        for(int i : digits) s += char('0' + i);

        int carry = 1;
        for(int i = s.size() - 1; i >= 0 && carry; i--) {
            int x = s[i] - '0' + carry;
            s[i] = char('0' + x % 10);
            carry = x / 10;
        }

        if(carry) s = '1' + s;
        for(char c : s) ans.push_back(c - '0');

        return ans;
    }
};
