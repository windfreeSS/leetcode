#include <iostream>
#include <vector>
using namespace std;

// 使用分治法，具体为，
// 1、先假定一个数是众数，比如a，并记该数出现次数为1
// 2、向后遍历，如果与a相同，则次数+1，否则-1.
// 3、如果a的次数减为0，则从当前遍历的位置，再次从第一步骤计算
// 原理：
// 假设，对于第一个众数a，在遍历到第k个数的时候，a的计数变为0，则可以有一下推论
// 1、在1~k个数，与a相同的数量，以及与a不同的数量，目前是一样的。
// 2、如果1~k中的a本来就是众数，则去掉相同的数量后，a在 k+1 ~ n 中，仍然是众数。
// 3、如果1~k中的其他数本来是众数，比如b，则在(1~k)中的占比，不会超过1/2，因为有一半是a。也就是说b在 k+1 ~ n中的比例，只增不减(仍然大于1/2)。

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int me = nums[0];
        int count=1;
        int num_len = nums.size();

        for(int i =1;i<num_len;)
        {

        	if(nums[i]==me)
        	{
        		++count;
        	}
        	else if(nums[i]!=me)
        	{
        		--count;
        	}
        	if(count==0)
        	{
        		me = nums[++i];
        		count=1;
        	}
        	++i;
        }
        return me;
    }
};

int main()
{
	vector<int> data={1,1,1,1,2,2,2,2,2};
	Solution s;
	cout<<s.majorityElement(data)<<endl;
}