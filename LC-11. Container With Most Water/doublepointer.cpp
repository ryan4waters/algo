class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp=0;
        int rp=height.size()-1;
        int res=min(height[lp],height[rp]) * (rp-lp);
        while (lp < rp) {
            if (height[lp] < height[rp]) {
                res=max(res,min(height[++lp],height[rp]) * (rp-lp));
            } else {
                res=max(res,min(height[lp],height[--rp]) * (rp-lp));
            }
        }
        return res;
    }
};
