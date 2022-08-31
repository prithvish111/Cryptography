/*-*- coding: utf-8 -*-
Created on Thu Jan 20
@author: Prithvish_CYS21019
*/
//BSGS
#include<bits/stdc++.h>
using namespace std;

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

int main(){

	int a, p, g, x, m;
	cout << endl;
	cout << "Congruence: a^x = g mod p" << endl;
	cout << endl;
	cout << "Enter the value of a: ";
	cin >> a;
	cout << "Enter the value of g: ";
	cin >> g;
	cout << "Enter the value of p: ";
	cin >> p;
	cout << endl;
	
	//step1
	cout << "---------------------------------" << endl;
	cout << "Step1: Take square root of p as m" << endl;
	cout << "---------------------------------" << endl;
	m = sqrt(p) + 1;
	int arri[m], arrj[m];
	cout << "m = ceil of square root of "<< p << " => " << m << endl << endl;

	//step2
	cout << "-----------------------------------------" << endl;
	cout << "Step2: Solve for a^mj mod p for each step" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "j" << "\ta^mj mod p" << endl;
	for(int j=0; j<m; j++){
		arrj[j] = powerMod(a, m*j, p);
		cout << j << "\t2^" << m*j << " mod " << p << " = " << arrj[j] << endl;
	}
	cout << endl;
	//step3
	cout << "-------------------------------------------" << endl;
	cout << "Step3: Solve for g.a^-i mod p for each step" << endl;
	cout << "-------------------------------------------" << endl;
	cout << "i" << "\ta^mi mod p" << endl;
	for(int i=0; i<m; i++){
		arri[i] = powerMod(a, p-i-1, p);
		arri[i] *= g;
		arri[i] %= p;
		cout << i << "\t" << g << '.' << "2^" << -1*i << " mod " << p << " = " << arri[i] << endl; 
	}
	cout << endl;
	//step4
	cout << "----------------------------------" << endl;
	cout << "Step4: Find Collision in L1 and L2" << endl;
	cout << "----------------------------------" << endl;
	int i=0, j=0, flag=0;
	for(j=0; j<m; j++){
		for(i=0; i<m; i++){
			if(arrj[j] == arri[i]){
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	cout << "Collision is at (" << j << ", " << arrj[j] << ')' << " and (" << i << ", " << arri[i] << ')' << endl;  
	cout << "Value of j = " << j << " and i = " << i << endl;
	cout << endl;
	//step5
	cout << "--------------------------" << endl;
	cout << "Step5: Find (m(j)+i) mod p" << endl;
	cout << "--------------------------" << endl;
	x = (m*j + i) % p;
	cout << "Value of x = " << x << endl;

	return 0;
}