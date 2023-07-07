package com.fawrydemo.Fawry.Forms;

import java.util.Scanner;

public class WeForm implements Iform {
    private String name;

    private String phonenum;


    public void Fill()
    {

    }




    public void setPhoneNum(String phonenum) {
        this.phonenum=phonenum;
    }


    public String GetPhoneNum() {
        return phonenum;
    }


    public void SetName(String Name) {
    this.name=name;
    }


    public String GetName() {
            return this.name;
    }
}