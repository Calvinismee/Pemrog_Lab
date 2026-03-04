import java.util.*;

abstract class Ruang2D {
    protected double a;
    protected double b;

    public Ruang2D(double p, double q) {
        a = p; 
        b = q;
    }

    abstract double  countLuas();
    abstract double countKeliling();
    
}

class Segiempat extends Ruang2D {
    public Segiempat(double p, double q) {
        super(p, q);
    }

    public double countLuas() {
        return a * b;
    }

    public double countKeliling() {
        return 2 * (a + b);
    }
}

class Segitiga extends Ruang2D {
    public Segitiga(double a, double t) {
        super(a, t);
    }

    public double countLuas() {
        return a * b / 2;
    }

    public double countKeliling() {
        return a + b + Math.sqrt(a * a + b * b);
    }
}

class Data {
    double sumLT = 0;
    double sumKT = 0;
    double sumLR = 0;
    double sumKR = 0;

    public void printSum() {
        System.out.println("LUAS");
        System.out.printf("- Segiempat : %.2f\n", sumLR);
        System.out.printf("- Segitiga : %.2f\n", sumLT);
        System.out.println("KELILING");
        System.out.printf("- Segiempat : %.2f\n", sumKR);
        System.out.printf("- Segitiga : %.2f\n", sumKT);
    }

    public double getSumLT() {
        return sumLT;
    }
    public double getSumLR() {
        return sumLR;
    }
    public double getSumKR() {
        return sumKR;
    }
    public double getSumKT() {
        return sumKT;
    }

    public void addSumLT(double l) {
        sumLT += l;
    }
    public void addSumKT(double l) {
        sumKT += l;
    }

    public void addSumLR(double l) {
        sumLR += l;
    }
    public void addSumKR(double l) {
        sumKR += l;
    }
}

public class Ruang {
    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);
        Data dt = new Data();

        char tipe = inp.next().charAt(0);
        while(tipe != 'X') {
            Ruang2D dummy;
            double a = inp.nextDouble();
            double b = inp.nextDouble();

            switch(tipe) {
                case 'R' : 
                    dummy = new Segiempat(a, b);
                    dt.addSumLR(dummy.countLuas());
                    dt.addSumKR(dummy.countKeliling());
                    break;
                case 'T' : 
                    dummy = new Segitiga(a, b);
                    dt.addSumLT(dummy.countLuas());
                    dt.addSumKT(dummy.countKeliling());
                    break;
            }
            tipe = inp.next().charAt(0);            
        }

        dt.printSum();

        inp.close();
    }
    
}