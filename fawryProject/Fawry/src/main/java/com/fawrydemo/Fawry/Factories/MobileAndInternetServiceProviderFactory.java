package com.fawrydemo.Fawry.Factories;
import com.fawrydemo.Fawry.ServiceProvider.*;
public class MobileAndInternetServiceProviderFactory {

    IserviceProvider iserviceProvider;
    public IserviceProvider makeObj(int choice) {
        if(choice ==1)
        {
            iserviceProvider=new We();
            return iserviceProvider;
        }
        else if(choice ==2)
        {
            iserviceProvider=new Orange();
            return iserviceProvider;
        }
        else if(choice ==3)
        {
            iserviceProvider=new Etisalat();
            return iserviceProvider;
        }

        else if(choice ==4)
        {
            iserviceProvider=new Vodafone();
            return iserviceProvider;
        }

        return null;

    }
}
