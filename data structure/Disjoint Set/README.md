# Disjoint Set

Disjoint Set is considered by many OIers to be one of the most concise and elegant data structures, mainly used to solve the problem of elements-grouping. It manages a series of disjoint sets and supports two operations:

* Union: Merge two disjoint sets into one set.
* Find: Find whether two elements are in the same set.

Of course, such a definition is too academic, and I am afraid that unable to understand its specific use after reading it. So let's take a look at the most direct application scenario of Disjoint Set: [Relative Problem](https://www.luogu.com.cn/problem/P1551).

This is actually a very practical question. We can build a model that divides all people into several disjoint sets, and the people in each set are relatives of each other. In order to judge whether two people are relatives, it is only necessary to see whether they belong to the same set. Therefore, here you can consider Disjoint Set for maintenance.

## Introduction

The important idea of Disjoint Set is to use an element in the set to represent this set. I have seen an interesting metaphor that compares the set to a gang, and the representative element is the gang boss. Next, let's use this metaphor to see how Disjoint Set works.

In the beginning, all the gangsters fought on their own. Every gang boss is naturally themselve. (For a set with only one element, the representative element is naturally the only element)

Now No. 1 and No. 3 are fighting, assuming that No. 1 wins (here it is not important who wins), then No. 3 will recognize No. 1 as the gang boss (merge the sets that No. 1 and No. 3 belong to, and No. 1 is the representative element).

Now No. 2 wants to fight with No. 3 (merge the sets that No. 3 and No. 2 belong to), but No. 3 says, "don't fight with me, I'll call my boss to f**k you" (merge representative elements). It might as well assume that No. 1 won again this time, then No. 2 also recognizes No. 1 as the boss.

Now let's assume that the No. 4, No. 5 and No. 6 also carried out some gang mergers, and the situation in the streets becomes as follows:

Now suppose that No. 2 wants to fight with No. 6, just like what I just said, they call their boss No. 1 and No. 4 to come out and fight (it's never easy being the boss). After No. 1 wins, No. 4 recognizes No. 1 as the gang boss, and of course his subordinates also surrendered.

Well, the metaphor is over. If you have a little graph theory foundation, I believe you have already noticed that this is a **tree** structure. To find the representative element of the set, you only need to find the parent node layer by layer (the circle pointed by the arrow in the figure). Go to the root node of the tree (the orange circle in the figure). The parent node of the root node is itself. We can draw it directly as a tree:

In this way, we can write the simplest version code of Disjoint Set.

### Initialization

```c
int fa[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
        fa[i] = i;
}
```

If there are n elements numbered 1, 2, 3, ..., n, we use an array fa[] to store the parent node of each element (because each element has and only one parent node, so this is feasible). At the beginning, we first set their parent node to ourselves.

### Query

```c
int find(int x)
{
    if(fa[x] == x)
        return x;
    else
        return find(fa[x]);
}
```

We use recursive writing to realize the query of representative elements: go to the parent node layer by layer until the root node (the sign of the root node is that the parent node is itself). To determine whether two elements belong to the same collection, you only need to check whether their root nodes are the same.

### Merge

```c
inline void merge(int i, int j)
{
    fa[find(i)] = find(j);
}
```

The merging operation is also very simple, first find the representative elements of the two collections, and then set the parent node of the former to the latter. Of course, the parent node of the latter can also be set to the former, which is not important here. A more reasonable comparison is given at the end of this article.

## Path Compression

The simplest version's efficiency is quite low. For example, consider the following scenario:

Now we want to merge(2,3), so we find 1 from 2, fa[1]=3, so it becomes like this:

Then we find another element 4, and need to execute merge(2,4):

Find 1 from 2, then find 3, then fa[3]=4, so it becomes like this:

You should have a feeling that this may form a long **chain** . As the chain gets longer, it will become more and more difficult for us to find the root node from the bottom.

How to solve it? We can use **path compression** . Since we only care about the **root node** corresponding to an element, we hope that the path from each element to the root node is as short as possible, preferably only one step, like this:

In fact, this is also very easy to achieve. As long as we **set the parent node of each node along the way as the root node** during the query process. We can save a lot of trouble the next time we look up. This is easy to implement in recursion.

### Merge (Path Compression)

```c
int find(int x)
{
    if(x == fa[x])
        return x;
    else{
        fa[x] = find(fa[x]);  // set the parent node as the root node
        return fa[x];         // return parent node
    }
}
```

The above code is often shortened to one line:

```c
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}
```

Note that the priority of the assignment operator `=` is not as high as that of the ternary operator `?:` , and parentheses are required here.

After path compression's 'optimization, the time complexity of Disjoint Set is quite low, and most Union and Find problems of Disjoint Set can be solved. However, for some problems with strict time limit, we can further optimize.

## Merge by rank

Some people may have a misunderstanding, thinking that after path compression and optimization, Disjoint Set is always a star graph (commonly known as a tree with only two layers). But in fact, since the path compression is only performed during the query, and only one path is compressed, the final structure of the Disjoint Set may still be relatively complicated. For example, now we have a more complex tree that needs to be merged with a single-element set:

If we want to merge(7,8) at this time, if we can choose, should we set the parent node of 7 to 8, or set the parent node of 8 to 7?

Of course it is the latter. Because if the parent node of 7 is set to 8, the **depth** of the tree (the length of the longest chain in the tree) will be deepened, and the distance from each element in the original tree to the root node will become longer. Then we look for the root node The path will be correspondingly longer. Although we have path compression, path compression also consumes time. On the contrary, Ssetting the parent node of 8 to 7 does not have this problem because it does not affect unrelated nodes.

This inspires us: we should merge simple trees into complex trees, not the other way around. Because after merging in this way, the number of nodes whose distance to the root node becomes longer is relatively small.

We use an array `rank[]` to record the depth of the tree corresponding to each root node (if it is not the root node, its rank is equivalent to the depth of the subtree with it as the root node). At the beginning, set the rank (rank) of all elements to 1. When merging, compare the two root nodes, and merge the one with the smaller rank to the one with the higher rank.

If path compression and merge by rank are used together, the time complexity is close to $O(n)$ , but it is likely to destroy the accuracy of rank.

### Initialization (merge by rank)

```c
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        rank[i] = 1;
    }
}
```

### Merge (merge by rank)

```c
inline void merge(int i, int j)
{
    int x = find(i), y = find(j); // First find two root nodes
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++; // If the depth is the same and the root node is different, the depth of the new root node +1
}
```

Why is the depth the same, but the depth of the new root node needs to be +1? As shown in the figure below, we have two trees with a depth of 2, and now we need to merge(2,5):

Here, the parent node of 2 is set to 5, or the parent node of 5 is set to 2, in fact, there is not much difference. We choose the former, so it becomes like this:

Obviously the depth of the tree is increased by 1. Another way of merging also increases the depth of the tree by +1.

## Disjoint Set applications

I first give the AC code for the Relative Problem:

```c
#include <cstdio>
#define MAXN 5005
int fa[MAXN], rank[MAXN];
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        rank[i] = 1;
    }
}
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}
inline void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++;
}
int main()
{
    int n, m, p, x, y;
    scanf("%d%d%d", &n, &m, &p);
    init(n);
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &x, &y);
        merge(x, y);
    }
    for (int i = 0; i < p; ++i)
    {
        scanf("%d%d", &x, &y);
        printf("%s\n", find(x) == find(y) ? "Yes" : "No");
    }
    return 0;
}
```

Next, let's look at a NOIP improvement group original question: [Cheese](https://www.luogu.com.cn/problem/P3958).

Do you see the relationship between this question and Disjoint Set?

This is the 2D version, the 3D version in the problem is similar.

Take a look at the picture above, do you see some tricks? We divide all holes into several sets, and once two holes intersect or tangent, put them into the same set.

We can also make 2 **special elements**, respectively representing **bottom** and **top**, if a hole is in contact with the bottom, put it in the same set as the element representing the bottom, The same goes for the top. In the end, you just need to see if **top and bottom are in the same set**. This can be achieved by Disjoint Set. Look at the code:

```c
#include <cstdio>
#include <cstring>
#define MAXN 1005
typedef long long ll;
int fa[MAXN], rank[MAXN];
ll X[MAXN], Y[MAXN], Z[MAXN];
inline bool next_to(ll x1, ll y1, ll z1, ll x2, ll y2, ll z2, ll r)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2) <= 4 * r * r;
    // Determine whether two holes are intersecting or tangent
}
inline void init(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        rank[i] = 1;
    }
}
int find(int x)
{
    return x == fa[x] ? x : (fa[x] = find(fa[x]));
}
inline void merge(int i, int j)
{
    int x = find(i), y = find(j);
    if (rank[x] <= rank[y])
        fa[x] = y;
    else
        fa[y] = x;
    if (rank[x] == rank[y] && x != y)
        rank[y]++;
}
int main()
{
    int T, n, h;
    ll r;
    scanf("%d", &T);
    for (int I = 0; I < T; ++I)
    {
        memset(X, 0, sizeof(X));
        memset(Y, 0, sizeof(Y));
        memset(Z, 0, sizeof(Z));
        scanf("%d%d%lld", &n, &h, &r);
        init(n);
        fa[1001] = 1001; // Use 1001 to represent the bottom
        fa[1002] = 1002; // Use 1002 to represent the top
        for (int i = 1; i <= n; ++i)
            scanf("%lld%lld%lld", X + i, Y + i, Z + i);
        for (int i = 1; i <= n; ++i)
        {
            if (Z[i] <= r)
                merge(i, 1001); // The hole in contact with the bottom merges with the bottom
            if (Z[i] + r >= h)
                merge(i, 1002); // The hole in contact with the top merges with the top
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (next_to(X[i], Y[i], Z[i], X[j], Y[j], Z[j], r))
                    merge(i, j); // Traverse all holes, merge intersecting or tangent balls
            }
        }
        printf("%s\n", find(1001) == find(1002) ? "Yes" : "No");
    }
    return 0;
}
```

Because of the data range, a long long is required here.

There are many applications of Disjoint Set, such as the Kruskal algorithm of the minimum spanning tree. I won't go into details here. All in all, any group management problem involving elements can be considered to use Disjoint Set for maintenance.
