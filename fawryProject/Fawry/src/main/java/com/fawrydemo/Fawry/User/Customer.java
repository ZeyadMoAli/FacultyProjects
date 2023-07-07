package com.fawrydemo.Fawry.User;
import com.fawrydemo.Fawry.Database.*;
import com.fawrydemo.Fawry.Factories.*;
import com.fawrydemo.Fawry.Service.*;
import com.fawrydemo.Fawry.ServiceProvider.*;
import com.fawrydemo.Fawry.Transactions.*;
import com.fawrydemo.Fawry.PaymentOptions.*;

public class Customer implements IUser {
    private String username;
    private String email;
    private String password;
    private static double discount = 0;
    private Wallet wallet = new Wallet();

    private CraditCard craditCard = new CraditCard();

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public double getDiscount() {
        return discount;
    }

    public void setDiscount(double discount_amount) {
        discount = discount_amount;
    }
    public Customer() {}
    public Customer(String username, String email, String password) {
        setUsername(username);
        setEmail(email);
        setPassword(password);
    }
    public boolean AddToWallet(double balance , TransactionDataManager transactionDataManager) {
        boolean bool=false;
        if( wallet.AddBalance(craditCard, balance))
        {
            AddtoWalltedTransaction  addtoWalltedTransaction=new AddtoWalltedTransaction(balance,this);
            transactionDataManager.AddWalletTransaction(addtoWalltedTransaction);
            bool=true;
            return bool;
        }
        return bool;
    }
    public double checkServiceDiscount(int choice)
    {
        ServiceFactory serviceFactory=new ServiceFactory();
        Iservice iservice= serviceFactory.makeObj(choice,1);
        return iservice.getDiscount();
    }
    public PaymentTransaction makeService(int serviceChoice,int serviceProviderChoice, int paymentChoice, double amount, int receiptChoice, TransactionDataManager transactionDataManager)
    {
        ServiceFactory serviceFactory=new ServiceFactory();
        Iservice iservice= serviceFactory.makeObj(serviceChoice,receiptChoice);
        PaymentTransaction itransaction ;

        IserviceProvider iserviceProvider= null;

        if(serviceChoice==1 || serviceChoice ==2)
        {
            MobileAndInternetServiceProviderFactory mobileAndInternetServiceProviderFactory= new MobileAndInternetServiceProviderFactory();
            iserviceProvider = mobileAndInternetServiceProviderFactory.makeObj(serviceProviderChoice);
        }
        else if(serviceChoice==4)
        {
            DonationFactory donationFactory=new DonationFactory();
            iserviceProvider = donationFactory.makeObj(serviceProviderChoice);
        }
        itransaction =new PaymentTransaction(this, iservice,iserviceProvider,amount,iservice.getDiscount()+ this.getDiscount());
        if(Pay(itransaction.getNetAmount(), iserviceProvider, paymentChoice ))
        {
            transactionDataManager.AddtoPaymentTransaction(itransaction);
            return itransaction;
        }
        return null ;


    }

    public void upDateDiscount(double amount) {
        this.discount = amount;
    }
    public Customer SignUp(CustomerDataManager customerDataManager) {
        Customer customer =new Customer();
        customer=customerDataManager.FindCustomer(this);
        if(customer == null )
        {
            customerDataManager.addCustomer(this);
            return this;
        }
        return null;

    }

    public Customer SignIn(CustomerDataManager customerDataManager) {
        return customerDataManager.FindCustomer(this);

    }
    public Iservice SearchService(String serviceName, ServiceDataManger serviceDataManger)
    {

        return serviceDataManger.Search(serviceName);
    }

    public  boolean Pay(double amount, IserviceProvider iserviceProvider, int paymentChoice)
    {
        if(paymentChoice==1)
            return craditCard.pay(amount);
        else if(paymentChoice==2)
            return wallet.pay(amount);
        else if(paymentChoice ==3 )
        {
            if(iserviceProvider ==null || iserviceProvider.CashState())
            {
                return true;
            }
            return false;
        }

        return false;
    }

    public boolean RefundRequest(int id, TransactionDataManager transactionDataManager) {
        PaymentTransaction transaction= transactionDataManager.transactionSearch(id);
        boolean bool=false;
        if(transaction==null)
            return bool;
        else {
            transactionDataManager.FromPaymentTransactionToRefund(transaction);
            bool=true;
            return bool;

        }

    }
    public double GetWalletBalance()
    {
        return wallet.GetBalance();
    }
    public double GetCreditBalance()
    {
        return craditCard.GetBalance();
    }
}
