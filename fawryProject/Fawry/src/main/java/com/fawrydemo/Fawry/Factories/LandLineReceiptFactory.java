package com.fawrydemo.Fawry.Factories;

import com.fawrydemo.Fawry.Receipts.Ireceipt;
import com.fawrydemo.Fawry.Receipts.MonthlyReceipt;
import com.fawrydemo.Fawry.Receipts.QuarterReceipt;

public class LandLineReceiptFactory {
    Ireceipt ireceipt;
    public Ireceipt makeObj(int choice)
    {
        if(choice==1)
        {
            ireceipt= new MonthlyReceipt();
             return ireceipt;
        }else if(choice==2)
        {
            ireceipt =new QuarterReceipt();
            return ireceipt;
        }
        return null;

    }
}
