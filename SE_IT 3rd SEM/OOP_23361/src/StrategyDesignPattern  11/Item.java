package StrategyDesignPattern;

public class Item {
    String UpcCode;
    int price;

    Item(String str, int p ){
        UpcCode = str;
        price = p;
    }

    String getUpcCode(){
        return UpcCode;
    }

    int getPrice(){
        return price;
    }
}
