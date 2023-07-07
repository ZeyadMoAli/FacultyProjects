package com.fawrydemo.Fawry.Factories;

import com.fawrydemo.Fawry.Service.*;

public class ServiceFactory implements IServiceFactory{
    Iservice iservice;

    @Override
    public   Iservice makeObj(int choice, int receiptChoice) {

        if(choice==1)
        {
             iservice=new MobileRecharge();
            return iservice;
        }
        else if(choice==2)
        {
            iservice=new InternetPayment();
            return iservice;
        }
        else if(choice==3)
        {
            iservice =new LandLine(receiptChoice);
            return iservice;
        }
        else if(choice==4) {
            iservice= new Donations();
            return iservice;
        }
        return null;
    }
}
