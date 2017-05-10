class Solution {
public:
    int mySqrt(int x) {
        if(x==0)
            return 0;
        int left=1,right=x,ans;
        while(left<=right){
            int mid=(left+right)/2;
            if(mid<=x/mid){
                left=mid+1;
                ans=mid;
            }
            else{
                right=mid-1;
            }
        }
        return ans;
    }
};

/*

class Solution {
public:
    int mySqrt(int x) {
        if (x==0) 
            return 0;
        double res=1, pre=0;
        while (res!=pre) {
            pre=res;
            res=(res+x/res)/2;
        }
        return int(res);
    }
};

*/
