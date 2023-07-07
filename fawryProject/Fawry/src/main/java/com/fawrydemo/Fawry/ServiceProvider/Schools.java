package com.fawrydemo.Fawry.ServiceProvider;
import com.fawrydemo.Fawry.Forms.*;
public class Schools implements IserviceProvider  {
    SchoolsForm form;
    String name="Schools";
    Boolean cash=false;
    public Schools()
    {

        form =new SchoolsForm();
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

