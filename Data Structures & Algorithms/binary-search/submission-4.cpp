class Solution {
public:
    int search(vector<int>& nums, int target) {
        // use the binary search template approach. the mini k such that the condition is true
        int l, r, mid;
        l = 0;
        r = nums.size() - 1;
        while(r > l)
        {
            // r - (r - l) / 2 doesn't work
            // nums=[-1,0,3,5,9,12], target=9
            // it should be l + (r - l) / 2
            mid = l + (r - l) / 2 ;
            // incorrectly use nums[mid] > target
            if(nums[mid] >= target)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
            // return r or l doesn't matter
            // the r and l will eventually in the same position
            // take 1,3,4, target = 0 as example
        }
        return (nums[l] == target)? l : -1;    
    }
};
