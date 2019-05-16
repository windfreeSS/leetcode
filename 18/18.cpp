#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int nums_len = nums.size();
        if (nums_len < 4)
        {
            return result;
        }

        std::sort(nums.begin(), nums.end());

        for (int j = 0; j < (nums_len - 3); ++j)
        { 
            //  can Optimization by use $ target < (nums[0]+nums[1]+nums[2]+nums[3]) 
            //  or target < nums[0]*4 or target > nums[nums_len-1]*4;
            if( j>0 && nums[j]==nums[j-1])
            {
                continue;
            }

            for (int k = j + 1; k < (nums_len - 2); ++k)
            {
                if( k > (j+1) && nums[k]==nums[k-1])
                {
                    continue;
                }
                int m = k+1;
                int n = nums_len-1;

                while(m<n)
                {
                    int curr_sum = nums[j] + nums[n] + nums[k]+nums[m];
                    if(curr_sum == target)
                    {
                        vector<int> data ={nums[j],nums[k],nums[m],nums[n]};
                        result.push_back(data);
                        ++m;
                        --n;
                        while( (m<n) && (nums[m]==nums[m-1]) )
                        {
                            ++m;
                        }
                        while( (m<n) && (nums[n]==nums[n+1]) )
                        {
                            --n;
                        }
                    }
                    else if(curr_sum>target)
                    {
                        --n;
                    }
                    else
                    {
                        ++m;
                    }

                }
            }
        }
        return result ;
    }
};

int main()
{
    Solution s;
    vector<int> data = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> result = s.fourSum(data,0);
    for(int i=0;i<result.size();++i)
    {
        printf("%d,%d,%d,%d\n",result[i][0],result[i][1],result[i][2],result[i][3]);
    }
}