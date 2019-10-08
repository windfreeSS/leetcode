#include "../all.cpp"

// dp
// 记录每一个矩阵点的最大正方形长度
// 还可以再进行优化

struct line_size
{
    int l; //长
    int b; //宽
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }
        int n = matrix[0].size();
        if (n == 0)
        {
            return false;
        }

        vector<vector<int>> grid(m, vector<int>(n));
        vector<vector<line_size>> lines(m, vector<line_size>(n)); 
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                grid[i][j] = matrix[i][j] - '0';
                lines[i][j].l = lines[i][j].b = grid[i][j];
            }
        }
        for (int i = m - 2; i >= 0; --i)
        {
            for (int j = n - 2; j >= 0; --j)
            {
                // update lines
                if (lines[i][j].l != 0 )
                {
                    lines[i][j].l = lines[i][j + 1].l + 1;
                    lines[i][j].b = lines[i + 1][j].b + 1;
                }
                if (grid[i][j] == 0)
                {
                    continue;
                }

                int mini_len = min(lines[i][j].l - 1, lines[i][j].b - 1);
                mini_len = min(mini_len, grid[i + 1][j + 1]);

                grid[i][j] += mini_len;

            }
        }
        int area = 0;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int square_size = grid[i][j] * grid[i][j];
                if (square_size > area)
                {
                    area = square_size;
                }
            }
        }

        return area;


    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<char>> data = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    cout << s.maximalSquare(data) << endl;
    return 0;
}