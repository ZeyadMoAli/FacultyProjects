import java.util.ArrayList;
import java.util.Vector;
public class Garage {
    private GarageOwner owner;
    private static int garageId=0;
    int id;
    private String city;
    private String area;
    private int capacity;
    private Slot[] slots;
    private String name;
    public String config;
    private int counter = 0; //To assign IDs to slots 

    public Garage(GarageOwner owner,String name,String city, String area, int capacity, String config) {

        this.owner = owner;
        this.id = ++garageId;
        this.city = city;
        this.area = area;
        this.capacity = capacity;
        slots = new Slot[this.capacity];
        this.name=name;
        this.config = config;

    }
    
    /*add num of slots of dimensions w x d to the garage */
    public void addSlots(int w, int d, int num)
    {
    	for(int i=0; i<num; i++)
    	{
    		if(counter<capacity)
    			slots[counter++] = new Slot(counter, w, d);
    		else
    			System.out.println("You're out of capacity !");
    	}
    }
    
    /*Display IDs of free slots*/
    public void displayActiveSlots() {
    	for(int i=0; i<capacity; i++)
    	
    		if(!slots[i].getStatus())
    			System.out.println(slots[i].getId());
    }
    
    
//SETTERS AND GETTERS
    public void setSlotStatus(boolean stat,int slotID)
    {
    	slots[slotID-1].setStatus(stat);
    }
    public Slot[] getSlots() {
        return slots;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName()
    {
        return name;
    }
    public GarageOwner getOwner() {
        return owner;
    }

    public void setOwner(GarageOwner owner) {
        this.owner = owner;
    }
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
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

    public void setArea(String area) {
        this.area = area;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }
    
    //class testing
    public class Main {
        public static void main(String[] args) {
        	
          	GarageOwner owner1 = new GarageOwner("Mohammed","1234");
        	Garage garage1 = new Garage(owner1,"Moh Parking","Cairo", "Dokki", 75, "BestFit");

        }
    }
    


}
