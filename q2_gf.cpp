/*-*- coding: utf-8 -*-
Created on Thu Jan 20
@author: Prithvish_CYS21019
*/
//Galois Fields

#include<iostream>
#include<bitset>
using namespace std;

int main(){
	string alpha[256];
	int op[256], inv;
	for(int i=0; i<256; i++)
		alpha[i] = "00000000";

	string prim = "100011101";
	for(int i=1; i<=7; i++){
		alpha[i][7-i] = '1'; 
	}
	alpha[8] = "00011101";

	for(int i=9; i<256; i++){
		string temp = alpha[i-1];
		string curalp = "00000000";
	    for(int j=7; j>=1; j--){
	    	if(temp[j] == '1'){
	    		curalp[j-1] = '1';
	    	}
	    }
	    if(temp[0]=='1'){
	    	string alp8 = alpha[8];
	    	for(int k=7; k>=0; k--){
	    		if(curalp[k] == '1' && alp8[k] == '1')
	    			curalp[k] = '0';
	    		else if(curalp[k] == '0' && alp8[k] == '0')
	    			curalp[k] = '0';
	    		else
	    			curalp[k] = '1';
	    	}
	    }
	    alpha[i] = curalp;
	}
	
	int x;
	cout << endl;
	cout << "Selected primitive polynomial is x^8 + x^4 + x^3 + x^2 + 1" << endl;
	cout << endl;
	cout << "Enter an element of GF(256) in decimal: ";
	cin >> x;
	cout << endl;
	cout << "Entered number in (dec): " << x << endl;
	cout << "Entered number in (hex): 0x" << hex << x << endl;
	cout << "Entered number in (bin): " << bitset<8>(x) << endl;

	string inp = bitset<8>(x).to_string();
	int arr[256];

	for(int i=0; i<256; i++)
		op[i] = 0;

	for(int i=0; i<256; i++){
		string bin = bitset<8>(i).to_string();

		for(int x=0; x<256; x++)
			arr[x] = 0;

		for(int j=0; j<8; j++){
			for(int k=0; k<8; k++){
				if(inp[j]=='1' && bin[k]=='1'){
					int t1 = 7-j, t2 = 7-k;
					if((t1+t2) > 7){
						arr[t1+t2] += 1;
						arr[t1+t2] %= 2;
					}
					else{
						int index = 7-(t1+t2);
						arr[index] += 1;
						arr[index] %= 2;
					}
				}
			}
		}

		for(int s=8; s<15; s++){
			if(arr[s] != 0){
				string temp = alpha[s];
				//cout << temp << endl;
				for(int m=7; m>=0; m--){
					if(arr[m] == 1 && temp[m] == '1')
						arr[m] = 0;
					else if(arr[m] == 0 && temp[m] == '0')
						arr[m] = 0;
					else
						arr[m] = 1;
				}
			}
		}

		for(int s=0; s<8; s++)
		op[i] = op[i] << 1 | arr[s];
			

		cout << bitset<8>(i) << " (" << dec << i << ") ->   " << op[i] << endl;
		if(op[i] == 1){
			inv = i;
			break;
		}
	}
	cout << endl;
	cout << "Inverse of " << dec << x << " (0x" << hex << x << ") is " << dec << inv << " (0x" << hex << inv << ')' << endl;

	return 0;
}