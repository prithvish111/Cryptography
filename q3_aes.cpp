#include<iostream>
using namespace std;

int main(){

	int inpnib[4], opnib[4];

	int sbox[16] = {9,4,10,11,13,1,8,5,6,2,0,3,12,14,15,7};

	
	cout << "Nibble Matrix Representation" << endl;
	cout << " _      _" << endl;
	cout << "|N0    N2|"<< endl;
	cout << "|N1    N3|"<< endl;
	cout << "|_      _|"<< endl << endl;
	cout << "Nibble Bit Representation" << endl;
	cout << " _	                      _" << endl;
	cout << "|n0 n1 n2 n3    n8  n9  n10 n11|" << endl;
	cout << "|n4 n5 n6 n7    n12 n13 n14 n15|" << endl;
	cout << "|_	                      _|" << endl;

	cout << endl << "Enter the 2x2 nibble matrix in hexadecimal like above format" << endl << endl;
	for(int i=0; i<4; i++){
		cout << "Enter the N" << i << " in hexadecimal : ";
		cin >> hex >> inpnib[i];
	}
	cout << endl;
	cout << "Your input is : " << endl;

	cout << hex << inpnib[0] << "    " << hex << inpnib[2]  << endl;
	cout << hex << inpnib[1] << "    " << hex << inpnib[3]  << endl;

	cout << endl;

	cout << "Nibble Substitution : " << endl;

	cout << hex << sbox[inpnib[0]] << "    " << hex << sbox[inpnib[2]] << endl;
	cout << hex << sbox[inpnib[1]] << "    " << hex << sbox[inpnib[3]] << endl;

	cout << endl;

	cout << "Shift Row SR : " << endl;

	cout << hex << sbox[inpnib[0]] << "    " << hex << sbox[inpnib[2]] << endl;
	cout << hex << sbox[inpnib[3]] << "    " << hex << sbox[inpnib[1]] << endl;
 

	return 0;
}