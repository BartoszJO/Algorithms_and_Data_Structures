package zadanie2_b;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random rand = new Random();
        CircularLinkedListb list = new CircularLinkedListb();

        // Generowanie tablicy T i wstawianie liczb do listy
        int[] T = new int[10000];
        for (int i = 0; i < T.length; i++) {
            T[i] = rand.nextInt(100001); // Losowe liczby z przedziału [0, 100000]
            list.insert(T[i]);
        }

        // Wyszukiwanie losowych liczb z listy
        int totalCostFound = 0;
        for (int i = 0; i < 1000; i++) {
            int searchValue = T[rand.nextInt(T.length)];
            int cost = list.searchCost(searchValue);
            totalCostFound += cost;
        }
        double averageCostFound = (double) totalCostFound / 1000;

        // Wyszukiwanie losowych liczb z całego przedziału
        int totalCostRandom = 0;
        for (int i = 0; i < 1000; i++) {
            int searchValue = rand.nextInt(100001);
            int cost = list.searchCost(searchValue);
            if (cost != -1) { // Liczymy tylko koszty dla znalezionych elementów
                totalCostRandom += cost;
            }
        }
        double averageCostRandom = (double) totalCostRandom / 1000;

        System.out.println("Średni koszt wyszukiwania liczb, które są na liście: " + averageCostFound);
        System.out.println("Średni koszt wyszukiwania losowej liczby z przedziału: " + averageCostRandom);
    }
}
