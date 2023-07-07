package com.fawrydemo.Fawry.Service;

public class InternetPayment implements Iservice {
    String name="InternetPayment";
    static double discount=0;
    @Override
    public String getName() {
        return name;
    }

    @Override
    public double getDiscount() {
        return discount;
    }

    @Override
    public void setDiscount(double discount) {
    this.discount=discount;
    }


}
