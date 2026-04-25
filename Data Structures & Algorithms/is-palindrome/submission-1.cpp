class Solution {
public:
    bool isPalindrome(string s) {
        // two pointer but you shouldn't create another string
        int l = 0, r = s.length() - 1;
        while(r >= l) {
            if(std::isalpha(s[r]) && std::isalpha(s[l])) {
                if(std::tolower(s[r]) != std::tolower(s[l]))
                {
                    return false;
                }
                l++;
                r--;
            } else {
                if(std::isalpha(s[r]))
                    l++;
                else
                    r--;
            }
        } 
        return true;
    }
};
