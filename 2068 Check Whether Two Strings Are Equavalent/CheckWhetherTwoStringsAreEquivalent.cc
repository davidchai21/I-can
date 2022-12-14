class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> dic(26, 0);
        for (char& c : word1) {
            ++dic[c-'a'];
        }
        for (char& c : word2) {
            --dic[c-'a'];
        }
        for (int &n : dic) {
            if (n < -3 || n > 3) return false;
        }
        return true;
    }
};