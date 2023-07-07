package com.fawrydemo.Fawry.Transactions;

import com.fawrydemo.Fawry.User.*;

public class AddtoWalltedTransaction implements Itransaction{

    private double amount  =0;
    private boolean refundStates = false;
    private static int count=0;
    private  int  transactionID;
    private Customer customer;

    public AddtoWalltedTransaction(double amount,  Customer customer) {
        this.amount = amount;
        count++;
        this.transactionID = count;
        this.customer = customer;
    }

    public boolean isRefundStates() {
        return refundStates;
    }

    public void setRefundStates(boolean refundStates) {
        this.refundStates = refundStates;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
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

    public String getCustomerName()
    {
        return customer.getUsername();
    }
    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

}
