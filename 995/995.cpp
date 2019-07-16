#include "../all.cpp"


class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.empty())
        {
            return 0;
        }

        int char_count = A[0].size();
        int a_count = A.size();

        if (char_count == 0)
        {
            return 0;
        }

        int del_count = 0;
        vector<int> pre_col_order_flag(a_count, 0); //0:表示等于前一列，1表示大于前一列


        for (int i = 0; i < char_count; ++i)
        {
            vector<int> curr_col_order_flag = pre_col_order_flag;
            curr_col_order_flag[0] = 1;

            for (int j = 1; j < a_count; ++j)
            {
                if (A[j][i] > A[j - 1][i])
                {// >
                    curr_col_order_flag[j] = 1;
                }
                else if(A[j][i] == A[j - 1][i])
                {// ==
                     curr_col_order_flag[0] = 0;
                }
                else // <
                {
                    if(curr_col_order_flag[j]==0)                    
                    {
                        curr_col_order_flag[0] = -1;
                        break;
                    }
                }
            }

            if(curr_col_order_flag[0] ==1)
            {
                break;
            }
            else if(curr_col_order_flag[0] == -1)
            {
                ++del_count;
            }
            else
            {
                pre_col_order_flag = curr_col_order_flag;
            }
        }
        return del_count;

    }
};

int main()
{
    vector<string> data = {"abx","agz","bgc","bfc"};
    Solution s;
    cout<<s.minDeletionSize(data)<<endl;
}