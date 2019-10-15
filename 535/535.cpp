#include "../all.cpp"


class Solution {
private:
    map<string,string> url_hash;  
public:
    string int2url(int val)
    {
        static string url_table = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string ret;
        for(int i =0;i<6;++i)
        {
            ret += url_table[val%62];
            val/=62;
        }
        return "http://tinyurl.com/"+ret;
    }
    int url2int(const string& str)
    {
        int ret = 0;
        for(int i=1;i<7;++i)
        {
            ret*=62;
            char ch = str[str.size()-i];
            if(ch>='a' && ch<='z')
            {
                ret += ch-'a';
            }
            else if(ch>='A' && ch<='Z')
            {
                ret += ch-'a'+26;
            }
            else
            {
                ret += ch-'0' + 52;
            }
        }
        return ret;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        static int id = 1;
        string ret  = int2url(id);
        url_hash[ret] = longUrl;
        ++id;
        return ret;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        map<string,string>::iterator it = url_hash.find(shortUrl);
        if(it==url_hash.end())
        {
            return "";
        }
        return it->second;
    }
};

int main()
{
    Solution s;
    for(int i=0;i<500;++i)
    {
        cout<<s.decode(s.encode("https://www.example.net/arithmetic/attraction?back=air"))<<endl;
    }
}

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));