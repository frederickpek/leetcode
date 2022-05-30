import java.math.BigInteger;

class Solution {
    public int divide(int dividend, int divisor) {
        BigInteger top = BigInteger.valueOf(dividend);
        BigInteger btm = BigInteger.valueOf(divisor);
        BigInteger res = top.divide(btm);
        long ans = res.longValue();
        return (int)Math.max(ans, -2e31);
    }
}