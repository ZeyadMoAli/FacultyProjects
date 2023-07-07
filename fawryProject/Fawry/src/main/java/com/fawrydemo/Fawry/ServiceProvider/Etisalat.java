package com.fawrydemo.Fawry.ServiceProvider;
import com.fawrydemo.Fawry.Forms.*;
import org.springframework.boot.context.properties.source.ConfigurationPropertyName;

public class Etisalat implements IserviceProvider  {
    EtisalatForm form;
    String name="Etisalat";
    Boolean cash=true;
    public Etisalat()
    {

        form =new EtisalatForm();
    }
    @Override
    public String getname() {
        return this.name;
    }

    @Override
    public Boolean CashState() {
        return this.cash;
    }

    @Override
    public void FillForm(String Name) {
        form.SetName(name);
        form.Fill();
    }
}

