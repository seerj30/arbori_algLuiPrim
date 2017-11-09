#include<iostream>
#include<fstream>
using namespace std;
int viz[50];

void citire(int &n,int a[50][50])
{
	int x,y,c;
	ifstream f("in.txt");
	f>>n;
	while(f>>x>>y>>c)
		a[x][y]=a[y][x]=c;
}

void tipar(int vf,int n,int a[50][50])
{
	viz[vf]=1;
	int minv=1000000,i,j,k,lin,col,ok,s=0;
	for(k=1;k<=n-1;k++)
	{
		minv=1000000;
		for(i=1;i<=n;i++)
		{
			ok=0;
			for(j=1;j<=n;j++)
				if(viz[i]==1 && viz[j]==0 && a[i][j]<minv)
				{
					minv=a[i][j];
					lin=i;
					col=j;
					ok=1;
				}
			if(ok)
			{
				s+=a[lin][col];
				cout<<lin<<" "<<col<<" cu costul: "<<a[lin][col]<<"\n";
				viz[col]=1;
			}
		}
	}
	cout<<"\n"<<"Costul de parcurgere a arborelui este: "<<s;
}

int main()
{
	int n,a[50][50],vf=1;
	for(int i=1;i<=49;i++)
		for(int j=1;j<=49;j++)
			a[i][j]=1000000;
	citire(n,a);
	tipar(vf,n,a);
	return 0;
}
