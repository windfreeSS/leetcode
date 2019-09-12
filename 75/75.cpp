#include "../all.cpp"
using namespace std;

// 分成三个区间，[0,white) [white,blue) [blue,pos]，遍历的时候，交换边界位置
// 比如下一个点是白色，则先修改蓝色的区间为 [blue+1,pos]，再修改白色的区间是[white,blue+1)。
// 如果是红色，先修改蓝色的区间是[blue+1,pos]，在修改白色的为[white+1,blue+1)。最后修改红色的为[0,white+1)。
// 注意边界值的处理即可
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int white = 0;
        int blue = 0;
        int pos = 0;
        int num_len = nums.size();

        while (pos < num_len)
        {
            if (nums[pos] == 1)
            {   //white
                if (pos != blue)
                {
                    nums[pos]=2;
                    nums[blue]=1;
                    ++blue;
                }
                else
                {
                    ++blue;
                }
            }
            else if (nums[pos] == 0)
            {   //red
                if (pos != blue)
                {
                    nums[pos]=2;
                    nums[blue]=0;
                    ++blue;
                }
                else
                {
                    ++blue;
                }
                if( white!= (blue-1))
                {
                    nums[white]=0;
                    nums[blue-1]=1;
                    ++white;
                }
                else
                {
                    ++white;
                }
            }
            ++pos;
        }

    }
};

int main(int argc, char const *argv[])
{
    vector<int> data = {2,0,2,1,1,0};
    Solution s;
    s.sortColors(data);
    print(data);
    return 0;
}