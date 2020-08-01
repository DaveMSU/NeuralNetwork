#include <iostream>
#include "matrix.h"

#define columns_number 6
#define rows_number 3
#define newLine std::cout << std::endl;

void fill_matrix( Matrix& A, 
		  int rows = rows_number, 
		  int columns = columns_number  ){

	for( int i = 0; i < rows; ++i )
       		for( int j = 0; j < columns; ++j )
       			A[i][j] = i*j;
}

int main(){

	newLine;

	Matrix A( rows_number, columns_number );
	std::cout << "Создали матрицу A!" << std::endl;
	std::cout << "Переписываем матрицу: A[i][j] = i*j" << std::endl;
	fill_matrix(A);
	A.print();
	std::cout << "Кол-во строк: "    << A.get_rows()    << std::endl;
	std::cout << "Кол-во столбцов: " << A.get_columns() << std::endl;
	newLine;

	int val_int = 2;
	std::cout << "Умножаем матрицу на " << val_int << ":\n";
	A *= val_int;
	A.print();
	newLine;

	double val_double = 3.1415;
	std::cout << "Умножаем матрицу на " << val_double << ":\n";
	A *= val_double;
	A.print();
	newLine;
	
	fill_matrix(A);
	std::cout << "Переписываем матрицу: A[i][j] = i*j" << std::endl;
	A.print();
	newLine;

	std::cout << "Умножаем матрицу на " << 5 << "(число):\n";
	A *= 5;
	A.print();
	newLine;

	Matrix B( rows_number, columns_number );
	std::cout << "Создали матрицу B!" << std::endl;
	std::cout << "Переписываем матрицу: B[i][j] = i*j" << std::endl;
	fill_matrix(B);
	B.print();
	std::cout << "Кол-во строк: "    << B.get_rows()    << std::endl;
	std::cout << "Кол-во столбцов: " << B.get_columns() << std::endl;
	newLine;

	std::cout << "Вопрос: A == B?\nОтвет: " << (A == B) << std::endl;
	newLine;

	std::cout << "Вопрос: A != B?\nОтвет: " << (A != B) << std::endl;
	newLine;

	std::cout << "Умножаем матрицу B на " << 5 << "(число):\n";
	B *= 5;
	B.print();
	newLine;

	std::cout << "Вопрос: A == B?\nОтвет: " << (A == B) << std::endl;
	newLine;

	Matrix C(4, 3);
	std::cout << "Создали матрицу C!" << std::endl;
	std::cout << "Переписываем матрицу: C[i][j] = i*j" << std::endl;
	fill_matrix(C, 4, 3);
	C.print();
	std::cout << "Кол-во строк: "    << C.get_rows()    << std::endl;
	std::cout << "Кол-во столбцов: " << C.get_columns() << std::endl;
	newLine;

	std::cout << "Вопрос: A == C?\nОтвет: " << (A == C) << std::endl;
	newLine;

	std::cout << "Вопрос: A != C?\nОтвет: " << (A != C) << std::endl;
	newLine;

	std::cout << "Матрица B:" << std::endl;
	B.print();
	newLine;

	std::cout << "B = C" << std::endl;
	B = C;
	newLine;

	std::cout << "Матрица B:" << std::endl;
	B.print();
	newLine;

	std::cout << "Матрица C:" << std::endl;
	C.print();
	newLine;

	std::cout << "Матрица A:" << std::endl;
	A.print();
	newLine;

	std::cout << "C = B.dot(A)" << std::endl;
	C = B.dot(A);
	newLine;

	std::cout << "Матрица C:" << std::endl;
	C.print();
	newLine;

	std::cout << "C.T_it()" << std::endl;
	C.T_it();
	newLine;

	std::cout << "Матрица C:" << std::endl;
	C.print();
	newLine;

	std::cout << "C = B.T() + B.T()" << std::endl;
	C = B.T() + B.T();
	newLine;

	std::cout << "Матрица С:" << std::endl;
	C.print();
	newLine;

	double x = A[1][3];
	double z = C[2][2];	
	
	std::cout << "x = A[1][3] = " << x << std::endl;
	std::cout << "B[2][1]  =  " << B[2][1] << std::endl;
	std::cout << "z = C[2][2] = " << z << std::endl;
	newLine;

	std::cout << "x * B[2][1] * z  =  " << x * B[2][1] * z << std::endl;
	newLine;

	std::cout << "Матрица B:" << std::endl;
	B.print();
	newLine;

	std::cout << "B *= 3" << std::endl; 
	B *= 3;
	newLine;

	std::cout << "Матрица B:" << std::endl;
	B.print();
	newLine;

	std::cout << "B /= x" << std::endl;
	B /= x;
	newLine;

	std::cout << "Матрица B:" << std::endl;
	B.print();
	newLine;

	std::cout << "C = Matrix( 4, 1 ); = [0, 1, 2, 3]" << std::endl;
	C = Matrix( 4, 1 ); 
	for( size_t i = 0; i < 4; ++i ) C[i][0] = i;
	newLine;

	std::cout << "A = B + C" << std::endl;
	A = B + C;
	newLine;

	std::cout << "Матрица A:" << std::endl;
	A.print();
	newLine;

	std::cout << "Matrix E = B + C;" << std::endl;
	Matrix E = B + C;
	newLine;

	std::cout << "Матрица E:" << std::endl;
	E.print();
	newLine;

	std::cout << "Матрица B:" << std::endl;
	B.print();
	newLine;

	std::cout << "B * E:" << std::endl;
	(B*E).print();
	newLine;

	std::cout << "B * C:" << std::endl;
	(B*C).print();
	newLine;

	std::cout << "C = Matrix( 1, 3 ); = [2, 4, 6]" << std::endl;
	C = Matrix( 1, 3 ); 
	for( size_t i = 0; i < 3; ++i ) C[0][i] = (i+1)*2;
	newLine;

	std::cout << "B / C:" << std::endl;
	(B/C).print();
	newLine;

	std::cout << "C = B * 0" << std::endl;
	C = B * 0;
	newLine;

	std::cout << "Матрица C:" << std::endl;
	C.print();
	newLine;

	std::cout << "Матрица B:" << std::endl;
	B.print();
	newLine;

	std::cout << "C = B * 2 + 1 + B" << std::endl;
	C = B * 2 + 1 + B;
	newLine;

	std::cout << "Матрица C:" << std::endl;
	C.print();
	newLine;

	std::cout << "C.apply( [](double x){ return x * x + 1; } );" << std::endl;
	C.apply( [](double x){ return x * x + 1; } );
	newLine;

	std::cout << "Матрица C:" << std::endl;
	C.print();
	newLine;

	std::cout << "C.apply( [](){ return rand()/(double)RAND_MAX; } );" << std::endl;
	C.apply( [](){ return 2*(rand()/(double)RAND_MAX) - 1; } );
	newLine;

	std::cout << "Матрица C:" << std::endl;
	C.print();
	newLine;

	return 0;
}

