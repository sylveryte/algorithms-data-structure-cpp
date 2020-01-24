/*
 * memoization.cpp
 * Copyright (C) 2019 sylveryte <sylveryte@archblue>
 *
 * Distributed under terms of the MIT license.
 */

#include "memoization.h"

using namespace std;

//memoized fib
map<int,int> fm;
int fibm(int n){
	/* fibonacci number with memoization */
	int f;
	if(n<3)return 1;
	else if(fm[n])return fm[n];
	f = fibm(n-1)+fibm(n-2);
	fm[n]=f;
	return f;
}

int fib(int n){
	/* fibonacci number */
	if(n<3)return 1;
	else return fib(n-1)+fib(n-2);
}

int main(){
	int N = 46; // Fibonacci of number N


	int start = clock();
	cout << endl <<"Traditional recursive fib" << endl;
	for(int i=1;i<N;i++)cout << fib(i) << ",";
	cout << endl;
	int end = clock();//Now check what amount of ticks we have now.
	std::cout << "it took " << end - start << "ticks, or " << ((float)end - start)/CLOCKS_PER_SEC << "seconds." << std::endl;

	int startm = clock();
	cout << endl <<"Memoized recursive fibm" << endl;
	for(int i=1;i<N;i++)cout << fibm(i) << ",";
	cout << endl;
	int endm = clock();//Now check what amount of ticks we have now.
	std::cout << "it took " << endm - startm << "ticks, or " << ((float)endm - startm)/CLOCKS_PER_SEC << "seconds." << std::endl;
}

