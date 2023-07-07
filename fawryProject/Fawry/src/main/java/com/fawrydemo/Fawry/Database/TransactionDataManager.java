package com.fawrydemo.Fawry.Database;
import com.fawrydemo.Fawry.Transactions.*;
import java.util.*;
public class TransactionDataManager implements IdataManger {
    ArrayList<PaymentTransaction> paymentTransactions = new ArrayList<PaymentTransaction>();
    ArrayList<PaymentTransaction> Refund = new ArrayList<PaymentTransaction>();
    ArrayList<AddtoWalltedTransaction> WalletTransaction = new ArrayList<AddtoWalltedTransaction>();
    ArrayList<PaymentTransaction> temp = new ArrayList<PaymentTransaction>();

    public void AddWalletTransaction(AddtoWalltedTransaction addtoWalltedTransaction)
    {
        WalletTransaction.add(addtoWalltedTransaction);
    }
    public PaymentTransaction transactionSearch(int TransactionId) {
        for(PaymentTransaction transaction: paymentTransactions)
        {
            if(transaction.getTransactionID()== TransactionId)
                return transaction;
        }
        return null;
    }
    public void AddtoPaymentTransaction(PaymentTransaction transaction)
    {
        paymentTransactions.add(transaction);
    }
    public void RemoveFromPaymentTransaction(PaymentTransaction transaction) {
        paymentTransactions.remove(transaction);}


    public void Addtorefund(PaymentTransaction transaction)
    {
        Refund.add(transaction);
    }
    public void RemoveFromRefund(PaymentTransaction transaction)
    {
        Refund.remove(transaction);
    }

    public void FromPaymentTransactionToRefund(PaymentTransaction transaction)
    {
        this.RemoveFromPaymentTransaction(transaction);
        this.Addtorefund(transaction);

    }
    public PaymentTransaction getRefundTransaction(int id)
    {
        for(PaymentTransaction paymentTransaction : Refund)
        {
            if(paymentTransaction.getTransactionID() == id)
                return paymentTransaction;
        }
        return null;
    }
    public ArrayList<AddtoWalltedTransaction> ListAddtoWalledTransactions ()
    {
        return WalletTransaction;
    }
    public ArrayList<PaymentTransaction> ListRefundTransactions()
    {
        return Refund;
    }

    public  ArrayList<PaymentTransaction> ListPaymentTransactions()
    {
        return paymentTransactions;
    }
    public Itransaction HandelRefund(int id , boolean state){
        PaymentTransaction itransaction = getRefundTransaction(id);
        if(itransaction == null)
            return null;
        itransaction.setRefundStates(state);
        if(state)
        {
            itransaction.getCustomer().AddToWallet(itransaction.getNetAmount(),this);
        }
        else
        {

            AddtoPaymentTransaction(itransaction);
        }
        RemoveFromRefund(itransaction);
        return itransaction;
    }


}
