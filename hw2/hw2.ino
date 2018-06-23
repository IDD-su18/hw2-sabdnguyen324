// set PushButton pin number
const int buttonPin1 = A5; //abc
const int buttonPin2 = A3; //def
const int buttonPin3 = A2; //ghi
const int buttonPin4 = A1; //jkl
const int buttonPin5 = 10; //mno
const int buttonPin6 = 11; //pqrs
const int buttonPin7 = 12; //tuv
const int buttonPin8 = A0; //wxyz

const int buttonPin9 = A4; //capitalization toggle
const int buttonPin10 = 9; //space, comma, period

const int LEDP13 = 13; // set LED pin 13

//setting up for debouncing 
const unsigned long DEBOUNCE_THRESH = 50; 
uint8_t ACTIVE = 0; 

byte buttonPin1_LAST = HIGH;
bool buttonPin1_PRESSED = false;
int buttonPin1_DEBOUNCE = 0;

byte buttonPin2_LAST = HIGH;
bool buttonPin2_PRESSED = false;
int buttonPin2_DEBOUNCE = 0;

byte buttonPin3_LAST = HIGH;
bool buttonPin3_PRESSED = false;
int buttonPin3_DEBOUNCE = 0;

byte buttonPin4_LAST = HIGH;
bool buttonPin4_PRESSED = false;
int buttonPin4_DEBOUNCE = 0;

byte buttonPin5_LAST = HIGH;
bool buttonPin5_PRESSED = false;
int buttonPin5_DEBOUNCE = 0;

byte buttonPin6_LAST = HIGH;
bool buttonPin6_PRESSED = false;
int buttonPin6_DEBOUNCE = 0;

byte buttonPin7_LAST = HIGH;
bool buttonPin7_PRESSED = false;
int buttonPin7_DEBOUNCE = 0;

byte buttonPin8_LAST = HIGH;
bool buttonPin8_PRESSED = false;
int buttonPin8_DEBOUNCE = 0;

byte buttonPin10_LAST = HIGH;
bool buttonPin10_PRESSED = false;
int buttonPin10_DEBOUNCE = 0;

unsigned long timePress1 = 0; 
unsigned long timePress2 = 0;
unsigned long timePress3 = 0;
unsigned long timePress4 = 0;
unsigned long timePress5 = 0;
unsigned long timePress6 = 0;
unsigned long timePress7 = 0;
unsigned long timePress8 = 0;
unsigned long timePress9 = 0;
unsigned long timePress10 = 0;

unsigned long timePressLimit1 = 0;
unsigned long timePressLimit2 = 0;
unsigned long timePressLimit3 = 0;
unsigned long timePressLimit4 = 0;
unsigned long timePressLimit5 = 0;
unsigned long timePressLimit6 = 0;
unsigned long timePressLimit7 = 0;
unsigned long timePressLimit8 = 0;
unsigned long timePressLimit9 = 0;
unsigned long timePressLimit10 = 0;

int clicks1 = 0;
int clicks2 = 0;
int clicks3 = 0;
int clicks4 = 0;
int clicks5 = 0;
int clicks6 = 0;
int clicks7 = 0;
int clicks8 = 0;
int clicks9 = 0;
int clicks10 = 0;

boolean caps = false;

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1 ,INPUT_PULLUP);
  pinMode(buttonPin2 ,INPUT_PULLUP);
  pinMode(buttonPin3 ,INPUT_PULLUP);
  pinMode(buttonPin4 ,INPUT_PULLUP);
  pinMode(buttonPin5 ,INPUT_PULLUP);
  pinMode(buttonPin6 ,INPUT_PULLUP);
  pinMode(buttonPin7 ,INPUT_PULLUP);
  pinMode(buttonPin8 ,INPUT_PULLUP);
  pinMode(buttonPin9 ,INPUT_PULLUP);
  pinMode(buttonPin10 ,INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  
//buttonPin1: a,b,c
      if (digitalRead(buttonPin1) == LOW){
            if (buttonPin1_LAST == HIGH){
              buttonPin1_DEBOUNCE = millis();
              buttonPin1_PRESSED = false; 
            }
            //Serial.println("Button Pressed");
            if (millis() - buttonPin1_DEBOUNCE >= DEBOUNCE_THRESH && buttonPin1_PRESSED == false) {
           
            ACTIVE ^= 1 << 1;
            buttonPin1_PRESSED = true;
            
                if (clicks1 == 0) {
                      timePress1 = millis();
                      timePressLimit1 = timePress1 + 1000;    
                      clicks1 = 1;
                }
                else if (clicks1 == 1 && millis() < timePressLimit1){
                      clicks1 = 2;  
                }
                else if (clicks1 == 2 && millis() < timePressLimit1){
                      Serial.print("c");
                      //set variables back to 0
                      timePress1 = 0;
                      timePressLimit1 = 0;
                      clicks1 = 0;      
                }
            }   
     }
     
     buttonPin1_LAST = digitalRead(buttonPin1);
     
     if (clicks1 == 2 && timePressLimit1 != 0 && millis() > timePressLimit1){
                Serial.print("b");
                timePress1 = 0;
                timePressLimit1 = 0;
                clicks1 = 0;
     }
     if (clicks1 == 1 && timePressLimit1 != 0 && millis() > timePressLimit1){
                /*if (caps)
                  {Serial.print("A");}
                else
                  {Serial.print("a");}
                */
                Serial.print("a");
                timePress1 = 0;
                timePressLimit1 = 0;
                clicks1 = 0;
     }
//end for buttonPin1: a,b,c
        
//buttonPin2: d,e,f
      if (digitalRead(buttonPin2) == LOW){
              //delay(200);
              if (buttonPin2_LAST == HIGH) {
                buttonPin2_DEBOUNCE = millis();
                buttonPin2_PRESSED = false; 
              }

              if (millis() - buttonPin2_DEBOUNCE >= DEBOUNCE_THRESH && buttonPin2_PRESSED == false){
                ACTIVE ^= 1 << 1; 
                buttonPin2_PRESSED = true; 
             
                if (clicks2 == 0) {
                      timePress2 = millis();
                      timePressLimit2 = timePress2 + 1000;    
                      clicks2 = 1;
                }
                else if (clicks2 == 1 && millis() < timePressLimit2){
                      clicks2 = 2;  
                }
                else if (clicks2 == 2 && millis() < timePressLimit2){
                      Serial.print("f");
                      //set variables back to 0
                      timePress2 = 0;
                      timePressLimit2 = 0;
                      clicks2 = 0;      
                } 
            }
      }
      buttonPin2_LAST = digitalRead(buttonPin2);  
     
     if (clicks2 == 2 && timePressLimit2 != 0 && millis() > timePressLimit2){
                Serial.print("e");
                timePress2 = 0;
                timePressLimit2 = 0;
                clicks2 = 0;
     }
     if (clicks2 == 1 && timePressLimit2 != 0 && millis() > timePressLimit2){
                Serial.print("d");
                timePress2 = 0;
                timePressLimit2 = 0;
                clicks2 = 0;
     }
//end for buttonPin2: d,e,f


//buttonPin3: g,h,i
      if (digitalRead(buttonPin3) == LOW){
              //delay(200); 
              if (buttonPin3_LAST == HIGH){
                buttonPin3_DEBOUNCE = millis();
                buttonPin3_PRESSED = false; 
              }

              if (millis() - buttonPin3_DEBOUNCE >= DEBOUNCE_THRESH && buttonPin3_PRESSED == false) {
                ACTIVE ^= 1 << 1;
                buttonPin3_PRESSED = true;
                
                if (clicks3 == 0) {
                      timePress3 = millis();
                      timePressLimit3 = timePress3 + 1000;    
                      clicks3 = 1;
                }
                else if (clicks3 == 1 && millis() < timePressLimit3){
                      clicks3 = 2;  
                }
                else if (clicks3 == 2 && millis() < timePressLimit3){
                      Serial.print("i");
                      //set variables back to 0
                      timePress3 = 0;
                      timePressLimit3 = 0;
                      clicks3 = 0;      
                }
              }
            
     }

     buttonPin3_LAST = digitalRead(buttonPin3);
     
     
     if (clicks3 == 2 && timePressLimit3 != 0 && millis() > timePressLimit3){
                Serial.print("h");
                timePress3 = 0;
                timePressLimit3 = 0;
                clicks3 = 0;
     }
     if (clicks3 == 1 && timePressLimit3 != 0 && millis() > timePressLimit3){
                Serial.print("g");
                timePress3 = 0;
                timePressLimit3 = 0;
                clicks3 = 0;
     }
//end for buttonPin3: g,h,i


//buttonPin4: j,k,l
      if (digitalRead(buttonPin4) == LOW){
            if (buttonPin4_LAST == HIGH) {
              buttonPin4_DEBOUNCE = millis();
              buttonPin4_PRESSED = false; 
            }

          if (millis() - buttonPin4_DEBOUNCE >= DEBOUNCE_THRESH && buttonPin4_PRESSED == false) {
            ACTIVE ^= 1 << 1;
            buttonPin4_PRESSED = true;
          
        
                if (clicks4 == 0) {
                      timePress4 = millis();
                      timePressLimit4 = timePress4 + 1000;    
                      clicks4 = 1;
                }
                else if (clicks4 == 1 && millis() < timePressLimit4){
                      clicks4 = 2;  
                }
                else if (clicks4 == 2 && millis() < timePressLimit4){
                      Serial.print("l");
                      //set variables back to 0
                      timePress4 = 0;
                      timePressLimit4 = 0;
                      clicks4 = 0;      
                }
        }    
     }
     buttonPin4_LAST = digitalRead(buttonPin4);
     
     if (clicks4 == 2 && timePressLimit4 != 0 && millis() > timePressLimit4){
                Serial.print("k");
                timePress4 = 0;
                timePressLimit4 = 0;
                clicks4 = 0;
     }
     if (clicks4 == 1 && timePressLimit4 != 0 && millis() > timePressLimit4){
                Serial.print("j");
                timePress4 = 0;
                timePressLimit4 = 0;
                clicks4 = 0;
     }
//end for buttonPin4: j,k,l


//buttonPin5: m,n,o
      if (digitalRead(buttonPin5) == LOW){
            if (buttonPin5_LAST == HIGH) {
              buttonPin5_DEBOUNCE = millis();
              buttonPin5_PRESSED = false; 
            }

            if (millis() - buttonPin5_DEBOUNCE >= DEBOUNCE_THRESH && buttonPin5_PRESSED == false) {
            ACTIVE ^= 1 << 1;
            buttonPin5_PRESSED = true;
                if (clicks5 == 0) {
                      timePress5 = millis();
                      timePressLimit5 = timePress5 + 1000;    
                      clicks5 = 1;
                }
                else if (clicks5 == 1 && millis() < timePressLimit5){
                      clicks5 = 2;  
                }
                else if (clicks5 == 2 && millis() < timePressLimit5){
                      Serial.print("o");
                      //set variables back to 0
                      timePress5 = 0;
                      timePressLimit5 = 0;
                      clicks5 = 0;      
                } 
            }  
     }
     buttonPin5_LAST = digitalRead(buttonPin5);
     
     if (clicks5 == 2 && timePressLimit5 != 0 && millis() > timePressLimit5){
                Serial.print("n");
                timePress5 = 0;
                timePressLimit5 = 0;
                clicks5 = 0;
     }
     if (clicks5 == 1 && timePressLimit5 != 0 && millis() > timePressLimit5){
                Serial.print("m");
                timePress5 = 0;
                timePressLimit5 = 0;
                clicks5 = 0;
     }
//end for buttonPin5: m,n,o


//buttonPin6: p,q,r,s
      if (digitalRead(buttonPin6) == LOW){
            if (buttonPin6_LAST == HIGH) {
              buttonPin6_DEBOUNCE = millis();
              buttonPin6_PRESSED = false; 
            }

            if (millis() - buttonPin6_DEBOUNCE >= DEBOUNCE_THRESH && buttonPin6_PRESSED == false) {
            ACTIVE ^= 1 << 1;
            buttonPin6_PRESSED = true;
                if (clicks6 == 0) {
                      timePress6 = millis();
                      timePressLimit6 = timePress6 + 1000;    
                      clicks6 = 1;
                }
                else if (clicks6 == 1 && millis() < timePressLimit6){
                      clicks6 = 2;  
                }
                else if (clicks6 == 2 && millis() < timePressLimit6){
                      clicks6 = 3;  
                }                
                else if (clicks6 == 3 && millis() < timePressLimit6){
                      Serial.print("s");
                      //set variables back to 0
                      timePress6 = 0;
                      timePressLimit6 = 0;
                      clicks6 = 0;      
                }
            }          
     }
     buttonPin6_LAST = digitalRead(buttonPin6);
     
     if (clicks6 == 3 && timePressLimit6 != 0 && millis() > timePressLimit6){
                Serial.print("r");
                timePress6 = 0;
                timePressLimit6 = 0;
                clicks6 = 0;
     }     
     if (clicks6 == 2 && timePressLimit6 != 0 && millis() > timePressLimit6){
                Serial.print("q");
                timePress6 = 0;
                timePressLimit6 = 0;
                clicks6 = 0;
     }
     if (clicks6 == 1 && timePressLimit6 != 0 && millis() > timePressLimit6){
                Serial.print("p");
                timePress6 = 0;
                timePressLimit6 = 0;
                clicks6 = 0;
     }
//end for buttonPin6: p,q,r,s


//buttonPin7: t,u,v
      if (digitalRead(buttonPin7) == LOW){
            if (buttonPin7_LAST == HIGH) {
              buttonPin7_DEBOUNCE = millis();
              buttonPin7_PRESSED = false; 
            }

            if (millis() - buttonPin7_DEBOUNCE >= DEBOUNCE_THRESH && buttonPin7_PRESSED == false) {
            ACTIVE ^= 1 << 1;
            buttonPin7_PRESSED = true;
            
                if (clicks7 == 0) {
                      timePress7 = millis();
                      timePressLimit7 = timePress7 + 1000;    
                      clicks7 = 1;
                }
                else if (clicks7 == 1 && millis() < timePressLimit7){
                      clicks7 = 2;  
                }
                else if (clicks7 == 2 && millis() < timePressLimit7){
                      Serial.print("v");
                      //set variables back to 0
                      timePress7 = 0;
                      timePressLimit7 = 0;
                      clicks7 = 0;      
                } 
            }  
     }
     buttonPin7_LAST = digitalRead(buttonPin7);
     
     if (clicks7 == 2 && timePressLimit7 != 0 && millis() > timePressLimit7){
                Serial.print("u");
                timePress7 = 0;
                timePressLimit7 = 0;
                clicks7 = 0;
     }
     if (clicks7 == 1 && timePressLimit7 != 0 && millis() > timePressLimit7){
                Serial.print("t");
                timePress7 = 0;
                timePressLimit7 = 0;
                clicks7 = 0;
     }
//end for buttonPin7: t,u,v


//buttonPin8: w,x,y,z
      if (digitalRead(buttonPin8) == LOW){
            if (buttonPin8_LAST == HIGH) {
              buttonPin8_DEBOUNCE = millis();
              buttonPin8_PRESSED = false; 
            }

            if (millis() - buttonPin8_DEBOUNCE >= DEBOUNCE_THRESH && buttonPin8_PRESSED == false) {
            ACTIVE ^= 1 << 1;
            buttonPin8_PRESSED = true;
                if (clicks8 == 0) {
                      timePress8 = millis();
                      timePressLimit8 = timePress8 + 1000;    
                      clicks8 = 1;
                }
                else if (clicks8 == 1 && millis() < timePressLimit8){
                      clicks8 = 2;  
                }
                else if (clicks8 == 2 && millis() < timePressLimit8){
                      clicks8 = 3;  
                }                
                else if (clicks8 == 3 && millis() < timePressLimit8){
                      Serial.print("z");
                      //set variables back to 0
                      timePress8 = 0;
                      timePressLimit8 = 0;
                      clicks8 = 0;      
                }
            }   
     }
     buttonPin8_LAST = digitalRead(buttonPin8);
     
     if (clicks8 == 3 && timePressLimit8 != 0 && millis() > timePressLimit8){
                Serial.print("y");
                timePress8 = 0;
                timePressLimit8 = 0;
                clicks8 = 0;
     }     
     if (clicks8 == 2 && timePressLimit8 != 0 && millis() > timePressLimit8){
                Serial.print("x");
                timePress8 = 0;
                timePressLimit8 = 0;
                clicks8 = 0;
     }
     if (clicks8 == 1 && timePressLimit8 != 0 && millis() > timePressLimit8){
                Serial.print("w");
                timePress8 = 0;
                timePressLimit8 = 0;
                clicks8 = 0;
     }
//end for buttonPin8: w,x,y,z


//buttonPin10: space, comma, period
      if (digitalRead(buttonPin10) == LOW){
            if (buttonPin10_LAST == HIGH) {
              buttonPin10_DEBOUNCE = millis();
              buttonPin10_PRESSED = false; 
            }

            if (millis() - buttonPin10_DEBOUNCE >= DEBOUNCE_THRESH && buttonPin10_PRESSED == false) {
            ACTIVE ^= 1 << 1;
            buttonPin10_PRESSED = true;
                if (clicks10 == 0) {
                      timePress10 = millis();
                      timePressLimit10 = timePress10 + 1000;    
                      clicks10 = 1;
                }
                else if (clicks10 == 1 && millis() < timePressLimit10){
                      clicks10 = 2;  
                }
                else if (clicks10 == 2 && millis() < timePressLimit10){
                      Serial.print('\n');
                      //set variables back to 0
                      timePress10 = 0;
                      timePressLimit10 = 0;
                      clicks10 = 0;      
                }
            }             
     }
     buttonPin10_LAST = digitalRead(buttonPin10);
     
     if (clicks10 == 2 && timePressLimit10 != 0 && millis() > timePressLimit10){
                Serial.print('.');
                timePress10 = 0;
                timePressLimit10 = 0;
                clicks10 = 0;
     }
     if (clicks10 == 1 && timePressLimit10 != 0 && millis() > timePressLimit10){
                Serial.print(' ');
                timePress10 = 0;
                timePressLimit10 = 0;
                clicks10 = 0;
     } 
//end for buttonPin10: space, comma, period


//buttonPin9: Capitalisor
      /*if (digitalRead(buttonPin9) == LOW){
              delay(200); 
              caps=!caps;*/            


//end for buttonPin9: capitalisor

}
