class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        m = {s[0]:1}
        for i in range(1,len(s)):
            ele = s[i];
            if ele not in m:
                m[ele] = 1;
            else:
                m[ele] = m[ele]+1
        tmap = {}
        for i in range(0,len(t)):
            ele = t[i];
            if ele not in tmap:
                #print("This "+ ele +" char was not there in 2nd string")
                tmap[ele] = 1
            else:
                tmap[ele]+=1
        return m == tmap;
        
        