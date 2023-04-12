package FactoryDesignPattern;

public class HatchBack extends Car{
    HatchBack(CarType model) {
        super(model);
        constructCar();
    }

    @Override
    void constructCar() {
        System.out.println("Manufacturing of HatchBack car");
        System.out.println("Construction of HatchBack car is done!!");
        System.out.println();
    }
}
