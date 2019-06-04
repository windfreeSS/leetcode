#include "../all.cpp"

class Solution {
public:

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m_size = matrix.size();
        if (m_size == 0)
        {
            return vector<int>();
        }
        int n_size = matrix[0].size();
        if (n_size == 0)
        {
            return vector<int>();
        }

        int r = 0;
        int c = 0;
        enum {
            left_down,
            right_up
        } torward = right_up;
        int ele_size = m_size * n_size;
        vector<int> result(ele_size);

        int curr_size = 0;
        result[curr_size] = matrix[r][c];
        ++curr_size;

        while (true)
        {
            if (curr_size >= ele_size)
            {
                break;
            }
            switch (torward)
            {
            case right_up:
            {
                if (c == (n_size - 1))
                {
                    torward = left_down;
                    ++r;
                }
                else if (r == 0)
                {
                    torward = left_down;
                    ++c;
                }
                else
                {
                    --r;
                    ++c;
                }
                result[curr_size] = matrix[r][c];

            }
            break;
            case left_down:
            {
                if (r == (m_size - 1))
                {
                    torward = right_up;
                    ++c;
                }
                else if (c == 0)
                {
                    torward = right_up;
                    ++r;
                }
                else
                {
                    ++r;
                    --c;
                }
                result[curr_size] = matrix[r][c];

            }
            break;
            }
            ++curr_size;
        }

        return result;

    }
};
int main()
{
    Solution s;
    vector<vector<int>> data = {
        { 1, 2, 3 },
        // { 4, 5, 6 },
        { 7, 8, 9 }
    };
    vector<int> result = s.findDiagonalOrder(data);
    print(result);
}