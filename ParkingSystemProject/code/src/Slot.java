public class Slot {
    private int id;
    private int width;
    private int depth;
    private boolean status;
    protected Vehicle vehicleInSlot;

    public Slot() {}
    
    public Slot( int id, int width, int depth){
        this.id = id;
        this.width = width;
        this.depth = depth;
        this.status = false;
    }

    public Slot( int id, int width, int depth, Vehicle vehicleInSlot){
            this.id = id;
            this.width = width;
            this.depth = depth;
            this.vehicleInSlot = vehicleInSlot;
        }

        public int getId () {
            return id;
        }

        public void setId ( int id){
            this.id = id;
        }

        public int getWidth () {
            return width;
        }

        public void setWidth ( int width){
            this.width = width;
        }

        public int getDepth () {
            return depth;
        }

        public void setDepth ( int depth){
            this.depth = depth;
        }

        public Vehicle getVehicleInSlot () {
            return vehicleInSlot;
        }

        public void setVehicleInSlot (Vehicle vehicleInSlot){
            this.vehicleInSlot = vehicleInSlot;
        }
        public boolean getStatus()
        {
            return status;
        }
        public void setStatus(boolean status)
        {
            this.status = status;
        }

    }


