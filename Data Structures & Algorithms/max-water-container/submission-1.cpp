class Solution {
public:
    int maxArea(vector<int>& heights) {
       // use optimal two pointer approach
       // 1. first take the largest width
       // 2. from this pair, if the right is higher than left. 
       //    then the other pair using i = 0 as left is impossible to be larger.
       //    because the width will be shorter causing smaller area. 
       //    select a higher right doesn't help because it is limited by the left
    
        int l = 0, r = heights.size() - 1;
        int max = 0;
        while(l < r)
        {
            int area = min(heights[l], heights[r]) * (r - l);
            if(area > max)
            {
                max = area;
            }
            if(heights[l] > heights[r])
            {
                r--;
            } 
            else
            {
                l++;
            }
        }
        return max;
    }
};
