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



struct line_data
{
    int first_x;
    int first_y;
    int count;
    bool is_valid;
    long y_minus_y1;
    long x_minus_x1;
};


class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int point_count = points.size();
        if(point_count<3)
        {
            return point_count;
        }

        vector<line_data> parallel_y;
        vector<line_data> slash_lines;

        for(int i=0;i<point_count;++i)
        {
            // update y 
            bool has_same_x = false;
            int y_counts = parallel_y.size();
            for(int y=0;y<y_counts;++y)
            {
                if(points[i][0]==parallel_y[y].first_x)
                {
                    has_same_x=true;
                    ++parallel_y[y].count;
                    break;
                }
            }
            if(!has_same_x)
            {
                line_data one_p;
                one_p.first_x=points[i][0];
                one_p.count=1;
                parallel_y.push_back(one_p);
            }

            // update slash line 
            int slash_size = slash_lines.size();
            for(int x=0;x<slash_size;++x)
            {
                if(slash_lines[x].first_x==points[i][0] && slash_lines[x].first_y==points[i][1])
                {// same point
                    ++slash_lines[x].count;
                    continue;
                }
                else if(slash_lines[x].first_x==points[i][0])
                {//same x ,parallel to y
                    continue;
                }
                else 
                {
                    long x_minus = slash_lines[x].first_x-points[i][0];
                    long y_minus = slash_lines[x].first_y-points[i][1];
                    if(!slash_lines[x].is_valid)
                    {//single point 
                         line_data one_p = slash_lines[x];
                         ++one_p.count;
                         one_p.is_valid= true;
                         one_p.x_minus_x1 = x_minus;
                         one_p.y_minus_y1 = y_minus;
                         slash_lines.push_back(one_p);
                    }
                    else if( x_minus*slash_lines[x].y_minus_y1 == y_minus*slash_lines[x].x_minus_x1 )
                    {//line 
                        ++slash_lines[x].count;
                    }
                    continue;
                }
                
            }
            line_data one_p;
            one_p.is_valid=false;
            one_p.first_x = points[i][0];
            one_p.first_y = points[i][1];
            one_p.count=1;
            slash_lines.push_back(one_p);
        }
        int the_max_point=0;
        for(int i=0;i<parallel_y.size();++i)
        {
            if(parallel_y[i].count>the_max_point)
            {
                the_max_point=parallel_y[i].count;
            }
        }
        for(int i=0;i<slash_lines.size();++i)
        {
            if(slash_lines[i].count>the_max_point)
            {
                the_max_point=slash_lines[i].count;
            }
        }
        return the_max_point;
    }
};


class Solution_V1 {
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
    vector<vector<int>> data = { {0,0},{94911151,94911150},{94911152,94911151}};
    Solution s;
    cout << s.maxPoints(data) << endl;
    // double result =(double)94911150/(double)94911151;
    // cout<< (fabs(result-1)< 1e-10)<<endl;
    return 0;
}