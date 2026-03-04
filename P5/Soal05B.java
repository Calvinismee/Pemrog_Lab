import java.util.Scanner;
import java.util.Arrays;


class Mhs {
    private String nim;
    private double ipk;
    private int sksxbobot;
    private int sks;

    public Mhs(String nim) {
        this.nim = nim; 
        sks = 0;
        sksxbobot = 0;
    }

    public void tambah_nilai(int sks, char hm) {
        int bobot = 0;
        switch(hm) {
            case 'A' : 
                bobot = 4;
                break;
            case 'B' : 
                bobot = 3;
                break;
            case 'C' : 
                bobot = 2;
                break;
            case 'D' : 
                bobot = 1;
                break;
            case 'E' : 
                bobot = 0;
                break;
        }


        this.sks += sks;
        sksxbobot += sks * bobot;
    }

    public void countIPK() {
        ipk = (double) sksxbobot / sks;
    }

    public double getIPK() {
        return ipk;
    }

    public int getsks() {
        return sks;
    }

    public int getbobot() {
        return sksxbobot;
    }

    public String getNIM() {
        return nim;
    }
};

public class Soal05B {


    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        int n = inp.nextInt();
        Mhs[] data = new Mhs[n];
        int k = inp.nextInt();
        for (int i = 0; i < n; i++) {
            inp.nextLine();
            String nim = inp.next();
            int t = inp.nextInt();

            Mhs dummy = new Mhs(nim);

            for(int j = 0; j < t; j++) {
                int sks = inp.nextInt();
                char hurufMutu = inp.next().charAt(0);
                dummy.tambah_nilai(sks, hurufMutu);
            }

            dummy.countIPK();
            data[i] = dummy;
        }

        Arrays.sort(data, (m1, m2) -> {
            if (m1.getIPK() == m2.getIPK())
                return m1.getNIM().compareTo(m2.getNIM());
            else
                return Double.compare(m2.getIPK(), m1.getIPK());
        });

        for(int i = 0; i < k; i++) {
            System.out.printf("%s %.2f\n", data[i].getNIM(), data[i].getIPK());
        }

        inp.close();
    }
}
