package com.fawrydemo.Fawry.PaymentOptions;

public class CraditCard implements IpaymentOptions {
	 private double balance = 1000;
	@Override
	public Boolean pay(double amount) {
		boolean bool=false;
		if(balance>=amount)
		{

			balance-=amount;
			bool=true;
			return bool;
		}
		return bool;
	}

	public double GetBalance() {
		return this.balance;
	}
}
