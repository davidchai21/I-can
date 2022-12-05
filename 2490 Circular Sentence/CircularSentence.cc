class Solution {
public:
    bool isCircularSentence(string sentence) {
        char head, tail;
        string word;
        stringstream ss(sentence);
        ss >> word;
        head = word.front();
        tail = word.back();
        while (ss >> word) {
            if (word.front() != tail) return false;
            head = word.front();
            tail = word.back();
        }
        return tail == sentence.front();
    }
};

class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence.back() != sentence.front()) return false;
        for (int i=1;i<sentence.size()-1;++i) {
            if (sentence[i]==' ' && sentence[i-1]!=sentence[i+1]) return false;
        }
        return true;
    }
};