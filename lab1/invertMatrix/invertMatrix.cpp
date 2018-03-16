// invertMatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
typedef int Matrix[3][3];

float det(Matrix& inputMatrix)
{
	return inputMatrix[0][0] * inputMatrix[1][1] * inputMatrix[2][2]
		- inputMatrix[0][0] * inputMatrix[1][2] * inputMatrix[2][1]
		- inputMatrix[0][1] * inputMatrix[1][0] * inputMatrix[2][2]
		+ inputMatrix[0][1] * inputMatrix[1][2] * inputMatrix[2][0]
		+ inputMatrix[0][2] * inputMatrix[1][0] * inputMatrix[2][1]
		- inputMatrix[0][2] * inputMatrix[1][1] * inputMatrix[2][0];
}

bool readFile(char** argv, Matrix& matrix)
{
	std::ifstream inputFile(argv[1]);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (!(inputFile >> matrix[i][j]))
				return false;
		}
	}
	return true;
}

void invertMatix(Matrix& inputMatrix)
{
	float determinant = det(inputMatrix);
	std::cout << determinant;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count\n";
		return 1;
	}

	Matrix inputMatrix;
	std::ifstream inputFile;
	inputFile.open(argv[1]);
	if (!inputFile)
	{
		std::cout << "Failed to open " << argv[1] << " for reading\n";
	};

	if (!readFile(argv, inputMatrix))
	{
		std::cout << "Can't reed file\n";
	};
	Matrix newMatrix;

	invertMatix(inputMatrix);
}
