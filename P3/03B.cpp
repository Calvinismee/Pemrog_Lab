#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;
 
// a : norek, b : batas transaksi, s : saldo awal
// Buka rek baru : c a b s
// Setor n rupiah : s a n
// Tarik n rupiah : tan
// Akhir transaksi : X

class AkunBank {
    string norek;
    int saldo;
    int maksTransaksi;

    public : 
        void set(string n, int mt, int sl) {
            norek = n; saldo = sl; maksTransaksi = mt;
        }
        void setor(int dataSetor) {
            saldo = dataSetor <= maksTransaksi ? saldo + dataSetor : saldo;
        }

        void tarik(int dataTarik) {
            if (dataTarik > saldo) {
                return;
            }
            saldo = dataTarik <= maksTransaksi ? saldo - dataTarik: saldo;
        }

        int getSaldo() {
            return saldo;
        }

        string getNorek() {
            return norek;
        }
};

vector<AkunBank> table;

bool sortBySaldo(AkunBank& a1, AkunBank &a2) {
    return a1.getNorek() < a2.getNorek();
}

int main () {
    char choice;

    cin >> choice;
    while (choice != 'X') {
        AkunBank dummy;
        string a;
        int b, s, n;
        switch (choice)
        {
        case 'C' : {
            cin >> a >> b >> s;
            dummy.set(a, b, s);
            table.push_back(dummy);
            break;
        }
        case 'T' : {
            cin >> a >> n;
            for (auto it = table.begin(); it < table.end(); it++) {
                if(a == it->getNorek()) {
                    it->tarik(n);
                    break;
                }
            }
            break;
        }

        case 'S' : {
            cin >> a >> n;
            for (auto it = table.begin(); it < table.end(); it++) {
                if(a == it->getNorek()) {
                    it->setor(n);
                    break;
                }
            }
            break;
        }
        default:
            break;
        }
        cin >> choice;
    }
    // cout << table.size() << endl;
    
    sort(table.begin(), table.end(), sortBySaldo);
    for (auto it = table.begin(); it < table.end(); it++) {
        cout << it->getNorek() << " " << it->getSaldo() << endl;
    }
    return 0;
}