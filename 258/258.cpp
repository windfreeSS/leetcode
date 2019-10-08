
// 找规律

class Solution {
public:
    int addDigits(int num) {
        if(num<10)
        {
            return num;
        }
        return (num-10)%9+1;
    }
};