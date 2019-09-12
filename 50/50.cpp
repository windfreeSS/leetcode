class Solution {
public:
    double myPow(double x, int n) {
        const double precision = 0.000001;
        if ( abs(x) < precision )
        {
            return 0.0;
        }
        if ( abs(x - 1) < precision )
        {
            return 1.0;
        }
        if ( abs(x + 1) < precision )
        {
            return (n % 2 == 0) ? 1.0 : -1.0;
        }

        if(n<0)
        {
            x = 1/x;
        }

        double result = 1;
        long long abs_n = n;
        bool is_positive = abs_n >= 0;
        abs_n = is_positive ? abs_n : -abs_n;

        for (long long i = 0; i < abs_n; ++i)
        {
            result *= x;
            if ( abs(result) < precision )
            {
                return 0.0;
            }
        }
        return result;
    }
};

