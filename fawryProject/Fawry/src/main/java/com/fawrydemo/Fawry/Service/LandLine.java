package com.fawrydemo.Fawry.Service;

import com.fawrydemo.Fawry.Factories.LandLineReceiptFactory;
import com.fawrydemo.Fawry.Receipts.Ireceipt;

public class LandLine implements Iservice {
    String name="Landline";
    static double discount=0;
    Ireceipt ireceipt =null ;

    public LandLine(int choice)
    {
        LandLineReceiptFactory landLineReceiptFactory = new LandLineReceiptFactory();
        ireceipt = landLineReceiptFactory.makeObj(choice);
    }

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
    this.discount= discount;
    }

}
