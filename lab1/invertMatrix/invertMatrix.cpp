// invertMatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

typedef int Matrix[3][3];

float Det(Matrix& inputMatrix)
{
	return inputMatrix[0][0] * inputMatrix[1][1] * inputMatrix[2][2]
		- inputMatrix[0][0] * inputMatrix[1][2] * inputMatrix[2][1]
		- inputMatrix[0][1] * inputMatrix[1][0] * inputMatrix[2][2]
		+ inputMatrix[0][1] * inputMatrix[1][2] * inputMatrix[2][0]
		+ inputMatrix[0][2] * inputMatrix[1][0] * inputMatrix[2][1]
		- inputMatrix[0][2] * inputMatrix[1][1] * inputMatrix[2][0];
}

bool ReadMatrix(const std::string& inputFileName, Matrix& matrix)
{
	std::ifstream inputFile;
	inputFile.open(inputFileName);
	if (!inputFile)
	{
		std::cout << "Failed to open" << inputFileName << "for reading\n";
		return false;
	}

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

bool InvertMatrix(Matrix& inputMatrix, Matrix& invertMatrix)
{
	float determinant = Det(inputMatrix);
	std::cout << determinant << "\n";

	if (fabs(determinant) < 0.0000001)
		return false;

	return true;
}

void PrintMartix(Matrix& invertMatrix)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << invertMatrix[i][j] << " ";
		}

		std::cout << "\n";
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument count\n";
		return 1;
	}

	Matrix inputMatrix;

	if (!ReadMatrix(argv[1], inputMatrix))
	{
		std::cout << "Can't reed file\n";
		return 1;
	};

	Matrix invertMatrix;
	if (!InvertMatrix(inputMatrix, invertMatrix))
	{
		std::cout << "Determinant = 0";
		return 1;
	};

	PrintMartix(invertMatrix);
}
