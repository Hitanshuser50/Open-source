class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
          vector<int> N(101, 0);
        #pragma unroll
        for(int x : nums)
            N[x]++;
        int sum=0;
        #pragma unroll
        for(int x=1; x<=100; x++)
            if (N[x]!=0) sum+=N[x]*(N[x]-1)/2;
        
        return sum;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
} ();
        