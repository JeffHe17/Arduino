
#include <string.h>;

int sensorPin = 3;    // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);  
  pinMode(5, INPUT);
//  decode("01100101");
}

void loop() {
  buttonState = digitalRead(5);
 if (buttonState == HIGH) {
    // turn LED on:
    String x = encode("hello world, this is a demo of free space optical communication");
    Serial.println(x);
    
   sensorValue = analogRead(sensorPin);
   Serial.println(sensorValue); 
   delay(100);
   decode("01100101");
  } else {

  }

}

//String to binary
String encode(String in)
{
    char c = in[0];
    String ans = "";
    for (int j = 0; j < in.length(); j++){
          c = in[j];
          char str[1024] = "";
        for (int i = 7; i >= 0; --i)
        {
          strcat(str, (c & (1 << i)) ? "1" : "0" );
            (c & (1 << i)) ? digitalWrite(ledPin, HIGH) : digitalWrite(ledPin, LOW);  
            delay(100);
        }
          Serial.println(str);
          Serial.println('\n');
          ans += str;
    }
    return ans;
}

//Binary back to String
void decode(String in){
  int i = 0;
  String ans = "";
  char bin[1024] = "";
  while(i < 8){
    sensorValue = analogRead(sensorPin);    
     delay(100);
    if(sensorValue > 600){ 
      strcat(bin, "1");
    }else{
      strcat(bin, "0");
    }
    i += 1;
  }
  //  in.toCharArray(bin, in.length());
    Serial.println(bin);
//    bin = "01100101";
    char c = strtol(bin, (char **)NULL, 2);
    ans += c;
    Serial.println(ans);
}

