#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int begin = 0;
        int end = nums.size()-1;

        while(begin<=end)
        {
        	if(nums[begin]==val)
        	{
        		while(begin<=end)
        		{
        			if(nums[end]!=val)
        			{
        				break;
        			}
        			--end;
        		}
        		if(begin>end)
        		{
        			break;
        		}
        		int tmp = nums[begin];
        		nums[begin]=nums[end];
        		nums[end]=tmp;
        		++begin;
        		--end;
        	}
        	else
        	{
        		++begin;
        	}
        }
        return (end+1);

    }
};

int main()
{
	Solution s;
	vector<int> data ={0,1,2,2,3,0,4,2};
	cout<<s.removeElement(data,2)<<endl;
}