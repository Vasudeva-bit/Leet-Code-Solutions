class Solution:
    def numMatchingSubseq(self, s: str, words: List[str]) -> int:
        umap = defaultdict(list)
        result = 0
        
        for i, ch in enumerate(s):
            umap[ch].append(i)
        
        for w in words:
            prev = -1
            found = True
            for ch in w:
                tem = bisect.bisect(umap[ch], prev)
                if tem == len(umap[ch]):
                    found = False
                    break
                else:
                    prev = umap[ch][tem]
            if found:
                result+=1
        return result