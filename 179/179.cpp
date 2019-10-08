#include "../all.cpp"


// 刚开始的时候，一直错在small_than的函数中，没有使用(s1+s2)这种最直接的形式，而是想通过不拼接字符串判断。
// 但是没有找到好的方法
class Solution {
public:
    bool small_than(const string& s1, const string& s2)
    {
        return (s1+s2)<=(s2+s1);  
    }
    void quick_sort(vector<string>& datas, int a, int b)
    {
        if (a >= (b - 1))
        {
            return ;
        }
        int ai = a + 1;
        int bi = b - 1;
        while (true)
        {
            while (ai <= bi && small_than(datas[ai], datas[a]))
            {
                ++ai;
            }
            while (bi >= ai && small_than(datas[a], datas[bi]))
            {
                --bi;
            }
            if (ai >= bi)
            {
                break;
            }
            string tmp = datas[ai];
            datas[ai] = datas[bi];
            datas[bi] = tmp;
        }
        string tmp = datas[a];
        datas[a] = datas[bi];
        datas[bi] = tmp;
        quick_sort(datas, a, bi);
        quick_sort(datas, bi+1, b);

    }
    string largestNumber(vector<int>& nums) {
        if (nums.empty())
        {
            return "0";
        }

        vector<string> strs;
        for (int i = 0; i < nums.size(); ++i)
        {
            char chs[20] = {0};
            sprintf(chs, "%d", nums[i]);
            strs.push_back(chs);
        }
        quick_sort(strs, 0, strs.size());

        string ret;
        for (int i = strs.size() - 1; i >= 0; --i)
        {
            ret += strs[i];
        }

        size_t pos = ret.find_first_not_of('0');
        if(pos==string::npos)
        {
            return "0";
        }
        return ret.substr(pos);

    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> data = {1,1,1};
    cout << s.largestNumber(data) << endl;
    return 0;
}