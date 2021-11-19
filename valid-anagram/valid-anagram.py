class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        m = {s[0]:1}
        for i in range(1,len(s)):
            ele = s[i];
            if ele not in m:
                m[ele] = 1;
            else:
                m[ele] = m[ele]+1
        for i in range(0,len(t)):
            ele = t[i];
            if ele not in m:
                return False
            else:
                m[ele] = m[ele] - 1;
        val = m.values();
        for i in val:
            if i > 0:
                return False
        return True;
        