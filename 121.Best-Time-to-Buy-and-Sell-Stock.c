int maxProfit(int* prices, int pricesSize) {
    int i=0,j=0,tmpmaxprofit=0;
    for(i=0;i<pricesSize;i++){
        for(j=0;j<i;j++){
            if(prices[i]-prices[j]>=tmpmaxprofit)
                tmpmaxprofit=prices[i]-prices[j];
        }
    }
    return tmpmaxprofit;
}
