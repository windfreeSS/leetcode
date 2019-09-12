class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0)
        {
            return ;
        }
        int n = matrix[0].size();
        if (n == 0)
        {
            return ;
        }

        for (int m_i = 0; m_i < m; ++m_i)
        {
            for (int n_i = 0; n_i < n; ++n_i)
            {
                if(matrix[m_i][n_i]==0)
                {
                    matrix[0][n_i] = 0 ;//设置标志位,第一行
                    matrix[m_i][0] = 0;  //设置标志位,第一列
                }
            }
        }
        for (int m_i = 0; m_i < m; ++m_i)
        {
            
        }

    }
};


// 使用两次遍历