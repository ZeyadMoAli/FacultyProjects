public class Driver extends Person{
    // following two attributes represent address of driver
    private String driverCity;
    private String driverArea;
    private Vehicle vehicle;
    //--------------------------------


    public Driver(String name, String password) {
        super(name, password);

    }
    public Driver(String name, String password,Vehicle vehicle) {
        super(name, password);

        this.vehicle = vehicle;
    }

}
