int maxProfit(int* prices, int pricesSize) {
    int i,maxProfit=0;
    for(i=1;i<pricesSize;i++){
        if(prices[i]>prices[i-1]){
            maxProfit+=prices[i]-prices[i-1];
        }
    }
    return maxProfit;
}
