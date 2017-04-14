class Solution {
public:
    int climbStairs(int n) {
        int counter = 1, prv = 0;
        for( int i = 1; i <= n ; i++ ){
            int tmp = counter;
            counter += prv;
            prv = tmp;
        }
        return counter;
    }
};
