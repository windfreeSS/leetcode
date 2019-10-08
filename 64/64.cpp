#include "../all.cpp"
// 动态规划，从最后一排计算每个点的最短路径 


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m,n;
        if( (m=grid.size()) ==0
            || (n=grid[0].size())==0 )
        {
            return 0;
        }

        vector<int> dp = grid[m-1];
        for(int i=n-2;i>=0;--i)
        {
            dp[i] += dp[i+1];
        }

        for(int i=m-2;i>=0;--i)
        {
            dp[n-1] += grid[i][n-1];
            for(int j=n-2;j>=0;--j)
            {
                dp[j] = min(dp[j],dp[j+1]) + grid[i][j];
            }
        }

        return dp[0];

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}