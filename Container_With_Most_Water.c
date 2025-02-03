static inline int max(int a, int b) {
    return (a > b) ? a : b;
}
static inline int min(int a, int b) {
    return (a < b) ? a : b;
}


int maxArea(int* nums, int heightSize) {
    int pointer1_Index = 0;
    int pointer2_Index = heightSize - 1;
    int area;

    while (pointer1_Index < pointer2_Index)
    {
        int height = min(nums[pointer1_Index], nums[pointer2_Index]);
        int width = (pointer2_Index - pointer1_Index);
        area = max(area, height * width);
         if (nums[pointer1_Index] < nums[pointer2_Index]) {
            pointer1_Index++;
        } else {
            pointer2_Index--;
        }
    }
    return area;
}
