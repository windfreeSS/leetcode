#include "../all.cpp"

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int num_size = nums.size();
        if(num_size==1)
        {
            return 0;
        }
        if(num_size==2)
        {
            return nums[0] > nums[1] ? 0:1;
        }

        int mid;
        int end = num_size-1;
        int begin = 0;
        while(begin<=end)
        {
            mid = (begin+end)/2;
            if(mid>0 && mid <(num_size-1))
            {
                if(nums[mid] <nums[mid+1])
                {
                    begin = mid+1;
                }
                else if (nums[mid] < nums[mid-1])
                {
                    end = mid;
                }
                else 
                {
                    return mid;
                }
            }
            else if(mid==0)
            {
                if(nums[mid]>nums[mid+1])
                {
                    return mid;
                }
                break;
            }
            else if(mid == (num_size-1))
            {
                if(nums[mid]>nums[mid-1])
                {
                    return mid;
                }
                break;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> data = {1,2,3,4,5};
    cout<<s.findPeakElement(data)<<endl;
}

// 可以将序列分成三段，前、中、后。比如x1,x2,x3,x4...xk...xn。
// 对于前半段，可以知道x1 > x0 ，因为x0是负无穷。
// 要想满足x1不是峰值，则必须x1<x2。
// 由此可以推理出，要想满足前p个数没有峰值，则满足x1<x2<x3<x4...<xp
// 
// 对于后半段，可以知道xn > x(n+1)，因为x(n+1)是负无穷
// 要想满足xn不是峰值，则必须x(n-1)>xn。
// 要想满足后q个数没有峰值，则满足x(n-q-1)>x(n-q)>x(n-q+1)....>x(n-1)>xn
// 
// a、现在取中间的数，如果中间的数，已经是峰值，则结束查找，否则进入下一步
// b、如果中间的数小于前面一个数，则在中间数以前的序列中，肯定存在一个峰值
// c、同理，如果中间的数小于后面一个数，则在中间数以后的序列中，肯定存在一个峰值。
// 现在证明b中的逻辑，是如何推导的。假设中间数的位置是k。
// 假设k=p+1，则可以知道，x1<x2<x3<x4...<xp, xp>xp+1，那么xp就是峰值。
// 假设k>p+1,则可以知道，那么前k-1个数，不包含峰值，需要满足 x1<x2<x3<....<xp<x(p+1)...<x(k-1)，对于此种情况，
// 前面假设的前p个，实际上变成了前k-1个，此时，x(k-1)就是峰值。