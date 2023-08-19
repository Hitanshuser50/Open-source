class DisjointSet {
    public:
    vector<int> size, parent;

    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        parent[i] = i;
    }

    int findUPar(int node)
    {
        if (parent[node] == node)
        return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
        return;

        if (size[ulp_u] >= size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Step 1 - Find the MST wt of the entire graph. Now remove each edge and check if removing that edge increase the MST wt, if it does, then it is a critical edge, else we check if it is a pseudo-critical edge.
        // Use another vector that also stores the index of the edge with it and sort it for kruskal
        vector<vector<int>> edgeCopy;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            edgeCopy.push_back({wt, u, v, i});
        }
        sort(edgeCopy.begin(), edgeCopy.end());

        // Figure out the weight of MST!
        DisjointSet MST(n);
        int mstWt = 0;
        for (auto &it: edgeCopy)
        {
            int wt = it[0], u = it[1], v = it[2];
            if (MST.findUPar(u) != MST.findUPar(v))
            {
                mstWt += wt;
                MST.unionBySize(u, v);
            }
        }

        vector<int> criticalEdges;
        vector<int> pseudocritEdges;

        // Iterate edgeCopy and try removing an edge and check if it's critical.
        for (int i = 0; i < edgeCopy.size(); i++)
        {
            // If weight increases or if all nodes aren't in 1 component, this edge is critical
            int newMSTwt = 0;
            DisjointSet ds(n);
            int edgeIndex = edgeCopy[i][3];
            // Ignoring the edge to check for criticality
            for (int j = 0; j < edgeCopy.size(); j++)
            {
                if (i != j) // ignore edge
                {
                    int wt = edgeCopy[j][0], u = edgeCopy[j][1], v = edgeCopy[j][2];
                    if (ds.findUPar(u) != ds.findUPar(v))
                    {
                        newMSTwt += wt;
                        ds.unionBySize(u, v);
                    }
                }
            }
            if (newMSTwt > mstWt || ds.size[ds.findUPar(0)] < n) // weight increased or more than 1 component MST
            criticalEdges.push_back(edgeIndex);
            else
            {
                // We only check for pseudoCritical when we know it's not critical!
                // Iterate edgeCopy and try forcing this edge and check if it's pseudo critical.
                // If the total weight of the resulting MST is the same as the mstWt, this edge is pseudo-critical.
            int forcedMSTwt = 0;
            DisjointSet forcedDs(n);
            int forcedWt = edgeCopy[i][0], forcedU = edgeCopy[i][1], forcedV = edgeCopy[i][2];
            forcedDs.unionBySize(forcedU, forcedV);
            forcedMSTwt += forcedWt;
            // add this edge to Ds and create MST to check if it's psedo critical or not
            for (int j = 0; j < edgeCopy.size(); j++)
            {
                if (i != j) // ignore edge as already counted
                {
                    int wt = edgeCopy[j][0], u = edgeCopy[j][1], v = edgeCopy[j][2];
                    if (forcedDs.findUPar(u) != forcedDs.findUPar(v))
                    {
                        forcedMSTwt += wt;
                        forcedDs.unionBySize(u, v);
                    }
                }
            }
            if (forcedMSTwt == mstWt) // weight remianed  same
            pseudocritEdges.push_back(edgeIndex);
            }
        }
        vector<vector<int>> res;
        res.push_back(criticalEdges);
        res.push_back(pseudocritEdges);
        return res;
    }
};
