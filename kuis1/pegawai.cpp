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
    public:
        Tetap(string pid, int u, int t, int gp) {
            set(pid, u, t);
            income += gp;
        }

        void inUangLembur(int ul) {
            income += ul;
        }
};

class Harian : public Pegawai {
    

    public : 
        Harian(string pid, int u, int t) {
            set(pid, usia, tipe);
        }

        void inUpah(int u) {
            income += u;
        }

};

vector<Tetap> dt_tetap;
vector<Harian> dt_harian;

int main() {
    int n, usia, tipe, uang, gaji_pokok;
    string id;

    cin >> n;
    while(n--) {
        cin >> id >> usia >> tipe;
        if(tipe == 1) {
            cin >> gaji_pokok;
            dt_tetap.push_back(Tetap(id, usia, tipe, gaji_pokok));
        }

        if (tipe == 2) {
            dt_harian.push_back(Harian(id, usia, tipe));
        }
    }

    cin >> id; 
    while (id != "END") {
        int done = 0;
        cin >> uang;

        for (auto& it : dt_tetap) {
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


        for (auto& it : dt_harian) {
            if(it.getID() == id) {
                it.inUpah(uang);
                break;
            }
        }

        cin >> id;
    }

    for (auto& it : dt_tetap) {
        it.show();
    }
    
    for (auto& it : dt_harian) {
        it.show();
    }
    


 
    return 0;
}