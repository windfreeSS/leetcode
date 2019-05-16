#include<iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int num_len = nums.size();

        long long latest_sum = nums[0]+nums[1]+nums[2];
        long long latest_abs_num = abs(latest_sum-target);

        for(int i=0;i<num_len-2;++i)
        {
        	int left_pos=i+1;
        	int right_pos=num_len-1;
      
 
        	while(left_pos < right_pos)
        	{
        		long long curr_sum =  nums[i] + nums[left_pos] + nums[right_pos];
        		long long curr_abs_num = abs(curr_sum-target);
        		if(curr_abs_num==0)
	        	{
	        		return target;
	        	}
	        	if(curr_abs_num < latest_abs_num)
	        	{
	        		latest_sum = curr_sum;
	        		latest_abs_num = curr_abs_num;
	        	}

	        	if(curr_sum > target)
	        	{
	        		--right_pos;
	        	}
	        	else
	        	{
	        		++left_pos;
	        	}

        	}
        }
        return latest_sum;
    }
};

int main()
{
	Solution s;
	vector<int> data = {-1,2,1,-4};
	cout<<s.threeSumClosest(data,-4)<<endl;
}