#include <iostream>
#include "matrix.h"
#include "NNet.h"

#define newLine std::cout << std::endl;

int main(){

	size_t n;
	std::cout << "Number of examples: ";
	std::cin >> n;

	size_t nIn;
	std::cout << "Number of inputs: ";
	std::cin >> nIn;

	size_t nNeur;
	std::cout << "Number of neurons: ";
	std::cin >> nNeur;

	size_t nOut;
	std::cout << "Number of outputs: ";
	std::cin >> nOut;
 
	Matrix X( n, nIn  );
	Matrix y( n, nOut );

	for( size_t r = 0; r < n; ++r ){

		std::cout << r << "-st example:" << std::endl;;

		std::cout << "X: ";
		for( size_t c = 0; c < nIn;  ++c )
			std::cin >> X[r][c] ;

		std::cout << "y: ";
		for( size_t c = 0; c < nOut; ++c )
			std::cin >> y[r][c];
	}

	newLine;
	std::cout << "X: " << std::endl;
	X.print();
	newLine;

	std::cout << "y: " << std::endl;
	y.print();
	newLine;

	std::cout << "network( nIn, nNeur, nOut )" << std::endl;
	NNet network( nIn, nNeur, nOut );
	newLine;

	std::cout << "network weights:" << std::endl;
	network.print();
	newLine;

	std::cout << "network.forward(X)" << std::endl;
	Matrix rez = network.forward( X );
	rez.print();
	newLine;

	return 0;
}
