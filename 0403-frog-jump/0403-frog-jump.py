class Solution:
    def canCross(self, stones: List[int]) -> bool:
        n=len(stones)

        @cache
        def f(i, k):
            if i==n-1: return True
            if i>=n: return False
            ans=False
            for jump in [k-1, k, k+1]:
                if jump==0: continue
                next= bisect_left(stones[i+1:], stones[i]+jump)+(i+1)
                if next==n or stones[next]!=stones[i]+jump: continue
                ans = ans or f(next, jump)
            return ans
        
        return f(0, 0)