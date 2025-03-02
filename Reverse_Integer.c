int reverse(int x){
    if (x < INT_MIN || x > INT_MAX) return 0;
    long ans = 0;
    while (x != 0)
    {
        int tmp = x % 10;
        ans = ans*10 + tmp;
        x /= 10;
    }
    if (ans < INT_MIN || ans > INT_MAX) return 0;
    return (int)ans;

}
