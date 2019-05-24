#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
        {
            return vector<int>();
        }
        vector<int> result;

        int height = matrix.size();
        int width =  matrix[0].size();

        int top=0;
        int left=0;
        int right = width;
        int bottom = height;

        int forward = 0; // 0:to right 1:to bottom 2:to left 3:to top
        while(true)
        {
            if(bottom<=top
                || left >= right)
            {
                break;
            }
            if(forward==0) // to right
            {
                for(int i=left;i<right;++i)
                {
                    result.push_back(matrix[top][i]);
                }
                ++top;
            }
            else if(forward==1)// to bottom
            {
                for(int i=top;i<bottom;++i)
                {
                    result.push_back(matrix[i][right-1]);
                }
                --right;
            }
            else if(forward==2)// to left
            {
                for(int i=right-1;i>=left;--i)
                {
                    result.push_back(matrix[bottom-1][i]);
                }
                --bottom;
            }
            else if(forward==3)// to top
            {
                for(int i=bottom-1;i>=top;--i)
                {
                    result.push_back(matrix[i][left]);
                }
                ++left;
            }
            forward  = ++forward % 4;
        }
        return result;


    }
};

int main()
{
    Solution s;
    vector<vector<int>> data;
    data.push_back({1, 2, 3, 4});
    // data.push_back({5, 6, 7, 8});
    // data.push_back({9,10,11,12});

    vector<int> result = s.spiralOrder(data);
    for(int i=0;i<result.size();++i)
    {
        cout<<result[i]<<",";
    }
    cout<<endl;

}