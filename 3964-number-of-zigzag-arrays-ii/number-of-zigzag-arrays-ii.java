class Solution {

    static final int MOD = 1_000_000_007;

    public int zigZagArrays(int n, int l, int r) {

        int m = r - l + 1;
        int sz = 2 * m;

        long[] base = new long[sz];

        for (int i = 0; i < m; i++) {
            base[i] = m - 1 - i;
            base[m + i] = i;
        }

        if (n == 2) {
            long ans = 0;
            for (long x : base)
                ans = (ans + x) % MOD;
            return (int) ans;
        }

        long[][] trans = new long[sz][sz];

        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                trans[i][m + j] = 1;
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                trans[m + i][j] = 1;
            }
        }

        long[][] power = matrixPower(trans, n - 2);

        long[] result = multiply(power, base);

        long ans = 0;
        for (long x : result)
            ans = (ans + x) % MOD;

        return (int) ans;
    }

    private long[][] matrixPower(long[][] mat, long exp) {

        int n = mat.length;

        long[][] res = new long[n][n];

        for (int i = 0; i < n; i++)
            res[i][i] = 1;

        while (exp > 0) {

            if ((exp & 1) == 1)
                res = multiply(res, mat);

            mat = multiply(mat, mat);

            exp >>= 1;
        }

        return res;
    }

    private long[][] multiply(long[][] A, long[][] B) {

        int n = A.length;

        long[][] C = new long[n][n];

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {

                if (A[i][k] == 0)
                    continue;

                long val = A[i][k];

                for (int j = 0; j < n; j++) {

                    if (B[k][j] == 0)
                        continue;

                    C[i][j] = (C[i][j] + val * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    private long[] multiply(long[][] A, long[] v) {

        int n = A.length;

        long[] res = new long[n];

        for (int i = 0; i < n; i++) {

            long sum = 0;

            for (int j = 0; j < n; j++) {

                if (A[i][j] == 0)
                    continue;

                sum = (sum + A[i][j] * v[j]) % MOD;
            }

            res[i] = sum;
        }

        return res;
    }
}