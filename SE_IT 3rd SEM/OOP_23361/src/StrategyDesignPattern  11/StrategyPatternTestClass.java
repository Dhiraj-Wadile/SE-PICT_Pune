package StrategyDesignPattern;

import java.util.Scanner;

public class StrategyPatternTestClass {
    public static void main(String[] args){
        ShoppingCart cart = new ShoppingCart();
        Item a1 = new Item("36985210000",80);
        Item a2 = new Item("31225210000",100);
        Item a3 = new Item("32365210000",900);
        Item a4 = new Item("38785210000",810);
        Item a5 = new Item("36984510000",780);
        cart.addItem(a1);
        cart.addItem(a2);
        cart.addItem(a3);
        cart.addItem(a4);
        cart.addItem(a5);
        int choice;
        Scanner sc = new Scanner(System.in);
        do {
            System.out.println("---Strategy Pattern Design---");
            System.out.println("1.Credit card");
            System.out.println("2.Bitcoin");
            System.out.println("3.Paypal");
            System.out.println("4.Exit");
            System.out.print("Enter your choice: ");
             choice = sc.nextInt();

            switch(choice){
                case 1:
                    cart.pay(new CreditCardStrategy());
                    break;
                case 2:
                    cart.pay(new BitcoinStrategy());
                    break;
                case 3:
                    cart.pay(new payPal());
                    break;
                case 4:
                    System.out.println("Exiting the program!");
                    break;
                default:
                    System.out.println("Invalid choice.");
                    break;
            }
        }while(choice < 4);
    }
}
