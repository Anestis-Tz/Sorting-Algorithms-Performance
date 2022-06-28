#include "Pinakas.h"
#include "RandMT.h"
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <algorithm> //sort

using namespace std;

void Pinakas::setArraySize(int n1){
	n=n1;
}

void Pinakas::createArray(){
	p=new int[n];
}

void Pinakas::copyArray(Pinakas ant){
	long i;
	for(i=0;i<n;i++){
		ant.p[i]=p[i];
	}
}

void Pinakas::freeMemory(){
	delete []p;
}

void Pinakas::fill_100(){
	long i;
	RandMT r;
	
	RandMT(time(NULL));
	for(i=0;i<n;i++){
		p[i]=r();
	}
}

void Pinakas::fill_50_sorted(){
	int m=n/2,i;
	RandMT r;
	
	RandMT(time(NULL));
	for(i=0;i<m;i++){
		p[i]=r();
	}
	sort(p,p+m); //den to exoume didaxtei alla den vrika kati allo sto stack overflow
	
	RandMT(time(NULL));
	for(i=m;i<n;i++){
		p[i]=r();
	}
}

void Pinakas::fill_DESC(){
	int i,j,t,x;
	RandMT r;
	
	RandMT(time(NULL));
	for(i=0;i<n;i++){
		p[i]=r();
	}
	for (i=2; i<=n; i++){
		x = p[i];
		p[0] = x;
		j = i -1;
		while (x > p[j]){
			p[j+1] = p[j] ;
			j = j-1 ;
		}
	p[j+1] = x ;
	}
}

void Pinakas::fill_ASC(){
	int i,j,t,x;
	RandMT r;
	
	RandMT(time(NULL));
	for(i=0;i<n;i++){
		p[i]=r();
	}
	
	for (i=2; i<=n; i++){
		x = p[i];
		p[0] = x;
		j = i -1;
		while (x < p[j]){
			p[j+1] = p[j] ;
			j = j-1 ;
		}
	p[j+1] = x ;
	}
	
}

void Pinakas::bubble(){
	long long i,j,t;
	for(i=1; i<n; i++)
		for(j=n-1;j>=1;j--)
			if(p[j-1]>p[j]){
				t = p[j-1];
				p[j-1]=p[j];
				p[j]=t;
	 } 
}

void Pinakas::select(){
	int i,j,k,min;
	
	for(i=0; i<n-1; i++){
		min = p[i];
		for(j=i+1; j<n; j++){
			if(p[j] < min){
				k = j;
				min = p[j];
			}
		}
		p[k] = p[i];
		p[i] = min;
	}
}

void Pinakas::insert(){
	long long i,j,x;
	
	for (i=2; i<=n; i++){
		x = p[i];
		p[0] = x;
		j = i -1;
		while (x < p[j]){
			p[j+1] = p[j] ;
			j = j-1 ;
		}
	p[j+1] = x ;
	}
}

void Pinakas::quick(int left,int right){
	long i,j,mid,x,t;
	if (left < right){
		i = left;
		j = right;
		mid = (left+right)/2;
		x = p[mid];
		while (i < j){
			while (p[i] < x)
				i++;
				while (p[j] > x)
					j--;
					if (i < j){
						if (p[i] == p[j]){
							if (i<mid)
								i++;
							if (j>mid)
								j--;
						}
					else{
						t = p[i];
						p[i] = p[j];
						p[j] = t;
					}
					}
		}
		quick(left,j-1);
		quick(j+1,right);
	}
}



