class Solution{
    
    // arr: input array
    // n: size of array
    // Function to find the trapped water between the blocks.
    static long trappingWater(int arr[], int n) { 
        // Your code here
        int left[] = new int[n];
        int right[] = new int[n];
        
        int i,max=0;
        for(i=0; i<n; ++i){
            left[i] = Math.max(arr[i],max);
            if(max<arr[i])
                max= arr[i];
        }
        
        max=0;
        for(i=n-1; i>=0; --i){
            right[i] = Math.max(arr[i],max);
            if(max<arr[i])
                max= arr[i];
        }
        long ans=0;
        for(i=0;i<n;++i){
            ans+= Math.min(right[i],left[i])-arr[i];
        }
        
        return ans;
    } 
}