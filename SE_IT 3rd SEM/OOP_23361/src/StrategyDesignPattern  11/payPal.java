package StrategyDesignPattern;

import java.util.Scanner;

public class payPal implements PaymentStrategy{

    String email_id;
    String pass;
    Scanner sc = new Scanner(System.in);

    public void getInfo(){
        System.out.println("Enter Email ID::");
        email_id=sc.nextLine();
        System.out.println("Enter Password::");
        pass=sc.nextLine();
    }
    @Override
    public void pay(int amt) {
        System.out.println("----------------------------------------------------------");
        System.out.println("Paying through payPal Charging Rs " + amt);
        System.out.println("----------------------------------------------------------");
    }
}
