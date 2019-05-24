#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int num_len = nums.size();
        int search_pos=0;
        int next_search_pos=0;
        while(search_pos<num_len-1)
        {
            int flag_val = nums[search_pos];
            if(flag_val!=nums[search_pos+1])
            {
                ++search_pos;
                continue;
            }

            for(next_search_pos =search_pos+2;next_search_pos<num_len;++next_search_pos)
            {
                if(nums[next_search_pos]!=flag_val)
                {
                    break;
                }
            }

            int dup_count= (next_search_pos-search_pos-1);
            // move
            for(int i=next_search_pos;i<num_len;++i)
            {
                nums[i-dup_count] = nums[i];
            }
            num_len-=dup_count;
            ++search_pos;
        }
        return num_len;
    }
};

int main()
{
    vector<int> data={1};
    Solution s;
    int len = s.removeDuplicates(data);
    for(int i=0;i<len;++i)
    {
        cout<<data[i]<<",";
    }
    cout<<endl;

}