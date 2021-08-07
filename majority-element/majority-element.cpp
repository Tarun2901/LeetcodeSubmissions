class Solution {
public:
    
    /*
        Boyce - Moore's Algorithm
        [2,2,1,1,1,2,2]
        
        
        Assume an element has majority
        
        .... | ***
        
        So now the algorithm is 
        . pair with *
        . pair with *
        . pair with *
        . is unpaired 
        
        So the number in place of . could be a majority element
        What we want to do is we want to group 2 distinct elements together 
        
        initialise
        i = 0, val = 2(arr[0]) and count = 1;
        
        Now when i = 1, val == arr[i] and count > 0 (i.e. the element in val is unpaired)
        action -> the action here is to increment count;
        val = 2, count = 2;
        
        i = 2 => val!=arr[i] and count>0(i.e. element is actually available)
        action->count--
        val = 2, count = 1
        
        i = 3, val!=arr[i] and count > 0
        action->count--
        val = 2, count = 0;
        
        i = 4 => val!=arr[i] and count == 0 (i.e. the element present in val is not )
        action->val = arr[i],count = 1
        
        i = 5=> val!=arr[i] and count>0 (element is actually present)
        action-> count--;
        
        i = 6=> val!=arr[i] and count = 0 (element is not actually present)
        action -> val = arr[i] and count = 1
        
        at the end check using a for loop whether val has freq > n/2;
    */
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int val = nums[0];
        int count = 1;
        
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i] == val)
            {
                count++;  
            }
            else
            {   //arr[i]!=val
                if(count == 0)
                {   //element is not actually present
                    val = nums[i];
                    count = 1;
                }
                else
                {   //element is actually present and hence can be paired
                    count--;
                }
            }
        }
        
        int elecount = 0;
        for(int i = 0;i<n;i++)
        {
            if(nums[i] == val)
            {
                elecount++;
            }
        }
        if(elecount > n/2)
        {
            return val;
        }
        
        return -1;
    }
};