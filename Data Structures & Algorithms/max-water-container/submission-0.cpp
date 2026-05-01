class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;
        int len = heights.size();
        // brute force first
        for(int i = 0; i < len - 1; i++)
        {
            for(int j = i + 1; j < len; j++)
            {
                int area = min(heights[i], heights[j]) * (j - i);
                if(max < area)
                {
                    max = area;
                }
            }
        }
        return max;
    }

    // int getArea(vector<int>& heights, int start, int end)
    // {
    //     return min(heights[start], heights[end]) * (end - start);
    // }
};
