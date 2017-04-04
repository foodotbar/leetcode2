int maxArea(int* height, int heightSize) {
    int water=0,i=0,j=heightSize-1;
    while(i < j){
        int max=(j-i)*(height[i]<height[j]?height[i]:height[j]);
        water=water>max?water:max;
        if (height[i] < height[j])
            i += 1;
        else
            j -= 1;
    }
    return water;
}
