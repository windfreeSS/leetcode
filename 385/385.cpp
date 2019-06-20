
class Solution {
public:
    NestedInteger deserialize_sub(const string& s, int& pos)
    {
        NestedInteger ni;
        ++pos;
        while (pos < s.size())
        {
            if (s[pos] == '[')
            {
                ni.add(deserialize_sub(s, pos));
                ++pos;
                continue;
            }
            if(s[pos] == ']')
            {
                return ni;
            }
            if(s[pos]==',')
            {
                ++pos;
                continue;
            }

            for (int i = pos + 1; i < s.size(); ++i)
            {
                if (s[i] == ',')
                {
                    int num = atoi(s.substr(pos,i-pos).c_str());
                    ni.add(NestedInteger(num));
                    pos = i+1;
                    break;
                }
                else if (s[i] == ']')
                {
                    int num = atoi(s.substr(pos,i-pos).c_str());
                    ni.add(NestedInteger(num));
                    pos = i;
                    return ni;
                }
            }
        }
        return ni;
    }
    NestedInteger deserialize(string s) {
        if ( s[0] == '-' ||
                (s[0] >= '0' && s[0] <= '9')
           )
        {
            int num = atoi(s.c_str());
            return NestedInteger(num);
        }
        int pos = 0;
        return deserialize_sub(s, pos);
    }
};