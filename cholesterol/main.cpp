/**
 * This is a program that generate Cholesterol and Blood pressure profile for individuals using the data gotten after tests
 * 
 * @author  Jeff Allo
 * @version 1.0
 */
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void evaluate_cholesterol(int, int, string&, string&);  //function prototypes
void evaluate_blood_pressure(int, int, string&, string&);
string ratio_condition(double ratio);


int main() {
    ifstream file; 
    string HDL_interpretation, LDL_interpretation, systolic_interpretation, diastolic_interpretation; 
    file.open("infile.txt");  //open file
    int number_of_records;

    //Get number of records from user
    cout << "Enter the number of patient records: ";
    cin >> number_of_records;
    cout << endl;

    //Loop over file and get records for each patient
    for (int i = 0; i < number_of_records; i++ ) {
        string name, records; 
        char ch;
        int HDL, LDL, systole, diastole;
        file >> name >> ch >> records; //Get patient's information
        cout << "Current Patient's Name - " << name << endl;
        cout << endl;
        for (int j = 0; j < stoi(records); j++) {
            cout << "DATA SET " << (j+1) << endl;
            file >> HDL >> LDL >> systole >> diastole;

            evaluate_cholesterol(HDL, LDL, HDL_interpretation, LDL_interpretation); //Call function to inteprete the Cholesterol data
                //Print out Interpretation
                double ratio = (double)HDL / (double)LDL;
                cout << "Cholesterol Profile" << endl;
                cout << "   HDL: " << HDL << " LDL: " << LDL << endl;
                cout << "   Ratio: " << setprecision(4) << ratio << endl;
                cout << "   HDL is " << HDL_interpretation << endl;
                cout << "   LDL is " << LDL_interpretation << endl;
                cout << ratio_condition(ratio) << endl;

            evaluate_blood_pressure(systole, diastole, systolic_interpretation, diastolic_interpretation); //Call function to interprete systolic and diastolic data
                //Print out Interpretation
                cout << "Blood Pressure Profile" << endl;
                cout << "   Systolic: " <<  systole << "  Diastolic: " << diastole << endl;
                cout << "   Systolic reading is " << systolic_interpretation << endl;
                cout << "   Diastolic reading is " << diastolic_interpretation << endl << endl;
        }
    }

    file.close();
    return 0;
}

/**
 * This function interpretes the HDL and LDL values
 * 
 * @param   HDL, LDL, &HDL_interpretation, &LDL_interpretation
 */

void evaluate_cholesterol(int HDL, int LDL, string &HDL_interpretation, string &LDL_interpretation) {

    //Match HDL value to the correct Interpretation
    if (HDL < 40) {
        HDL_interpretation = "Too low";
    }
    else if(HDL >= 40 && HDL < 60) {
        HDL_interpretation = "Is okay";
    }
    else if(HDL >= 60) {
        HDL_interpretation = "Excellent";
    }

    //Match LDL value to the correct Interpretation

    if (LDL < 100) {
        LDL_interpretation = "Optimal";
    }
    else if (LDL >= 100 && LDL < 130) {
        LDL_interpretation = "Near Optimal";
    }
    else if(LDL >= 130 && LDL < 160) {
        LDL_interpretation = "Borderline high";
    }
    else if(LDL >= 160 && LDL < 190) {
        LDL_interpretation = "High";
    }
    else if(LDL >= 190) {
        LDL_interpretation = "Very high";
    }
}

/**
 * This function interpretes the systolic and diastolic values
 * 
 * @param   systole, diastole, &systolic_interpretation, &diastolic_interpretation
 */

void evaluate_blood_pressure(int systole, int diastole, string &systolic_interpretation, string &diastolic_interpretation) {

    //Match systolic value to the correct Interpretation
    if (systole < 120) {
        systolic_interpretation = "Optimal";
    }
    else if(systole < 130) {
        systolic_interpretation = "Normal";
    }
    else if(systole < 140) {
        systolic_interpretation = "Normal high";
    }
    else if(systole < 160) {
        systolic_interpretation = "Stage 1 hypertension";
    }
    else if(systole < 180) {
        systolic_interpretation = "Stage 2 hypertension";
    }
    else if(systole >= 180) {
        systolic_interpretation = "Stage 3 hypertension";
    }
   


    //Match diastolic value to the correct Interpretation
    if (diastole < 80) {
        diastolic_interpretation = "Optimal";
    }
    else if(diastole < 85) {
        diastolic_interpretation = "Normal";
    }
    else if(diastole < 90) {
        diastolic_interpretation = "High normal";
    }
    else if(diastole < 100) {
        diastolic_interpretation = "Stage 1 hypertension";
    }
    else if(diastole < 110) {
        diastolic_interpretation = "Stage 2 hypertension";
    }
    else if(diastole >= 110) {
        diastolic_interpretation = "Stage 3 hypertension";
    }
}

/**
 * This function interpretes the systolic and diastolic values
 * 
 * @param   ratio
 * @return ratio_c 
 */

string ratio_condition(double ratio) {
    string ratio_c;
    if (ratio > 0.3) {
        ratio_c = "   Ratio of HDL to LDL is good";
    }
    else {
        ratio_c = "   Ratio of HDL to LDL is not good";
    }

    return ratio_c;
}