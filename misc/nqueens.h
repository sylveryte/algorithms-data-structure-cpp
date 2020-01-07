/*
 * nqueens.h
 * Copyright (C) 2020 sylveryte <sylveryte@archred>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef NQUEENS_H
#define NQUEENS_H


class NqueensBoard{
	private:
		short int siNSize;
		int* board;
		bool isSafe(int,int);
		bool solveQueens(int,int);

	public:
		void printBoard();
		void printAllSolutions();
		NqueensBoard(int n);
		~NqueensBoard();

};
#endif /* !NQUEENS_H */
