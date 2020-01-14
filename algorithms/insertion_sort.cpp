#include<iostream>
#include "../sylvtools.cpp"

void insertion_sort(int *a, int n){
	/* interts element in sorted array and keeping 
	 * sorted property of the array
	 * better use binary_insertion_sort
	 * */
	int t=0;
	for(int i=1,j=0; i<n; i++){
		j=i;
		t=a[j];
		while(j>0 && a[j-1]>t) a[j--]=a[j-1];
		a[j]=t;
	}
}

int main(){
	int a[10] = {4,7,1,21,43,14,34,2,25,23};

	printl("Insertion SORT");
	printa("before",a,10);
	insertion_sort(a,10);
	printa("after",a,10);

	return 0;
}
