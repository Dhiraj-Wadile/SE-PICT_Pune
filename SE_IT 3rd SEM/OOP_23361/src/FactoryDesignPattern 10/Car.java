package FactoryDesignPattern;

public abstract class Car {
    private CarType model;
    Car(CarType model){
        this.model = model;
    }

    abstract void constructCar();
}
