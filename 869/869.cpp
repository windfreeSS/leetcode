#include "../all.cpp"
// 生成2的幂表，将幂表转换为字母序的字符串列表，
// 将对应数字转换为字符串序列，并按照字母序排序



class Solution {
public:
    string num_to_order_str(int n)
    {
        if(n==0)
        {
            return "0";
        }
        char chs[15]={0};
        int pos =0;
        while(n)
        {
            chs[pos] = n%10 + '0';
            n/=10;
            ++pos;
        }
        sort(chs,chs+pos);  //不需要独立实现排序，使用系统函数即可
        return string(chs);
    }
    vector<string> gen_pow_table()
    {
        vector<string> result;
        result.push_back("1");
        int num = 1;
        for(int i=1;i<31;++i)
        {
            num*=2;
            result.push_back(num_to_order_str(num));
        }
        return result;
    }
    bool reorderedPowerOf2(int N) {
        static vector<string> pow_table = gen_pow_table();
        string find_val = num_to_order_str(N);
        for(int i=0;i<pow_table.size();++i)
        {
            if(find_val == pow_table[i])
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    cout<<s.reorderedPowerOf2(4201)<<endl;
}