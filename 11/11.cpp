#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size()==2)
        {
            return min(height[0],height[1]);
        }

        int left_idx = 0;
        int right_idx = height.size()-1;
        int max_area=0;
        while(true)
        {
            if(left_idx>=right_idx)
            {
                break;
            }
            int current_area = (right_idx-left_idx)*(min(height[left_idx],height[right_idx]));
            if(current_area>max_area)
            {
                max_area=current_area;
            }
            if(height[left_idx] < height[right_idx])
            {
                ++left_idx;
            }
            else
            {
                --right_idx;
            }
        }

        return max_area;
    }
};

int main()
{
    vector<int> vals ={1,8,6,2,5,4,8,3,7};
    Solution s;
    cout<<s.maxArea(vals)<<endl;
}


/**
 * https://leetcode-cn.com/problems/container-with-most-water/
 * 对于x轴排好顺序的边，比如a,b,c,d,e
 * 现在来考察a和e围成的区域，可以知道，区域面积等于a与e之间的x轴距离，乘以a与e中的较小者。
 * 现在假设a是较小的边，那么不难推出：
 * a，e围成的区域，是以a作为一边时，能围成的最大区域。
 * 因为与b、c、d边组成区域计算的时候，高度最多是a(超过a，以a计算高度)，而宽度(x轴间距)不断变小，所以a与e围成的边，是a能围成的最大的区域。
 * 那么，就可以知道，不需要在计算a与其他边了，下一个从b重新开始这个计算过程就可以了。 
 */