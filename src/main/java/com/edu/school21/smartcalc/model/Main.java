package com.edu.school21.smartcalc.model;

public class Main {
    public static void main(String[] args)  {
        Wrapper n = new Wrapper("libs/wrapper.so");
        System.out.println(n.ComputePolishNotation("6 + 6", 0));
    }
}
