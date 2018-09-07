#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int M[100][100] = {};
int ROW, COL;
void input(){
	string input;
	cin >> input;
	vector<string> a;
	vector<string> b;
	vector<string> output;
	string t[100];
	string temp;
	a.reserve(50);
	int x = 0;
	int w = 0;
	int count = 0;
	while (w <= input.length()){
		if (input[w] != ';'){
			temp = temp + input[w];
			w++;
		}
		else{
			w++;
			a.push_back(temp);
			count++;
			temp = "";
		}
	}
	temp = "";
	string temp2 = "";
	int j = 0;
	int z = 0;
	for (int q = 0; q < count; q++){
		temp2 = a[q];
		int j = 0;
		while (j <= temp2.length()){
			if (temp2[j] != ','){
				temp = temp + temp2[j];
			}
			else{
				b.push_back(temp);
				temp = "";
			}
			if (j + 1 > temp2.length()){
				b.push_back(temp);
				temp = "";
			}
			j++;

		}
		temp2 = "";
	}

	for (int i = 0; i < b.size(); ++i){
		t[i] = b[i];
	}
	int size = b.size();
	int row = 0;
	int col = 0;
	int o = 0;
	int e = size / count;
	int c = 0;
	while (o < size){
		for (col = 0; col < e; col++){
			M[row][col] = atoi(t[o].c_str());
			o++;
		}
		row++;
	}
	ROW = row;
	COL = e;
	std::cout << endl;
	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COL; c++)
		{
			std::cout << M[r][c] << ' ' << ' ' << ' ';
		}
		std::cout << endl;
	}
}
int kadane(int* arr, int* start, int* finish, int n)
{
	int sum = 0;
	int maxSum = INT_MIN;
	int i;
	*finish = -1;
	int lstart = 0;
	for (i = 0; i < n; ++i)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			lstart = i + 1;
		}
		else if (sum > maxSum)
		{
			maxSum = sum;
			*start = lstart;
			*finish = i;
		}
	}
	if (*finish != -1)
		return maxSum;
	maxSum = arr[0];
	*start = *finish = 0;
	for (i = 1; i < n; i++)
	{
		if (arr[i] > maxSum)
		{
			maxSum = arr[i];
			*start = *finish = i;
		}
	}
	return maxSum;
}
void maxSum(int M[][100],int n , int m)
{
	int maxSum = INT_MIN, fLeft, fRight, fTop, fBottom;
	int left, right;
	int temp[100];
	int sum, start, finish,i;
	for (left = 0; left < m; ++left)
	{
		//initialize temp to 0 
		memset(temp, 0, sizeof(temp));
		for (right = left; right < m; ++right)
		{
			for (i = 0; i < n; ++i)
				temp[i] += M[i][right];
			sum = kadane(temp, &start, &finish, n);
			if (sum > maxSum)
			{
				maxSum = sum;
				fLeft = left;
				fRight = right;
				fTop = start;
				fBottom = finish;
			}
		}
	}
	cout << "from" <<'['<< fTop << fLeft <<']'<< endl;
	cout << "to:" << '[' << fBottom << fRight << ']' << endl;
	cout << "max sum is:" << maxSum << endl;
	for (int i = fTop; i <= fBottom; i++){
		for (int j = fLeft; j <= fRight; j++){
			cout << M[i][j] << "     ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = fTop; i <= fBottom; i++){
		for (int j = fLeft; j <= fRight; j++){
			cout << M[i][j];
			if (j != fRight){
				cout << ",";
			}
		}
		cout << ";";
	}
}
int main()
{
	    input();
		maxSum(M,ROW,COL);
		getchar();
		getchar();
		return 0;
	}
