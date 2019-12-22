#include <iostream>
#include "../sylvtools.cpp"

void merge(int* a,int s, int e){
	//cout << " -----> " << s << " : " << e << endl;
	//printa("whola",a,10);
	if(s==e){
		return;
	}
	int m = (s+e)/2;
	merge(a,s,m);
	merge(a,m+1,e);

	//cout << m << " <- " << s << " : " << e << endl;
	//printl("2 splits >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ");

	int lc=m-s+1, rc=e-m, fk;
	int la[lc],ra[rc];
	for(int i=0,fk=s;i<lc;i++)la[i]=a[fk++];
	for(int i=0,fk=m+1;i<rc;i++)ra[i]=a[fk++];
	//printa("first",la,lc);
	//printa("sicnd",ra,rc);

	int rsk=s;
	int lk=0,rk=0;
	//for(int qi=s,qe=e;qi<=qe;qi++)a[qi]=0;
	//printa("before merge",a,10);
	while(1){
		if(lk==lc || rk == rc)break;
		if(la[lk]<=ra[rk]) a[rsk++]=la[lk++];
		if(ra[rk]<=la[lk]) a[rsk++]=ra[rk++];
	}
	//printa("between merge",a,10);
	//cout << "lk=" << lk << "lc=" << lc << "   rk=" << rk << "rc=" << rc << endl;
	while(lk<lc)a[rsk++]=la[lk++];
	while(rk<rc)a[rsk++]=ra[rk++];
	//cout << "lk=" << lk << "lc=" << lc << "   rk=" << rk << "rc=" << rc << endl;
	//printa("after merge",a,10);
}

void merge_sort(int* a, int n){
	merge(a,0,n-1);
}



int main(){
	int a[10] = {4,7,1,21,43,14,34,2,25,23};

	printl("Merge SORT");
	printa("before",a,10);
	merge_sort(a,10);
	printa("after",a,10);

	return 0;
}
