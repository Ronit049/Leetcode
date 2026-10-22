```
Q3. Find Root of a Colored Tree
Medium
5 pt.
You are given an undirected tree of n nodes labeled from 0 to n - 1, represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an undirected edge between nodes ui and vi.

You are also given a string colors of length n, where colors[i] is one of 'R', 'B', or 'W', and denotes the color of node i.

A node chosen as root must satisfy both of the following conditions once the tree is oriented away from it:

Binary-tree property: Every node has at most two children.
Layered color pattern: All nodes at the same depth have the same color. Starting at depth 0, these colors follow one of the three repeating sequences:
R → B → W → R → B → W → ...
B → W → R → B → W → R → ...
W → R → B → W → R → B → ...
Return the index of any root that satisfies both conditions, or -1 if no such root exists.

A tree is a connected undirected graph with no cycles.

The depth of a node is the number of edges on the path from the root to that node. The root has depth 0. A child of a node is an adjacent node whose depth is one greater.

The degree of a node is the number of edges incident to it.

 

Example 1:

Input: edges = [[3,1],[3,2],[1,4],[2,0]], colors = "BRRWB"

Output: 3

Explanation:



Rooting at node 3 gives each node at most two children and every edge advances to the next color in the cycle (W → R → B), so return 3.

Example 2:

Input: edges = [[0,1],[1,2],[2,3]], colors = "RBRB"

Output: -1

Explanation:



No root satisfies the required color step on every edge, so return -1.

 

Constraints:

2 <= n <= 105
edges.length == n - 1
edges[i] = [ui, vi]
0 <= ui, vi < n
colors.length == n
colors[i] is one of 'R', 'B', 'W'.
The input graph is a tree and every node has degree at most three.
```