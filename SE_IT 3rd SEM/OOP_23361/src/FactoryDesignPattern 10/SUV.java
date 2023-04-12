package FactoryDesignPattern;

public class SUV extends Car{

    SUV(CarType model) {
        super(model);
        constructCar();
    }

    @Override
    void constructCar() {
        System.out.println("Manufacturing of SUV car");
        System.out.println("Construction of SUV car is done!!");
        System.out.println();
    }
}
