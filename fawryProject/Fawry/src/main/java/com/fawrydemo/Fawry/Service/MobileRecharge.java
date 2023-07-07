package com.fawrydemo.Fawry.Service;
public class MobileRecharge implements Iservice {
    String name="MobileRecharge";
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
