class Solution {
public:
    vector<vector<int>> types;
    vector<vector<string>> result;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // brute force
        // stats array
        types.clear();
        vector<vector<string>> result;
        
        for(auto it = strs.begin(); it != strs.end(); it++)
        {
            vector<int> stat(26);
            int type = 0;
            // count char in every string 
            for(int i = 0; i < (*it).length(); i++)
            {
                stat[(*it)[i] - 'a']++;
            }
            if(-1 != (type = isExist(stat)))
            {
                // save the string to the group
                result[type].push_back(*it);
            }
            else
            {
                // update type, create new group and save the string to the group
                int new_type = result.size();
                types.push_back(stat);
                result.push_back(vector<string>());
                result[new_type].push_back(*it);
            }
        }
        
        return result;
    }

    int isExist(vector<int> stat)
    {
        for(int i = 0; i < types.size(); i++)
        {
            if(stat == types[i])
            {
                return i;
            }
        }
        return -1;
    }

};
