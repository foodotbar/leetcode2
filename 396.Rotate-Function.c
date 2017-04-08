int maxRotateFunction(int* A, int ASize) {
    int i=0,j=0,F=0,allsum=0,max=0;
    for(i=0;i<ASize;i++){
        F+=i*A[i];
        allsum+=A[i];
    }
    max=F;
    for(i=1;i<ASize;i++){
        F=F+allsum-ASize*A[ASize-i];
        if(F>max)
            max=F;
    }
    return max;
}
