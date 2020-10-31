#include"pch.h"
#include <iostream>
#include<string>
#include<cstdlib>
#include<sstream> 
#include<math.h>
using namespace std;
int main()
{
	float real_mat[100][100], imj_mat[100][100], temp_imj, real_mat2[100][100], imj_mat2[100][100], real_multimatrix[100][100], imj_multimatrix[100][100], imj_sum = 0, real_sum = 0;
	string strmatrix1, strmatrix2;
	char op;
	getline(cin, strmatrix1);
	cin >> op;
	cin.ignore();
	getline(cin, strmatrix2);
	int mat1len = strmatrix1.length();
	int mat2len = strmatrix2.length();
	int c1 = 0, r1 = 0, c2 = 0, r2 = 0, x;
	string strnum = "", temp = "";
	for (int i = 1; i < mat1len; i++)
	{
		if ((strmatrix1[i] == ' ') || (i == mat1len - 1))
		{
			continue;
		}
		else if (strmatrix1[i] == ';')
		{
			r1++;
			c1 = 0;
			continue;
		}
		else
		{
			strnum += strmatrix1[i];
			if ((strmatrix1[i + 1] == ' ') || (strmatrix1[i + 1] == ';') || (strmatrix1[i + 1] == ']'))
			{
				int l = strnum.length();
				for (int j = 0; j < l; j++)
				{
					if (strnum[j] == '+' || strnum[j] == '-' || strnum[j] == 'i')
					{
						continue;
					}
					else
					{
						temp += strnum[j];
						if ((strnum[j + 1] == '+') || (strnum[j + 1] == '-'))
						{
							real_mat[c1][r1] = atof(temp.c_str());
							if (strnum[0] == '-')
							{
								real_mat[c1][r1] *= -1;
							}
							temp = "";
							x = j + 1;
						}
						else if (strnum[j + 1] == 'i')
						{
							temp_imj = atof(temp.c_str());
							temp = "";
							if (strnum[x] == '+')
							{
								imj_mat[c1][r1] = temp_imj;
							}
							else if (strnum[x] == '-')
							{
								imj_mat[c1][r1] = temp_imj * -1;
							}
						}
					}
				}
				c1++;
				strnum = "";
			}
		}
	}
	string strnum2 = "", temp2 = "";
	for (int i = 1; i < mat2len; i++)
	{
		if ((strmatrix2[i] == ' ') || (i == mat2len - 1))
		{
			continue;
		}
		else if (strmatrix2[i] == ';')
		{
			r2++;
			c2 = 0;
			continue;
		}
		else
		{
			strnum2 += strmatrix2[i];
			if ((strmatrix2[i + 1] == ' ') || (strmatrix2[i + 1] == ';') || (strmatrix2[i + 1] == ']'))
			{
				int l = strnum2.length();
				for (int j = 0; j < l; j++)
				{
					if (strnum2[j] == '+' || strnum2[j] == '-' || strnum2[j] == 'i')
					{
						continue;
					}
					else
					{
						temp2 += strnum2[j];
						if ((strnum2[j + 1] == '+') || (strnum2[j + 1] == '-'))
						{
							real_mat2[c2][r2] = atof(temp2.c_str());
							if (strnum2[0] == '-')
							{
								real_mat2[c2][r2] *= -1;
							}
							temp2 = "";
							x = j + 1;
						}
						else if (strnum2[j + 1] == 'i')
						{
							temp_imj = atof(temp2.c_str());
							temp2 = "";
							if (strnum2[x] == '+')
							{
								imj_mat2[c2][r2] = temp_imj;
							}
							else if (strnum2[x] == '-')
							{
								imj_mat2[c2][r2] = temp_imj * -1;
							}
						}
					}
				}
				c2++;
				strnum2 = "";
			}
		}
	}
	int column1 = c1, row1 = r1 + 1, column2 = c2, row2 = r2 + 1;
	switch (op)
	{
	case '+':
		if (column1 == column2 && row1 == row2)
		{
			for (int j = 0; j < row1; j++)
			{
				for (int i = 0; i < column1; i++)
				{
					real_mat[i][j] += real_mat2[i][j];
					imj_mat[i][j] += imj_mat2[i][j];
				}
			}
			cout << "[";
			for (int j = 0; j < row1; j++)
			{
				for (int i = 0; i < column1; i++)
				{
					cout << real_mat[i][j];
					if (imj_mat[i][j] >= 0)
					{
						cout << "+" << imj_mat[i][j] << "i";
					}
					else
					{
						cout << imj_mat[i][j] << "i";
					}
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
		if (column1 == column2 && row1 == row2)
		{
			for (int j = 0; j < row1; j++)
			{
				for (int i = 0; i < column1; i++)
				{
					real_mat[i][j] -= real_mat2[i][j];
					imj_mat[i][j] -= imj_mat2[i][j];
				}
			}
			cout << "[";
			for (int j = 0; j < row1; j++)
			{
				for (int i = 0; i < column1; i++)
				{
					cout << real_mat[i][j];
					if (imj_mat[i][j] >= 0)
					{
						cout << "+" << imj_mat[i][j] << "i";
					}
					else
					{
						cout << imj_mat[i][j] << "i";
					}
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
		if (row2 == column1)
		{
			for (int j = 0; j < row1; j++)
			{
				for (int i = 0; i < column2; i++)
				{
					for (int k = 0; k < row2; k++)
					{
						real_sum += (real_mat[k][j] * real_mat2[i][k]) + (-1)*(imj_mat[k][j] * imj_mat2[i][k]);
						imj_sum += (real_mat[k][j] * imj_mat2[i][k]) + (imj_mat[k][j] * real_mat2[i][k]);
					}
					real_multimatrix[i][j] = real_sum;
					imj_multimatrix[i][j] = imj_sum;
					real_sum = 0;
					imj_sum = 0;
				}
			}
			cout << "[";
			for (int j = 0; j < row1; j++)
			{
				for (int i = 0; i < column2; i++)
				{
					cout << real_multimatrix[i][j];
					if (imj_multimatrix[i][j] >= 0)
					{
						cout << "+" << imj_multimatrix[i][j] << "i";
					}
					else
					{
						cout << imj_multimatrix[i][j] << "i";
					}
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
	default:
		cout << "ERROR";
	}
}
