## Chapter 6: Weighted Graph ALgorithms

Chapter 5's graph data structure quietly supported edge-weighted graphs, but we'll make it explicit for this chapter. The adjacency list structure consists of an array of linked lists where the outgoing edges from vertex.x appear in the list edges[x]

```
typedef struct {
    edgenode *edges[MAXV+1]; /* adjacency info */
    int degree[MAXV+1]; /* outdegree of each vertex */
    int nvertices; /* number of vertices in graph */
    int nedges; /* number of edges in graph */
    int directed; /* is the graph directed? */
} graph;
```

Each edgenode is a record with three fields: first describing second endpoint of the edge (y), second enabling us to annotate the edge with a weight (weight) and third to annotate the next edge in the list (nex):

```
typedef struct {
    int y; /* adjacency info */
    int weight; /* edge weight, if any */
    struct edgenode *next; /* next edge in list */
} edgenode;
```

### Minimum Spanning Trees

A spanning tree of a graph G = (V, E) is a subset of edges from E forming a tree connecting all vertices of V. For edge-weighted graphs, a tree whose sum of edge weights is as small as possible is a minimum spanning tree. There can be more than one minimum spanning tree in a graph. All spanning trees of an unweighted graph are minimum spanning trees.

### Prim's Algorithm

Starts from one vertex and grows the rest of the tree one edge at a time until all vertices included

Prim-MST(G)

&nbsp;&nbsp;&nbsp;&nbsp;Select an arbitrary vertex s to start the tree from

&nbsp;&nbsp;&nbsp;&nbsp;While (therre are still nontree vertices)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Select the edge of minimum weight between a tree and nontree vertex

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Add the selected edge and vertex to the tree T<sub>prim</sub>

```
prim(graph *g, int start) {
    int i; /* counter */
    edgenode *p; /* temporary pointer */
    bool intree[MAXV+1]; /* is the vertex in the tree yet? */
    int distance[MAXV+1]; /* cost of adding to tree */
    int v; /* current vertex to process */
    int w; /* candidate next vertex */
    int weight; /* edge weight */
    int dist; /* best current distance from start */

    for (i = 1; i <= g->nvertices; i++) {
        intree[i] = False
        distance[i] = MAXINT;
        parent[i] = -1;
    }
    distance[start] = 0;
    v = start;
    while (intree[v] == False) {
        intree[v] = True;
        p = g->edges[v];
        while (p != NULL) {
            w = p->y;
            weight = p->weight;
            if ((distance[w] > weight) && (intree[v] == False)) {
                distance[w] = weight;
                parent[w] = v;
            }
            p = p->next;
        }
        v = 1;
        dist = MAXINT;
        for (i = 1; i <= g->nvertices; i++)
            if ((intree[i] == False) && (dist > distance[i])) {
                dist = distance[i];
                v = i;
            }
    }
}
```

This is an O(n<sup>2</sup>) implementation. Priority-queue data structures lead to an O(m + n lg n) implementation by making it faster to find the minimum cost edge to expand the tree at each iteration.

### Kruskal's Algorithm

Builds up connected components of vertices, culminating in the minimum spanning tree. Initially, each vertex forms its own separate component in the tree to be. The algorithm repeatedly considers the lightest remaining edge and tests whether its two endpoints lie within the same connected component. If so, the edge will be discarded because adding it would create a cycle in the tree to be. If the endpoints are in different components, we insert the edge and merge the two components into one. Since each connected component is always a tree, don't have to test for cycles.

Kruskal-MST(G)

&nbsp;&nbsp;&nbsp;&nbsp;Put the edges in a prirority queue ordered by weight

&nbsp;&nbsp;&nbsp;&nbsp;count = 0

&nbsp;&nbsp;&nbsp;&nbsp;while (count < n-1) do

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;get next edge(v, w)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;if (component(v) does not equal component(w))

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Add to T<sub>kruskal</sub>

What is the time complexity?

- Sorting the m edges takes O(m lg m) time
- The for loop makes m iterations, each testing the connectivity of two trees plus an edge. In the most simple-minded approach, this can be implemented by breadth-first or depth-first search in a sparse graph with at most n edges and n vertices, thus yielding an O(mn) algorithm.

Faster implementation results if we can implement the component test in faster than O(n) time. Union-find is a data structure that can support such queries in O(lg n) time, allowing Kruskal's algorithm to run in O(m lg m) time, faster than Prim's for sparse graphs.

```
kruskal(graph *g) {
    int i; /* counter */
    set_union s; /* set union data structure */
    edge_pair e[MAXV+1]; /* array of edges data structure */
    bool weight_compare();
    set_union_init(&s, g->nvertices);
    to_edge_array(g, e); /* sort edges by increasing cost */
    qsort(&e, g->nedges, sizeof(edge_pair), weight_compare);
    for (i = 0; i < (g->nedges); i++) {
        if (!same_component(s, e[i].x, e[i].y)) {
            printf("edge (%d, %d) in MST\n", e[i].x, e[i].y);
            union_sets(&s, e[i].x, e[i].y);
        }
    }
}
```

### Union-Find Data Structure

A set partition is a partitioning of the elements of some universal set (say integers 1 to n) into a collection of disjointed subsets. Each element must be in exactly one subset.

The connected components in a graph can be represented as a set partition. For Kruskal's algorithm to run efficiently, we need a data structure that efficiently supports the following operations:

- _Same component(V<sub>1</sub>, V<sub>2</sub>)_ - Do vertices V<sub>1</sub> and V<sub>2</sub> occur in the same connected component of the current graph?
- _Merge components(C<sub>1</sub>, C<sub>2</sub>)_ - Merge the given pair of connected components into one component in response to an edge between them.

The union-find data structure represents each subset as a "backwards" tree, with pointers from a node to its parent. Each node of this tree contains a set el.ement and the name of the set is taken from the key at the root.

```
typedef struct {
    int p[SET_SIZE+1]; /* parent element */
    int size[SET_SIZE+1]; /* number of elements in subtree */
    int n; /* number of elements in set */
} set_union;
```

We implement desired ops in terms of operations _union_ and _find_:

- _Find(i)_ - Find the root of tree containing element _i_ by walking up the parent pointers until there is nowhere to go. Return the lable of the root.
- _Union(i, j)_ - Link the root of one of the trees (say containing i) to the root of the tree containing the other (say j) so _find(i)_ now equals _find(j)_.

To minimize tree height, it is better to make the smaller tree the subtree of the larger one. The height of all the nodes in the root subtree stay the same while the height of the nodes merged into the tree all increase by one. Thus, merging in the smaller tree leaves the height unchanged on the larger set of vertices

```
set_union_init(set_union *s, int n) {
    int i; /* counter */
    for (i = 1; i <= n; i++) {
        s->p[i] = i;
        s->size[i] = 1;
    }
    s->n = n;
}

int find(set_union *s, int x) {
    if (s->p[x] == x)
        return x;
    else
        return find(s, s->p[x]);
}

int union_sets(set_union *s, int s1, int s2) {
    int r1, r2; /* roots of sets */
    r1 = find(s, s1);
    r2 = find(s, s2);
    if (r1 == r2) return; /* already in same set */
    if (s->size[r1] >= s->size[r2]) {
        s->size[r1] = s->size[r1] + s->size[r2];
        s->p[r2] = r1;
    }
    else {
        s->size[r2] = s->size[r1] + s->size[r2];
        s->p[r1] = r2;
    }
}

bool same_component(set_union *s, int s1, int s2) {
    return (find(s, s1) == find(s, s2))
}
```

On each union, the tree with fewer nodes becomes the child. Only when merging two height 2 trees do we get a tree of height 3 (now with four nodes). At most, we can do lg<sub>2</sub>n doublings to use up all n nodes, so we can do both unions and finds in O(log n) time.

### Variations on Minimum Spanning Trees

- _Maximum Spanning Trees_ - The maximum spanning tree of any graph can be found by simply negating the weights of all edges and running Prim's algorithm. The most negative tree in the negated graph is the maximum spanning tree in the original. Most graph algorithms do not adapt so easily to negative numbers.
- _Minimum Product Spanning Trees_ - Since lg(a <sup>.</sup> b) = lg(a) + lg(b), the minimum spanning tree on a graph whose edge weights are replaced with their logarithms gives the minimum product spanning tree on the original graph
- _Minimum Bottleneck Spanning Tree_ - Tree that minimizes the maximum edge weight over all trees

The minimum spanning tree of a graph is unique if all m edge weights in the graph are distinct. Otherwise, the way Prim's/Kruskal's algorithms break ties determines which minimum spanning tree is returned.

Two variants of minimum spanning tree not solvable with these techniques:

- _Steiner tree_ - If you want to wire a bunch of houses together but have the freedom to add extra intermediate vertices to serve as a shared junction
- _Low-degree Spanning Tree_ - If you want to find the minimum spanning tree where the highest degree node in the tree is small. The lowest max-degree tree possible would be a simple path and have n-2 nodes of degree 2 with two endpoints of degree 1. A path that visits each vertex once is called a Hamiltonian path.

### Shortest Paths

A path is a sequence of edges connecting two vertices. The shortest path from _s_ to _t_ in an unweighted graph can be constructed using a breadth-first search from _s_.

### Dijkstra's Algorithm

The method of choice for finding the shortest path in an edge and/or vertex-weighted graph. Given a particular start vertex _s_, it finds the shortest path from _s_ to every other vertex in the graph, including your desired destination _A_.

Dijkstra's Algorithm proceeds in a series of rounds where each round establishes the shortest path from _s_ to some new vertex. Specifically, _x_ is the vertex that minimizes the _dist(s, v<sub>1</sub>) + w(v<sub>1</sub>, x)_ over all unfinished 1 ≤ _i_ ≤ _n_ where _w(i, j)_ is the length of the edge from _i_ to _j_ and _dist(i, j)_ is the length of the shortest path between them.

ShortestPath-Dijkstra(G, s, t)

&nbsp;&nbsp;&nbsp;&nbsp;known = {s)

&nbsp;&nbsp;&nbsp;&nbsp; for i = 1 to n, dist[i] = infinity

&nbsp;&nbsp;&nbsp;&nbsp; for each edge (s, v), dist[v] = w(s, v)

&nbsp;&nbsp;&nbsp;&nbsp; last = s

&nbsp;&nbsp;&nbsp;&nbsp;while (last does not equal t)

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;select v<sub>next</sub>, the unkonwn vertex minimizing dist[v]

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;for each edge(v<sub>next, x), dist[x] = min[dist[x], dist[v<sub>next</sub>] + w(v<sub>next</sub>, x)]

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;last = v<sub>next</sub>

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;known = known U {v<sub>next</sub>}
