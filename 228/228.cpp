#include "../all.cpp"


class Solution {
public:
    void add(vector<string>& result,vector<int>&nums,size_t pos ,size_t count)
    {
        char chs[40]={0};
        if(count==1)
        {
            sprintf(chs,"%d",nums[pos]);
        }
        else
        {
            sprintf(chs,"%d->%d",nums[pos],nums[pos+count-1]);
        }
        result.push_back(chs);
    }
    vector<string> summaryRanges(vector<int>& nums) {
        size_t n_len = nums.size();
        size_t pos = 0;
        vector<string> result;

        while(pos<n_len)
        {
            size_t end_pos = pos+1;
            while(end_pos<n_len && 
                (nums[end_pos] == (nums[end_pos-1]+1)) )
            {
                ++end_pos;
            }
            add(result,nums,pos,end_pos-pos);
            pos = end_pos;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}