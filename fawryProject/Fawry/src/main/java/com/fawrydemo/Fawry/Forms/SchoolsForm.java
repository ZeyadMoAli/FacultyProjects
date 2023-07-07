package com.fawrydemo.Fawry.Forms;

import java.util.Scanner;

public class SchoolsForm implements Iform {

    private String name;
    private String phonenum;
    private String schoolname="";
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

void setSchoolname(String schoolname)
{
    this.schoolname=schoolname;
}
String getSchoolname()
{
    return schoolname;
}

}
