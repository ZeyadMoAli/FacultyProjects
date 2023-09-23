import java.util.Calendar;

public class Main {

    public static void main(String[] args) {
    	/*CREATING OBJECTS*/
    	
    	/*Creating Drivers and their respective Vehicles*/
    	Driver driver1 = new Driver("Zeyad", "2020");
    	Vehicle vehicle1 = new Vehicle(driver1, "Audi A6", 2021, 156, 68, "Cairo", "Dokki");
    	
    	Driver driver2 = new Driver("Youssef", "2021");
    	Vehicle vehicle2 = new Vehicle(driver2, "Mercedes A-Class", 2022, 160, 72, "Cairo", "Giza");
    
    	
    	/*Creating Garages and their respective owners, 
    	 *then filling them with slots of different dimensions*/
      	GarageOwner owner1 = new GarageOwner("Mohammed","1234");
    	Garage garage1 = new Garage(owner1,"Moh Parking","Cairo", "Dokki", 75, "FirstFit");
    	garage1.addSlots(68, 156,35);
    	garage1.addSlots(75, 190, 40);
    	
    	GarageOwner owner2 = new GarageOwner("Osama","4321");
    	Garage garage2 = new Garage(owner2,"Osama Parking","Cairo", "Giza", 45, "BestFit");
    	garage2.addSlots(30, 85, 15);
    	garage2.addSlots(75, 175, 30);
    	/*******************************************************************************************/
    	
    	//BEGIN PROGRAM
    	Display display = new Display();
    	
    	//Make tow reservations for two vehicles
    	System.out.println("Parking in for vehicle 1 in garage 2...");
    	Reservation res1 = display.parkIn(driver1, vehicle1, owner2, garage2);
    	res1.endResevation();
    	display.displayReservation(res1);
    	System.out.println("////////////////////////////////////////");
    	
    	
    	System.out.println("Parking in for vehicle 2 in garage 1...");
    	Reservation res2 = display.parkIn(driver2, vehicle2, owner1, garage1);
    	display.displayReservation(res2);
    	System.out.println("////////////////////////////////////////");
    	
    	//Display Active slots to print slot IDs of the free slots 
    	garage1.setSlotStatus(true, 1);    //setting some slots in the garage to true -->occupied
    	garage1.setSlotStatus(true, 2);
    	garage1.setSlotStatus(true, 3);
    	System.out.println("Free slots in garage 1: \n-----------------------------");
    	garage1.displayActiveSlots();   	

    	
    	
    }

}
