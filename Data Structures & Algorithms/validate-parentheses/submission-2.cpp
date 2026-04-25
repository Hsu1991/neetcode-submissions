class Solution {
public:
    bool isValid(string s) {
        // Use stack
        stack<char> pstack;
        int length = s.length();
        if(length % 2 != 0 || length == 0)
            return false;
        // push first element in the stack
        for (int i = 0; i < length; i++) {
            if(isLeft(s[i])) {
                pstack.push(s[i]);
            } else {
                if(pstack.size() == 0)
                    return false;
                char top = pstack.top();
                if(!isPair(top, s[i])) 
                    return false;
                pstack.pop();
            }
        }
        // Forgot to check stack in case "((" causes error
        return pstack.size() == 0;
    }
    bool isPair(char l, char r)
    {
        switch(l) 
        {
            case '(':
                return r == ')';
                break;
            case '[':
                return r == ']';
                break;
            case '{':
                return r == '}';
                break;
            default:
                return false; 
                break;                           
        }
    }

    bool isLeft(char c)
    {
        return c == '(' || c=='[' || c=='{';
    }
};
