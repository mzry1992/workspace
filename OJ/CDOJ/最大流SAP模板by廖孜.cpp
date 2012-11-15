#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int n,l,b[220][220],f[220],vst[220],pre[220],cur[220],no[220],a[220],c[220],tv[220],nxt[220];
void bfs(){
	int i,k;
	queue<int> q;
	memset(vst,255,sizeof(vst));
	memset(no,0,sizeof(no));
	q.push(n);
	vst[n]=0;
	while (!q.empty()){
		k=q.front();
		q.pop();
		i=a[k];
		while (i!=-1){
			//printf("%d %d %d\n",i,tv[i],c[i]);
			if (!c[i] && vst[tv[i]]==-1){
				vst[tv[i]]=vst[k]+1;
				q.push(tv[i]);
				no[vst[tv[i]]]++;
			}
			i=nxt[i];
		}
	}
}
int max_flow(){
	int i,u=1,v,min,j,ans=0,tmp;
	bfs();
	for (i=1;i<=n;i++) cur[i]=a[i];//printf("%d\n",vst[i]);}
	while (vst[1]<n){
		v=cur[u];
		
		while (v!=-1)
			if (c[v]-f[v]>0 && vst[u]==vst[tv[v]]+1) break;else v=nxt[v];
		//printf("%d %d %d %d %d %d\n",u,v,tv[v],vst[u],vst[tv[v]],ans);
		if (v!=-1){
			cur[u]=v;
			u=tv[v];
			pre[u]=v;
			if (u==n){
				min=210000000;
				j=n;
				while (j!=1){
					i=pre[j];
					if (c[i]-f[i]<min) min=c[i]-f[i];
					j=tv[i^1];
				}
				j=n;
				while (j!=1){
					i=pre[j];
					f[i]+=min;
					f[i^1]-=min;
					j=tv[i^1];
				}
				ans+=min;
				u=1;
			}
		}
		else{
			cur[u]=a[u];
			min=n-1;
			i=a[u];
			while (i!=-1){
				if (c[i]-f[i]>0 && vst[tv[i]]<min)
					min=vst[tv[i]];
				i=nxt[i];
			}
			tmp=vst[u];
			no[vst[u]]--;
			vst[u]=min+1;
			no[vst[u]]++;
			if (u!=1) u=tv[pre[u]^1];
			if (no[tmp]==0) break;
		}
		//printf("%d %d\n",u,vst[u]);
	}
	return ans;
}
int main(){
	freopen("C: \\Users\\Zero\\Desktop\\in.txt","r",stdin);
	freopen("C: \\Users\\Zero\\Desktop\\out.txt","w",stdout);
	int m,i,x,y,z,j;
	while (scanf("%d%d",&m,&n)!=EOF){
		l=0;
		memset(a,255,sizeof(a));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				b[i][j]=0;
		for (i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			b[x][y]+=z;
		}
		l=-1;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				if (b[i][j]) {
					l++;
					c[l]=b[i][j];
					f[l]=0;
					tv[l]=j;
					nxt[l]=a[i];
					a[i]=l;
					l++;
					c[l]=f[l]=0;
					tv[l]=i;
					nxt[l]=a[j];
					a[j]=l;
				}
		printf("%d\n",max_flow());
	}
}#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int n,l,b[220][220],f[220],vst[220],pre[220],cur[220],no[220],a[220],c[220],tv[220],nxt[220];
void bfs(){
	int i,k;
	queue<int> q;
	memset(vst,255,sizeof(vst));
	memset(no,0,sizeof(no));
	q.push(n);
	vst[n]=0;
	while (!q.empty()){
		k=q.front();
		q.pop();
		i=a[k];
		while (i!=-1){
			//printf("%d %d %d\n",i,tv[i],c[i]);
			if (!c[i] && vst[tv[i]]==-1){
				vst[tv[i]]=vst[k]+1;
				q.push(tv[i]);
				no[vst[tv[i]]]++;
			}
			i=nxt[i];
		}
	}
}
int max_flow(){
	int i,u=1,v,min,j,ans=0,tmp;
	bfs();
	for (i=1;i<=n;i++) cur[i]=a[i];//printf("%d\n",vst[i]);}
	while (vst[1]<n){
		v=cur[u];
		
		while (v!=-1)
			if (c[v]-f[v]>0 && vst[u]==vst[tv[v]]+1) break;else v=nxt[v];
		//printf("%d %d %d %d %d %d\n",u,v,tv[v],vst[u],vst[tv[v]],ans);
		if (v!=-1){
			cur[u]=v;
			u=tv[v];
			pre[u]=v;
			if (u==n){
				min=210000000;
				j=n;
				while (j!=1){
					i=pre[j];
					if (c[i]-f[i]<min) min=c[i]-f[i];
					j=tv[i^1];
				}
				j=n;
				while (j!=1){
					i=pre[j];
					f[i]+=min;
					f[i^1]-=min;
					j=tv[i^1];
				}
				ans+=min;
				u=1;
			}
		}
		else{
			cur[u]=a[u];
			min=n-1;
			i=a[u];
			while (i!=-1){
				if (c[i]-f[i]>0 && vst[tv[i]]<min)
					min=vst[tv[i]];
				i=nxt[i];
			}
			tmp=vst[u];
			no[vst[u]]--;
			vst[u]=min+1;
			no[vst[u]]++;
			if (u!=1) u=tv[pre[u]^1];
			if (no[tmp]==0) break;
		}
		//printf("%d %d\n",u,vst[u]);
	}
	return ans;
}
int main(){
	freopen("C: \\Users\\Zero\\Desktop\\in.txt","r",stdin);
	freopen("C: \\Users\\Zero\\Desktop\\out.txt","w",stdout);
	int m,i,x,y,z,j;
	while (scanf("%d%d",&m,&n)!=EOF){
		l=0;
		memset(a,255,sizeof(a));
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				b[i][j]=0;
		for (i=1;i<=m;i++){
			scanf("%d%d%d",&x,&y,&z);
			b[x][y]+=z;
		}
		l=-1;
		for (i=1;i<=n;i++)
			for (j=1;j<=n;j++)
				if (b[i][j]) {
					l++;
					c[l]=b[i][j];
					f[l]=0;
					tv[l]=j;
					nxt[l]=a[i];
					a[i]=l;
					l++;
					c[l]=f[l]=0;
					tv[l]=i;
					nxt[l]=a[j];
					a[j]=l;
				}
		printf("%d\n",max_flow());
	}
}
