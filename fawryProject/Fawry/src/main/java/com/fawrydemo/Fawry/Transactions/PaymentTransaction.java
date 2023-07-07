package com.fawrydemo.Fawry.Transactions;

import com.fawrydemo.Fawry.ServiceProvider.*;
import com.fawrydemo.Fawry.User.*;
import com.fawrydemo.Fawry.Service.*;

public class PaymentTransaction implements Itransaction{

    private double amount = 0;
    private double discount=0;
    private double NetAmount= amount - discount;
    private static int count=0;
    private  int  transactionID=0;
    private Customer customer= null;
    private Iservice iservice= null;
    private IserviceProvider iserviceProvider= null;
    private boolean refundStates = false;


    public PaymentTransaction(Customer c, Iservice is, IserviceProvider isp, double amount, double discount)
    {
        customer=c;
        iservice=is;
        iserviceProvider=isp;
        count++;
        transactionID=count;
        this.amount= amount;
        this.discount=discount;
        NetAmount= amount - (amount * (discount/100));
        if(isp ==null)
        {
            We we =new We();
            iserviceProvider= we;
        }
    }
    public PaymentTransaction()
    {
        count++;
        transactionID=count;

    }



    public void SetServiceProvider(IserviceProvider iserviceProvider) {
        this.iserviceProvider=iserviceProvider;

    }

    public String getCustomerName()
    {
        return customer.getUsername();
    }

    public String getServiceProviderName()
    {
        return iserviceProvider.getname();
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public double getDiscount() {
        return discount;
    }

    public void setDiscount(double discount) {
        this.discount = discount;
    }

    public double getNetAmount() {
        return NetAmount;
    }

    public void setNetAmount(double netAmount) {
        NetAmount = netAmount;
    }

    public int getTransactionID() {
        return transactionID;
    }

    public void setTransactionID(int transactionID) {
        this.transactionID = transactionID;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void setCustomer(Customer customer) {
        this.customer = customer;
    }

    public Iservice getIservice() {
        return iservice;
    }

    public void setIservice(Iservice iservice) {
        this.iservice = iservice;
    }

    public IserviceProvider getIserviceProvider() {
        return iserviceProvider;
    }

    public void setIserviceProvider(IserviceProvider iserviceProvider) {
        this.iserviceProvider = iserviceProvider;
    }

    public boolean isRefundStates() {
        return refundStates;
    }

    public void setRefundStates(boolean refundStates) {
        this.refundStates = refundStates;
    }
}
