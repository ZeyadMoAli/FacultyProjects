
public class Vehicle {
  private static int id=1;
  protected Driver driver;
  private String modelName;
  private int model_year;
  private int vehicleDepth;
  private int vehicleWidth;
  private String city;
  private String area;


  // constructor , setters and getters

  public Vehicle(Driver driver, String modelName, int model_year, int vehicleDepth, int vehicleWidth, String city, String area) {
    this.id=++(this.id);
    this.driver = driver;
    this.modelName = modelName;
    this.model_year = model_year;
    this.vehicleDepth = vehicleDepth;
    this.vehicleWidth = vehicleWidth;
    this.city = city;
    this.area = area;
  }

  public Driver getDriver() {
    return driver;
  }

  public void setDriver(Driver driver) {
    this.driver = driver;
  }

  public String getModelName() {
    return modelName;
  }

  public void setModelName(String modelName) {
    this.modelName = modelName;
  }

  public int getModel_year() {
    return model_year;
  }

  public void setModel_year(int model_year) {
    this.model_year = model_year;
  }

  public int getVehicleDepth() {
    return vehicleDepth;
  }

  public void setVehicleDepth(int vehicleDepth) {
    this.vehicleDepth = vehicleDepth;
  }

  public int getVehicleWidth() {
    return vehicleWidth;
  }

  public void setVehicleWidth(int vehicleWidth) {
    this.vehicleWidth = vehicleWidth;
  }

  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public void setArea(String area) {
    this.area = area;
  }
  public String getCity() {
    return city;
  }

  public void setCity(String city) {
    this.city = city;
  }

  public String getArea() {
    return area;
  }
}




