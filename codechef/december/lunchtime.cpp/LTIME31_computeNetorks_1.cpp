#include <bits/stdc++.h>
using namespace std;

int n,m;

int main() {
	int T;
	scanf("%d",&T);
	for (int t=0;t<T;t++) {
		scanf("%d%d",&n,&m);
		// begin all right
		if (n==1) assert(0);
		if (n==2) {
			printf("1 2\n");
			continue;
		}
		if (n==3) {
			if (m<3) printf("-1 -1\n");
			else printf("1 2\n2 3\n3 1\n");
			continue;
		}
		if (n==4) {
			if (m!=4) printf("-1 -1\n");
			else if (m==4) printf("1 2\n2 3\n3 4\n4 1\n");
		}
		// end all right
		if (n>4) {
			if (m<n || m>2*(n-2)) {
				printf("-1 -1\n");
				continue;
			}
			int cyclen = 2*(n-2)-m+4;
			for (int i=1;i<cyclen;i++) printf("%d %d\n",i,i+1);
			printf("%d %d\n",cyclen,1);
			for (int i=cyclen+1;i<=n;i++) {
				printf("%d %d\n",1,i);
				printf("%d %d\n",i,2);
			}
		}
	}
}
