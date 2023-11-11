class Graph:

  def __init__(self, n: int, edges: List[List[int]]):
    g = [[] for _ in range(n)]
    for v1, v2, w in edges:
      g[v1].append((v2, w))
    self.g = g
      

  def addEdge(self, edge: List[int]) -> None:
    v1, v2, w = edge
    self.g[v1].append((v2, w))

  def shortestPath(self, v1: int, v2: int) -> int:
    frontier = [(0, v1)]
    heapify(frontier)
    all_cost = [float('inf')] * len(self.g)

    while frontier:
      cost, node = heappop(frontier)
      if node == v2:
        return cost

      for node_nxt, c in self.g[node]:
        if cost + c < all_cost[node_nxt]:
          all_cost[node_nxt] = cost + c
          heappush(frontier, (cost + c, node_nxt))
    
    return -1