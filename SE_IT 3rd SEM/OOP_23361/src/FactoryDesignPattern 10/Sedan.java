package FactoryDesignPattern;

public class Sedan extends Car{

    Sedan(CarType model) {
        super(model);
        constructCar();
    }

    @Override
    void constructCar() {
        System.out.println("Manufacturing of Sedan car");
        System.out.println("Construction of Sedan car is done!!");
        System.out.println();
    }
}
