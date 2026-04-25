class Solution {
public:
    bool isPalindrome(string s) {
        // use the two pointer approach
        // trim non-alphanumeric char first and convert it to lower case
        s = trim(s);
        int r = s.length() - 1, l = 0;
        // std::cout << s << std::endl;
        while (r >= l)
        {
            if(s[r] != s[l])
            {
                return false;
            }
            r--;
            l++;
        }
        return true;
    }
    string trim(string s)
    {
        string result;
        
        for(auto it = s.begin(); it != s.end(); it++)
        { 
            if(std::isalnum(*it))
            {
                // std::cout << *it << std::endl;
                // convert to lower case if necessary
                if(*it < 'a')
                    result += ((*it) + 32);
                else
                    result += *it;
            }
        }
        return result;
    }

};
