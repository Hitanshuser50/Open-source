class Solution:
    def countOrders(self, n: int) -> int:
        mod=10**9+7
        num=1
        for i in range(1, n):
            num=num*(i+1)*(2*i+1)%mod
        return num