class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size(), sum = 0;
        unordered_map<int, int> m;
        for (int &k : skill) {
            sum += k;
            ++m[k];
        }
        if (sum*2 % n) return -1;

        long long res = 0LL;
        sum = sum*2/n;
        for (auto it = m.begin(); it != m.end(); ++it) {
            if (it->first*2 > sum) continue;
            else if (it->first*2 == sum) {
                if (it->second%2) return -1;
                res += (long long)it->first*it->first*(it->second/2);
            } else {
                if (it->second != m[sum-it->first]) return -1;
                res += (long long)it->first*(sum-it->first)*it->second;
            }
        }
        return res;
    }
};