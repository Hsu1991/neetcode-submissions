class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // create the hash table
        unordered_map<int, int> tbl;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++)
        {
            int ind = target - nums[i];
            if(tbl.contains(ind))
            {
                result.push_back(tbl[ind]);
                result.push_back(i);
                break;
            }
            else
            {
                // caution: use tbl[ind] = i which is incorrect. think more carefully next time
                tbl[nums[i]] = i;
            }
        }
        return result;
    }
};
