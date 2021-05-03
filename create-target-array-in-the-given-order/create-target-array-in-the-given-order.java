class Solution {
   public int[] createTargetArray(int[] nums, int[] index) {
        int[] arr = new int[nums.length];
        for(int i = 0; i < nums.length; i++){
            addAtIndex(arr, index[i], nums[i]);
        }
        return arr;
    }
    private void addAtIndex(int[] arr, int index, int num){
        for(int i = arr.length-1; i > index; i--){
            arr[i] = arr[i-1];
        }
        arr[index] = num;
    }
}