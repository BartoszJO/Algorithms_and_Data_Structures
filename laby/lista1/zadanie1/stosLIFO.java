package zadanie1;
import java.util.Stack;

public class stosLIFO {
    public static void main(String[] args) {

        Stack<Integer> stack = new Stack<>();

        // Dodawanie 50 elementów do stosu
        for (int i = 1; i <= 50; i++) {
            stack.push(i);
            System.out.println("Dodano do stosu: " + i);
        }

        // Pobieranie i wyświetlanie elementów ze stosu
        while (!stack.isEmpty()) {
            try {
                int removed = stack.pop();
                System.out.println("Usunięto ze stosu: " + removed);
            } catch (Exception e) {
                System.out.println("Błąd: Stos jest pusty");
            }
        }



    }
}
