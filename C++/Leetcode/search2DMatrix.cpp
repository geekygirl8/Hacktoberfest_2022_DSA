#include<bits/stdc++.h>
using namespace std;




bool searchMatrix(vector<vector<int>>& matrix, int target) {
	
	int row = matrix.size();
	int col = matrix[0].size();
	
	int i = 0;
	int j = col-1;
	
	while((i>=0&&j>=0)&&(i<row&&j<col)){
		
		if(matrix[i][j]==target)
			return true;
		else if (matrix[i][j]>target)
			j--;
		else 
			i++;
		
	}        
	
	return false;


}

int main()
{
	vector<int> v;
	
}