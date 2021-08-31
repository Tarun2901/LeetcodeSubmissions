class Solution {
public:
   set<string> s;
    
    string gen(string str, int st, int end){
        if(st==end){
            if(s.find(str)==s.end()){
                return str;
            }
            else{
                return "";
            }
        }
        string temp=gen(str+'0',st+1,end);
        if(temp!=""){
            return temp; 
        }
        temp=gen(str+'1',st+1,end);
        if(temp!=""){
            return temp; 
        }
        return "";
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        for(string st:nums){
            s.insert(st);
        }
        return gen("",0,nums[0].size());
    }
};