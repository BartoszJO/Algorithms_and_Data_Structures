package zadanie3;
import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Random rand = new Random();
        CircularDoublyLinkedList list = new CircularDoublyLinkedList();

        // Wypełnienie listy i tablicy T
        int[] T = new int[10000];
        for (int i = 0; i < T.length; i++) {
            T[i] = rand.nextInt(100001);
            list.insert(T[i]);
        }

        // Średni koszt wyszukiwania dla liczb z listy
        long totalCostFound = 0;
        for (int i = 0; i < 1000; i++) {
            int searchValue = T[rand.nextInt(T.length)];
            totalCostFound += list.searchCost(searchValue, true);
        }

        // Średni koszt wyszukiwania dla losowych liczb
        long totalCostRandom = 0;
        for (int i = 0; i < 1000; i++) {
            int searchValue = rand.nextInt(100001);
            totalCostRandom += list.searchCost(searchValue, true);
        }

        System.out.println("Średni koszt wyszukiwania dla liczb z listy: " + (double)totalCostFound / 1000);
        System.out.println("Średni koszt wyszukiwania dla losowych liczb: " + (double)totalCostRandom / 1000);
    }
}