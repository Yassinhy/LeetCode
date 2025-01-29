double func (double X, int Y)
{
    return (X - (X*X - Y)/(2*X));
}

int mySqrt(int x) {
    double initial_guess = x/2;
    if (x == 0 || x == 1)
    {
        return x;
    }
    for (int i = 0; i < 19; i++ )
    {
        initial_guess = func(initial_guess, x);
    }
    int ans = (int)floor(initial_guess);
    return ans;
}
