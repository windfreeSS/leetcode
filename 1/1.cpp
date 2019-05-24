#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	
    vector<int> twoSum(vector<int>& nums, int target) {
        int num_len = nums.size();
        for(int i=0;i<num_len;++i)
        {
        	for(int j=i+1;j<num_len;++j)
        	{
        		if( (nums[i]+nums[j])==target)
        		{
        			vector<int> result = {i,j};
        			return result;
        		}
        	}
        }
        return vector<int>();
    }
};

int main()
{
	Solution s;
	vector<int> data= {15,11,7,2};
	vector<int>result= s.twoSum(data,9);

}