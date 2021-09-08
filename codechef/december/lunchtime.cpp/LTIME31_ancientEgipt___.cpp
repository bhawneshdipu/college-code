#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int p[500013];
ll pop[500013];
multiset<ll> has;

int find(int x) {

 return p[x]==x ? x : p[x]=find(p[x]);

}

void merge(int a, int b) {
	a = find(a); b = find(b);
	if (a==b) return;
	p[a] = b;
	has.erase(has.find(pop[a]));
	has.erase(has.find(pop[b]));
	pop[b]+=pop[a];
	has.insert(pop[b]);
}

int n,m,q;
int val[500013];
int u[500013], v[500013];
bool here[500013];
char type[500013];
int k[500013], a[500013], x[500013];
ll ans[500013];

int main() {
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++) scanf("%d",&val[i]);
	for (int i=0;i<m;i++) {
		scanf("%d%d",&u[i],&v[i]);
		here[i] = 1;
	}
	for (int i=0;i<q;i++) {
		scanf(" %c",&type[i]);
		if (type[i]=='D') {
			scanf("%d",&k[i]);
			k[i]-=1;
			here[k[i]] = 0;
		} else {
			scanf("%d%d",&a[i],&x[i]);
			swap(val[a[i]],x[i]);
		}
	}
	iota(p,p+n+1,0);
	for (int i=1;i<=n;i++)
        has.insert(pop[i] = val[i]);
	for (int i=0;i<m;i++)
        if (here[i]) merge(u[i],v[i]);
	for (int i=q-1;i>=0;i--) {
		ans[i] = *has.rbegin();
		if (type[i]=='D')
            merge(u[k[i]],v[k[i]]);
		else {
			int loc = find(a[i]);
			has.erase(has.find(pop[loc]));
			pop[loc]+=x[i]-val[a[i]];
			has.insert(pop[loc]);
			val[a[i]] = x[i];
		}
	}
	for (int i=0;i<q;i++)
        printf("%lld\n",ans[i]);

	return 0;
}
