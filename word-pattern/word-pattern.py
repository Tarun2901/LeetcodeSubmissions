class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        str1 = "";
        str2 = "";
        occur = 1;
        mp = {'':0}
        for ch in pattern:
            if ch not in mp:
                mp[ch] = occur;
                str1+=(str)(occur);
                occur+=1;
            else:
                str1+=str(mp[ch]);
                
        print(str1)
        arr = s.split(" ");
        mp1 = {'':0}
        oc = 1;
        for ch in arr:
            if ch not in mp1:
                mp1[ch] = oc;
                str2+=(str)(oc);
                oc+=1;
            else:
                str2+=str(mp1[ch]);
        print(str2)
        return str1 == str2;
            
        