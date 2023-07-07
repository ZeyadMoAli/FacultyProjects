package com.fawrydemo.Fawry.PaymentOptions;

public class Wallet  implements IpaymentOptions {
	private double balance = 1000;
	public boolean AddBalance (CraditCard c,double num) {
		boolean temp=false;
		if(c.pay(num) ==true)
		{
			balance+=num;
			temp=true;
			return temp;
		}
		return temp;
	}
	@Override
	public Boolean pay(double amount) {
		if(balance>=amount)
		{

			balance-=amount;
			return true;
		}
		return false;
	}


	public double GetBalance() {
		return this.balance;
	}
}
