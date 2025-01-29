void MergeArrays (int nums1[], int nums1Size, int nums2[], int nums2Size, int sum[])
{
    int i = 0, j = 0, k = 0;
    while (i < nums1Size && j < nums2Size)
    {
        if (nums1[i] < nums2[j])
        {
            sum[k] = nums1[i];
            i++;
            k++;
        }
        else if (nums1[i] > nums2[j])
        {
            sum[k] = nums2[j];
            j++;
            k++;
        }
        else
        {
            sum[k] = nums1[i];
            i++;
            k++;
            sum[k] = nums2[j];
            j++;
            k++;
        }
    }
    while (i < nums1Size)
    {
        sum[k] = nums1[i];
        i++;
        k++;
    }
    while (j < nums2Size)
    {
        sum[k] = nums2[j];
        j++;
        k++;
    }
    
}



double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    int loo = nums1Size + nums2Size;
    int roo = loo/2;
    int sum[loo];
    MergeArrays(nums1, nums1Size, nums2, nums2Size, sum);
    if ( loo % 2 == 1)
    {
        return sum[loo/2];
    }
    else
    {
        return (sum[loo/2 - 1] + sum[(loo/2)]) / 2.0 ;
    }
}
