/* There is a fence with n posts, each post can be painted with one of the k colors.

You have to paint all the posts such that no more than two adjacent fence posts have the same color.

Return the total number of ways you can paint the fence.*/

class Solution {
public:
    int numWays(int n, int k) {
        /*Dp problem: 相邻的两个post， 假如第一个有k个选择， 第二个可以选择相同的颜色，也可以选择不同的颜色
         * dp1[0] = k; // different color with previous one
         * dp2[0] = 0; // same color with previous one
         * so until post "0", total number = dp1[0] + dp2[0]
         * final, we return dp1[n-1] + dp2[n-1] ***/
        if( n <= 0 ){
           return 0;
        }
        vector<int> same(n, 0), dif(n, 0);
        same[0] = 0;
        dif[0] = k;
        for(int i = 1; i < n; i++) {
            same[i] = dif[i-1];// can not add same[i-1], it will cause three posts looks the same
            dif[i] = (dif[i-1] + same[i-1]) * (k-1);
        }
        return dif[n-1] + same[n-1];
    }
};













