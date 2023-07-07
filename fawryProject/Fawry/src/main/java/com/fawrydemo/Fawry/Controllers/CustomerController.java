package com.fawrydemo.Fawry.Controllers;


import com.fawrydemo.Fawry.Database.*;
import com.fawrydemo.Fawry.User.Customer;
import com.fawrydemo.Fawry.Service.*;
import com.fawrydemo.Fawry.ServiceProvider.*;
import com.fawrydemo.Fawry.Transactions.*;
import org.springframework.web.bind.annotation.*;


public class CustomerController {
    Customer customer1;
    CustomerController()
    {
        customer1 = new Customer();
    }
    public Customer SignIn(Customer customer, CustomerDataManager customerDataManager) {
        return customer.SignIn(customerDataManager);
    }
    public double checkServiceDiscount(Customer customer ,int choice)
    {
        return customer.checkServiceDiscount(choice);
    }
    public PaymentTransaction makeService(Customer customer,int serviceChoice, int serviceProviderChoice, int paymentChoice,double amount,int receiptChoice, TransactionDataManager transactionDataManager, CustomerDataManager customerDataManager)
    {
        customer1 =SignIn(customer,customerDataManager);
        if ( customer1 == null)
        {
            SignUp(customer,customerDataManager);
        }
        else
        {
            customer =customer1;
        }
        return customer.makeService(serviceChoice,serviceProviderChoice, paymentChoice, amount,receiptChoice,transactionDataManager);
    }

    public Customer SignUp(Customer customer, CustomerDataManager customerDataManager) {
        return customer.SignUp(customerDataManager);
    }
    public boolean AddToWallet(Customer customer,  double balance,  TransactionDataManager transactionDataManager, CustomerDataManager customerDataManager) {
        customer1 =SignIn(customer,customerDataManager);
        if ( customer1 == null)
        {
            SignUp(customer,customerDataManager);
        }
        else
        {
            customer =customer1;
        }
        return customer.AddToWallet(balance, transactionDataManager);
    }
    Iservice SearchService(Customer customer, String serviceName, ServiceDataManger serviceDataManger)
    {
        return customer.SearchService( serviceName,serviceDataManger);
    }
    public  boolean Pay(Customer customer, double amount, IserviceProvider iserviceProvider, int paymentChoice)
    {
        return customer.Pay(amount,iserviceProvider, paymentChoice);
    }

    public Boolean RefundRequest(Customer customer, int id, TransactionDataManager transactionDataManager) {
        return  customer.RefundRequest(id, transactionDataManager);
    }

    public String getUsername(Customer customer) {
        return customer.getUsername();
    }

    public void setUsername(Customer customer,String username) {
        customer.setUsername(username);
    }

    public String getEmail(Customer customer) {
       return customer.getEmail();
    }

    public void setEmail(Customer customer,String email) {
        customer.setEmail(email);    }

    public String getPassword(Customer customer) {
        return customer.getPassword();
    }

    public void setPassword(Customer customer,String password) {
        customer.setPassword(password);
    }

    public double getDiscount(Customer customer) {
        return customer.getDiscount();
    }

    public void setDiscount(Customer customer,double discount_amount) {
        customer.setDiscount(discount_amount);
    }

    public double GetWalletBalance(Customer customer)
    {
        return customer.GetWalletBalance();
    }
    public double GetCreditBalance(Customer customer)
    {
        return customer.GetCreditBalance();
    }




}
