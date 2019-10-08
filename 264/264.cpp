

// 找规律,2，3，5个数的变化规律
class Solution {
public:
    void calc_pow(int&a,int&b,int&c,int n)
    {
        if(n<=0)
        {
            return ;
        }
        if(c>0)
        {
            --c;
            ++a;
            ++b;
        }
        else if(b>0)
        {
            --b;
            a+=2;
        }
        else
        {
            
        }

        return calc_pow(a,b,c,n-1);
    }
    int nthUglyNumber(int n) {
        int a,b,c;
        a=b=c=0;
        calc_pow(a,b,c,n);
    }
};