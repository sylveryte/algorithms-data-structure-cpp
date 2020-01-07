/*
 * nqueens.cpp
 * Copyright (C) 2020 sylveryte <sylveryte@archred>
 *
 * Distributed under terms of the MIT license.
 */

#include "nqueens.h"
#include<iostream>
#include<cmath>


using namespace std;

NqueensBoard:: ~NqueensBoard(){
	delete [] board;
};
NqueensBoard:: NqueensBoard(int n){
	this -> siNSize = n;
	this -> board = new int(n);
	for(int i=0; i< n; i++){
		this->board[i] = -1;
	}
};

void NqueensBoard:: printBoard(){
	cout << endl;

	cout << " ";
	for(int i=0; i< this -> siNSize; i++)
		cout << this -> board[i] << " | ";
	cout << endl;
	for(int i=0; i< this -> siNSize; i++)
		cout << "----";
	cout << endl;


	for(int i=0; i< this -> siNSize; i++){
		for(int j=0; j< this -> siNSize; j++){
			if ( this-> board[i] == j)
				cout << "_Q_|" ;
			else
				cout << "___|" ;
		}
		cout << endl;
	}
};

bool NqueensBoard:: isSafe(int i,int j){
	/* this -> printBoard(); */
	/* cout << "cecking for i&j " <<i << " " << j << endl; */

	//row checks
	for(int li=0;li < i; li++){
		if(this->board[li] == j)
			return false;
	}

	//diagonal check
	for(int li=0;li < i; li++){
		short int columnDiff = abs(i-li);
		short int rowDiff = abs(j-this->board[li]);

		if(columnDiff == rowDiff) return false;
	}

	/* cout << " it passed" << endl; */
	return true;
}

//make it non -recursive
bool NqueensBoard:: solveQueens(int i,int j){
	for(; j < this -> siNSize; j++){
		if(isSafe(i,j)){
			this -> board[i] = j;
			if(i == this -> siNSize -1 )
				return true;
			if(solveQueens(i+1,0)) {
				printBoard();
			}
		}
	}
	return false;
}

void NqueensBoard:: printAllSolutions(){
	if(!solveQueens(0,0)){
		cout << "No More solutions" << endl;
	}
}


void endGame(){
	cout << "-------------------Game out-------------" << endl;
}
int main(){

	NqueensBoard q4 = NqueensBoard(4);
	q4.printAllSolutions();

	NqueensBoard q6 = NqueensBoard(6);
	q6.printAllSolutions();

	endGame();
	return 0;
}
