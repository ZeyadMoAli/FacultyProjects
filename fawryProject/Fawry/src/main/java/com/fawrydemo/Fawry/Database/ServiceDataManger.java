package com.fawrydemo.Fawry.Database;
import com.fawrydemo.Fawry.Service.*;
import java.util.*;

public class ServiceDataManger implements IdataManger{
    public ArrayList<Iservice> iservices= new ArrayList<Iservice>();
    public ServiceDataManger()
    {
        Iservice iservice1= new MobileRecharge();
        Iservice iservice2= new InternetPayment();
        Iservice iservice3 = new LandLine(1);
        Iservice iservice4 = new Donations();
        Addservice(iservice1);
        Addservice(iservice2);
        Addservice(iservice3);
        Addservice(iservice4);
    }

    public void Addservice(Iservice iservice)
    {
        iservices.add(iservice);
    }
    public Iservice Search(String  service)
    {
        for(Iservice iservice1 :iservices)
        {
            if(iservice1.getName().equals(service))
                return iservice1;
        }
        return null;
    }
}
