/*
int reverse(int x) {
    long i=0,sum=0;
    while(x!=0){
        sum=sum*10+x%10;
        x/=10;
    }
    return (sum<INT_MIN || sum>INT_MAX) ? 0 : sum;
}
*/
int reverse(int x) {
    int ans = 0;
    while (x) {
        int temp = ans * 10 + x % 10;
        if (temp / 10 != ans)
            return 0;
        ans = temp;
        x /= 10;
    }
    return ans;
}
