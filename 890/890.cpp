class Solution {
public:
    string get_mapstr(string& str)
    {
        map<char,char> hash_chs;
        int hash_count = -1;
        string result;
        vector<bool> flag(255,false);
        
        for(int i=0;i<str.size();++i)
        {
            if(!flag[str[i]])
            {
                ++hash_count;
                hash_chs[str[i]] = hash_count+'a';
                flag[str[i]] = true;
            }
            result += hash_chs[str[i]];
        }
        return result;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string p_m = get_mapstr(pattern);
        vector<string> result;
        for(int i=0;i<words.size();++i)
        {
            string word_m = get_mapstr(words[i]);
            if(word_m == p_m)
            {
                result.push_back(words[i]);
            }
        }
        return result;
    }
};