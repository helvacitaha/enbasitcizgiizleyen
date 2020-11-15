#define motorsol 11
#define motorsag 10
#define sensorsol A0
#define sensorsag A1
const int sensorsagreferansdeger=24;
const int sensorsolreferansdeger=24;
const int motortamhiz=255;
const int motoryavashiz=75;
const int motordonmehiz=100;
const int motordonmehizters=-100;
const int motortamhizters=-255;
const int motoryavashizters=-75;
int sensorsoldeger;
int sensorsagdeger;

void setup() {
  pinMode(motorsol,OUTPUT);
  pinMode(motorsag,OUTPUT);
  pinMode(sensorsol,INPUT);
  pinMode(sensorsag,INPUT);
}

void loop() {
  sensorsoldeger=analogRead(sensorsol);
  sensorsagdeger=analogRead(sensorsag);
  sensorsoldeger=map(sensorsoldeger,0,1023,0,100);
  sensorsagdeger=map(sensorsagdeger,0,1023,0,100);
  if(sensorsoldeger>sensorsolreferansdeger&&sensorsagdeger>sensorsagreferansdeger){
    analogWrite(motorsag,motortamhiz);
    analogWrite(motorsol,motortamhiz);
  }else if(sensorsoldeger<sensorsolreferansdeger&&sensorsagdeger<sensorsagreferansdeger){
    analogWrite(motorsag,motordonmehiz);
    analogWrite(motorsol,motordonmehizters);
  }else if(sensorsagdeger<sensorsagreferansdeger&&sensorsoldeger<sensorsolreferansdeger){
    analogWrite(motorsag,motordonmehizters);
    analogWrite(motorsol,motordonmehiz);
  }else if(sensorsoldeger<sensorsolreferansdeger&&sensorsagdeger<sensorsagreferansdeger){
    digitalWrite(motorsol,LOW);
    digitalWrite(motorsag,LOW);
  }
}
