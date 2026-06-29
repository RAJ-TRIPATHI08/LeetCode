class Solution {
    public boolean checkIfCanBreak(String x, String y) {
        int n = x.length();
        int m = y.length();

        if(m != n)
            return false;

        char[] arr = x.toCharArray();
        Arrays.sort(arr);

        char[] arr1 = y.toCharArray();
        Arrays.sort(arr1);

        boolean res = false;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] >= arr1[i])
                res = true;
            else
            {
                res = false;
                break;
            }
        }

        if(res == true)
        {
            return res;
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                if(arr1[i] >= arr[i])
                    res = true;
                else
                {
                    res = false;
                    break;
                }
            }
        }

        return res;
    }
}