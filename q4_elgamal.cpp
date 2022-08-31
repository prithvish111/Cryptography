/*-*- coding: utf-8 -*-
Created on Thu Jan 20
@author: Prithvish_CYS21019
*/
//Elgamal
#include<iostream>
#include<math.h>
using namespace std;

int modInverse(int a, int m){
	for(int i=1; i<m; i++)
		if(((a%m) * (i%m)) % m == 1)
			return i;
	return 0;
}

int powerMod(long long x, unsigned int y, int p) 
{ 
    int res = 1;    
    x = x % p;
    if (x == 0) 
    	return 0; 

    while (y > 0) 
    { 
        if (y & 1) 
            res = (res*x) % p; 
        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 

void elgamalSign(int p){

	int prime, g, a, e, k, y1, y2, s;
	cout << endl;
	cout << "---------Elgamal Signing---------" << endl << endl;
	cout << "----Enter the public keys---" << endl;
	cout << "Enter prime number P: ";
	cin >> prime;
	cout << "Enter primitive root g: ";
	cin >> g;
	cout << "Enter random integer a: ";
	cin >> a;
	cout << "Enter k: ";
	cin >> k;
	e = powerMod(g, a, prime);
	cout << "e is " << e << endl;
	cout << endl;

	cout << "Cipher text is:-" << endl;
	y1 = powerMod(g, k, prime);
	y2 = powerMod(p, 1, prime);
	y2 *= powerMod(e, k, prime);
	y2 %= prime;

	cout << "Y1 = g^a (mod p)   => " << y1 << endl;
	cout << "Y2 = p*e^a (mod p) => " << y2 << endl;
}

void elgamalVerify(int p){
	int prime, y1, y2, a, d, pt;
	cout << "---------Elgamal Verification---------" << endl << endl;
	cout << "---Enter the public keys---" << endl;
	cout << "Enter the prime P: ";
	cin >> prime;
	cout << "Enter Y1: ";
	cin >> y1;
	cout << "Enter Y2: ";
	cin >> y2;
	cout << endl;

	cout << "---Enter the private keys---" << endl;
	cout << "Enter a: ";
	cin >> a;

	int arg = pow(y1, d)+0.5;
	pt = powerMod(y2, 1, prime);
	pt *= powerMod(y1, prime-1-a, prime);
	pt %= prime;

	cout << "Plain text = Y2 * (Y1^(p-1-a) (mod p) => " << pt << endl;
	if(pt == p){
		cout << "Message is verified(1)" << endl;
	}
	else
		cout << "Message is not correct(0)" << endl;

}

int main(){

	int ch, p;
	while(1){
		cout << endl << endl;
		cout << "--------------------------------------------" << endl;
		cout << "1. Elgamal Signature" << endl;
		cout << "2. Elgamal Verification" << endl;
		cout << "3. Exit" << endl;
		cout << endl << "Enter the choice: ";
		cin >> ch;
		
		cout << endl;
		switch(ch){
			case 1: cout << "Enter Plain text p: ";
					cin >> p;
					elgamalSign(p);
					break;
			case 2: elgamalVerify(p);
					break;
			case 3: exit(0);
		}
	}

	return 0;
}