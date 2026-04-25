class Solution {
public:
    // as we know, the duplicates will appear even if we use i, j+1, k+2 approach in brute force
    // we need to find a way to avoid the duplicates
    
    // because this problem doesn't require the index which contains the information of initial 
    // ordering. so we can sort the nums first to group the same item in groups. then we can
    // conduct a simple way to detect duplicates.

    // what is the duplicate detection logic? take the example [-1,0,1,2,-1,-4]
    // sort => [-4,-1,-1,0,1,2], when i = 1, we can find [-1, 0, 1], 
    // However, when i = 2, we can still get the [-1, 0, 1] which is a duplicates

    // we can find see the logic here => we can't use the same value as begin and rematch the same
    // candidates again

    // let's use brute force with sorted vector. we get result [[-1,2,-1],[0,1,-1],[0,1,-1]]
    // Note 1: use unordered_set won't help if the array is not sorted. take the sol1's result
    //         [[0,1,-1],[2,-1,-1],[1,-1,0]]. we still can't distinguish the [0, 1, -1] and [1, -1, 0]
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        auto end = nums.end();
        int prev = 0;
        for (auto it = nums.begin(); it != end; it++)
        {
            if(it != nums.begin())
            {
                if(prev == *it)
                    // duplicates
                    continue;
            }
            vector<vector<int>> result = twosum((it + 1), end, 0 - (*it));
            for(auto jt = result.begin(); jt != result.end(); jt++)
            {
                (*jt).push_back(*it);
                ret.push_back(*jt);
            }
            prev = *it;
        }
        return ret;

    }
    // create a two sum by brute force
    vector<vector<int>> twosum (vector<int>::iterator b, vector<int>::iterator e, int target)
    {
        vector<vector<int>> result;
        auto begin = b;
        int prev = 0;
        for(;b != e; b++)
        {
            // need to consider duplicates too
            if(b != begin)
            {
                if(prev == *b)
                {
                    continue;
                }
            }
            for(auto it = b + 1; it != e; it++)
            {
                if(*b + *it == target)
                {
                    result.push_back(vector<int>{*b, *it});
                }
            }
            prev = *b;
        }
        return result;
    }
};
