class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& arr) {
        int k = 0;
        for(int i = 0;i<arr.size();i++)
        {
            if(arr[i]%2 == 0)
            {
                int temp = arr[i];
                arr[i] = arr[k];
                arr[k] = temp;
                k++;
            }
     
        }
        return arr;
    }
};