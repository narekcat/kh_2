#include "stdafx.h"
#include "zujg.h"

void zujg::SetParam(short int sk,short int sn)
{
	K=sk;
	N=sn;
	p=new expen_gn[N];
	int i,l,j;
	for(l=0;l<N;l++)
		for(i=0;i<K;i++)
			for(j=0;j<K;j++)
				p[l].mat[i][j]='x';
	for(i=0;i<N;i++)
		this_drip[i]=K*(K-1)/2;
	all_drip=N*K*(K-1)/2;
	for(i=0;i<K+1;i++)
		for(j=0;j<K+2;j++)
			gumar[i][j]=0;
	index=0;
}

void zujg::run(double& W,double& S)
{
	int i,j,max;
	for(i=0;i<K;i++)
	{
		gumar[i][K+1]=0;
		gumar[K][i]=0;
	}
	for(i=0;i<K;i++)
	{
		max=0;
		while(gumar[max][K+1])
			max++;
		for(j=max+1;j<K;j++)
			if(gumar[j][K]>gumar[max][K] && gumar[j][K+1]==0)
				max=j;
		gumar[max][K+1]=i+1;
	}
/*	int nd[100],l;
	for(l=0;l<K;l++)
	{
		for(i=0;i<K;i++)
			nd[i]=0;
		for(i=0;i<K;i++)
		{
			max=0;
			while(nd[max])
				max++;
			for(j=max+1;j<K;j++)
				if(gumar[j][l]>gumar[max][l] && nd[j]==0)
					max=j;
			nd[max]=i+1;
		}
		for(i=0;i<K;i++)
			if(nd[i]==gumar[i][K+1])
				gumar[K][l]++;
	}*/
	int l;
	for(l=0;l<K;l++)
		for(i=0;i<K;i++)
			if(gumar[i][l]==gumar[i][K+1])
				gumar[K][l]++;
	double t=N*(K+1)/2.0;
	S=0;
	for(i=0;i<K;i++)
		S+=(gumar[i][K]-t)*(gumar[i][K]-t);
	double T=0;
	for(i=0;i<K;i++)
		T+=gumar[K][i]*(gumar[K][i]*gumar[K][i]-1);
	W=12*S/(N*N*(K*K*K-K)-N*T);
}

void zujg::Serialize(CArchive& archive)
{
	int i,j,l;
	if(archive.IsStoring())
	{
		archive<<K;
		archive<<N;
		for(l=0;l<N;l++)
			for(i=0;i<K;i++)
				for(j=0;j<K;j++)
					archive<<p[l].mat[i][j];
		archive<<all_drip;
		for(i=0;i<N;i++)
			archive<<this_drip[i];
		for(i=0;i<K+1;i++)
			for(j=0;j<K+2;j++)
				archive<<gumar[i][j];
		archive<<index;
	}
	else
	{
		archive>>K;
		archive>>N;
		p=new expen_gn[N];
		for(l=0;l<N;l++)
			for(i=0;i<K;i++)
				for(j=0;j<K;j++)
					archive>>p[l].mat[i][j];
		archive>>all_drip;
		for(i=0;i<N;i++)
			archive>>this_drip[i];
		for(i=0;i<K+1;i++)
			for(j=0;j<K+2;j++)
				archive>>gumar[i][j];
		archive>>index;
	}
}

IMPLEMENT_SERIAL(zujg,CObject,0)