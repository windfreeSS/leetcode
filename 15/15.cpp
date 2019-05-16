#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int num_len = nums.size();
        if(num_len < 3)
        {
        	return vector<vector<int>>();
        }
        std::sort(nums.begin(),nums.end());// min to max

        vector<vector<int>> eq_result;

        for(int i=0;i<num_len-2;++i)
        {
        	int left_bound = i+1;
        	int right_bound = num_len-1;
        	if(nums[i]>0)//end 
        	{
        		break;
        	}
        	if( i> 0 && nums[i]==nums[i-1])
        	{
        		continue;//duplicate 
        	}
        	while(left_bound < right_bound)
        	{
        		long long curr_sum = nums[i] + nums[left_bound] + nums[right_bound];
        		if(curr_sum==0)
        		{
        			vector<int> curr_data = {nums[i],nums[left_bound],nums[right_bound]};
        			eq_result.push_back(curr_data);
        			++left_bound;
        			--right_bound;
        			while( (left_bound<right_bound) && (nums[left_bound]==nums[left_bound-1]))
	        		{
	        			++left_bound;
	        		}
	        		while( (left_bound<right_bound) && (nums[right_bound]==nums[right_bound+1]))
	        		{
	        			--right_bound;
	        		}
        		}
        		else if(curr_sum < 0)
        		{
        			++left_bound;
        		}
        		else
        		{
        			--right_bound;
        		}
        		
        	}
        }
        return eq_result;

    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	vector<int> data = {0,0,0};//{-1, 0, 1, 2, -1, -4};

	vector<vector<int>> result = s.threeSum(data);

	for (int i = 0; i < result.size(); ++i)
	{
		printf("%d,%d,%d\n",result[i][0],result[i][1],result[i][2]);
	}
	
	return 0;
}