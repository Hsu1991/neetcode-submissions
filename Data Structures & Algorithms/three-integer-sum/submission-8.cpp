class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // use optimal way, two pointers
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        int len = nums.size();
        int prev = 0;
        for (int i = 0; i < len - 2; i++)
        {
            if(i != 0 && nums[i] == prev)
                // duplicates
                continue;
            vector<vector<int>> result = twoSum(nums, i + 1, len - 1, 0 - nums[i]);
            for(auto jt = result.begin(); jt != result.end(); jt++)
            {
                (*jt).push_back(nums[i]);
                ret.push_back(*jt);
            }
            prev = nums[i];
        }
        return ret;
        
    }

    vector<vector<int>> twoSum(vector<int>& numbers, int start, int end, int target) {
        // need to detect duplicates
        int l = start, r = end;
        vector<vector<int>> result;
        while(l < r)
        {
            int sum = numbers[l] + numbers[r];
            // if(l != start && (numbers[l] == numbers[l - 1]))
            // {
            //     l++;
            //     continue;
            // }
            if(sum == target)
            {
                result.push_back(vector<int> { numbers[l], numbers[r]});
                l++;
                r--;
                // 
            }
            else if(sum > target)
            {
                // sum too large, need to decrease
                r--;
            }
            else
            {
                // sum too small, need to increase
                l++ ;
            }
            // skip outer duplicates after processing
            // fail: input: nums=[-1,0,1,2,-1,-4,-2,-3,3,0,4] 
            //       -> output: [[0,4,-4],[1,3,-4],[-1,4,-3],[0,3,-3],[1,2,-3],[-1,3,-2],[0,2,-2],[0,1,-1]]
            //       -> expected [[-4,0,4],[-4,1,3],[-3,-1,4],[-3,0,3],[-3,1,2],[-2,-1,3],[-2,0,2],[-1,-1,2],[-1,0,1]]
            while (l < r && numbers[l] == numbers[l - 1]) l++;
        }
        return result;
    }
};
