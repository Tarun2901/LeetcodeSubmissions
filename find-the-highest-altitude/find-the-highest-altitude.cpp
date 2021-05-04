class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest=0,now=0;
        for(auto i:gain){
            now+=i;
            highest=max(highest,now);
        }
        return highest;
    }
};