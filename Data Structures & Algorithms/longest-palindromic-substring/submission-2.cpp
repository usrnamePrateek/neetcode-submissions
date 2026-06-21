class Solution {
   public:
    string longestPalindrome(string s) {
        if(s.size() == 0){
            return "";
        }

        int maxLen = 0;
        string maxStr = "";

        for (int i = 0; i < s.size(); i++) {
            int a = i - 1;
            int b = i + 1;

            while (a >= 0 && b < s.size()) {
                if (s[a] == s[b]) {
                    a--;
                    b++;
                } else {
                    break;
                }
            }

            if (b - a - 1 > maxLen) {
                maxLen = b - a - 1;
                maxStr = s.substr(a + 1, maxLen);
            }

            a = i;
            b = i + 1;

            while (a >= 0 && b < s.size()) {
                if (s[a] == s[b]) {
                    a--;
                    b++;
                } else {
                    break;
                }
            }

            if (b - a - 1 > maxLen) {
                maxLen = b - a - 1;
                maxStr = s.substr(a + 1, maxLen);
            }

            // cout << maxStr << endl;
        }

        return maxStr;
    }
};
