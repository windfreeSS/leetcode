#include "../all.cpp"

// 二分查找

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0]<=nums[n-1])
        {
            return nums[0];
        }

        int a= 1;
        int b= n;
        while(a<b)
        {
            int mid = a+(b-a)/2;

            if( nums[mid] < nums[mid-1])
            {
                return nums[mid];
            }
            if(nums[mid]>nums[0])
            {
                a = mid+1;
            }
            else
            {
                b = mid;
            }
        }

        return 0;
    }
};