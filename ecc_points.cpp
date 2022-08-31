//ECC_POINTS
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, z;
	cout << "Enter the coeff of an equation y2=x3+ax+b" << endl;
	cout << "a : ";
	cin >> a;
	cout << "b : ";
	cin >> b;
	cout << "Z : ";
	cin >> z;
	int lhs[z], rhs[z];
	cout << "x     y" << endl;
	for(int i=0; i<z; i++){
		rhs[i] = (i*i*i + a*i + b) % z;
		lhs[i] = (i*i) %z;
		cout << i << '|' << rhs[i] << "   " << i << '|' << lhs[i] << endl;
	}
	cout << "Points are : " << endl;
	for(int i=0; i<z; i++){
		for(int j=0; j<z; j++){
			if(rhs[i] == lhs[j])
				cout << "(" << i << ", " << j << ")" << endl;
		}
	}


	return 0;
}