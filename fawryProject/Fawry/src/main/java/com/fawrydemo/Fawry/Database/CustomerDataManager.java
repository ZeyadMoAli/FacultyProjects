package com.fawrydemo.Fawry.Database;

import com.fawrydemo.Fawry.User.*;
import java.util.*;

public class CustomerDataManager implements IdataManger{
    public ArrayList<Customer> customers= new ArrayList<Customer>();
    public CustomerDataManager()
    {
        addCustomer(new Customer("zeyad","gmail", "123"));
    }
    public void addCustomer(Customer customer)
    {
        customers.add(customer);
    }


   public Customer FindCustomer(Customer customer)
    {
        for(Customer customer1: customers)
        {
            if( (customer1.getEmail().equals(customer.getEmail())) && (customer1.getPassword().equals(customer.getPassword())))
            {
                return customer1;
            }
        }
        return null;
    }

}
