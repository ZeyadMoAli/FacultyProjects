package com.fawrydemo.Fawry.Forms;

import java.util.Scanner;

public class CancerHospitalForm implements Iform{
    private String name;
    private String phonenum;
    private String hospitalName;
    private String roomnum;

    public void Fill()
    {

    }

    public void setPhoneNum(String phonenum) {
        this.phonenum=phonenum;
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

    public void SetHospitalName(String hospitalName) {
        this.hospitalName=hospitalName;
    }
    public String GetHospitalName() {
        return name;
    }
    public void RoomNum(String roomNum) {
        this.roomnum=roomNum;
    }


    public String roomNum() {
        return roomnum;
    }

}
