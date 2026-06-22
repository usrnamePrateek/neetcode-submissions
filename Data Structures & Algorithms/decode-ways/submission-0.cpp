class Solution {
   public:
    vector<int> mp;
    int numDecodings(string s) {
        mp.resize(s.size(), -1);
        return sol(s, 0);
    }

    int sol(string& s, int idx) {
        if (idx == s.size()) {
            return 1;
        }

        if (mp[idx] != -1) {
            return mp[idx];
        }

        if (s[idx] == '0') {
            return 0;
        }

        int c1 = sol(s, idx + 1);
        int c2 = 0;

        string str = "";
        str.push_back(s[idx]);

        if (idx < s.size() - 1) {
            str.push_back(s[idx + 1]);
            if (stoi(str) <= 26) {
                c2 = sol(s, idx + 2);
            }
        }

        mp[idx] = c1 + c2;
        return mp[idx];
    }
};
