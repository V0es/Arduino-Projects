#define mosfet 5         //силовой ключ для насоса
#define mosfet_sensor 3  //силовой ключ для датчика влажности
#define hum_sensor A0    //датчик влажности
#define humidity 650         //постоянная влажности
#define led 4

unsigned long last_time;   // переменная времени    
long wait = 60000;  //периодичность опроса датчика(в миллисекундах)
int val; //переменная показания датчика влажности почвы
boolean flag;

void setup() {
   pinMode(mosfet, OUTPUT);
   pinMode(hum_sensor, INPUT);
   pinMode(mosfet_sensor, OUTPUT);
   pinMode(led, OUTPUT);
   Serial.begin(9600);
}

void loop() {
 
 if(millis() - last_time > wait){
  last_time = millis();
  digitalWrite(mosfet_sensor, HIGH);
  delay(60);
  val = analogRead(hum_sensor);
  Serial.println(val);
  delay(60);
  digitalWrite(mosfet_sensor, LOW);
  delay(60);
  } 
  
  if(val > humidity){
    flag = true;
    digitalWrite(mosfet_sensor, HIGH);
    while(val > humidity && flag == true){
     digitalWrite(mosfet, HIGH);
     val = analogRead(hum_sensor);
      if(val <= humidity){
        flag = false;
        }
     }
      
  digitalWrite(mosfet, LOW);
  digitalWrite(mosfet_sensor, LOW);
  digitalWrite(led, LOW);
  
    }
}
