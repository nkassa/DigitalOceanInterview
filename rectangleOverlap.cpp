class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) 
    {
        int x1 = rect1[0];
        int x2 = rect1[2];

        int x3 = rect2[0];
        int x4 = rect2[2];

        int y1 = rect1[1];
        int y2 = rect1[3];

        int y3 = rect2[1];
        int y4 = rect2[3];

        if(x2 <= x3 || x4 <= x1)
        {
            return false;
        }

        if(y2 <= y3 || y4 <= y1)
        {
            return false;
        }

        if(x1 == x2 || x3 == x4 || y1 == y2 || y3 == y4)
        {
            return false;
        }
        return true;
    }
};