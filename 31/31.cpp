#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // [begin,end]
    void exchange_range(vector<int>& nums,int begin,int end)
    {
        while(begin < end)
        {
            int tmp = nums[begin];
            nums[begin]=nums[end];
            nums[end]=tmp;

            if(nums[begin]==nums[end])
            {
                break;
            }

            ++begin;
            --end;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int find_less_pos=-1;
        int nums_len = nums.size();
        for(int i=nums_len-2;i>=0;--i)
        {
            if(nums[i] < nums[i+1])
            {
                find_less_pos=i;
                break;
            }
        }
        if(find_less_pos==-1) //adjust all
        {
            exchange_range(nums,0,nums_len-1);
            return ;
        }
        else
        {
            int first_bigger_pos= -1;
            for(int i=nums_len-1;i>=0;--i)
            {
                if(nums[i] > nums[find_less_pos])
                {
                    first_bigger_pos = i;
                    break;
                }
            }
            // swap find_less_pos and first_bigger_pos
            int swap_tmp=nums[first_bigger_pos];
            nums[first_bigger_pos]=nums[find_less_pos];
            nums[find_less_pos]=swap_tmp;

            exchange_range(nums,find_less_pos+1,nums_len-1);
            return ;
        }
        return ;

    }
};

int main()
{
    Solution s;
    vector<int> data ={4, 5, 3, 3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
    s.nextPermutation(data);
    for(int i=0;i<data.size();++i)
    {
        cout<<data[i]<<",";
    }
    cout<<endl;
}