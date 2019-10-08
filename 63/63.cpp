#include "../all.cpp"

// 动态规划

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m, n;
        if ( (m = obstacleGrid.size()) == 0
                || (n = obstacleGrid[0].size()) == 0
           )
        {
            return 0;
        }

        vector<long long > dp(n);
        if (obstacleGrid[m - 1][n - 1] == 0)
        {
            dp[n - 1] = 1;
        }
        for (int i = n - 2; i >= 0; --i)
        {
            if(dp[i+1]==1 && obstacleGrid[m - 1][i]==0)
            {
                dp[i]=1;
            }
            else
            {
                dp[i]=0;
            }
        }

        for (int i = m - 2; i >= 0; --i)
        {
            if (obstacleGrid[i][n - 1] == 1)
            {
                dp[n - 1] = 0;
            }
            for(int j=n-2;j>=0;--j)
            {
                if(obstacleGrid[i][j]==1)
                {
                    dp[j]=0;
                }
                else
                {
                    dp[j] +=dp[j+1];
                }
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