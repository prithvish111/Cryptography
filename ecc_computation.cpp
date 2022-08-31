//ECC_COMPUTATION
#include<bits/stdc++.h>
using namespace std;

int modInverse(int a, int m){
	for(int i=1; i<m; i++)
		if(((a%m) * (i%m)) % m == 1)
			return i;
	return 0;
}

int main(){

	int ch, a, x1, x2, y1, y2, z, s, n, d, x3, y3;
	cout << "Enter the value of z: ";
	cin >> z;
	cout << "Enter the value of a: ";
	cin >> a;
	cout << endl;
	while(1){
	
	cout << "Is point p equal to q?(press 1 if yes, 0 if no): ";
	cin >> ch;
	cout << endl;
	
	if(ch==1){
		int ch1;
		cout << "Enter the value of x: ";
		cin >> x1;
		cout << "Enter the value of y: ";
		cin >> y1;
		cout << endl;
		n = (3*x1*x1 + a) % z;
		d = 2*y1;
		d = modInverse(d, z);
		int m = d;
		d = d % z;
		s = (n*d)%z;
		cout << "s = " << (3*x1*x1 + a) << '/' << 2*y1 << " mod " << z << endl;
		cout << "s = " << (3*x1*x1 + a) << '*' << 2*y1 << "^-1 mod " << z << endl;
		cout << "s = " << (3*x1*x1 + a) << '*' << m << " mod " << z << endl; 
		cout << "s = " << s << endl;
		x3 = (s*s - (2*x1)) % z;
		if(x3 < 0)
			x3 += z;
		y3 = (s*x1 - s*x3 - y1) % z;
		if(y3 < 0)
			y3 += z;
		cout << "Sum of points (" << x1 << ", " << y1 << ") + (" << x1 << ", " << y1 << ") = (" << x3 << ", " << y3 << ")" << endl << endl; 
	}
	else{
		cout << "Enter the value of x1: ";
		cin >> x1;
		cout << "Enter the value of y1: ";
		cin >> y1;
		cout << "Enter the value of x2: ";
		cin >> x2;
		cout << "Enter the value of y2: ";
		cin >> y2;
		cout << endl;
		n = (y2 - y1);
		if(n < 0)
			n += z;
		d = x2 - x1;
		if(d < 0)
			d += z;
		d = modInverse(d, z);
		int m = d;
		d = d % z;
		s = (n*d)%z;
		cout << "s = " << (y2 - y1) << '/' << x2 - x1 << " mod " << z << endl;
		cout << "s = " << (y2 - y1) << '*' << x2 - x1 << "^-1 mod " << z << endl;
		cout << "s = " << (y2 - y1) << '*' << m << " mod " << z << endl;
		cout << "s = " << s << endl;
		x3 = (s*s - x1 - x2) % z;
		if(x3 < 0)
			x3 += z;
		y3 = (s*x1 - s*x3 - y1) % z;
		if(y3 < 0)
			y3 += z;
		cout << "Sum of points (" << x1 << ", " << y1 << ") + (" << x2 << ", " << y2 << ") = (" << x3 << ", " << y3 << ")" << endl << endl; 
	}
	cout << "Enter\n 0. Exit\n 1. Want to check Again \n";
	cin >> ch;
	if(ch==0)
		exit(0);
	}
	return 0;
}