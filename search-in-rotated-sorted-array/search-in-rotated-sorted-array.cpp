class Solution {
public:
    int search(vector<int>& arr, int target) {
        
        int i = 0;
        int j = arr.size()-1;
        
        while(i<=j)
        {
            int mid = i + (j-i)/2;
            
            if(arr[mid] == target)
            {
                return mid;
            }
            else if(arr[i]<=arr[mid])
            {   //low to mid part is sorted 
                if(target>=arr[i] && target<arr[mid])
                {
                   j = mid-1;
                }
                else
                {
                    i = mid+1;
                }
            }
            else if(arr[mid]<=arr[j])
            {
                //mid to high part is sorted
                if(target>arr[mid] && target<=arr[j])
                {
                    i = mid+1;
                }
                else
                {
                    j = mid-1;
                }
            }
          
        }
        return -1;
    }
};