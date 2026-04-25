class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int len = nums.size();
        int prev = 0;
        for (int i = 0; i < len; i++)
        {
            if(i != 0 && nums[i] == prev)
                // duplicates
                continue;
            vector<vector<int>> result = twosum(nums, i + 1, len, 0 - nums[i]);
            for(auto jt = result.begin(); jt != result.end(); jt++)
            {
                (*jt).push_back(nums[i]);
                ret.push_back(*jt);
            }
            prev = nums[i];
        }
        return ret;
    }
    vector<vector<int>> twosum (vector<int>& nums, int start, int end, int target)
    {
        vector<vector<int>> result;
        // unordered_set + [1] =  fails at [0,0,0]
        unordered_map<int, int> tmp;
        int prev = 0;
        // cout << "target:" <<target << "\n";
        for(int i = start; i < end; i++)
        {
            // cout << nums[i] << "\n";
            //if(i != 0 && nums[i] == prev) --> [1]
            //    // duplicates
            //    continue;
            if(tmp.contains(target - nums[i]) && tmp[target - nums[i]] == 0)
            {
                vector<int> valid_pair;
                valid_pair.push_back(nums[i]);
                valid_pair.push_back(target - nums[i]);
                result.push_back(valid_pair);
                // cout << "matched\n";
                tmp[target - nums[i]] = tmp[target - nums[i]] + 1;
            }
            else
            {
                // insert nums[i] instead of target - nums[i] => 2nd times
                tmp[nums[i]] = 0;
            }
            prev = nums[i];
        }
        return result;
    }
};
