/*
First assignement embedded software

Name : EMONOT--DE CAROLIS Evrard
ID : H00385163

*/

// defining constant for the INPUT and OUTPUT of the ESP32
#define SIGNAL_A 14
#define SIGNAL_B 12
#define INPUT_1 35
#define INPUT_2 34

// defining the period calculated with my name
int input_1_Btn = 0;
int input_2_Btn = 0;
int const B = 50;
int const b = 1300;
int const d = 6500;
int a = 500;
int i = 0;

// the setup function runs once we boot the board
void setup() {
  // initialize digital pins as inputs and outputs
  pinMode(SIGNAL_A, OUTPUT);
  pinMode(SIGNAL_B, OUTPUT);
  pinMode(INPUT_1, INPUT);
  pinMode(INPUT_2, INPUT);
}

// the loop function acts like a while true, that runs while the ESP32 is power
void loop() {

  //turning the LED off
  digitalWrite(SIGNAL_B, LOW);    
  digitalWrite(SIGNAL_A, LOW);    

  //read the buttons
  input_1_Btn = digitalRead(INPUT_1);
  input_2_Btn = digitalRead(INPUT_2);

  //4 conditions to verify the states of the buttons as there are pressed or not
  // if both button are not pressed, we run in normal mode
  
  if(input_1_Btn == LOW and input_2_Btn == LOW)
  {
    //we apply the bliking of the LEDS as requested in the assignement
    digitalWrite(SIGNAL_B, HIGH);    
    delayMicroseconds(B);
    digitalWrite(SIGNAL_B, LOW); 

    //we have 16 blink with a period increment between each blink
    for(i=0;i<16;i++){
      digitalWrite(SIGNAL_A, HIGH);
      delayMicroseconds(a);
      digitalWrite(SIGNAL_A, LOW);
      a += 50;
      delayMicroseconds(b);
    }
    delayMicroseconds(d); 
    digitalWrite(SIGNAL_B, LOW);
    a = 500;
  }

  // if only the second button is pressed, we run in the second mode
  else if(input_2_Btn == HIGH and input_1_Btn == LOW)
  {              
    //we apply the bliking of the LEDS as requested in the assignement      
    digitalWrite(SIGNAL_B, HIGH);    
    delayMicroseconds(B);
    digitalWrite(SIGNAL_B, LOW);
     
    //we have 13 blinks with "a" period increment between each blink
    for(i=0;i<13;i++){
      digitalWrite(SIGNAL_A, HIGH);
      delayMicroseconds(a);
      digitalWrite(SIGNAL_A, LOW);
      a += 50;
      delayMicroseconds(b);
    }
    delayMicroseconds(d);
    digitalWrite(SIGNAL_A, LOW);
    digitalWrite(SIGNAL_B, LOW);S
    a = 500; //reset a to the normal period
  }            

  //on all the other cases, we just turns the LEDS off
  
  else if(input_2_Btn == HIGH and input_1_Btn == HIGH)
  {
    digitalWrite(SIGNAL_B, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(SIGNAL_A, LOW);  
    delay(5);   
  }

  else if(input_2_Btn == LOW and input_1_Btn == HIGH)
  {
    digitalWrite(SIGNAL_B, LOW);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(SIGNAL_A, LOW);  
    delay(1000);   
  }
  
  else
  {                    
    digitalWrite(SIGNAL_B, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(SIGNAL_A, LOW);  
    delay(1000);
  } 
  
}
//END
