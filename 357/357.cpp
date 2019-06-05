#include "../all.cpp"

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return 10;
        }
        if(n==2)
        {
            return 91;
        }
        if(n>=10)
        {
            n=9;
        }
        int valid_count = 91;
        for(int i = 3;i<=n;++i)
        {
            int not_same_num = 9;
            for(int j=0;j<i-1;++j)
            {
                not_same_num *= (9-j);
            }
            valid_count += not_same_num;
        }

        return (valid_count);
    }
};

int main()
{
    Solution s;
    cout<<s.countNumbersWithUniqueDigits(9)<<endl;
}