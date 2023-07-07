package com.fawrydemo.Fawry.ServiceProvider;
import com.fawrydemo.Fawry.Forms.*;
public class We implements IserviceProvider {
    String name="We";
    WeForm form;
    Boolean cash=true;
    public  We()
    {

       form =new WeForm();
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
    public void FillForm(String Name){
        form.SetName(name);
        form.Fill();
    }


}
