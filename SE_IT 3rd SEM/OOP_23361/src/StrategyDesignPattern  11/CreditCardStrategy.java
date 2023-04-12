package StrategyDesignPattern;

import java.util.Scanner;

public class CreditCardStrategy implements PaymentStrategy{

    String name;
    String cardNo;
    int cvv,expDate;
    CreditCardStrategy(){
        getInfo();
    }
    Scanner sc = new Scanner(System.in);
    public void getInfo(){
        System.out.print("Enter your name: ");
        name = sc.next();
        System.out.print("Enter your Card number: ");
        cardNo = sc.next();
        System.out.print("Enter cvv of card: ");
        cvv = sc.nextInt();
        System.out.print("Enter Expiry Date of card: ");
        expDate = sc.nextInt();
    }
    @Override
    public void pay(int amt) {
        System.out.println("----------------------------------------------------------");
        System.out.println("Paying through CreditCard Charging Rs " + amt);
        System.out.println("----------------------------------------------------------");
    }
}
