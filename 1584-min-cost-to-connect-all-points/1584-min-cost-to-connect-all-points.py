class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        n=len(points)
        def find(parent,x):
            if parent[x]==x:
                return x
            parent[x]=find(parent,parent[x])
            return parent[x]
        def union(parent,x,y):
            parent[find(parent,x)]=find(parent,y)
        edges=[(abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j) for i in range(n) for j in range(i+1,n)]
        edges.sort()
        parent=list(range(n))
        minCost,numEdges=0,0
        for cost,u,v in edges:
            if find(parent,u)!=find(parent,v):
                union(parent,u,v)
                minCost+=cost
                numEdges+=1
            if numEdges==(n-1):
                break
        return minCost   