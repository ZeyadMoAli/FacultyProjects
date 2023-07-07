package com.fawrydemo.Fawry.PaymentOptions;

public class Cash implements IpaymentOptions{

    @Override
    public Boolean pay(double amount) {
        return true;
    }
    
}
