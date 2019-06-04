#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int num_count = nums.size();
        if(num_count==0)
        {
        	return 0;
        }
        if(target <nums[0])
        {
        	return 0;
        }
        else if(target >nums[num_count-1])
        {
        	return num_count;
        }

        int begin = 0;
        int end = num_count;
        while(begin<end)
        {
        	int mid = (begin+end)/2;
        	if(target < nums[mid])
        	{
        		end = mid;
        	}
        	else if(target > nums[mid])
        	{
        		begin =mid+1;
        	}
        	else
        	{
        		return mid;
        	}
        }
        
        return ((begin+end)/2);
    }
};

int main()
{
	Solution s;
	vector<int> data={1,3};
	cout<<s.searchInsert(data,3)<<endl;
}