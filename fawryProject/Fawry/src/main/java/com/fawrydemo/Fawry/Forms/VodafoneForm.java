package com.fawrydemo.Fawry.Forms;

import java.util.Scanner;

public class VodafoneForm implements Iform {


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



        public void SetName(String name) {
            this.name=name;
        }

        public String GetName() {
            return name;
        }

    }
