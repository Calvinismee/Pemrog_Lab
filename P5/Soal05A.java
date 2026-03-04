import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;

public class Soal05A {

    static List<Double> data = new ArrayList<>();
    public static double avg() {
        double sum = 0;
        for(double num: data) {
            sum += num;
        }

        return sum / data.size();
    }

    public static double stdev(double average) {
        double sum = 0;
        for(double num: data) {
            sum += Math.pow(num - average, 2);
        }

        return Math.sqrt(sum / (data.size() - 1));
    }

    public static void main(String[] args) {
        Scanner inp = new Scanner(System.in);

        int n = inp.nextInt();

        for (int i = 0; i < n; i++) {
            double x = inp.nextDouble();
            data.add(x);
        }

        Collections.sort(data);

        System.out.printf("%.2f %.2f\n", data.get(0), data.get(data.size() - 1));
        System.out.printf("%.2f %.2f\n", avg(), stdev(avg()));

        inp.close();

    }
    
}