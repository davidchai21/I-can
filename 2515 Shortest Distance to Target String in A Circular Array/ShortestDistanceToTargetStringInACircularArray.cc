class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int l = 0;
        while (l <= n/2) {
            if (target == words[(startIndex+n-l)%n] || target == words[(startIndex+l)%n]) return l;
            ++l;
        }
        return -1;
    }
};