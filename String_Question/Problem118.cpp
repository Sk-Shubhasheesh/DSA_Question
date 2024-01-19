// Problem 118 - Sorting the Sentence
// Problem link - https://leetcode.com/problems/sorting-the-sentence/
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string sortSentence(string s) {
        vector<string> ans(10);
        int index = 0;
        string temp;

        while (index < s.size()) {
            if (s[index] == ' ') {
                int pos = temp[temp.size() - 1] - '0';
                temp.pop_back();
                ans[pos] = temp;
                temp.clear();
            } else {
                temp += s[index];
            }
            index++;
        }
        int pos = temp[temp.size() - 1] - '0';
        temp.pop_back();
        ans[pos] = temp;
        temp.clear();
        for (int i = 1; i < ans.size(); i++) {
            if (!ans[i].empty()) {
                temp += ans[i];
                temp += ' ';
            }
        }
        temp.pop_back();
        return temp;
    }
};
