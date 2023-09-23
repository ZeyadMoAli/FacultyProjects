public class FirstFit extends Search{

    public Slot findSlot(Vehicle vehicle, Slot[] slots) {
        for(int i=0; i<slots.length; i++)
        {
            if(slots[i].getWidth()  >=vehicle.getVehicleWidth() && slots[i].getDepth()>= vehicle.getVehicleDepth() && slots[i].getStatus()==false)
            {
                slots[i].setVehicleInSlot(vehicle);
                slots[i].setStatus(true);
                return slots[i];
            }

        }
        System.out.println("There are no available slots");
        return null;
    }


}
