class Solution {
public:
    int get_level(int val)
    {// 1 是在第一层
        int l = 0;
        while(val)
        {
            val >>= 1;
            ++l;
        }
        return l;
    }
    int get_lvl_num(int lvl,int seq)
    { //lvl从1开始 seq 从0开始
        if( (lvl&0x01)==0 )
        {//even
            return (1<<lvl) - seq-1;
        }
        else
        {
            return (1 << (lvl-1))+seq;
        }
    }
    vector<int> pathInZigZagTree(int label) {
    
        int lable_lvl = get_level(label);
        int seq;
        if( (lable_lvl&0x01) ==0)
        {//even
            seq = (1<<lable_lvl)-label - 1;
        }   
        else
        {//odd
            seq = label - (1<<(lable_lvl-1));
        }
        vector<int> result(lable_lvl);
        while(lable_lvl>0)
        {
            result[lable_lvl-1] = get_lvl_num(lable_lvl,seq);
            --lable_lvl;
            seq >>=1;
        }
        return result;
    }
};

// 找规律