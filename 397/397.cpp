// 考虑其位模式，
// 对于  1000001 这个二进制数.首先这个数是奇数，如果使用n+1,则变成1000010，倒数第二位由原先的0变成了1，在后面的计算中，相当于增加了次数
// 如果 使用n-1，则变成了1000000，不会新增次数
// 相反，对于 1111111这样形式的，如果使用 n+1，则变成10000000，则原先中间的奇数，都不需要再处理。
#include "../all.cpp"
class Solution {
public:
    int integerReplacement(int n) {
       if(n==1)
       {
        return 0;
       }
       if(n==3)
       {//此处是为了解决 n+1 处理的错误逻辑。如果n=3，则会被处理为 2次 + integerReplacement(2) = 3次。
        return 2;
       }
       if((n&0x01)==0)
       {
            return 1 + integerReplacement(n>>1);
       }
       if( ( (n&0x02)==0x02) )
       { // n+1
            return 2+integerReplacement( (n>>1)+1);
       }
       else
       {
            return 2+integerReplacement(n>>1);
       }

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    printf("%d\n",s.integerReplacement(100000000));
    return 0;
}