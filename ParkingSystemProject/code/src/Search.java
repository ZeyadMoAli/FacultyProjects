import java.util.Vector;

public abstract class Search {

    public abstract Slot findSlot(Vehicle vehicle, Slot[] slots);

    public Garage findGarage(Vehicle vehicle, Vector<Garage> garages)
    {
        for(int i=0; i<garages.size(); i++)
        {
            if(garages.elementAt(i).getArea()==vehicle.getArea() && garages.elementAt(i).getCity()==vehicle.getCity())
            {
                return garages.elementAt(i);
            }

        }
        return null;
    }


}
