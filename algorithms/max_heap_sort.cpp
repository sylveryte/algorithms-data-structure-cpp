#include<iostream>
#include "../sylvtools.cpp"

class MaxHeap{
	private:
		int n; //size of current heap
		int N; //max size of heap array a will be helpful in insertion
		int* a; //pointer to array

	public:
		//provided array, current size n, size of array
		MaxHeap(int* a,int n,int N){
			//cout << "new heap with size " << n << "/" << N << endl;
			this -> N = N;
			if(N<n){
				cout << "ERROR:size of array cannot be SMALLER than current size"<<endl;
				this-> N=n;
			}
			this -> a = a;
			this -> n = n;
			firstHeapify();
		}
		MaxHeap(int* a,int n){
			this -> a = a;
			this -> n = n;
			firstHeapify();
		}


		int max(){
			return a[0];
		}
		int extractMax(){
			if(n<0){return -99999;}
			int temp;
			temp=a[0];
			a[0]=a[n-1];
			n--;
			maxHeapifyDown(0);

			//printHeap();
			return temp;
		}
			

		void firstHeapify(){
			for(int i=(n-1)/2;i>=0;i--)maxHeapify(i);
		}
		int maxHeapify(int index){
			//cout <<"Heapifying ++++ " << index <<":"<< a[index] << endl;
			if(index>=n || index<0)return -1;
			int leftChildIndex = (2*index)+1;
			if(leftChildIndex>=n)return -1;
			int swapIndex,temp;

			if(n<2){
				if(a[index]<a[leftChildIndex])swapIndex=leftChildIndex;
				else return -1;
			}else{
				if(a[index]>a[leftChildIndex]&&a[index]>a[leftChildIndex+1])return -1;
				else if(a[leftChildIndex]>=a[leftChildIndex+1])swapIndex=leftChildIndex;
				else swapIndex=leftChildIndex+1;
			}
			temp=a[index];
			a[index]=a[swapIndex];
			a[swapIndex]=temp;

			//printHeap();

			return swapIndex;
		}
		void maxHeapifyDown(int index){
			int swapIndex=maxHeapify(index);
			if(swapIndex<0)return;
			maxHeapifyDown(swapIndex);
		}

		//dont need it.....yet
		/*void MaxHeapifyUp(int index){
		 *	if(index<=0)return;
		 *	maxHeapify(index);
		 *	if(index%2==0)//its a right child;
		 *		index=(index-2)/2;//parent
		 *		else
		 *			index/=2;//parent
		 *	MaxHeapifyUp(index);
		 *}
		 */

		void printchildren(int index){
			if(index>=n)return;
			int leftChildIndex = (2*index)+1;
			if(leftChildIndex>=n)return;
			cout << "~" << index << " -> " << a[index] ;
			if(leftChildIndex < n)cout << " : " << a[leftChildIndex];
			if(leftChildIndex+1 < n)cout << " _ " << a[leftChildIndex+1];
			printchildren(leftChildIndex);
			printchildren(leftChildIndex+1);
		}
		void printHeap(){
			cout << endl;
			for(int i=0;i<n;i++)cout<< "| " <<a[i] << " ";
			cout<< "|\nTree______" <<endl;
			printchildren(0);
			cout << endl;
		}
};

void heap_sort(int* a,int n){
	int b[n];
	for(int i=0;i<n;i++)b[i]=a[i];
	MaxHeap h=MaxHeap(b,n);
	for(int i=0;i<n;i++)a[i]=h.extractMax();
}



int main(){
	int a[9]={3,8,23,4,6,9,17,56,12};

	printa("Before : ",a,9);
	heap_sort(a,9);
//	MaxHeap h= MaxHeap(a,9,9);
	printa("after : ",a,9);
//	cout << h.extractMax()<<endl;

	return 0;
}
