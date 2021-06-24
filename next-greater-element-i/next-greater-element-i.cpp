class Solution {
public: vector<int> res;
   
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
            stack<int> st;
            vector<int> nge(nums2.size(),0);
            unordered_map<int,int> mp;
        
        
        for(int i = nums2.size()-1;i>=0;i--)
        {     
            while(!st.empty() && nums2[i]>=st.top())
            {
                st.pop();
            }
          
            if(st.size()>0)
                {
                    nge[i] = st.top();
                    mp[nums2[i]] = nge[i];
                }
            else 
                {
                    nge[i] = -1;
                    mp[nums2[i]] = -1;
                }
            
            st.push(nums2[i]);    
        }
        
   
        for(int i = 0;i<nums1.size();i++)
        {
            res.push_back(mp[nums1[i]]);
        }
        
        return res;
    }
};