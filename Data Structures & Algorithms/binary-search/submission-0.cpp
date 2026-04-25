class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r, l, index = -1;
        int mid;
        l = 0;
        r = nums.size() - 1;
        while(r > l)
        {
            mid = (r + l) / 2;
            if(nums[mid] == target)
            {
                index = mid;
                break;
            }
            if(nums[mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        return index;
        
    }
};
