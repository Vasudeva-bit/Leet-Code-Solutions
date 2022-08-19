class Solution:
    def numFactoredBinaryTrees(self, arr: List[int]) -> int:
        arr = sorted(arr)
        result = defaultdict(int)
        for a in arr:
            tem = 1;
            for b in arr:
                if(b > a):
                    break;
                tem += result[b]*result[a/b]
            result[a] = tem
        return sum(result.values())%(10**9+7)