#include <iostream>
#include "../sylvtools.cpp"

void merge(int* a,int start, int end){

	/* DIVIDE */

	//cout << " -----> " << start << " : " << end << endl;
	//printa("whola",a,10);
	if(start==end){
		return;
	}
	int middle = (start+end)/2;
	merge(a,start,middle);
	merge(a,middle+1,end);

	//cout << middle << " <- " << start << " : " << end << endl;
	//printl("2 splits >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> ");


	/* CONQUER/MERGE */

	int lc=middle-start+1, rc=end-middle, fk;
	int la[lc],ra[rc];
	for(int i=0,fk=start;i<lc;i++)la[i]=a[fk++];
	for(int i=0,fk=middle+1;i<rc;i++)ra[i]=a[fk++];
	//printa("first",la,lc);
	//printa("sicnd",ra,rc);

	int rsk=start;
	int lk=0,rk=0;
	//for(int qi=s,qe=end;qi<=qe;qi++)a[qi]=0;
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
	/* sorts array a of size n, 
	 * using divide & conquer technique merge_sort
	 * */
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
