int myLEDs[5] = {4,5,6,7,8};

bool btnState = false;
int BTN_PIN = 2;

int sensorPin = A0;
int valSensor = 0;

int speakerPin = 2;


int sensor = 3;
int val;

void setup()
{
  
  pinMode(sensorPin,INPUT);
  pinMode(speakerPin,OUTPUT);
  
  
  for(int i = 0; i < 5; i++){
    pinMode(myLEDs[i], OUTPUT);
  }
  pinMode(BTN_PIN, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  
  valSensor = analogRead(sensorPin);  
  Serial.println(valSensor);    
  
  if(valSensor >= 80){
    Serial.println("bruh"); 
    digitalWrite(speakerPin,HIGH);
  }
  
  
  btnState = digitalRead(BTN_PIN);
  
  for(int i = 0; i < 5; i++){
    if(btnState){
     digitalWrite(myLEDs[4 - i], HIGH);
    }else{
      digitalWrite(myLEDs[i], HIGH);
    }
    delay(500);
  }
  
  for(int i = 0; i < 5; i++){
    if(btnState){
      digitalWrite(myLEDs[i], LOW);
    }else{
      digitalWrite(myLEDs[4 - i], LOW); 
    }    
    delay(500);
  }
  
  

}
