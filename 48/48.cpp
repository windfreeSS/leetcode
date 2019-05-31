#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix, int m_size, int where)
    {
        int curr_size = m_size - 2 * where;
        vector<int> tmp(curr_size);
        // top to right
        for (int i = 0; i < curr_size - 1; ++i)
        {
            tmp[i] = matrix[where + i][m_size - where - 1];
            matrix[where + i][m_size - where - 1] = matrix[where][where + i];
        }

        // left to top
        for (int i = 0; i < curr_size - 1; ++i)
        {
            matrix[where][where + i] = matrix[m_size - where - 1 - i][where];
        }

        //  bottom to left
        for (int i = 0; i < curr_size - 1; ++i)
        {
            matrix[m_size - where - 1 - i][where] = matrix[m_size - 1 - where][m_size - where - 1 - i];
        }

        // right to bottom
        for (int i = 0; i < curr_size - 1; ++i)
        {
            matrix[m_size - 1 - where][m_size - where - 1 - i] = tmp[i];
        }

    }
    void rotate(vector<vector<int>>& matrix) {
        int m_size = matrix.size();
        int circle_count =  m_size / 2;

        for (int i = 0; i < circle_count; ++i)
        {
            rotate(matrix, m_size, i);
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> data = {
        { 5, 1, 9, 11},
        { 2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };

    data = {
        {1, 2, 3, 4, 5,},
        {16, 17, 18, 19, 6,},
        {15, 24, 25, 20, 7,},
        {14, 23, 22, 21, 8,},
        {13, 12, 11, 10, 9}
    };
    s.rotate(data);
    for (int i = 0; i < data.size(); ++i)
    {
        for (int j = 0; j < data.size(); ++j)
        {
            cout << data[i][j] << ",";
        }
        cout << endl;
    }


}