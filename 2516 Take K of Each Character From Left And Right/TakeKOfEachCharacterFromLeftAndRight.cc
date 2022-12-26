class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k==0) return 0;
        int n = s.size();
        int a = 0, b = 0, c = 0;
        vector<vector<int>> left(n+1, vector<int>(3,0)), right(n+1, vector<int>(3,0));
        for (int i=0;i<n;++i) {
            switch (s[i]) {
                case 'a':
                ++a;
                break;
                case 'b':
                ++b;
                break;
                case 'c':
                ++c;
                break;
                default:
                return -1;
            }
            left[i+1][0] = a;
            left[i+1][1] = b;
            left[i+1][2] = c;
        }
        if (a < k || b < k || c < k) return -1;

        a = b = c = 0;
        for (int i=n-1;i>=0;--i) {
            switch (s[i]) {
                case 'a':
                ++a;
                break;
                case 'b':
                ++b;
                break;
                case 'c':
                ++c;
                break;
                default:
                return -1;
            }
            right[i][0] = a;
            right[i][1] = b;
            right[i][2] = c;
        }

        int l = 1, r = n;
        while (l < r) {
            int mid = (l+r)/2;
            if (helper(left, right, mid, k)) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return r;
    }
private:
    bool helper(vector<vector<int>>& left, vector<vector<int>>& right, int len, const int& k) {
        int n = left.size();
        for (int i=0;i<=len;++i) {
            if (left[i][0]+right[n-1-(len-i)][0] >= k && left[i][1]+right[n-1-(len-i)][1] >= k && left[i][2]+right[n-1-(len-i)][2] >= k) return true;
        }
        return false;
    }
};

// Two Pointer:
class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int a = 0, b = 0, c = 0;
        for (char& l : s) {
            if (l == 'a') {++a;}
            else if (l == 'b') {++b;}
            else if (l == 'c') {++c;}
        }
        if (a < k || b < k || c < k) return -1;

        int i=n-1, j=n-1;
        int res = n;
        while (i >= 0) {
            if (s[i] == 'a') --a;
            else if (s[i] == 'b') --b;
            else if (s[i] == 'c') --c;
            while (a < k || b < k || c < k) {
                if (s[j] == 'a') ++a;
                else if (s[j] == 'b') ++b;
                else if (s[j] == 'c') ++c;
                --j;
            }
            res = min(res, i+n-1-j);
            --i;
        }
        return res;
    }
};