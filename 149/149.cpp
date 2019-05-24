#include <vector>
#include <map>
#include <iostream>
#include <cmath>
using namespace std;

struct linear_equation_factor
{
    double k;
    double b;
    linear_equation_factor(): k(0), b(0) {}

};

bool operator < (const linear_equation_factor& first , const linear_equation_factor& other)
{
    if (fabs(first.k - other.k) > 1e-10) // difference k
    {
        return first.k < other.k;
    }
    if (fabs(first.b - other.b) > 1e-10)
    {
        return first.b < other.b;
    }
    return false;

}
class Solution {
public:

    int maxPoints(vector<vector<int>>& points) {
        map<int, int> parallel_x_axis; //first:y val,second:count
        map<int, int> parallel_y_axis; //first x val,second:count
        map<linear_equation_factor, int> slash_lines;

        int point_num = points.size();
        if (point_num < 2)
        {
            return point_num;
        }

        for (int i = 0; i < point_num - 1; ++i)
        {
            for (int j = i + 1; j < point_num; ++j)
            {
                if ( points[i][0] == points[j][0] ) //same x
                {
                    parallel_y_axis[points[i][0]] += 1;
                }
                else if (points[i][1] == points[j][1]) //same y
                {
                    parallel_x_axis[points[i][1]] += 1;
                }
                else //calc k and b
                {
                    linear_equation_factor line;
                    line.k = double(points[j][1] - points[i][1]) / double(points[j][0] - points[i][0]);
                    if (points[i][1] == 0)
                    {
                        line.b = (double)points[i][0];
                    }
                    else if (points[j][1] == 0)
                    {
                        line.b = (double)points[j][0];
                    }
                    else
                    {
                        line.b = points[j][0] - double(points[j][1]) / line.k;
                    }
                    slash_lines[line] = slash_lines[line] + 1;
                }
            }
        }
        int line_counts = 0;
        for (map<int, int>::iterator it = parallel_x_axis.begin(); it != parallel_x_axis.end(); ++it)
        {
            if (it->second > line_counts)
            {
                line_counts = it->second;
            }
        }
        for (map<int, int>::iterator it = parallel_y_axis.begin(); it != parallel_y_axis.end(); ++it)
        {
            if (it->second > line_counts)
            {
                line_counts = it->second;
            }
        }
        for (map<linear_equation_factor, int>::iterator it = slash_lines.begin(); it != slash_lines.end(); ++it)
        {
            if (it->second > line_counts)
            {
                line_counts = it->second;
            }
        }
        return line_counts;
        int line_real_num = 1;
        while (true)
        {
            int n_val = (line_real_num + 1) * line_real_num / 2;
            if (n_val == line_counts)
            {
                break;
            }
            ++line_real_num;
        }

        return (line_real_num + 1);
    }
};

int main()
{
    vector<vector<int>> data = { {0, 0}, {1, 1}, {0, 0}};
    Solution s;
    cout << s.maxPoints(data) << endl;
    return 0;
}