#include <iostream>
#include <string>
#include <unordered_map>
#include <iomanip>
using namespace std;

int main() {
	unordered_map<string, char> jk;
	unordered_map<string, int> u;
	
	int n, q, usia; 
	double sumL=0, sumP=0, countL=0, countP=0;
	string nim, nama;
	char kelamin;

	cin >> n;

	for (int i=0; i<n; i++) {
		cin >> nim;
		if (nim.size() == 9) cin >> kelamin >> usia;
		else cin >> nama >> kelamin >> usia;

		jk.emplace(nim, kelamin);
		u.emplace(nim, usia);
	}

	cin >> q;

	for (int i=0; i<q; i++) {
		cin >> nim;
		
		if(jk.find(nim) != jk.end()) {
			if(jk[nim] == 'L') { sumL += u[nim]; countL++; }
			else { sumP += u[nim]; countP++; }
		}
	}

	cout << fixed << setprecision(2) << sumL/countL << " " << sumP/countP;

	return 0;
}
