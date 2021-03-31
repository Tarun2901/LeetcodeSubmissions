class Solution {
    
    
    
    public int[] searchRange(int[] arr, int data) {
        int[] res = new int[2];
        int fi = -1;
        int li = -1;
        int high = arr.length - 1;
        int low = 0;
        while(high>=low)
        {   int mid = (high+low)/2;
            if(arr[mid]<data)
            {
                low = mid + 1;
            }
            else if(arr[mid] > data)
            {
                high = mid - 1;
            }
            else
            {
                fi = mid;
                high = mid - 1;
            }
        }
        res[0] = fi;
        int high1 = arr.length - 1;
        int low1 = 0;
        while(high1>=low1)
        {   int mid = (high1+low1)/2;
            if(arr[mid]<data)
            {
                low1 = mid + 1;
            }
            else if(arr[mid] > data)
            {
                high1 = mid - 1;
            }
            else
            {
                li = mid;
                low1 = mid + 1;
            }
        }
        res[1] = li;
        return res;
    }  
    }
