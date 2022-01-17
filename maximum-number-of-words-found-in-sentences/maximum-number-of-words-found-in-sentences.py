class Solution:
    def mostWordsFound(self, sentences: List[str]) -> int:
        mx = -1;
        
        for sentence in sentences:
            arr = sentence.split(" ");
            mx = max(len(arr),mx);
        return mx;