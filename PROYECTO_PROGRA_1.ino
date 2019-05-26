include <Stepper.h> //Importamos la librería para controlar motores paso a paso
 
#define STEPS 200 //Ponemos el número de pasos que necesita para dar una vuelta. 200 en nuestro caso
 
// Ponemos nombre al motor, el número de pasos y los pins de control
Stepper stepper(STEPS, 9, 10, 11, 12); //Stepper nombre motor (número de pasos por vuelta, pins de control)

int voc = 2;

//Definicion sensores
int sensor0=6;
int sensor1=7;
int sensor2=8;

//Definicion botones de llamada
int boton0=3;
int boton1=4;
int boton2=5;

int b2 = 0;
int b1 = 0;
int b0 = 0;


void setup () {
  Serial.begin(9600);
  stepper.setSpeed(30);
  pinMode(sensor0,INPUT);
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(boton0,INPUT);
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(voc,OUTPUT);
}


void loop () {
digitalWrite(voc,LOW);
int s0, s1, s2;

lecturasensores (&s0, &s1, &s2);

if (s0 == 1) {
  
  b1 = digitalRead(boton1);
  b2 = digitalRead(boton2);
  
  if (b1 == HIGH){
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
    while (s1 == 0){
      lecturasensores (&s0, &s1, &s2);
      stepper.step(10);
    }
    stepper.step(35);
    stepper.step(0);
    digitalWrite(voc,HIGH);
    delay(400);
    digitalWrite(voc,LOW);
    delay(100);
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
  }
  
  if (b2 == HIGH){
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
    while (s2 == 0){
      lecturasensores (&s0, &s1, &s2);
      stepper.step(10);
    }
    stepper.step(30);
    stepper.step(0);
    digitalWrite(voc,HIGH);
    delay(400);
    digitalWrite(voc,LOW);
    delay(100);
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
  }
}

if (s1 == 1) {
  
  b0 = digitalRead(boton0);
  b2 = digitalRead(boton2);
  
  if (b0 == HIGH){
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
    while (s0 == 0){
      lecturasensores (&s0, &s1, &s2);
      stepper.step(-10);
    }
    stepper.step(0);
    digitalWrite(voc,HIGH);
    delay(400);
    digitalWrite(voc,LOW);
    delay(100);
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
  }
  
  if (b2 == HIGH){
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
    while (s2 == 0){
      lecturasensores (&s0, &s1, &s2);
      stepper.step(10);
    }
    stepper.step(30);
    stepper.step(0);
    digitalWrite(voc,HIGH);
    delay(400);
    digitalWrite(voc,LOW);
    delay(100);
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
  }
}

if (s2 == 1) {
  
  b0 = digitalRead(boton0);
  b1 = digitalRead(boton1);
  
  if (b0 == HIGH){
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
    while (s0 == 0){
      lecturasensores (&s0, &s1, &s2);
      stepper.step(-10);
    }
    stepper.step(0);
    digitalWrite(voc,HIGH);
    delay(400);
    digitalWrite(voc,LOW);
    delay(100);
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
  }
  
  if (b1 == HIGH){
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
    while (s1 == 0){
      lecturasensores (&s0, &s1, &s2);
      stepper.step(-10);
    }
    stepper.step(-20);
    stepper.step(0);
    digitalWrite(voc,HIGH);
    delay(400);
    digitalWrite(voc,LOW);
    delay(100);
    digitalWrite(voc,HIGH);
    delay(300);
    digitalWrite(voc,LOW);
  }
}
}

void lecturasensores (int *s0,int *s1,int *s2) {


int e0, e1, e2;


//lectura y muestra de datos de los sensores
  e0=digitalRead(sensor0);
delay(5);
  e1=digitalRead(sensor1);
delay(5);
  e2=digitalRead(sensor2);
delay(5);


//Filtrado de datos analogicos a digitales

if  (e0==HIGH)
    *s0=1;
else
    *s0=0;
if  (e1==HIGH)
    *s1=1;
else
    *s1=0;
if  (e2==HIGH)
    *s2=1;
else
    *s2=0;
}
