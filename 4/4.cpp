#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    // 主要思想是进行逐步向中间数据靠拢，缩小查找范围
    int getkth(vector<int>::iterator v1_it, int v1_size, vector<int>::iterator v2_it, int v2_size, int k)
    {
        if (v1_size > v2_size )
        {
            return getkth( v2_it, v2_size, v1_it, v1_size, k);
        }
        if (v1_size == 0)
        {
            return *(v2_it + k - 1);
        }
        if (k == 1)
        {
            return min(*v1_it, *v2_it);
        }
        int v1_k = min(v1_size,k/2);
        int v2_k = min(v2_size,k/2);
        if( *(v1_it+v1_k-1) > *(v2_it+v2_k-1) )
        {
            advance(v2_it,v2_k);
            return getkth(v1_it,v1_size,v2_it,v2_size-v2_k,k-v2_k);
        }
        else
        {
            advance(v1_it,v1_k);
            return getkth(v1_it,v1_size-v1_k,v2_it,v2_size,k-v1_k);
        }
        return -1;

    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_size = nums1.size()+nums2.size();
        int left_pos = (total_size+1)>>1;   
        int right_pos = (total_size+2)>>1;  
        vector<int>::iterator it_1 = nums1.begin();
        vector<int>::iterator it_2 = nums2.begin();

        int left_val = getkth(it_1,nums1.size(),it_2,nums2.size(),left_pos);
        int  right_val= getkth(it_1,nums1.size(),it_2,nums2.size(),right_pos);

        return (left_val +right_val)/2.0;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> v1,v2;
    v1.push_back(2);
    v2.push_back(1);
    v2.push_back(3);

    Solution sv;
    sv.findMedianSortedArrays(v1,v2);
    return 0;
}