#pragma once

class NNet{

	size_t input_amount;  // brief abbreviation: in_am,
	size_t neuron_amount; // neur_am,
	size_t output_amount; // out_am.

	Matrix W0, W1; 	      // Matrixes of weights for hidden layer and output layer.
	Matrix b0, b1;	      // Bieses -//-

public:
	NNet( const size_t, const size_t, const size_t ); // initialize in_am, neur_am, out_am, W, b.
	void print(); // print all weights.
	Matrix forward( const Matrix& X_input ); // forward propagation.
};
