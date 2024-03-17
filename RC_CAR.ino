// hello guys
// comments have been put in place wheere ever needed
// workflow will be on the chart in the repository

unsigned long a,b,c,d,e,f,ca,cb,cc,cd,ce,cf,mode,throttle;
unsigned int dir = -1;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
  
  pinMode(9,INPUT); // ch1
  pinMode(10,INPUT); // ch2
  pinMode(11,INPUT);// ch3

  // control pins for the motor
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
    

  // drive side A
  
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);

  // drive side B

  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

//  set each motor 1|0 for clock
//  set each motor 0|1 for anti clock



}
void measureIn(){
  a = pulseIn(9,HIGH); 	//LEFT<>RIGHT using ch1
  b = pulseIn(0,LOW);
  c = pulseIn(11,HIGH); //Throttle using ch3
  d = pulseIn(10,LOW);	//FWD<>BCKWD using ch2
  f = pulseIn(6,LOW); 	//TRIG2 use them in case you need special actions
  e = pulseIn(5,LOW); 	//TRIG1 use them in case you need special actions
  
}
void correctIn(){

  ca = map(a,900,2000,0,1023); // L<=>R
  cd = map(d,900,2000,0,1023); // F<=>B
  cc = map(c,900,2000,0,255);// throttle  
  ce = map(e,993,1986,0,1);
  cf = map(f,993,1986,0,1);
    
}
int measureD(){
  if(cd>900){
    mode = 0;
    Serial.println(mode);
  }
  if(cd<300){
    mode = 1;
    Serial.println(mode);
  }
  if(ca<300){
    mode= 2;
    Serial.println(mode);
  }
  if(ca>900){
    mode=3;
    Serial.println(mode);
  }

  


}

void throttleM(){
  throttle = cc;
  // Serial.println(cc);
}
void driveM(){
  
  analogWrite(5,throttle);
  analogWrite(6,throttle);
    
  if(mode == 0){
        
	// forward 
	// M0
	// 3,4 7,8
	digitalWrite(3,HIGH);
	digitalWrite(4,LOW);

	digitalWrite(7,HIGH);
	digitalWrite(8,LOW);

  
  }
  if(mode == 1){
	// backwards
	// M0
  
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);

  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  }
  if(mode ==2){
	//  Right
	// M0	
  
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);

  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  }
  if(mode == 3){
	// LEFT
	// M0
  
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);

  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  }
  
  
    // no out put
  
  
}
void loop() {
  // put your main code here, to run repeatedly:
  measureIn();
  correctIn();
  measureD();
  throttleM();
  driveM();
  // Serial.println(mode);

  
// Serial.print(" Corrected A: ");Serial.println(ca);
  
// Serial.print(" Corrected D: ");Serial.println(cd);  
// Serial.println(":::");

  
  
    
}
// -------------- END ---------------------_
