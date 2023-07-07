package com.fawrydemo.Fawry.Forms;

import java.util.Scanner;

public class EtisalatForm implements Iform{
    private String name= null;
    private String phonenum= null;


    public void Fill()
    {
    }
    public void setPhoneNum(String phonenum) {
        this.phonenum = phonenum;
    }


    public String GetPhoneNum() {
        return phonenum;
    }



    public void SetName(String name) {
        this.name=name;

    }


    public String GetName() {
        return name;
    }


}
