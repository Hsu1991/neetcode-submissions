class Solution {
public:
    bool isAnagram(string s, string t) {
        // use the unordered_map to store the char cnt;
        // => no, use an array is enough, only lowercase english letters
        // a-z: 97-122
        char stat[2][26] = {0};
        // check two string's length
        if(s.length() != t.length())
            return false;
        // but about empty string?

        // run through the strings to count the chars
        // in the end, compare the count of each char for both strings
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            stat[0][s[i] - 'a']++;
            stat[1][t[i] - 'a']++;
        }
        // check two stat are same;
        for(int i = 0; i < 26; i++)
        {
            if(stat[0][i] != stat[1][i])
                return false;
        }
        return true;

    }
};
