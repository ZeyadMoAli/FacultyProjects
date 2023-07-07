package com.fawrydemo.Fawry.Controllers;

import com.fawrydemo.Fawry.Database.*;
import com.fawrydemo.Fawry.Transactions.AddtoWalltedTransaction;
import com.fawrydemo.Fawry.Transactions.Itransaction;
import com.fawrydemo.Fawry.Transactions.PaymentTransaction;
import com.fawrydemo.Fawry.User.Admin;

import java.util.ArrayList;

public class AdminController {
    Admin admin = new Admin();
    public Itransaction HandleRefund(int id, boolean state, TransactionDataManager transactionDataManager)
    {
        return admin.HandleRefund(id, state,transactionDataManager);
    }
    public void MakeDiscount(double discountAmount ,CustomerDataManager customerDataManager ,int discountChoice, int serviceChoice )
    {
        admin.MakeDiscount(discountAmount,customerDataManager,discountChoice,serviceChoice);
    }

    public ArrayList<PaymentTransaction> ListPaymentTransactions(TransactionDataManager transactionDataManager)
    {
       return admin.ListPaymentTransactions(transactionDataManager);
    }

    public ArrayList<PaymentTransaction> ListRefundTransactions(TransactionDataManager transactionDataManager)
    {
        return admin.ListRefundTransactions(transactionDataManager);
    }
    public ArrayList<AddtoWalltedTransaction> ListAddtoWalletTransactions(TransactionDataManager transactionDataManager)
    {
        return admin.ListAddtoWalletTransactions(transactionDataManager);
    }


    public String getAdminname() {
        return admin.getUsername();
    }

    public void setAdminname(String username) {
        admin.setUsername(username);
    }

    public String getEmail() {
        return admin.getEmail();
    }

    public void setEmail(String email) {
        admin.setEmail(email);
    }

    public String getPassword() {
        return admin.getPassword();
    }

    public void setPassword(String password) {
        admin.setPassword(password);
    }
}
