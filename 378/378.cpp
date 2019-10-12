#include "../all.cpp"


class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int ret;
        vector<int> indexs(n,0);
        while(k--)
        {
            for(int i=0;i<n;++i)
            {
                if(indexs[i]>=n)
                {
                    continue;
                }
                if(i==(n-1))
                {
                    ret = matrix[i][indexs[i]];
                    ++indexs[i];
                    continue;
                }

                if( matrix[i][indexs[i]] <= matrix[i+1][indexs[i+1]] )
                {
                    ret = matrix[i][indexs[i]];
                    ++indexs[i];
                    break;
                }
            }
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}