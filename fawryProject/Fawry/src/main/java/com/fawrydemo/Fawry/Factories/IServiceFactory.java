package com.fawrydemo.Fawry.Factories;

import com.fawrydemo.Fawry.Service.*;

public interface IServiceFactory {
    public Iservice makeObj(int choice, int receiptChoice);
}
