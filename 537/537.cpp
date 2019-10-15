using complexNum = pair<int,int>;
class Solution {
public:
    // 直接根据公式 (a+bi)(c+di) = ac-bd + (ad+bc)i
    complexNum parse_str(const string& str)
    {
        complexNum cn;
        sscanf(str.c_str(),"%d+%di",&cn.first,&cn.second);
        return cn;
    }
    string complexNumberMultiply(string a, string b) {
        complexNum ca = parse_str(a);
        complexNum cb = parse_str(b);

        complexNum result;
        result.first = ca.first*cb.first - ca.second*cb.second;
        result.second = ca.first * cb.second + ca.second*cb.first;

        char chs[100]={0};
        sprintf(chs,"%d+%di",result.first,result.second);

        return chs;

    }
};