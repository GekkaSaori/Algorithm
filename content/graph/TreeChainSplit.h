/**
 * Author: Mingqi_H
 * Date: 2018-08-27
 * License: CC0
 * Source: Templates
 * Description: Tree-Chain Split.
 * Time: construction $O(N \log N)$, queries $O(\log N)$
 * Status: Tested
 */

#include <cstdio>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;
template<typename T> inline void read(T &x) {
    x = 0; T w = 1; char ch = getchar();
    while(!isdigit(ch)) {if(ch == '-') w = -1; ch = getchar();}
    while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    x *= w; 
}
const int maxn = 100005;
vector<int> G[maxn];
typedef vector<int>::iterator Iter;
int w[maxn], wt[maxn], son[maxn], id[maxn], fa[maxn], dep[maxn], siz[maxn],
        top[maxn], cnt, n, m, r, mod, a, b, k, x, y, z;
inline void add(int u, int v) {G[u].push_back(v);}
struct node {
    int l, r, mid, len, sum, laz; node *ls, *rs;
} *root, MemPool[2 * maxn]; int MemCnt;
inline void alloc(node* &x) {x = MemPool + MemCnt++;}
inline void pushup(node *rt) {rt->sum = (rt->ls->sum + rt->rs->sum) % mod;}
inline void pushdown(node *rt) {
    rt->ls->laz += rt->laz, rt->rs->laz += rt->laz;
    rt->ls->sum += rt->ls->len * rt->laz, rt->rs->sum += rt->rs->len * rt->laz;
    rt->ls->sum %= mod, rt->rs->sum %= mod, rt->laz = 0; 
}
inline void build(node* &rt, int l, int r) {
    if(!rt) alloc(rt);
    rt->l = l, rt->r = r, rt->mid = (l + r) >> 1, rt->len = r - l + 1;
    if(l == r) {rt->sum = wt[l]; if(rt->sum > mod) rt->sum %= mod; return;}
    build(rt->ls, rt->l, rt->mid), build(rt->rs, rt->mid + 1, rt->r);
    pushup(rt);
}
inline int query(node *rt, int l, int r) {
    if(rt->l >= l && rt->r <= r) {return rt->sum % mod;}
    if(rt->laz) pushdown(rt);
    int ans = 0;
    if(l <= rt->mid) ans += query(rt->ls, l, r);
    if(r > rt->mid) ans += query(rt->rs, l, r);
    return ans % mod;
}
inline void update(node *rt, int l, int r, int k) {
    if(rt->l >= l && rt->r <= r) {rt->laz += k; rt->sum += rt->len * k; return;}
    if(rt->laz) pushdown(rt);
    if(l <= rt->mid) update(rt->ls, l, r, k);
    if(r > rt->mid) update(rt->rs, l, r, k);
    pushup(rt);
}
inline int qRange(int x, int y) {
    int ans = 0;
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        ans = (ans + query(root, id[top[x]], id[x])) % mod; x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    return (ans + query(root, id[x], id[y])) % mod;
}
inline void updRange(int x, int y, int k) {
    while(top[x] != top[y]) {
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        update(root, id[top[x]], id[x], k); x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    update(root, id[x], id[y], k);
}
inline void dfs1(int x, int f, int deep) {
    dep[x] = deep, fa[x] = f, siz[x] = 1;
    for(Iter it = G[x].begin(); it != G[x].end(); ++it) {
        if(*it == f) continue;
        dfs1(*it, x, deep + 1);
        siz[x] += siz[*it];
        if(siz[*it] > siz[son[x]]) son[x] = *it;
    }
}
inline void dfs2(int x, int topf) {
    id[x] = ++cnt, wt[id[x]] = w[x], top[x] = topf;
    if(!son[x]) return;
    dfs2(son[x], topf);
    for(Iter it = G[x].begin(); it != G[x].end(); ++it) {
        if(*it == fa[x] || *it == son[x]) continue;
        dfs2(*it, *it);
    }
}
int main() {
    read(n), read(m), read(r), read(mod);
    for(int i = 1; i <= n; ++i) read(w[i]);
    for(int i = 1; i < n; ++i) read(a), read(b), add(a, b), add(b, a);
    dfs1(r, 0, 1), dfs2(r, r), build(root, 1, n);
    while(m--) {
        read(k), read(x);
        if(k == 1) read(y), read(z), updRange(x, y, z);
        else if(k == 2) read(y), printf("%d\n", qRange(x, y));
        else if(k == 3) read(y), update(root, id[x], id[x] + siz[x] - 1, y);
        else printf("%d\n", query(root, id[x], id[x] + siz[x] - 1));
    }
    return 0;
}