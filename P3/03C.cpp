#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Persegi{
    int panjang, lebar, luas;

    public :
        void set(int p, int l) {
            panjang = p; lebar = l;
        }

        void hitungLuas() {
            luas =  panjang * lebar;
        }

        int getLuas() {
            return luas;
        }
};

bool compByLuas(Persegi& a1, Persegi &a2) {
    return a1.getLuas() < a2.getLuas();
}

int main () {
    vector<Persegi> data;
    Persegi dummy;
    int n, k, p, l;

    cin >> n >> k;

    while(n--) {
        cin >> p >> l;
        dummy.set(p, l);
        dummy.hitungLuas();
        data.push_back(dummy);
    }

    sort(data.begin(), data.end(), compByLuas);

    for(int i = 0; i < k; i++) {
        cout << data[i].getLuas() << endl;
    }


    return 0;
}