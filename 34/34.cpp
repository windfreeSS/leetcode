#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int bs_last_less(vector<int>& nums,int num_size,int target)
	{
		int begin=0;
		int end = num_size;
		int result = -1;
		while(begin<end)
		{
			int mid = (begin+end)/2;
			if(nums[mid]<target)
			{
				result = mid;
				begin = mid +1;
			}
			else // >=
			{
				end = mid;
			}
		}
		return result;
	}
	int bs_first_bigger(vector<int>& nums,int num_size ,int target)
	{
		int begin=0;
		int end = num_size;
		int result = -1;
		while(begin<end)
		{
			int mid = (begin+end)/2;
			if(nums[mid]>target)
			{
				result = mid;
				end = mid ;
			}
			else // <=
			{
				begin = mid +1;
			}
		}
		return result;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
    	int num_size = nums.size();
        int left = bs_last_less(nums,num_size,target);
        int right = bs_first_bigger(nums,num_size,target);
        if( right==0
        || left ==  (num_size-1)
        || (right-left)==1 )
        {
        	vector<int> result={ -1,-1};
        	return result ; 
        }
        if(right==-1)
        {
        	right = num_size;
        }

        vector<int> result = {left+1,right-1};
        return result;
    }
};

int main()
{
	Solution s;
	vector<int> data = {1,4};
	data = s.searchRange(data,4);
	cout<<"["<<data[0]<<","<<data[1]<<"]"<<endl;
}