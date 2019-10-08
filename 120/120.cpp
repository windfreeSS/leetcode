class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {        

        vector<int> dp = triangle[triangle.size()-1];

        for(int i = triangle.size()-2;i>=0;--i)
        {
            const vector<int>& data = triangle[i];
            for(int col = 0;col < data.size();++col)
            {
                dp[col] = min(dp[col],dp[col+1]) + data[col];
            }
        }
        return dp[0];
    }
};

// 使用动态规划，具体可见笔记