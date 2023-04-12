package FactoryDesignPattern;

import java.util.Scanner;

public class TestFactoryPattern {

    int menu(){
        int choice = 0;
        System.out.println("---------------------------");
        System.out.println("1.Sedan");
        System.out.println("2.SUV");
        System.out.println("3.HatchBack");
        System.out.println("4.Exit");
        System.out.println("---------------------------");
        return choice;
    }
    public static void main(String [] args){
        int choice = 0;
        Scanner sc = new Scanner(System.in);
        TestFactoryPattern ob = new TestFactoryPattern();
        CarFactory obj = new CarFactory();

        do{
            System.out.println("-------Factory Design Pattern-------");
            ob.menu();
            System.out.print("\nEnter your choice to construct a car: ");
            choice = sc.nextInt();

            switch (choice){
                case 1:
                    obj.buildCar(CarType.Sedan);
                    break;
                case 2:
                    obj.buildCar(CarType.SUV);
                    break;
                case 3:
                    obj.buildCar(CarType.HatchBack);
                    break;
            }
        }while(choice < 4);
    }
}
