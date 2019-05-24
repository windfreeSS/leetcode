#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
	int findKthSmallest(vector<int>&nums ,int k)
	{
		int num_size = nums.size();
		for(int i=0;i<k;++i)
        {
        	for(int j = 1;j<num_size-i;++j)
        	{
        		if(nums[j]>nums[j-1])
        		{
        			nums[j-1]=nums[j-1]^nums[j];
        			nums[j] = nums[j-1]^nums[j];
        			nums[j-1]=nums[j-1]^nums[j];
        		}
        	}
        }
        return nums[num_size-k];
	}
    int findKthLargest(vector<int>& nums, int k) {
        int num_size = nums.size();

        if( k> (num_size/2))
        {
        	return findKthSmallest(nums,num_size-k+1);
        }

        for(int i=0;i<k;++i)
        {
        	for(int j = 1;j<num_size-i;++j)
        	{
        		if(nums[j]<nums[j-1])
        		{
        			nums[j-1]=nums[j-1]^nums[j];
        			nums[j] = nums[j-1]^nums[j];
        			nums[j-1]=nums[j-1]^nums[j];
        		}
        	}
        }
        return nums[num_size-k];
    }
};
void print(vector<int> data)
{
	for(int i=0;i<data.size();++i)
	{
		cout<<data[i]<<",";
	}
	cout<<endl;
}

int main()
{
	vector<int> data = {7,6,5,4,3,2,1};
	Solution s;
	cout<<s.findKthLargest(data,2)<<endl;
	print(data);

}