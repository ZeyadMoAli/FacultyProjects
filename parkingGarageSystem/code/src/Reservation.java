import java.util.Calendar;
import java.util.Vector;

public class Reservation {
    private Garage garage;

    private static int id=0;
    private Slot slot;
    private Driver driver;
    private Vehicle vehicle;
    private GarageOwner garageOwner;
    private double rate=5;
    private Search search;
    private Calendar starTime;
    private Calendar endTime;

    public Reservation(Driver driver, Vehicle vehicle, GarageOwner garageOwner,Garage garage)
    {
    	this.id = ++id;
        this.driver=driver;
        this.garage = garage;
        this.garageOwner=garageOwner;
        this.vehicle=  vehicle;
        this.setConfigration();
    }
    
    public void startReservation()
    {
            this.slot= search.findSlot(this.vehicle, this.garage.getSlots());
            starTime= Calendar.getInstance();
    }

    public void endResevation()
    {
        endTime= Calendar.getInstance();
        this.slot.setStatus(false);
    }

    public double getTotalFees()
    {
        return this.rate*(this.endTime.get(Calendar.HOUR_OF_DAY) -this.starTime.get(Calendar.HOUR_OF_DAY));
    }

    public double getCurrentlFees()
    {
        Calendar currentTime;
        currentTime= Calendar.getInstance();
        return this.rate*( currentTime.get(Calendar.HOUR_OF_DAY)- this.starTime.get(Calendar.HOUR_OF_DAY));
    }

    
    //SETTERS AND GETTERS
    public void setConfigration()
    {
        if(garage.config=="FirstFit")
        {
            search= new FirstFit();
        }
        else if(garage.config=="BestFit")
        {
            search=new BestFit();
        }
    }
    public Garage getGarage()
    {
        return garage;
    }

    public Slot getSlot()
    {
        return slot;
    }

    public int getId()
    {
        return id;
    }

    public Vehicle getVehicle()
    {
        return vehicle;
    }
    public GarageOwner getGarageOwner()
    {
        return garageOwner;
    }

    public Calendar getStarTime()
    {
        return starTime;
    }
    public Calendar getEndTime()
    {
        return endTime;
    }
    

}
