#include <bits/stdc++.h>
using namespace std;

class Orang
{
protected:
    char gender;
    int usia;

public:
    Orang(char g, int u) : gender(g), usia(u) {}

    void print()
    {
        cout << gender << " " << usia;
    }

    char getGender()
    {
        return gender;
    }

    int getUsia()
    {
        return usia;
    }
};

class Pegawai : public Orang
{
    string nama;
    string nip;

public:
    Pegawai(char g, int u, string name, string NIP) : Orang(g, u), nama(name), nip(NIP)
    {
        // cout << "Pegawai " << nama << endl;
    }

    void print()
    {
        cout << nip << " " << nama;
        Orang::print();
    }

    string getNip()
    {
        return nip;
    }
};

class Mhs : public Orang
{
    string nim;

public:
    Mhs(char g, int u, string n) : Orang(g, u), nim(n)
    {
        // cout << "Mhs " << endl;
    }
    void print()
    {
        cout << nim << " ";
        Orang::print();
    }

    string getNim()
    {
        return nim;
    }
};

int main()
{
    int n, q, sumP, sumL, countP, countL;
    string nim_nip, nama;
    char gender;
    int usia;

    // make 2 maps for each Pegawai and Mhs
    unordered_map<string, Pegawai> dataPegawai;
    unordered_map<string, Mhs> dataMhs;

    cin >> n;

    while (n--)
    {
        cin >> nim_nip;
        if (isdigit(nim_nip[0]))
        {
            cin >> nama >> gender >> usia;
            Pegawai dummy(gender, usia, nama, nim_nip);
            dataPegawai.emplace(nim_nip, dummy);
        }
        else
        {
            cin >> gender >> usia;
            Mhs dummy(gender, usia, nim_nip);
            dataMhs.emplace(nim_nip, dummy);
        }
    }

    sumP = sumL = countP = countL = 0;

    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> nim_nip;

        switch (isdigit(nim_nip[0]))
        {
        case true:
            if (auto search = dataPegawai.find(nim_nip); search != dataPegawai.end())
            {
                switch (search->second.getGender())
                {
                case 'L':
                    sumL += search->second.getUsia();
                    countL++;
                    break;
                case 'P':
                    sumP += search->second.getUsia();
                    countP++;
                }
            }
            break;
        case false:
            if (auto search = dataMhs.find(nim_nip); search != dataMhs.end())
            {
                switch (search->second.getGender())
                {
                case 'L':
                    sumL += search->second.getUsia();
                    countL++;
                    break;
                case 'P':
                    sumP += search->second.getUsia();
                    countP++;
                }
            }
            break;
        }
    }

    cout << fixed << setprecision(2) <<((double)sumL) / countL << " " << ((double)sumP) / countP << endl;
    return 0;
}