package com.fawrydemo.Fawry.ServiceProvider;
import com.fawrydemo.Fawry.Forms.*;
public class NGOS implements IserviceProvider  {
    NGOSForm form;
    Boolean cash=false;
    String name= "NGOS";
    public NGOS()
    {

        form =new NGOSForm();
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

