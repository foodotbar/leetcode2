void merge(int* nums1, int m, int* nums2, int n) {
    if(m==0&&n!=0){
        for(int t=0;t<n;t++)
            nums1[t]=nums2[t];
        return;
    }
    if(n==0){
        return;
    }
    if(m!=0&&n!=0){
    int* tmp=(int*)malloc(m*sizeof(int));
    for(int z=0;z<m;z++)
        tmp[z]=nums1[z];
    int i=0,j=0,k=0;
    for(i=0;i<m+n;i++){
        if(j>m-1||k>n-1)
            break;
        if(tmp[j]>nums2[k])
            nums1[i]=nums2[k++];
        else
            nums1[i]=tmp[j++];
    }
    while(j<m){
        nums1[i++]=tmp[j++];
    }
    while(k<n){
        nums1[i++]=nums2[k++];
    }
    }
}
