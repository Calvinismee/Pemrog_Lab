#include <iostream>
#include <iomanip>
using namespace std;

class Orang {
  private:
    string nama;
    int usia;
    double tinggi, berat;
  public:
    Orang(string n, int u, double t, double b) : nama(n), usia(u), tinggi(t), berat(b) {
        cout << nama << " | " << usia <<" | " << fixed << setprecision(2) << tinggi << " | " << fixed << setprecision(2) << berat << endl;
    }  // constructor
};
 
int main () {
    string nama;
    int usia;
    double tinggi, berat;

    getline(cin >> ws, nama);
    cin >> usia >> tinggi >> berat;

    Orang o(nama, usia, tinggi, berat);
    
    return 0;
}