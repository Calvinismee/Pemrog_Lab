#include <iostream>
#include <vector>
using namespace std;

class Pegawai {
    protected:
        string id;
        int usia;
        int tipe;
        int income;

    public:
        Pegawai() {
            id = " ";
            usia = income = 0;
            tipe = 1;
        }

        void set(string pid, int u, int t) {
            id = pid;
            usia = u;
            tipe = t;
        }

        string getID() {
            return id;
        }

        void show() {
            cout << id << " " << tipe << " " << income << endl;
        }

};

class Tetap : public Pegawai {
    int gaji_pokok, uang_lembur;

    public:
        Tetap(string pid, int u, int t, int gp): gaji_pokok(gp) {
            set(pid, u, t);
            income += gaji_pokok;
        }

        // Buat fungsi untuk nambah income

        void inUangLembur(int ul) {
            income = income + ul;

            // income += ul
        }
};

class Harian : public Pegawai {
    int upah;

    public: 
        Harian(string pid, int u, int t) {
            set(pid, u, t);
        }

        void inUpah(int up) {
            income = income + up;
        }
};

vector<Tetap> data_tetap;
vector<Harian> data_harian;

 
int main() {
    int n;
    string id;
    int usia, tipe, gaji_pokok, uang;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> id >> usia >> tipe;

        // Tipe 1 : Tetap
        // Tipe 2 : Harian

        if(tipe == 1) {
            cin >> gaji_pokok;
            Tetap dummy_tetap(id, usia, tipe, gaji_pokok);
            data_tetap.push_back(dummy_tetap);
        }

        if(tipe == 2) {
            Harian dummy_harian(id, usia, tipe);
            data_harian.push_back(dummy_harian);
        }
    }

    // T baris
    // Input 1
    // Input 2
    // ...
    // END

    cin >> id;
    while(id != "END") {
        cin >> uang;
        int done = 0;

        // for(auto it = data_tetap.begin(); it != data_tetap.end(); it++) {

        // }

        for(auto& it : data_tetap) {
            if(it.getID() == id) {
                it.inUangLembur(uang);
                done = 1;
                break;
            }
        }

        if(done == 1) {
            cin >> id;
            continue;
        }


        for(auto& it : data_harian) {
            if(it.getID() == id) {
                it.inUpah(uang);
                break;
            }
        }

        cin >> id;
    }

    for(auto& it : data_tetap) {
        it.show();
    }

    for(auto& it : data_harian) {
        it.show();
    }

    return 0;
}