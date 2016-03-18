#include <bits/stdc++.h>
#define MAX 1000000
#define IVL 8
#define ONEMASK 255

using namespace std;

char VISIT[MAX]={0};
unsigned int arr[MAX]={0};

inline void unmark(int term, int diff)
{
	//cout<<(int)VISIT[term]<<endl;
	VISIT[term] = VISIT[term] & (~(1<<diff));
	//cout<<(int)VISIT[term]<<endl;
}

inline bool mark(int term, int diff)
{
	if(VISIT[term]&(1<<diff))	return true;
	VISIT[term]|=(1<<diff);
	return false;
}

inline void prtout(const int n)
{
	cout<<arr[0];
	for(int i=1; i<n; i++)
		cout<<' '<<arr[i];
	cout<<'\n';
}

inline void dfs(const int n, const int max_d, int depth)
{
	int term, diff;
	if(max_d==depth)
	{
		prtout(n);
	}
	else
	{
		for(int i=n; i>=1; i--)
		{
			term = i/sizeof(char); diff = i%sizeof(char);
			if(!mark(term,diff))//Haven't visited;Mark it
			{
				//cout<<"debug: "<<i<<"\tdepth: "<<depth<<endl;
				arr[depth] = i;
				dfs(n,max_d,depth+1);
				unmark(term, diff);
			}
		}
	}
}

int main(void)
{
	//freopen("testout.txt","w",stdout);
	cin.sync_with_stdio(false);
	int num;
	for(int i=0; i<MAX; i++)VISIT[i] = 0;
	cin>>num;
	dfs(num,num,0);

	return 0;
}
