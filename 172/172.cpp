class Solution {
public:
	int factorNumOfFive(int n)
	{
		if(n<5)
		{
			return 0;
		}
		return (n/5+factorNumOfFive(n/5));
	}
    int trailingZeroes(int n) {
        return factorNumOfFive(n);
    }
};