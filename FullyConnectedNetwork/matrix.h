#pragma once

typedef double value_type;

class ContData{
	

	size_t block_size;
	size_t blocks;
	value_type* data;
public:
	ContData( size_t, value_type* );
	value_type& operator[]( size_t );
	const value_type& operator[]( size_t ) const;
	~ContData();
};

class Matrix{

	size_t num_rows;
	size_t num_cols;
	value_type* data;
public:
	Matrix();
	Matrix( const size_t r, const size_t c );
	Matrix( const Matrix& matr );             // Copy constructor.
	Matrix& operator=( const Matrix& matr );
	ContData operator[]( size_t );
	const ContData operator[]( size_t ) const;

	Matrix operator*( const Matrix& rmatrix ) const;
	Matrix operator/( const Matrix& rmatrix ) const;
	Matrix operator+( const Matrix& rmatrix ) const;
	Matrix operator-( const Matrix& rmatrix ) const;

	Matrix operator*( double value ) const;
	Matrix operator/( double value ) const;
	Matrix operator+( double value ) const;
	Matrix operator-( double value ) const;
	
	Matrix& operator*=( double value );
	Matrix& operator/=( double value );
	Matrix& operator+=( double value );
	Matrix& operator-=( double value );	

	void apply( value_type (*function)( value_type value ) );
	void apply( value_type (*function)() );
	Matrix dot( const Matrix& rmatrix ) const;
	bool operator==( const Matrix& tmp_matrix ) const;
	bool operator!=( const Matrix& tmp_matrix ) const;
	size_t get_rows() const;
	size_t get_columns() const;
	Matrix T() const;
	void T_it();
	void print();
	~Matrix();
};
