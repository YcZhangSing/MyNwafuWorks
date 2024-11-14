public class Number {
    public static String primeNumber(int n)
    {
        int k=2;
        String rs = n+"=";
        while(k<=n) {
            if(k==n) {
                rs=rs+n;
                break;
            } else {
                if(n%k==0) {
                    rs=rs+k+"*";
                    n/=n/k;
                } else {
                    k++;
                }
            }
        }
        return rs;
    }
}
