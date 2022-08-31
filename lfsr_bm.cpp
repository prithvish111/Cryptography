#include<iostream>
using namespace std;

int main(){

	int bx[20], tx[20], cx[20], temp_bx[20], seq[20];
	for(int i=0; i<20; i++){
		bx[i] = tx[i] = cx[i] = 0;
	}
	cx[0]=1, bx[0] = 1;
	int N=0, d=0, n=9, L=0, m=-1;
	cout << "Enter the number of bits: ";
	cin >> n;
	//int seq[n] = {0,0,1,1,0,1,1,1,0};
	for(int i=0; i<n; i++){
		cout << "Enter S" << i << ": ";
		cin >> seq[i];
	}

	cout << "N       d          T(x)          C(x)           L         m         B(x)" << endl;

	while(N < n){
		cout << N << "       ";
		d = seq[N];
		for(int i=1; i<=L; i++){
			//cout << '.'  << cx[i] << " ." << seq[N-i] << ' ';
			d ^= (cx[i] * seq[N-i]) % 2 ;
		}
		cout << d << "      ";


		if(d == 1){
			for(int i=0; i<20; i++){
				tx[i] = cx[i];
				if(tx[i]==1)
					cout << "x^" << i << "+";
			}
			cout << "      ";
			for(int i=0; i<20; i++)
				temp_bx[i] = bx[i];

			int cnt=0;
			for(int i=0; i<20; i++){
				if(temp_bx[i] == 1){
					cnt += i;
					temp_bx[i] = 0;
				}
			}
			temp_bx[cnt+N-m] = 1;
			/*cout << endl << "...";
			for(int i=0; i<20; i++){
				if(temp_bx[i] == 1)
					cout << "x^" << i << "+";
			}
			cout << endl;*/

			for(int i=0; i<20; i++){
				tx[i] = cx[i];
			}

			for(int i=0; i<20; i++){
				if(temp_bx[i] == 1 && cx[i] != 1){
					cx[i] = 1;
				}
				else if(temp_bx[i] == 1 && cx[i] == 1){
					cx[i] = 0;
				}
				if(cx[i]==1)
					cout << "x^" << i << "+";
			}


			
			cout << "                    ";
			if(L <= N/2){
				L = N+1-L;
				m = N;
				for(int i=0; i<20; i++){
					bx[i] = tx[i];
				}
			}
			cout << L << "        ";
			cout << m << "      ";
			for(int i=0; i<20; i++){
				if(bx[i] == 1)
					cout << "x^" << i << "+";
			}

		}


		else{
			//cout << tx[0] << "see here";
			for(int i=0; i<20; i++){
				if(tx[i]==1)
					cout << "x^" << i << "+";
			}
			cout << "     ";

			for(int i=0; i<20; i++){
				if(cx[i]==1)
					cout << "x^" << i << "+";
			}
			cout << "           ";

			cout << L << "     ";
			cout << m << "     ";

			for(int i=0; i<20; i++){
				if(bx[i]==1)
					cout << "x^" << i << "+";
			}
		}
		N = N + 1;
		cout << endl;
	}
	cout << "L = " << L;
	return 0;
}