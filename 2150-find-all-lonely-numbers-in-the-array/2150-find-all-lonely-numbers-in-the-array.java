class Solution {
    public List<Integer> findLonely(int[] nums) {
        int[] arr = new int[1000001] ;
        List<Integer> result = new ArrayList<>() ;
        for(int i : nums){
            if(i>0)
            arr[i-1]++ ;
            arr[i]++ ;
            if(i<1000000)
            arr[i+1]++ ;
        }
        for(int i: nums){
            if(arr[i]==1){
                result.add(i) ;
            }
        }
        return result ;
    }
}