#include "../all.cpp"
// 尾部交替插入最大值，最小值，次大值，次小值 比如对于 1、2、3、4、5、6，则使用，3、4、2、5、1、6
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int small_num=1;
        int big_num = n;
        int fixed_count = (n-1-k);

        vector<int> result(n,0);
        for(int i=0;i<fixed_count;++i)
        {
            result[i]=i+1;
            ++small_num;
        }
        while(small_num < big_num)
        {
            int indx = 2*big_num-n-1;
            result[indx] = big_num;
            result[indx-1] = small_num;
            --big_num;
            ++small_num;
        }
        if(k%2==0)
        {
            result[2*big_num-n-1] = big_num;
        }
        return result;


    }
};

int main()
{
    Solution s;
    vector<int> data = s.constructArray(6,5);
    print(data);

}