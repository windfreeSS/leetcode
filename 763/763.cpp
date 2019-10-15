
class Solution {
public:
    vector<int> partitionLabels(string S) {
        using Section = pair<int,int>;  //[first, second]
        int n = S.size();
        vector<bool> flag(26,true);
        vector<Section> vs(26,Section(-1,-1));
        for(int i=0;i<n;++i)
        {
            int idx = S[i]-'a';
            flag[idx] = false;
            if(vs[idx].first==-1)
            {
                vs[idx].first = i;
            }
            if(i>vs[idx].second)
            {
                vs[idx].second = i;
            }
        }

        vector<int> ret;
        int start = S[0]-'a';
        flag[start] = true;
        while(start<26)
        {
            int end = vs[start].second;
            while(true)
            {
                bool is_overlapped = false;    
                for(int i=0;i<26;++i)
                {
                    if(flag[i])
                    {
                        continue;
                    }
                    if(vs[i].first>end)
                    {
                        continue;
                    }
                    flag[i] = true;
                    is_overlapped = true;
                    end = std::max(end,vs[i].second);
                    break;
                }
                if(!is_overlapped)
                {
                    break;
                }
            }
            ret.push_back(end-vs[start].first+1);
            start = 27;
            for(int i=0;i<26;++i)
            {
                if(flag[i])
                {
                    continue;
                }
                if(vs[i].first==(end+1))
                {
                    start = i;
                    flag[start]=true;
                    break;
                }
            }
            
        }
        return ret;
    }
};