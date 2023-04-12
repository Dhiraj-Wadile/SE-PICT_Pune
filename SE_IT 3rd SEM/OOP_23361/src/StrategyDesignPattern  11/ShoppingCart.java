package StrategyDesignPattern;

import java.util.ArrayList;

public class ShoppingCart {
    ArrayList<Item> items = new ArrayList<Item>();

    ShoppingCart() {
        this.items = items;
    }

    void addItem(Item item) {
        this.items.add(item);
    }

    int CalculateTotal() {
        int total = 0;
        for (Item item : items) {
            total = total + item.getPrice();
        }
        return total;
    }

    void pay(PaymentStrategy payMethod){
        int amount = CalculateTotal();
        payMethod.pay(amount);
    }
}



