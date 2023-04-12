package StrategyDesignPattern;

import java.util.Scanner;

public class BitcoinStrategy implements PaymentStrategy{

    String BitcoinWalletAddress;
    String BitcoinAmt;
    Scanner sc = new Scanner(System.in);

    public void getInfo(){
        System.out.print("Enter Bitcoin Wallet Address: ");
        BitcoinWalletAddress = sc.next();
        System.out.print("Enter Bitcoin amount: ");
        BitcoinAmt = sc.next();
    }
    @Override
    public void pay(int amt) {
        System.out.println("----------------------------------------------------------");
        System.out.println("Paying through Bitcoin Charging Rs " + amt);
        System.out.println("----------------------------------------------------------");
    }
}
