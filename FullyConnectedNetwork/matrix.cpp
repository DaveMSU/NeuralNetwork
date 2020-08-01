#include <iostream>
#include <vector>
#include "matrix.h"

//----------------------------CONT_DATA:--------------------------------
ContData::ContData( size_t size , value_type* ptr ) : block_size(size), data(ptr){}

value_type& ContData::operator[]( size_t index ){
	
	if( index >= block_size )
		throw std::out_of_range("");
	return data[index];
}	

const value_type& ContData::operator[]( size_t index ) const {
	
	if( index >= block_size )
		throw std::out_of_range("");
	return data[index];
}	

ContData::~ContData(){}

//-----------------------------Matrix:----------------------------------
Matrix::Matrix(){ data = nullptr; }

Matrix::Matrix( const size_t r, const size_t c ) : num_rows(r), num_cols(c){

	data = new value_type[r*c];
}

Matrix::Matrix( const Matrix& matr ) : num_rows(matr.num_rows), num_cols(matr.num_cols){

//	delete [] data;
	data = new value_type[num_rows * num_cols];
	for( size_t i = 0; i < num_rows * num_cols; ++i )
		data[i] = matr.data[i];
}

Matrix& Matrix::operator=( const Matrix& rmatrix ){

//	if( num_rows != rmatrix.get_rows() ||
//	    num_cols != rmatrix.get_columns() ){

		delete [] data;
		num_rows = rmatrix.get_rows();
		num_cols = rmatrix.get_columns();
		data = new value_type[num_rows * num_cols];
//	}

	for( size_t i = 0; i < num_rows; ++i )
		for( size_t j = 0; j < num_cols; ++j )
			data[ i * num_cols + j ] = rmatrix.data[ i * num_cols + j ];
	return *this;
}

ContData Matrix::operator[]( size_t index ){

	if( index >= num_rows )
		throw std::out_of_range("");
	return ContData( num_cols, data + index*num_cols );
}

const ContData Matrix::operator[]( size_t index ) const {

	if( index >= num_rows )
		throw std::out_of_range("");
	return ContData( num_cols, data + index*num_cols );
}

//-----------------------------------Matrix:------------------------------------------
//

Matrix Matrix::operator*( const Matrix& rmatrix ) const {

	if( rmatrix.get_columns() != num_cols &&
	    rmatrix.get_columns() != 1	||
	    rmatrix.get_rows() != num_rows &&
	    rmatrix.get_rows() != 1 )		
	
		throw std::out_of_range("");


	Matrix new_matrix( num_rows, 
			   num_cols );


	// broadcasting by same rows number.
	if( rmatrix.get_columns() == 1 &&
	    rmatrix.get_rows() == num_rows ){

		for( size_t i = 0; i < num_rows; ++i )
			for( size_t j = 0; j < num_cols; ++j )
				new_matrix.data[ i * num_cols + j ] = data[ i * num_cols + j ] * rmatrix.data[i];
		return new_matrix;
	}


	// broadcasting by same cols number.
	if( rmatrix.get_rows() == 1 &&
	    rmatrix.get_columns() == num_cols ){

		for( size_t i = 0; i < num_rows; ++i )
			for( size_t j = 0; j < num_cols; ++j )
				new_matrix.data[ i * num_cols + j ] = data[ i * num_cols + j ] * rmatrix.data[j];
		return new_matrix;
	}	


	for( size_t i = 0; i < num_cols * num_rows; ++i )
		new_matrix.data[i] = data[i] * rmatrix.data[i];

	return new_matrix;
}


Matrix Matrix::operator/( const Matrix& rmatrix ) const {

	if( rmatrix.get_columns() != num_cols &&
	    rmatrix.get_columns() != 1	||
	    rmatrix.get_rows() != num_rows &&
	    rmatrix.get_rows() != 1 )		
	
		throw std::out_of_range("");


	Matrix new_matrix( num_rows, 
			   num_cols );


	// broadcasting by same rows number.
	if( rmatrix.get_columns() == 1 &&
	    rmatrix.get_rows() == num_rows ){

		for( size_t i = 0; i < num_rows; ++i )
			for( size_t j = 0; j < num_cols; ++j )
				new_matrix.data[ i * num_cols + j ] = data[ i * num_cols + j ] / rmatrix.data[i];
		return new_matrix;
	}


	// broadcasting by same cols number.
	if( rmatrix.get_rows() == 1 &&
	    rmatrix.get_columns() == num_cols ){

		for( size_t i = 0; i < num_rows; ++i )
			for( size_t j = 0; j < num_cols; ++j )
				new_matrix.data[ i * num_cols + j ] = data[ i * num_cols + j ] / rmatrix.data[j];
		return new_matrix;
	}	


	for( size_t i = 0; i < num_cols * num_rows; ++i )
		new_matrix.data[i] = data[i] / rmatrix.data[i];

	return new_matrix;
}

Matrix Matrix::operator+( const Matrix& rmatrix ) const {

	if( rmatrix.get_columns() != num_cols &&
	    rmatrix.get_columns() != 1	||
	    rmatrix.get_rows() != num_rows &&
	    rmatrix.get_rows() != 1 )		
	
		throw std::out_of_range("");


	Matrix new_matrix( num_rows, 
			   num_cols );


	// broadcasting by same rows number.
	if( rmatrix.get_columns() == 1 &&
	    rmatrix.get_rows() == num_rows ){

		for( size_t i = 0; i < num_rows; ++i )
			for( size_t j = 0; j < num_cols; ++j )
				new_matrix.data[ i * num_cols + j ] = data[ i * num_cols + j ] + rmatrix.data[i];
		return new_matrix;
	}


	// broadcasting by same cols number.
	if( rmatrix.get_rows() == 1 &&
	    rmatrix.get_columns() == num_cols ){

		for( size_t i = 0; i < num_rows; ++i )
			for( size_t j = 0; j < num_cols; ++j )
				new_matrix.data[ i * num_cols + j ] = data[ i * num_cols + j ] + rmatrix.data[j];
		return new_matrix;
	}	


	for( size_t i = 0; i < num_cols * num_rows; ++i )
		new_matrix.data[i] = data[i] + rmatrix.data[i];

	return new_matrix;
}

Matrix Matrix::operator-( const Matrix& rmatrix ) const {

	if( rmatrix.get_columns() != num_cols &&
	    rmatrix.get_columns() != 1	||
	    rmatrix.get_rows() != num_rows &&
	    rmatrix.get_rows() != 1 )		
	
		throw std::out_of_range("");


	Matrix new_matrix( num_rows, 
			   num_cols );


	// broadcasting by same rows number.
	if( rmatrix.get_columns() == 1 &&
	    rmatrix.get_rows() == num_rows ){

		for( size_t i = 0; i < num_rows; ++i )
			for( size_t j = 0; j < num_cols; ++j )
				new_matrix.data[ i * num_cols + j ] = data[ i * num_cols + j ] - rmatrix.data[i];
		return new_matrix;
	}


	// broadcasting by same cols number.
	if( rmatrix.get_rows() == 1 &&
	    rmatrix.get_columns() == num_cols ){

		for( size_t i = 0; i < num_rows; ++i )
			for( size_t j = 0; j < num_cols; ++j )
				new_matrix.data[ i * num_cols + j ] = data[ i * num_cols + j ] - rmatrix.data[j];
		return new_matrix;
	}	


	for( size_t i = 0; i < num_cols * num_rows; ++i )
		new_matrix.data[i] = data[i] - rmatrix.data[i];

	return new_matrix;
}

//-----------------------------------Bin. Value:------------------------------------------
//

Matrix Matrix::operator*( double value ) const {

	Matrix new_matrix( num_rows, num_cols );
	for( size_t i = 0; i < num_cols * num_rows; ++i )
		new_matrix.data[i] = data[i] * value;
	return new_matrix;
}

Matrix Matrix::operator/( double value ) const {

	Matrix new_matrix( num_rows, num_cols );
	for( size_t i = 0; i < num_cols * num_rows; ++i )
		new_matrix.data[i] = data[i] / value;
	return new_matrix;
}

Matrix Matrix::operator+( double value ) const {

	Matrix new_matrix( num_rows, num_cols );
	for( size_t i = 0; i < num_cols * num_rows; ++i )
		new_matrix.data[i] = data[i] + value;
	return new_matrix;
}

Matrix Matrix::operator-( double value ) const {

	Matrix new_matrix( num_rows, num_cols );
	for( size_t i = 0; i < num_cols * num_rows; ++i )
		new_matrix.data[i] = data[i] - value;
	return new_matrix;
}

//-----------------------------------Un. Value:------------------------------------------
//

Matrix& Matrix::operator*=( double value ){

	for( size_t i = 0; i < num_cols * num_rows; ++i )
		data[i] *= value;
	return *this;
}

Matrix& Matrix::operator/=( double value ){

	for( size_t i = 0; i < num_cols * num_rows; ++i )
		data[i] /= value;
	return *this;
}

Matrix& Matrix::operator+=( double value ){

	for( size_t i = 0; i < num_cols * num_rows; ++i )
		data[i] += value;
	return *this;
}

Matrix& Matrix::operator-=( double value ){

	for( size_t i = 0; i < num_cols * num_rows; ++i )
		data[i] -= value;
	return *this;
}

//-----------------------------------Methods:------------------------------------------
//

void Matrix::apply( value_type (*function)() ){

	for( size_t i = 0; i < num_cols * num_rows; ++i )
		data[i] = function();
}

void Matrix::apply( value_type (*function)( value_type value ) ){

	for( size_t i = 0; i < num_cols * num_rows; ++i )
		data[i] = function(data[i]);
}

Matrix Matrix::dot( const Matrix& rmatrix ) const {

	if( num_cols != rmatrix.get_rows() )
		throw std::out_of_range("");

	Matrix new_matrix( num_rows, rmatrix.get_columns() );

	value_type tmp_cij;
	
	for( size_t i = 0; i < num_rows; ++i )
		for( size_t j = 0; j < rmatrix.get_columns(); ++j ){

			tmp_cij = 0;
			for( size_t k = 0; k < num_cols; ++k )
				tmp_cij += data[ i * num_cols + k ] * rmatrix.data[ k * rmatrix.get_columns() + j ];
			
			new_matrix.data[ i * rmatrix.get_columns() + j ] = tmp_cij;
		}

	return new_matrix;
}

bool Matrix::operator==( const Matrix& right ) const {

	if( right.get_rows() != num_rows 
			|| right.get_columns() != num_cols )
		return false;

	for( size_t i = 0; i < num_rows; ++i )
		for( size_t j = 0; j < num_cols; ++j )
			if( data[ i * num_cols + j ] != right[i][j] )
				return false;
	return true;
}

bool Matrix::operator!=( const Matrix& right ) const {

	return !(*this==right);
}

size_t Matrix::get_rows() const {
	
	return num_rows;
}

size_t Matrix::get_columns() const {

	return num_cols;
}

void Matrix::T_it(){ // Inplace.

	value_type* tmp_data = new value_type[num_cols * num_rows];
	for( size_t i = 0; i < num_cols * num_rows; ++i )
		tmp_data[i] = data[i];

	for( size_t i = 0; i < num_rows; ++i )
		for( size_t j = 0; j < num_cols; ++j )
			data[ j * num_rows + i ] = tmp_data[ i * num_cols + j ];

	delete [] tmp_data;
	num_rows ^= num_cols;
	num_cols ^= num_rows;
	num_rows ^= num_cols;
}

Matrix Matrix::T() const {

	Matrix new_matrix(num_cols, num_rows);

	for( size_t i = 0; i < num_rows; ++i )
		for( size_t j = 0; j < num_cols; ++j )
			new_matrix.data[ j * num_rows + i ] = data[ i * num_cols + j ];
	return new_matrix;
}

void Matrix::print(){

	for( int i = 0; i < num_rows; ++i ){
		for( int j = 0; j < num_cols; ++j )
			std::cout << data[ i * num_cols + j ] << " ";
		std::cout << "\n";
	}
}

Matrix::~Matrix(){

	if( data != nullptr )
		delete [] data;
}
