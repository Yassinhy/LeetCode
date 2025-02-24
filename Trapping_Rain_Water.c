#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))


int trap(int* height, int heightSize) {
    int total = 0;
    int l = 0;
    int r = heightSize - 1;

    while (height[l] == 0 && l < r) l++;
    while (height[r] == 0 && l < r) r--;

    int max_left = height[l];
    int max_right = height[r];

    while (l < r)
    {	
        if (max_left < max_right)
        {
            l++;
            max_left = MAX(height[l], max_left);
            total += MAX(0, (max_left - height[l]));
        }
        else
        {
            r--;
            max_right = MAX(height[r], max_right);
            total += MAX(0, (max_right - height[r]));
        }
    }

    return total;
}
