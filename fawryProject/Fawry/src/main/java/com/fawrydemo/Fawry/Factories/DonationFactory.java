package com.fawrydemo.Fawry.Factories;

import com.fawrydemo.Fawry.ServiceProvider.CancerHospital;
import com.fawrydemo.Fawry.ServiceProvider.IserviceProvider;
import com.fawrydemo.Fawry.ServiceProvider.NGOS;
import com.fawrydemo.Fawry.ServiceProvider.Schools;

public class DonationFactory {
    IserviceProvider iserviceProvider;
    public IserviceProvider makeObj(int choice) {
        if (choice == 1) {
            iserviceProvider = new Schools();
            return iserviceProvider;
        } else if (choice == 2) {
            iserviceProvider = new NGOS();
            return iserviceProvider;
        } else if (choice == 3) {
            iserviceProvider = new CancerHospital();
            return iserviceProvider;
        }
        return null;
    }
}



