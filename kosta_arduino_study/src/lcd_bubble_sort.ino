#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27, 16, 2);

void setup(){
    lcd.init(); 
    lcd.backlight(); 
}

void loop(){

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
        
    }

    delete[] DataSet;

}