class Solution {
// NOT A WORKING solution, because the incorrect duplicates detection logic 
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
            // checkout about input:[-2, -1,-1,0,0,1,2,3,4]
            // WHEN i = 1, nums[l] = -1 and nums[r] = 4 first compare for two sum. 
            // THEN r--, However, in next iteration the l is being checked with duplicates detection logic
            // IT IS POSSIBLE THAT this l can be paired with the new r. WE CAN NOT JUST CHECK THE DUPLICATES HERE and DISCARD
            
            // 1. IT IS just "lucky" that the duplicates start at beginning so my solution seems work
            // 2. OUT of bound element checks if l is not moved yet
            
            // The core issue is: duplicate check fires on every iteration regardless of whether a match was found, 
            // so it wrongly skips l values that were never part of any pushed result. 
            // It should ONLY skip duplicates after a successful push_back, which is exactly what the while skip loops after a match achieve.
            if(l != start && (numbers[l] == numbers[l - 1]))
            {
                l++;
                continue;
            }
            if(sum == target)
            {
                result.push_back(vector<int> { numbers[l], numbers[r]});
                l++;
                r--;
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
        }
        return result;
    }
};
