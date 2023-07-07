package com.fawrydemo.Fawry.ServiceProvider;
import com.fawrydemo.Fawry.Forms.*;
public class Vodafone implements IserviceProvider {
    String name="Vodafone";
    VodafoneForm form;
    Boolean cash=false;
    public  Vodafone()
    {

        form =new VodafoneForm();
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

