#include <vector>
#include <stdio.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        // search and move
        int gap = 0;
        int check_pos = 0;
        int same_cnt = 0;
        int tmp ;

        while (check_pos < len)
        {
            if ( (len - check_pos) < 3)
            {
                if (gap != 0)
                {
                    for (int i = check_pos; i < len; ++i)
                    {
                        nums[i - gap] = nums[i];
                    }
                }
                break;
            }
            same_cnt = 0;
            while ( true )
            {
                tmp = same_cnt + check_pos + 1;
                if (tmp >= len)
                {
                    break;
                }
                if ( nums[tmp] == nums[check_pos])
                {
                    ++same_cnt;
                }
                else
                {
                    break;
                }

            }
           

            if (same_cnt < 2)
            {
                if (gap > 0)
                {
                    for(int mi = 0;mi < same_cnt+1;++mi)
                    {
                        nums[check_pos + mi - gap] = nums[check_pos+mi];    
                    }
                }
                check_pos += same_cnt + 1;
                
            }
            else
            {
                if (gap > 0)
                {
                    nums[check_pos - gap] = nums[check_pos];
                    nums[check_pos + 1 - gap] = nums[check_pos + 1];
                }
                gap += same_cnt - 1;
                check_pos += same_cnt + 1;
            }
        }

        return (len - gap);

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v = {1,1,1,1,1};
    int result = s.removeDuplicates(v);

    for (int i = 0; i < result; ++i)
    {
        printf("%d,", v[i]);
    }
    printf("\n");
    return 0;
}




