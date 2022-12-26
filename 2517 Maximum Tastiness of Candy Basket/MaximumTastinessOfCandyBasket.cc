class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        unordered_map<int, int> m;
        for (int& p : price) {
            ++m[p];
        }
        if (m.size() < k) return 0;

        vector<int> record(m.size());
        int index = 0;
        for (auto it = m.begin(); it != m.end(); ++it) {
            record[index++] = it->first;
        }
        sort(record.begin(), record.end());

        int left = 1, right = record.back()-record.front();
        while (left+1 < right) {
            int mid = left + (right-left)/2;
            if (helper(record, mid, k)) left = mid;
            else right = mid-1;
        }
        return helper(record, right, k) ? right : left;
    }
private:
    bool helper(vector<int>& record, int interval, int k) {
        int pre = -interval;
        for (int & n : record) {
            if (n-pre >=interval) {
                pre = n;
                if (--k <=0) return true;
            }
        }
        return false;
    }
};