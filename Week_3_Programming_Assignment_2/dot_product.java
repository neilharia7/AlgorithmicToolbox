import java.util.*;
import java.lang.*;
import java.io.*;

class  MaximizeRevenue {
    private static long maxProduct(int[] a, int[] b) {
        long result = 0;
        Arrays.sort(a);
        Arrays.sort(b);
        for (int i = 0; i < a.length; i++) {
            result += (long) a[i] * (long) b[i];
        }
        return result;
    }
    public static void main(String[] args) throws java.lang.Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[1000];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int b[] = new int[1000];
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        System.out.println(maxProduct(a, b));
    }
}
