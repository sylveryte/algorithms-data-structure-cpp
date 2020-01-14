#include<iostream>
#include "../sylvtools.cpp"

int binary_search(int start, int end,int* a, int k){
	/* takes an array a[] with start, end indexes and a key k
	 * returns index of key or next lower element's.
	 * */
	int m = (start+end)/2;
	/* printia("l", a, start,end); */
	/* cout << start << " and " << end << " = " << m << endl; */

	if(start == end) return m;

	if(end-start == 1)return (a[start]>k)?start:end;	

	if(a[m]>k) return binary_search(start,m, a, k);
	else return binary_search(m, end, a, k);
}

void binary_insertion_sort(int *a, int n){
	/* intsertion sort
	 * except for method of intsertion part, 
	 * it uses binary_search to find index where inserting element must go,
	 * then shifts rest of element and inserts the element.
	 * faster than vanilla intsertion sort
	 * */
	for(int i=1,j,t,k,rk; i<n; i++){
		j=i;
		k=a[i];
		/* cout<<endl; */
		/* cout << "k=" << k << "start=" << 0 << "end=" << j << endl; */ 
		/* printa("loc_bef",a,j+1); */
		rk=binary_search(0,j,a,k);
		/* cout << j << " j rk " << rk <<endl; */
		while(j>rk){
			a[j]=a[j-1];
			j--;
		}
		a[rk]=k;
		/* printa("loc_aft",a,i+1); */
		/* printa("loc_aft",a,n); */
	}
}

int main(){
	int a[10] = {4,7,1,21,43,14,34,2,25,23};

	printl("Binary Insertion SORT");
	printa("before",a,10);
	binary_insertion_sort(a,10);
	printa("after",a,10);

	return 0;
}
