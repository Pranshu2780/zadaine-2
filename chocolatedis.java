class Solution
{
    public long findMinDiff (ArrayList<Long> a, long n, long m)
    {
        // your code here
        Collections.sort(a);
       
        long ans=Integer.MAX_VALUE;
        
        if(n==m)
         {
             ans = a.get( (int) (n-1) ) - a.get((int)0);
         }else{
             for(int i=0; i+m-1<n; ++i){
                ans = Math.min(ans, a.get((int)(i+m-1))-a.get(i) );
             }
         }
        return ans;
    }
}