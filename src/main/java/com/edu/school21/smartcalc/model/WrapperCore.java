package com.edu.school21.smartcalc.model;
import com.sun.jna.Library;

public interface WrapperCore extends Library {
     double ComputePolishNotation(String str, double x);

}
