package com.fawrydemo.Fawry.Discount;

import com.fawrydemo.Fawry.Service.*;



import java.util.ArrayList;

public class SpecificDiscount implements Idiscount{

    ArrayList<Iservice> iservices =new ArrayList<Iservice>() ;
    public SpecificDiscount (Iservice iservice,  double amount)
    {
        subscribe(iservice);
        setDiscountAmount(amount);
    }

    public void subscribe(Iservice service) {
        iservices.add(service);
    }
    public void unsubscribe(Iservice service) {
        iservices.remove(service);
    }
    public void notifyall(double amount) {
        for(Iservice ser : iservices)
        {
            ser.setDiscount(amount);
        }
    }

    public void setDiscountAmount(double amount) {
        notifyall(amount);
    }

}
