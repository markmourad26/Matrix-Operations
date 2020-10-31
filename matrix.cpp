#include"pch.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<sstream> 
#include<math.h>
#include<complex>
using namespace std;
float strtoarr(string strmatrix, float matrix[100][100], int length, int &c, int &r);
float clearmatrix(float matrix[100][100]);
float copymatrix(float(matrix1)[100][100], float matrix2[100][100], int rows, int column);
float determenant(float matrix1[100][100], int column);
void check(string strmatrix, int &flag);
float adjoint(float matrix1[100][100], float matrix2[100][100], int column);
void getCofactor(float matrix[100][100], float matrix2[100][100], int l, int n, int column);

int main()
{
	string strmatrix1, strmatrix2;
	float matrix1[100][100], matrix2[100][100],multimatrix[100][100],adj[100][100],sum = 0,det;
	int r1 = 0, c1 = 0, r2 = 0, c2 = 0, y, column2, row2,new_row,new_column, c = 0, l = 0, flag = 0, find;
	char op;
	getline(cin, strmatrix1);
	cin >> op;
	cin.ignore();
	int x = strmatrix1.length();
	matrix1[100][100]=clearmatrix(matrix1);
	matrix1[100][100] = strtoarr(strmatrix1, matrix1, x, c1, r1);
	int column1 = r1, row1 = c1 + 1;
	switch (op)
	{
		case '+':
			getline(cin, strmatrix2);
			y = strmatrix2.length();
			matrix2[100][100] = clearmatrix(matrix2);
			matrix2[100][100] = strtoarr(strmatrix2, matrix2, y, c2, r2);
			column2 = r2, row2 = c2 + 1;
			if (column1 == column2 && row1 == row2)
			{
				for (int j = 0; j <row1; j++)
				{
					for (int i = 0; i < column1; i++)
					{
						matrix1[i][j] += matrix2[i][j];
					}
				}
				cout << "[";
				for (int j = 0; j < row1; j++)
				{
					for (int i = 0; i < column1; i++)
					{
						cout << matrix1[i][j];
						if (i < column1 - 1)
							cout << " ";
						else if (j == row1 - 1)
							break;
						else
							cout << ";";
					}
				}
				cout << "]";
			}
			else {
				cout << "ERROR";
			}
			break;
		case '-':
			getline(cin, strmatrix2);
			y = strmatrix2.length();
			matrix2[100][100] = clearmatrix(matrix2);
			matrix2[100][100] = strtoarr(strmatrix2, matrix2, y, c2, r2);
			column2 = r2, row2 = c2 + 1;
			if (column1 == column2 && row1 == row2)
			{
				for (int j = 0; j < row1; j++)
				{
					for (int i = 0; i < column1; i++)
					{
						matrix1[i][j] -= matrix2[i][j];
					}
				}
				cout << "[";
				for (int j = 0; j < row1; j++)
				{
					for (int i = 0; i < column1; i++)
					{
						cout << matrix1[i][j];
						if (i < column1 - 1)
							cout << " ";
						else if (j == row1 - 1)
							break;
						else
							cout << ";";
					}
				}
				cout << "]";
			}
			else {
				cout << "ERROR";
			}
			break;
		case '*':
			getline(cin, strmatrix2);
			y = strmatrix2.length();
			matrix2[100][100] = clearmatrix(matrix2);
			matrix2[100][100] = strtoarr(strmatrix2, matrix2, y, c2, r2);
			column2 = r2, row2 = c2 + 1;
			multimatrix[100][100] = clearmatrix(multimatrix);
			if (row2 == column1)
			{
				for (int j = 0; j < row1; j++)
				{
					for (int i = 0; i < column2; i++)
					{
						for (int k = 0; k < row2; k++)
						{
							sum += matrix1[k][j] * matrix2[i][k];
						}
						multimatrix[i][j] = sum;
						sum = 0;
					}
				}
				cout << "[";
				for (int j = 0; j < row1; j++)
				{
					for (int i = 0; i < column2; i++)
					{
						cout << multimatrix[i][j];
						if (i < column2 - 1)
							cout << " ";
						else if (j == row1 - 1)
							break;
						else
							cout << ";";
					}
				}
				cout << "]";
			}
			else 
			{
				cout << "ERROR";
			}
			break;
		case'^':
			int power;
			cin >> power;
			multimatrix[100][100] = clearmatrix(multimatrix);
			matrix2[100][100] = copymatrix(matrix1, matrix2, row1, column1);
			if (row1 == column1)
			{
				for (int q = 0; q <= power-2; q++)
				{
					for (int j = 0; j < row1; j++)
					{
						for (int i = 0; i < column1; i++)
						{
							for (int k = 0; k < column1; k++)
							{
								sum += matrix1[k][j] * matrix2[i][k];
							}
							multimatrix[i][j] = sum;
							sum = 0;
						}
					}
					matrix1[100][100] = copymatrix(multimatrix,matrix1,row1,column1);
				}
				cout << "[";
				for (int j = 0; j < row1; j++)
				{
					for (int i = 0; i < column1; i++)
					{
						cout << multimatrix[i][j];
						if (i < column1 - 1)
							cout << " ";
						else if (j == row1 - 1)
							break;
						else
							cout << ";";
					}
				}
				cout << "]";
			}
			else
				cout << "ERROR";
			break;
		case'T':
			check(strmatrix1, flag);
			if (flag == 0)
			{
				new_row = column1, new_column = row1;
				cout << "[";
				for (int j = 0; j < new_row; j++)
				{
					for (int i = 0; i < new_column; i++)
					{
						cout << matrix1[j][i];
						if (i < new_column - 1)
							cout << " ";
						else if (j == new_row - 1)
							break;
						else
							cout << ";";
					}
				}
				cout << "]";
			}
			else
				cout << "ERROR";
			break;
		case'D':
			if (row1 == column1)
			{
				cout<<determenant(matrix1, column1);
			}
			else
				cout << "ERROR";
			break;
		case'I':
			if (row1 == column1)
			{
				det = determenant(matrix1, column1);
				if (det != 0)
				{
					adj[100][100] = adjoint(matrix1, adj, column1);
					for (int i = 0; i < column1; i++)
						for (int j = 0; j < column1; j++)
							matrix1[i][j] = adj[i][j] / float(det);
					cout << "[";
					for (int j = 0; j < row1; j++)
					{
						for (int i = 0; i < column1; i++)
						{
							cout << matrix1[i][j];
							if (i < column1 - 1)
								cout << " ";
							else if (j == row1 - 1)
								break;
							else
								cout << ";";
						}
					}
					cout << "]";
				}
				else
					cout << "ERROR";
			}
			else
				cout << "ERROR";
			break;
		case'/':
			getline(cin, strmatrix2);
			y = strmatrix2.length();
			matrix2[100][100] = clearmatrix(matrix2);
			matrix2[100][100] = strtoarr(strmatrix2, matrix2, y, c2, r2);
			column2 = r2, row2 = c2 + 1;
			check(strmatrix2, flag);
			if (flag == 0)
			{
				if (row2 == column2)
				{
					det = determenant(matrix2, column2);
					if (det != 0)
					{
						adj[100][100] = adjoint(matrix2, adj, column2);
						for (int i = 0; i < column2; i++)
							for (int j = 0; j < column2; j++)
								matrix2[i][j] = adj[i][j] / float(det);
						multimatrix[100][100] = clearmatrix(multimatrix);
						if (row2 == column1)
						{
							for (int j = 0; j < row1; j++)
							{
								for (int i = 0; i < column2; i++)
								{
									for (int k = 0; k < row2; k++)
									{
										sum += matrix1[k][j] * matrix2[i][k];
									}
									multimatrix[i][j] = sum;
									sum = 0;
								}
							}
							cout << "[";
							for (int j = 0; j < row1; j++)
							{
								for (int i = 0; i < column2; i++)
								{
									cout << multimatrix[i][j];
									if (i < column2 - 1)
										cout << " ";
									else if (j == row1 - 1)
										break;
									else
										cout << ";";
								}
							}
							cout << "]";
						}
						else
						{
							cout << "ERROR";
						}
					}
					else
						cout << "ERROR";
				}
				else
					cout << "ERROR";
			}
			else
				cout << "ERROR";
			break;
		default:
			cout << "ERROR";
	}
}


float strtoarr(string strmatrix, float matrix[100][100], int length, int &c, int &r)
{
	string strnum = "";
	for (int i = 1; i < length; i++)
	{
		if ((strmatrix[i]==' ')||(i == length - 1))
		{
			continue;
		}
		else if (strmatrix[i]==';')
		{
			c++;
			r = 0;
			continue;
		}
		else
		{
			strnum += strmatrix[i];
			if ((strmatrix[i + 1] == ' ')||(strmatrix[i + 1] == ';')||(strmatrix[i + 1] == ']'))
			{
				matrix[r][c] = atof(strnum.c_str());
				strnum = "\0";
				r++;
			}
		}
	}
	return matrix[100][100];
}
float clearmatrix(float matrix[100][100])
{
	for (int i = 0; i < 100; i++)
	{

		for (int j = 0; j < 100; j++)
		{
			matrix[i][j] = 0;
		}
	}
	return matrix[100][100];
}
float copymatrix(float(matrix1)[100][100], float matrix2[100][100], int rows, int column)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matrix2[j][i] = matrix1[j][i];

		}
	}
	return matrix2[100][100];
}
float determenant(float matrix1[100][100],int column)
{
	float det = 0,temp[100][100];
	int n, l;
	if (column == 1)
		return matrix1[0][0];
	else if (column == 2)
	{
		return ((matrix1[0][0] * matrix1[1][1]) - (matrix1[1][0] * matrix1[0][1]));
	}
	else
	{
		for (int i = 0; i < column; i++)
		{
			n = 0;
			for (int j = 1; j < column; j++)
			{
				l = 0;
				for (int k = 0; k < column; k++)
				{
					if (k == i)
						continue;
					temp[n][l] = matrix1[j][k];
					l++;
				}
				n++;
			}
			det += (pow(-1, i)*matrix1[0][i] * determenant(temp, column - 1));
		}
	}
	return det;
}
void check(string strmatrix, int &flag)
{
	int find,l=0,c=0;
	for (int j = 1; j < strmatrix.length() - 1; j++)
	{
		find = strmatrix.find(';');
		if (find >= 0)
		{
			for (int i = 1; i < find; i++)
			{

				if (strmatrix[i] == ' ')
				{
					l++;
				}
			}
			strmatrix.erase(1, find);
		}
		else
		{
			find = strmatrix.find(']');
			for (int i = 1; i < find; i++)
			{

				if (strmatrix[i] == ' ')
				{
					l++;
				}
			}
		}
		if (c == 0)
		{
			c = l;
			l = 0;
		}
		else if (c != l)
		{
			flag = 1;
		}
		else
			l = 0;
	}
}
void getCofactor(float matrix[100][100], float matrix2[100][100], int l, int n, int column)
{
	int i = 0, j = 0; 
	for (int row = 0; row < column; row++)
	{
		for (int col = 0; col < column; col++)
		{
			if (row != l && col != n)
			{
				matrix2[i][j++] = matrix[row][col];
				if (j == column - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}
float adjoint(float matrix1[100][100], float matrix2[100][100],int column)
{
	if (column == 1)
	{
		return matrix2[0][0] = 1;
	}
	int sign = 1;
	float temp[100][100];

	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < column; j++)
		{
			getCofactor(matrix1, temp, i, j, column); 
			sign = ((i + j) % 2 == 0) ? 1 : -1;
			matrix2[j][i] = (sign)*(determenant(temp, column - 1));
		}
	}
	return matrix2[100][100];
}