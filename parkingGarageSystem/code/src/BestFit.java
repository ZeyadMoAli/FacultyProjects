import java.util.Calendar;

public class BestFit extends Search {

    public Slot findSlot(Vehicle vehicle, Slot[] slots) {

        if (vehicle.getVehicleWidth() <= 45 && vehicle.getVehicleDepth() <= 100) {
            for (int i = 0; i < slots.length; i++) {
                if (slots[i].getWidth() >= 25 && slots[i].getWidth() <= 45 && slots[i].getDepth() >= 75 && slots[i].getDepth() <= 100 && slots[i].getStatus() == false) {
                    slots[i].setVehicleInSlot(vehicle);
                    slots[i].setStatus(true);
                    return slots[i];
                }

            }
        } else if (vehicle.getVehicleWidth() <= 78 && vehicle.getVehicleDepth() <= 197) {
            for (int i = 0; i < slots.length; i++) {
                if (slots[i].getWidth() >= 68 && slots[i].getWidth() <= 78 && slots[i].getDepth() >= 156 && slots[i].getDepth() <= 197 && slots[i].getStatus() == false) {
                    slots[i].setVehicleInSlot(vehicle);
                    slots[i].setStatus(true);
                    return slots[i];
                }
            }

        }
        System.out.println("There are no available slots");
        return null;
    }
}