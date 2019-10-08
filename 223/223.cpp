#include "../all.cpp"

// 根据两个矩形的相对关系，进行分类

class Solution {
public:
    int left_intersect_right(int l_x0, int l_y0, int l_x1, int l_y1, int r_x0, int r_y0, int r_x1, int r_y1)
    {
        int intersect_area = 0;
        if (r_y0 >= l_y1
                || l_y0 >= r_y1)
        {   // 上下不重叠
        }
        else if (r_x0 >= l_x1)
        {   //左右不重叠
        }
        else
        {
            int h = min(r_y1, l_y1) - max(l_y0, r_y0);
            int w = min(r_x1, l_x1) - r_x0;
            intersect_area = h * w;
        }
        return (l_x1 - l_x0) * (l_y1 - l_y0) - intersect_area + (r_x1 - r_x0) * (r_y1 - r_y0);
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if (A < E)
        {
            return left_intersect_right(A, B, C, D, E, F, G, H);
        }
        else
        {
            return left_intersect_right(E, F, G, H, A, B, C, D);
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}