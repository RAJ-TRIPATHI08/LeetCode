class Solution {
    public int numOfStrings(String[] patterns, String word) {
        int res = 0;
        
        for(String str : patterns)
            if(word.contains(str))
                res++;
        
        return res;
    }
}