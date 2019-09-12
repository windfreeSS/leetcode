#include "../all.cpp"

// 视为一维情况处理，涉及到坐标转换
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        long long  m = matrix.size();
        if(m==0)
        {
            return false;
        }
        long long n = matrix[0].size();
        if(n==0)
        {
            return false;
        }

        long long right = m*n;
        long long left = 0 ;
        long long mid;

        while(left<right)
        {
            mid = (left+right)/2;
            long long x = mid/n;
            long long y = mid%n;
            if(matrix[x][y] == target)
            {
                return true;
            }
            else if(matrix[x][y]>target)
            {
                right = mid;
            }
            else
            {
                left = mid+1;
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