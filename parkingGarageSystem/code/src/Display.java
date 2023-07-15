import java.util.Vector;
import java.util.Calendar;

public class Display {
	 
	
	Reservation parkIn(Driver driver, Vehicle vehicle, GarageOwner owner, Garage garage){
		Reservation res = new Reservation(driver, vehicle, owner, garage);
    	res.setConfigration();
    	res.startReservation();
    	return res;
	}
		
	void displayActiveSlots(Garage garage) {
		garage.displayActiveSlots();
	}

    void displayReservation( Reservation reservation)
    {
        System.out.println("reservation id: "+reservation.getId());
        System.out.println("driver id: "+reservation.getId());
        System.out.println("vehicle id: "+reservation.getVehicle().getId());
        System.out.println("garage id: "+reservation.getGarage().getId());
        System.out.println("garage owner: "+reservation.getGarage().getOwner().getName());
        System.out.println("slot id: "+reservation.getSlot().getId());
        System.out.println("Start time: "+reservation.getStarTime().get(Calendar.HOUR_OF_DAY) + ":" + reservation.getStarTime().get(Calendar.MINUTE));
        if(reservation.getEndTime()==null)
        {
        	System.out.println("End Time: NULL");
        	System.out.println("Total Fees: NULL");
        }
        else
        {
        	System.out.println("end time: "+reservation.getEndTime().get(Calendar.HOUR_OF_DAY) + ":" + reservation.getEndTime().get(Calendar.MINUTE));
        	System.out.println("Total Fees: "+reservation.getTotalFees()+" EGP");
        }
    }
    
    void displayCurrentFees(Reservation reservation)
    {
        System.out.println("Current Fees: "+reservation.getCurrentlFees()+" EGP");
    }

    void displayGarageOwner(GarageOwner garageOwner)
    {
        System.out.println("GarageOwner name: "+garageOwner.getName());
        System.out.println("GarageOwner id: "+garageOwner.getId());
    }
    void displayVehicle(Vehicle vehicle)
    {
        System.out.println("vehicle id: "+vehicle.getId());
        System.out.println("vehicle depth: "+vehicle.getVehicleDepth());
        System.out.println("vehicle width: "+vehicle.getVehicleWidth());
        System.out.println("vehicle model name: "+vehicle.getModelName());
        System.out.println("vehicle model year: "+vehicle.getModel_year());
        System.out.println("vehicle driver: ");
        this.displayDriver(vehicle.getDriver());

    }
    void displaySlot(Slot slot)
    {
        System.out.println("slot id: "+slot.getId());
        System.out.println("slot width: "+slot.getWidth());
        System.out.println("slot depth: "+slot.getDepth());
    }

    void displayGarage(Garage garage)
    {
        System.out.println("garage id: "+garage.getId());
        System.out.println("garage name: "+garage.getName());
        System.out.println("garage city: "+garage.getCity());
        System.out.println("garage area: "+garage.getArea());
        System.out.println("garage capacity: "+garage.getCapacity());
        System.out.println("garage owner: ");
        this.displayGarageOwner(garage.getOwner());
        System.out.println("garage slots: ");
        Slot[] slots= garage.getSlots();
        for(int i=0; i<garage.getCapacity(); i++)
        {
            this.displaySlot(slots[i]);

        }
    }

    void displayDriver(Driver driver)
    {
        System.out.println("driver name: "+driver.getName());
        System.out.println("driver id: "+driver.getId());
    }
}
