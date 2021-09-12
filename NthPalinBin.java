import java.io.*;
import java.util.*;

public class Main {

    public static int getRev(int n) {
        int rev = 0;
        for (int i = 0; i < 32; i++) {
            rev <<= 1;
            if ((n & 1) == 1)
                ++rev;
            n >>= 1;
            if (n == 0)
                break;
        }
        return rev;
    }

    public static int NthPalindromicBinary(int n) {
        // write your code here
        int count = 1, len = 1;
        while (count < n) {
            ++len;
            int elementsForThisLen = (1 << ((len - 1) / 2));
            count += elementsForThisLen;
        }
        count -= (1 << ((len - 1) / 2));
        int offset = n - count - 1;
        int ans = (1 << (len - 1));
        ans |= (offset << (len / 2));
        int valFR = ans >> (len / 2);
        int rev = getRev(valFR);
        ans |= rev;
        return ans;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        System.out.println(NthPalindromicBinary(n));
    }

}