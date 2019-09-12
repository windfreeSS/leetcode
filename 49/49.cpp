#include "../all.cpp"
struct str_factor
{
    int cnts[26];
    str_factor()
    {
        memset(this, 0, sizeof(str_factor));
    }
};
bool operator < (const str_factor& first, const str_factor& other)
{
    for (int i = 0; i < 26; ++i)
    {
        if (first.cnts[i] < other.cnts[i])
        {
            return true;
        }
        else if(first.cnts[i] > other.cnts[i])
        {
            return false;
        }
    }
    return false;
}

class Solution {
public:


    str_factor calc_factor(string& data)
    {
        str_factor sf;
        for (int i = 0; i < data.size(); ++i)
        {
            ++sf.cnts[data[i] - 'a'];
        }
        return sf;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<str_factor, vector<string>> str_hash;

        for (int i = 0; i < strs.size(); ++i)
        {
            str_factor tmp = calc_factor(strs[i]);
            str_hash[tmp].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (map<str_factor, vector<string>>::iterator it = str_hash.begin(); it != str_hash.end(); ++it)
        {

            result.push_back(it->second);
        }

        return result;
    }

    vector<vector<string>> groupAnagrams_v1(vector<string>& strs) {
        map<string, vector<string>> str_hash;
        for (int i = 0; i < strs.size(); ++i)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            str_hash[tmp].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for (map<string, vector<string>>::iterator it = str_hash.begin(); it != str_hash.end(); ++it)
        {
            result.push_back(it->second);
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> data = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution s;
    vector<vector<string>> result = s.groupAnagrams(data);
    for (int i = 0; i < result.size(); ++i)
    {
        print(result[i]);
    }

    


    return 0;
}

// 排序，散列