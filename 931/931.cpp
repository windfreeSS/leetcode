#include "../all.cpp"

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<int> dp = A[m-1];

        for(int i=m-2;i>=0;--i)
        {
            vector<int> tmp(n);
            for(int j=0;j<n;++j)
            {
                int val = dp[j];
                if( (j-1)>=0 && dp[j-1] <val )
                {
                    val = dp[j-1];
                }
                if( (j+1)<n && dp[j+1]<val )
                {
                    val = dp[j+1];
                }
                tmp[j]  = A[i][j] + val;
            }
            dp = tmp;
        }

        int ret = dp[0];
        for(int i=1;i<n;++i)
        {
            if(dp[i]<ret)
            {
                ret =dp[i];
            }
        }

        return ret;
    }
};