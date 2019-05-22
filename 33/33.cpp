#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:

    int search(vector<int>& nums, int target) {
        int begin = 0;
        int end = nums.size();
        if(end==0)
        {
            return -1;
        }
        else if(end==1)
        {
            if(nums[0]==target)
            {
                return 0;
            }
            return -1;
        }
        int rotate_pos = -1;
        if(nums[0]>nums[end-1])
        {
            // find rotate pos 
            while(begin < end)
            {
                rotate_pos = (begin+end)/2;
                cout<<"ro,"<<rotate_pos<<"being,"<<begin<<",end,"<<end<<endl;
                 if( nums[rotate_pos] > nums[end-1])
                {
                    if(nums[rotate_pos]>nums[rotate_pos+1])
                    {
                        break;
                    }
                    begin = rotate_pos+1;
                    continue;
                }
                else if(nums[rotate_pos] > nums[begin])
                {
                    rotate_pos = end-1;
                    break;
                }
                else if( rotate_pos == (end-1) )
                {
                    if(nums[rotate_pos] > nums[begin])
                    {
                        break;
                    }
                    else
                    {
                        end=rotate_pos;    
                    }
                    continue;
                }
                else
                {
                    
                    end = rotate_pos;
                    continue;
                }
            }
        }
        
        begin=0;
        end=nums.size();
        if(rotate_pos!=-1)
        {
            if(target > nums[0])
            {
                end = rotate_pos+1;
            }
            else if(target < nums[nums.size()-1])
            {
                begin=rotate_pos+1;
            }
            else if(target ==nums[0])
            {
                return 0;
            }
            else if(target ==nums[nums.size()-1])
            {
                return nums.size()-1;
            }
            else
            {
                return -1;
            }
        }

        // binary search
        while (begin < end)
        {
            int mid = (begin + end) / 2;
            if (nums[mid] > target)
            {
                end = mid;
                continue;
            }
            else if (nums[mid] < target)
            {
                begin = mid + 1;
                continue;
            }
            else
            {
                return mid;
            }
        }
        return -1;

    }
};


int main()
{
    
    Solution s;
    vector<int> data = {5,1,2,3,4};
    // vector<int> data = {8,9,2,3,4};
    cout << s.search(data, 1) << endl;
}