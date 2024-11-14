#include <stdio.h>
#include <string.h>
#include <math.h>

double fac[105];
int main(void)
{
    double x, ans;
    int i;
    fac[1] = 1;
    scanf("%lf", &x);
    for(i = 2; i < 105; ++i)
        fac[i] = i*fac[i-1];
    ans = 1-x;
    for(i = 2; i < 100; ++i) {
        ans += ( (pow(-1, i) * pow(x, i)) / fac[i]);
    }
    printf("%lf\n", ans);
    return 0;
}
