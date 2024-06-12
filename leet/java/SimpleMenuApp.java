//Java 22 demo
import java.util.Scanner;

class SimpleMenuApp {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        boolean exit = false;

        while (!exit) {
            System.out.println("Menu:");
            System.out.println("1. Say Hello");
            System.out.println("2. Calculate Sum");
            System.out.println("3. Exit");
            System.out.print("Choose an option: ");

            int choice = scanner.nextInt();

            switch (choice) {
                case 1 -> System.out.println("Hello!");
                case 2 -> {
                    System.out.print("Enter first number: ");
                    int num1 = scanner.nextInt();
                    System.out.print("Enter second number: ");
                    int num2 = scanner.nextInt();
                    int sum = num1 + num2;
                    System.out.println("The sum is: " + sum);
                }
                case 3 -> exit = true;
                default -> System.out.println("Invalid choice. Please try again.");
            }
            System.out.println();
        }

        scanner.close();
        System.out.println("Goodbye!");
    }
}