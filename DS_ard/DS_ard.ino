unsigned int start_flag = 0;
unsigned int end_flag = 0;
unsigned int interval = 10000;
unsigned long start_discharging;
unsigned long end_discharging;
unsigned long discharge_time;
unsigned long current_time;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
if(end_flag==0) {// put your main code here, to run repeatedly:
    float sensor_value = analogRead(0);
    float voltage_level = sensor_value*(25.0 / 1023.0);
    voltage_level = 11;

    if(voltage_level>10.5 && start_flag == 0) {
      start_flag = 1;
    }

    if(voltage_level>10.5 && start_flag == 1){
      start_discharging = millis();
      current_time = start_discharging;
      start_flag = 2;
    }

    if(voltage_level > 10.5 && start_flag == 2) {
      discharge_time = millis();
      if(discharge_time - current_time > interval)
      {
        current_time = discharge_time;
        Serial.print(double(start_discharging/1000));
        Serial.print(";");
        Serial.print(double(discharge_time/1000));
        Serial.print(";");
        Serial.print(voltage_level);
        Serial.print(";\n");
      }  
    }
  
    if(voltage_level<=10.5 && start_flag!=0) {
      end_flag = 1;
    }
  }
  
  if(end_flag==1) {
    Serial.println("end");
    end_flag=2;
  }

  if(end_flag==2) {
    //Nie robię nic
  }
}
/*
  if(discharge_time > 10000) {
    voltage_level = 10;
  }

/*
  if(end_flag == false) {
    if(start == true) {
      Serial.println("\nstart");
      start = false;
      unsigned long start = millis();

    }
    delay(1000);
    unsigned long end = millis();

    Serial.println(start);
    //*Serial.print(" ");
    Serial.println(end);
    //Serial.print("\n");

    if(end>20000) {
      end_flag=true;
      Serial.println("end");
    }
  
  
  }  
} */
