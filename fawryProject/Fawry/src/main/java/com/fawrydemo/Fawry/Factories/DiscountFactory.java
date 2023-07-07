package com.fawrydemo.Fawry.Factories;
import com.fawrydemo.Fawry.Database.*;
import com.fawrydemo.Fawry.Discount.*;
import com.fawrydemo.Fawry.Service.*;

import java.util.Scanner;

public class DiscountFactory implements IDiscountFactory{
    Idiscount idiscount;

    @Override
    public Idiscount MakeObj( int choice , double amount, CustomerDataManager customerDataManager, int serviceChoice) {
        if(choice==1 )
        {
            idiscount = new OverAllDiscount(customerDataManager, amount);
            return idiscount;
        }
        else if (choice ==2)
        {
            ServiceFactory serviceFactory=new ServiceFactory();
            Iservice iservice = serviceFactory.makeObj(serviceChoice,1);
            idiscount =new SpecificDiscount(iservice, amount);
            return idiscount;

        }
        return  null;
    }
}
