// https://leetcode.com/problems/permutation-in-string/ 
// Approach: for each window of size s1.length() in s2, build frequency array and compare with s1's frequency array
class Solution {
public:
    bool is_samefreq(int a[], int b[]) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for (int i = 0; i < s1.length(); i++) {
            freq[s1[i] - 'a']++;
        }

        int windSize = s1.length();
        for (int i = 0; i < s2.length(); i++) {
            int windIdx = 0, idx = i;
            int windfreq[26] = {0};
            while (windIdx < windSize && idx < s2.length()) {
                windfreq[s2[idx] - 'a']++;
                windIdx++, idx++;
            }
            if (is_samefreq(windfreq, freq)) {
                return true;
            }
        }
        return false;
    }
};
