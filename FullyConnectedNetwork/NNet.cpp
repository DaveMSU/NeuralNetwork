#include <iostream>
#include <cmath>
#include "matrix.h"
#include "NNet.h"

// Initialize:
// - number of input features,
// - number of neuron on hidden layer (here is one hidden layer),
// - number of outputs,
// - weigth matrix (by random),
// - bias (by zero).
//
NNet::NNet( const size_t in_am, const size_t neur_am, const size_t out_am ) :
	input_amount( in_am ), neuron_amount( neur_am ), output_amount( out_am ){

	// vector = column vector, so we create already transposed weight matrix.
	//
	W0 = Matrix( neuron_amount, input_amount  ); 
	W1 = Matrix( output_amount, neuron_amount );


	// fill weight matrix by random number from [-0.01 , 0.01]
	// to prevent of vanishing ot exploding of gradient.
	// ( in deep network implementation it will be realized Xavier initialization)
	//
	W0.apply( [](){ return (2*(rand()/(double)RAND_MAX) - 1) * 0.01; } );
	W1.apply( [](){ return (2*(rand()/(double)RAND_MAX) - 1) * 0.01; } );

	// if we initializated W by zeros, it would cause network symmetry problem, 
	// so if we init. W by rand, we can init. bias by zeros.
	//
	
	b0 = Matrix( neuron_amount, 1 ); // it'll broadcasting which implemented in matrix.h.
	b1 = Matrix( output_amount, 1 );

	b0.apply( [](){ return 0.0; } );
	b1.apply( [](){ return 0.0; } );
}

void NNet::print(){

	std::cout << "W0:" << std::endl;
	W0.print();
	std::cout << std::endl;

	std::cout << "W1:" << std::endl;
	W1.print();
	std::cout << std::endl;

	std::cout << "b0:" << std::endl;
	b0.print();
	std::cout << std::endl;

	std::cout << "b1:" << std::endl;
	b1.print();
	std::cout << std::endl;
}

Matrix NNet::forward( const Matrix& X_input ){

	size_t example_amount = X_input.get_columns(); // brief abbreviation: exmpl_am.

	Matrix Z1 = W0.dot(X_input.T()) + b0; // neur_am x exmpl_am.
	Matrix A1 = Z1;
	A1.apply( [](double x){ return 1 / (1 + exp(-x)); } ); // applying sigmoid.                       
	Matrix Z2 = W1.dot(A1) + b1; // out_am x exmpl_am.
	Matrix A2 = Z2;
	A2.apply( [](double x){ return 1 / (1 + exp(-x)); } );
	
	Matrix y_hat = A2; // out_am x exmpl_am = vector-answer for each example.

	return y_hat;
}
