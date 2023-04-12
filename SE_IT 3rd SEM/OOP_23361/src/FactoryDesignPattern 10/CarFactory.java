package FactoryDesignPattern;

public class CarFactory {
    public void buildCar(CarType model){
        Car c = null;

        switch(model){
            case Sedan:
                c = new Sedan(model);
                break;
            case SUV:
                c = new SUV(model);
                break;
            case HatchBack:
                c = new HatchBack(model);
                break;
        }
    }
}
