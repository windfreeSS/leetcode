#include "../all.cpp"


// 使用了比较笨的方法
// 可以参考评论区，直接从左下角或者右上角搜索，复杂度为o(m+n)
class Solution {
private:
    int m;
    int n;
public:
    // [r_a,r_b)
    bool col_find(const vector<vector<int>>& matrix, const int& col, int r_a, int r_b, const int& target)
    {
        while (r_a < r_b)
        {
            int mid = r_a + (r_b - r_a) / 2;

            if (matrix[mid][col] == target)
            {
                return true;
            }

            if (matrix[mid][col] > target)
            {
                r_b = mid ;
            }
            else
            {
                r_a = mid + 1;
            }
        }

        return false;
    }

    // [c_a,c_b)
    bool row_find(const vector<vector<int>>& matrix, const int& row, int c_a, int c_b, const int& target)
    {
        while (c_a < c_b)
        {
            int mid = c_a + (c_b - c_a) / 2;

            if (matrix[row][mid] == target)
            {
                return true;
            }

            if (matrix[row][mid] > target)
            {
                c_b = mid;
            }
            else
            {
                c_a = mid + 1;
            }
        }

        return false;
    }

    // [top_r,bottom_r) [top_c,bottom_c)
    bool binary_find(vector<vector<int>>& matrix, int top_r, int top_c, int bottom_r, int bottom_c, int target)
    {
        if (top_r >= bottom_r
                || top_c >= bottom_c)
        {
            return false;
        }

        int mid_r = (top_r + bottom_r) / 2;
        int mid_c = (top_c + bottom_c) / 2;

        if (matrix[mid_r][mid_c] == target)
        {
            return true;
        }

        if (matrix[mid_r][mid_c] > target)
        {
            bool ret = row_find(matrix,mid_r,top_c,mid_c,target);
            ret |= col_find(matrix,mid_c,top_r,mid_r,target);
            if(!ret && (matrix[mid_r][top_c]<target))
            {
                ret |= binary_find(matrix,mid_r+1,top_c,bottom_r,mid_c,target);
            }
            if(!ret && (matrix[top_r][mid_c]<target) )
            {
                ret |= binary_find(matrix,top_r,mid_c+1,mid_r,bottom_c,target);
            }

            ret |= binary_find(matrix,top_r,top_c,mid_r,mid_c,target);
            return ret;
        }
        else
        {
            bool ret = row_find(matrix,mid_r,mid_c+1,bottom_c,target);
            ret |= col_find(matrix,mid_c,mid_r+1,bottom_r,target);
            if(!ret && (matrix[mid_r][bottom_c-1]>target) )
            {
                ret |= binary_find(matrix,top_r,mid_c+1,mid_r,bottom_c,target);
            }
            if(!ret && (matrix[bottom_r-1][mid_c]>target) )
            {
                ret |= binary_find(matrix,mid_r+1,top_c,bottom_r,mid_c,target);
            }
            ret |= binary_find(matrix,mid_r+1,mid_c+1,bottom_r,bottom_c,target);

            return ret;
        }


        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m =  matrix.size();
        if (m == 0)
        {
            return false;
        }
        n = matrix[0].size();
        if (n == 0)
        {
            return false;
        }

        return binary_find(matrix, 0, 0, m , n , target);
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}