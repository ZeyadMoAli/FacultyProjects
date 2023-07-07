package com.fawrydemo.Fawry.Controllers;
import com.fawrydemo.Fawry.Database.*;
import com.fawrydemo.Fawry.Service.Iservice;
import com.fawrydemo.Fawry.Transactions.AddtoWalltedTransaction;
import com.fawrydemo.Fawry.Transactions.Itransaction;
import com.fawrydemo.Fawry.Transactions.PaymentTransaction;
import com.fawrydemo.Fawry.User.Customer;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;

@RestController

public class MainController {
    static CustomerDataManager customerDataManager =new CustomerDataManager();
    static ServiceDataManger serviceDataManger =new ServiceDataManger();
    static TransactionDataManager transactionDataManager=new TransactionDataManager();
    CustomerController customerController =new CustomerController();
    AdminController adminController =new AdminController();
    @GetMapping(value = "/Admin/ListPaymentTransactions")
    public ArrayList<PaymentTransaction> ListPaymentTransactions()
    {
        return adminController.ListPaymentTransactions(transactionDataManager);
    }
    @GetMapping(value = "/Admin/ListRefundTransactions")
    public ArrayList<PaymentTransaction> ListRefundTransactions()
    {
        return adminController.ListRefundTransactions(transactionDataManager);
    }

    @GetMapping(value = "/Admin/ListAddtoWalletTransactions")
    public ArrayList<AddtoWalltedTransaction> ListAddtoWalletTransactions()
    {
        return adminController.ListAddtoWalletTransactions(transactionDataManager);
    }
    @PostMapping(value = "/Admin/MakeDiscount")
    public ResponseEntity<Void> MakeDiscount(@RequestParam (value ="discount") double discountAmount ,@RequestParam (value ="discountChoice") int discountChoice,@RequestParam(value = "serviceChoice") int serviceChoice )
    {
        adminController.MakeDiscount(discountAmount,customerDataManager,discountChoice,serviceChoice);
        return ResponseEntity.status(HttpStatus.OK).build();
    }
    @PostMapping(value = "Customer/SignUp")
    public ResponseEntity<Void> SignUp(@RequestBody Customer customer) {
        if(customerController.SignUp(customer,customerDataManager) == null)
        {
            return ResponseEntity.status(HttpStatus.NOT_ACCEPTABLE).build();
        }
        return ResponseEntity.status(HttpStatus.OK).build();
    }

    @PostMapping(value = "Customer/Signin")
    public Customer SignIn(@RequestBody Customer customer) {
        return customerController.SignIn(customer,customerDataManager);
    }


    @GetMapping(value = "/Customer/SearchService")
    public ResponseEntity<Void> SearchService(@RequestBody Customer customer,  @RequestParam ( value ="service") String serviceName)
    {
        if(customerController.SearchService(customer,serviceName, serviceDataManger) == null)
        {
           return ResponseEntity.status(HttpStatus.NOT_FOUND).build();
        }
        return ResponseEntity.status(HttpStatus.OK).build();
    }
    @PostMapping(value = "/Customer/RefundRequest")
    public ResponseEntity<Void> RefundRequest(@RequestBody Customer customer , @RequestParam(value ="id") int id) {
        if(customerController.RefundRequest(customer,id,transactionDataManager))
        {
            return ResponseEntity.status(HttpStatus.OK).build();
        }
        return ResponseEntity.status(HttpStatus.NOT_FOUND).build();
    }

    @PostMapping(value = "/Customer/AddToWallet")
    public ResponseEntity<Void> AddToWallet(@RequestBody Customer customer,  @RequestParam(value ="amount") double balance)
    {
        boolean obj=customerController.AddToWallet(customer,balance,transactionDataManager, customerDataManager);
        if(obj)
        {
            return ResponseEntity.status(HttpStatus.OK).build();
        }
        return ResponseEntity.status(HttpStatus.NOT_ACCEPTABLE).build();
    }

    @GetMapping(value = "/Customer/checkServiceDiscount")
    public double checkServiceDiscount(@RequestBody Customer customer ,@RequestParam(value ="choice") int choice)
    {
        return customerController.checkServiceDiscount(customer,choice);
    }

    @PostMapping(value = "/Customer/makeService")
    public PaymentTransaction makeService(@RequestBody Customer customer,@RequestParam(value ="serviceChoice") int serviceChoice,@RequestParam(value = "receiptChoice") int receiptChoice,@RequestParam(value ="serviceProviderChoice") int serviceProviderChoice,@RequestParam(value ="paymentChoice") int paymentChoice, @RequestParam(value ="amount") double amount)
    {
        return customerController.makeService(customer,serviceChoice,serviceProviderChoice,paymentChoice,amount,receiptChoice,transactionDataManager, customerDataManager);

    }

    @PostMapping(value = "/Admin/HandleRefund")
    public  ResponseEntity<Void>  HandleRefund(@RequestParam(value ="id") int id,@RequestParam(value ="state") boolean state)
    {
        if(adminController.HandleRefund(id, state,transactionDataManager)== null)
            return ResponseEntity.status(HttpStatus.NOT_FOUND).build();
        return ResponseEntity.status(HttpStatus.OK).build();
    }

}
