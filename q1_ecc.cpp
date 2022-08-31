/*-*- coding: utf-8 -*-

Created on Thu Jan 20

@author: Prithvish_CYS21019
*/
//ECC_COMPUTATION

#include<iostream>
using namespace std;

int modInverse(int a, int m){
	for(int i=1; i<m; i++)
		if(((a%m) * (i%m)) % m == 1)
			return i;
	return 0;
}

int main(){

	int ch, a, b, x1, x2, y1, y2, z, s, n, d, x3, y3, scalar, count=0;
	cout << "Enter the value of z: ";
	cin >> z;
	cout << "Enter the value of a: ";
	cin >> a;
	cout << "Enter the value of b: ";
	cin >> b;
	cout << endl;
	int lhs[z], rhs[z];
	for(int i=0; i<z; i++){
		rhs[i] = (i*i*i + a*i + b) % z;
		lhs[i] = (i*i) %z;
	}
	cout << "Points are : " << endl;
	for(int i=0; i<z; i++){
		for(int j=0; j<z; j++){
			if(rhs[i] == lhs[j]){
				cout << "(" << i << ", " << j << ") ";
				count++;
			}
		}
	}
	cout << endl << "Total number of points: " << count << endl;
	cout << endl << endl;

	cout << "Enter the points P(x, y)" << endl;
	cout << "Enter the value of x: ";
	cin >> x1;
	cout << "Enter the value of y: ";
	cin >> y1;
	cout << "Enter the scalar: ";
	cin >> scalar;
	cout << endl;


	n = (3*x1*x1 + a) % z;
	d = 2*y1;
	d = modInverse(d, z);
	int m = d;
	d = d % z;
	s = (n*d)%z;
	x3 = (s*s - (2*x1)) % z;
	if(x3 < 0)
		x3 += z;
	y3 = (s*x1 - s*x3 - y1) % z;
	if(y3 < 0)
		y3 += z;
	cout << "  P" << " => " << '(' << x1 << ", " << y1 << ')' << endl;
	cout << " 2P" << " = P + P => " << '(' << x3 << ", " << y3 << ')' << endl;

	for(int i=3; i<=scalar; i++){
		x2 = x3, y2 = y3;
		n = (y2 - y1);
		if(n < 0)
			n += z;
		n %= z;
		d = x2 - x1;
		if(d < 0)
			d += z;
		d = modInverse(d, z);
		d = d % z;
		s = (n*d)%z;
		x3 = (s*s - x1 - x2) % z;
		if(x3 < 0)
			x3 += z;
		y3 = (s*x1 - s*x3 - y1) % z;
		if(y3 < 0)
			y3 += z;
		cout << ' ' << i << "P" << " = " << i-1 << "P + P => " << '(' << x3 << ", " << y3 << ')' << endl;
		
	}
	

	return 0;
}