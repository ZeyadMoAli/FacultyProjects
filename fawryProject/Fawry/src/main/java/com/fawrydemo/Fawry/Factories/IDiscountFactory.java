package com.fawrydemo.Fawry.Factories;
import com.fawrydemo.Fawry.Database.*;
import com.fawrydemo.Fawry.Discount.*;

public interface IDiscountFactory {
    public Idiscount MakeObj( int choice , double amount, CustomerDataManager customerDataManager,int serviceChoice);
}
