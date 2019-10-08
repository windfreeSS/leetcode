#include "../all.cpp"

// 这样的元素，不会超过两个，假设有三个元素，每个元素数量都大于n/3，则总数量大于n。
// 摩尔投票法

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        {
            return vector<int>();
        }
        if(n==1)
        {
            return nums;
        }
        vector<int> cnt(2,0);
        vector<int> val;
        size_t pos = 0;
        cnt[0]=1;
        val.push_back(nums[pos]);

        //查找第一个
        while(++pos<n && nums[pos]==nums[pos-1])
        {
            ++cnt[0];
        }
        if(pos>=n)
        {
            return val;
        }


        //查找第二个
        cnt[1]=1;
        val.push_back(nums[pos]);
        while(++pos<n&&nums[pos]==nums[pos-1])
        {
            ++cnt[1];
        }

        // 更新
        for(int i=pos;i<n;++i)
        {
            if( (cnt[0]==0 || val[0]==nums[i]) && nums[i]!=val[1])
            {
                ++cnt[0];
                val[0]=nums[i];
            }
            else if( cnt[1]==0||val[1]==nums[i] )
            {
                ++cnt[1];
                val[1]=nums[i];
            }
            else
            {
                --cnt[0];
                --cnt[1];
            }
        }

        cnt[0]=cnt[1]=0;
        
        for(int i=0;i<n;++i)
        {
            if(val[0]==nums[i])
            {
                ++cnt[0];
            }
            else if(val[1]==nums[i]){
                ++cnt[1];
            }
        }

        vector<int> result;
        if(cnt[0]>n/3)
        {
            result.push_back(val[0]);
        }
        if(cnt[1]>n/3)
        {
            result.push_back(val[1]);
        }

        return result;


    }
};


int main(int argc, char const *argv[])
{
    

    return 0;
}