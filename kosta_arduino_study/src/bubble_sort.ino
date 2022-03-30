#include <stdio.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// LiquidCrystal_I2C_Hangul lcd(0x27, 16, 2);

void setup(){
    Serial.begin(9600);
    // lcd.init(); 
    // lcd.backlight();  
}

void loop(){
    bubbleSort();
    Serial.end();
}


void bubbleSort(){

    int size = 100;
    int *DataSet = new int[size];

    for(int i =0 ; i < size; i++){
        DataSet[i] = (rand()%100);
    }

    // 버블정렬
    int temp = 0;
    for(int i =0 ; i < size -1; i++){
        for(int j =0 ; j < size -(i+1); j++){
            
            if(DataSet[j] > DataSet[j+1]){
                temp = DataSet[j+1];
                DataSet[j+1] = DataSet[j];
                DataSet[j] = temp;
            }
        }
    }

    for(int i =0 ; i < size; i++){
        Serial.print(DataSet[i]);
        Serial.print(", "); 
    }

    delete[] DataSet;

    // lcd.setCursor(0, 0);
    // for(int i =0; i<10; i++){
    //     lcd.print(DataSet[i]);
    // }
    // lcd.setCursor(0, 0);
    // for(int i =799; i>789; i--){
    //     lcd.print(DataSet[i]);
    // }

}