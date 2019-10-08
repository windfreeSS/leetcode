#include "../all.cpp"


int row_offset[] = {0, 1, 0, -1};
int col_offset[] = { -1, 0, 1, 0};
class Solution {
private:
    int m;
    int n;
    size_t str_len;

public:
    bool valid_neighbour(int net_row, int net_col, vector<vector<bool>>& flag)
    {
        if (net_row < 0 || net_row >= m)
        {
            return false;
        }
        if (net_col < 0 || net_col >= n)
        {
            return false;
        }
        return !flag[net_row][net_col];
    }
    bool judge_bfs(int net_row, int net_col, vector<vector<char>>&net, string& word, size_t w_pos, vector<vector<bool> >& flag)
    {
        if (w_pos >= str_len)
        {
            return true;
        }

        if (net[net_row][net_col] != word[w_pos])
        {
            return false;
        }
        ++w_pos;
        if(w_pos >= str_len)
        {
            return true;
        }

        for (int i = 0; i < 4; ++i)
        {
            int next_row = net_row + row_offset[i];
            int next_col = net_col + col_offset[i];
            if (!valid_neighbour(next_row, next_col, flag))
            {
                continue;
            }
            flag[next_row][next_col] = true;
            if (judge_bfs(next_row, next_col, net, word, w_pos, flag))
            {
                return true;
            }
            flag[next_row][next_col] = false;
        }

        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        str_len = word.size();
        if (str_len == 0)
        {
            return true;
        }
        m = board.size();
        if (m == 0)
        {
            return false;
        }
        n = board[0].size();
        if (n == 0)
        {
            return false;
        }

        vector<vector<bool>> used_flag(m, vector<bool>(n, false));

        for (int row = 0; row < m; ++row)
        {
            for (int col = 0; col < n; ++col)
            {
                used_flag[row][col] = true;
                if (judge_bfs(row, col, board, word, 0, used_flag))
                {
                    return true;
                }
                used_flag[row][col] = false;
            }
        }

        return false;

    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}