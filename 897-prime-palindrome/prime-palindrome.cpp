class Solution {
public:
    bool isPalindrome(int n)
    {
        string rev = to_string(n);
        string num = to_string(n);
        reverse(begin(rev), end(rev));
        return num == rev;
    }

    bool isPrime(int n)
    {
        if(n < 2)
            return false;

        if(n == 2)
            return true;

        if(n % 2 == 0)
            return false;

        for(int i = 3; i * i <= n; i += 2)
        {
            if(n % i == 0)
                return false;
        }

        return true;
    }

    int primePalindrome(int n) {

        // special case
        if(n <= 2) return 2;
        if(n <= 3) return 3;
        if(n <= 5) return 5;
        if(n <= 7) return 7;
        if(n <= 11) return 11;

        // skip all even length palindromes
        for(int x = n; ; x++)
        {
            int len = to_string(x).size();

            // skip even digit lengths
            if(len % 2 == 0)
            {
                x = pow(10, len);
                continue;
            }

            if(isPalindrome(x) && isPrime(x))
                return x;
        }
    }
};