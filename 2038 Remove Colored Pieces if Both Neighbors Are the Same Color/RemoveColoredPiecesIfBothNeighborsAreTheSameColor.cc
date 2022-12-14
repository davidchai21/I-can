class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.size();
        if (n < 3) return false;
        char c = colors.front();
        int count = -1;
        int A = 0, B = 0;
        for (int i=1;i<n;++i) {
            if (c == colors[i]) {
                ++count;
            } else {
                if (c=='A') {
                    A += max(0, count);
                    c = 'B';
                } else {
                    B += max(0, count);
                    c = 'A';
                }
                count = -1;
            }
        }

        if (c == 'A') {
            A += max(0, count);
        } else {
            B += max(0, count);
        }
        return A>B;
    }
};