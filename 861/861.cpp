class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int m  = A.size();
        int n = A[0].size();
        //首先处理第一列，使其全为1
        for(int i=0;i<m;++i)
        {
            if(A[i][0]==1)
            {
                continue;
            }
            for(int j=0;j<n;++j)
            {
                if(A[i][j]==1)
                {
                    A[i][j]=0;
                }
                else
                {
                    A[i][j]=1;
                }
            }
        }
        vector<int> bits(n);
        bits[0] = m;
        for(int col=1;col<n;++col)
        {
            int one_cnt = 0;
            for(int row = 0 ;row<m;++row)
            {
                one_cnt+=A[row][col];
            }
            bits[col] += std::max(one_cnt,m-one_cnt);
        }
        int ret = 0 ;
        for(int i = n-1;i>=0;--i)
        {
            ret += (1<<(n-i-1))*bits[i];
        }
        return ret;
    }
};

// 贪心算法