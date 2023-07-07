package com.fawrydemo.Fawry.Discount;
import com.fawrydemo.Fawry.User.*;
import com.fawrydemo.Fawry.Database.*;
import java.util.ArrayList;

public class OverAllDiscount implements Idiscount{

    private ArrayList<Customer> customers=new ArrayList<Customer>();
    public OverAllDiscount(CustomerDataManager customerDataManager, double amount)
    {
         customers = customerDataManager.customers;
         setDiscountAmount(amount);
    }

    public void subscribe(Customer user) {
        customers.add(user);
    }
    public void unsubscribe(Customer user) {
        customers.remove(user);
    }
    public void notifyall(double amount) {
        for(Customer customer : customers )
        {
            customer.upDateDiscount(amount);
        }
    }
    public void setDiscountAmount(double amount) {
        notifyall(amount);
    }
}
