class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        for(string &str: strs){
            res += to_string(str.size());
            res.push_back('#');
            res += str;
        }

        return res;
    }

    vector<string> decode(string s) {
        // cout << s << endl;
        // return vector<string>();
        vector<string> res;
        int start = 0;

        while(start < s.size()){
            int numOfChars = s[start] - '0';
          
            start++;

            while(s[start] != '#' && start < s.size()){
                numOfChars = (s[start] - '0') + numOfChars * 10;
                start++; 
            }

            // cout << numOfChars << endl;

            start++;
            string word = s.substr(start, numOfChars);
            // cout << word << endl;
            res.push_back(word);

            start += numOfChars;
        }

        return res;
    }
};
