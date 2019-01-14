#include <SoftwareSerial.h>
  // motor A
int enA = 11;
int in1 = 13;
int in2 = 12;
  // motor B
int enB = 10;
int in3 = 9;
int in4 = 8;
  // adc
int potPin = A2;
  // variabel pembacaan nilai adc
int potValue = 0;
int motorSpeed = 240;
  // variabel pembacaan input keyboard
int data;
  // led
int led[]={7,6,5,4,3,2};

SoftwareSerial mySerial(A0, A1); // RX, TX

void setup() {
  // Open serial communications and wait for port to open

  // set the data rate for the SoftwareSerial port
  Serial.begin(9600);
  Serial.println("Bluetooth Communication Is Ready");
  for(int i=0; i<6; i++){
    pinMode(led[i], OUTPUT);
  }
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(potPin, INPUT);

  //  ########################      INTRO      #########################
    Serial.println("PROJECT MIKRO & ANTARMUKA 1");

//    Serial.println("\nKelompok 3");
//    Serial.println("Anggota:  Ach.Chusnul Chikam  NRP 32");    delay(400);
//    Serial.println("          Aulia Rahmah N.F.   NRP 49");    delay(400);
//    Serial.println("          Alvita Khairinia K. NRP 54");    delay(400);
//    Serial.println("          Diah Ayu Pitaloka   NRP 57");    delay(400);
//    Serial.println("          Nurul Hidayah       NRP 59");
//    delay(400);
//  //  ##################### PENGECEKAN KOMPONEN #########################
//     Serial.print("Inisialisasi...");
//     Serial.print("1..");  delay(100);
//     Serial.print("2..");  delay(100);
//     Serial.println("3..");  delay(100);
//    Serial.println("Pengecekan LED.....");
//    delay(600);
//    digitalWrite(led[0],HIGH);
//    delay(400);
//    digitalWrite(led[0],LOW);
//    digitalWrite(led[1],HIGH);
//    delay(400);
//    digitalWrite(led[1],LOW);
//    digitalWrite(led[2],HIGH);
//    delay(400);
//    digitalWrite(led[2],LOW);
//    digitalWrite(led[3],HIGH);
//    delay(400);
//    digitalWrite(led[3],LOW);
//    digitalWrite(led[4],HIGH);
//    delay(400);
//    digitalWrite(led[4],LOW);
//    digitalWrite(led[5],HIGH);
//    delay(400);
//    digitalWrite(led[5],LOW);
//    delay(400);
//    Serial.println(" Pengecekan LED Selesai...");
//    delay(600);
//    Serial.println("Selanjutnya..");
//    Serial.println(" Pengecekan Motor DC.....");
//    delay(600);
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, HIGH);
//    digitalWrite(in3, HIGH);
//    digitalWrite(in4, LOW);
//    // kecepatan 250
//    analogWrite(enA, 250);
//    analogWrite(enB, 250);
//    delay(600);
//    digitalWrite(in1, HIGH);
//    digitalWrite(in2, LOW);
//    digitalWrite(in3, LOW);
//    digitalWrite(in4, HIGH);
//    // kecepatan 250
//    analogWrite(enA, 250);
//    analogWrite(enB, 250);
//    delay(600);
//    // Motor DC mati
//    digitalWrite(in1, LOW);
//    digitalWrite(in2, LOW);
//    digitalWrite(in3, LOW);
//    digitalWrite(in4, LOW);
//    Serial.println("");
//    delay(200);
    Serial.println(" UNTUK MENGETES KOMUNIKASI SERIAL ANTARA ARDUINO DENGAN BLUETOOTH,");
    Serial.println(" BERI MASUKAN!!!");
}
//  #################### FUNGSI INDIKATOR LED #####################
void ledMaju(){
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], HIGH);
  digitalWrite(led[2], LOW);
  digitalWrite(led[3], LOW);
  digitalWrite(led[4], LOW);
  digitalWrite(led[5], LOW);
}
void ledMundur(){
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], HIGH);
  digitalWrite(led[3], LOW);
  digitalWrite(led[4], LOW);
  digitalWrite(led[5], LOW);
}
void ledKanan(){
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], LOW);
  digitalWrite(led[3], HIGH);
  digitalWrite(led[4], LOW);
  digitalWrite(led[5], LOW);
}
void ledKiri(){
  digitalWrite(led[0], LOW);
  digitalWrite(led[1], LOW);
  digitalWrite(led[2], LOW);
  digitalWrite(led[3], LOW);
  digitalWrite(led[4], HIGH);
  digitalWrite(led[5], LOW);
}
void ledMati(){
  while(Serial.available()==0){
//    animasiLed();
  }
}
//  ####################################################################
//  #################### FUNGSI AKTIVITAS MOTOR DC #####################

void maju(){
  while(Serial.available()==0){
    setKecepatan();
    Serial.println("\n  Motor Berjalan MAJU ");
    Serial.print("  dengan Kecepatan \t");
    Serial.println(motorSpeed);
    // Menyalakan motor A & B(maju)
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // set kecepatan
    analogWrite(enA, motorSpeed);
    analogWrite(enB, motorSpeed);
    delay(led[1]);        
    ledMaju();
  }
}

void mundur(){
  while(Serial.available()==0){
    setKecepatan();
    Serial.println("\n  Motor Berjalan MUNDUR ");
    Serial.print("  dengan Kecepatan \t");
    Serial.println(motorSpeed);
    // Menyalakan motor A & B (mundur)
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // set kecepatan
    analogWrite(enA, motorSpeed);
    analogWrite(enB, motorSpeed);
    delay(led[1]);
    ledMundur();
  }
}

void kanan(){
  while(Serial.available()==0){
    setKecepatan();
    Serial.println("\n  Motor KANAN ON, Motor Kiri off");
    Serial.print("  dengan Kecepatan \t");
    Serial.println(motorSpeed);
    Serial.println("");
    // Mematikan motor A
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Menyalakan motor B
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);  
    // set speed motor dc
    analogWrite(enB, motorSpeed);
    delay(led[1]);
    ledKiri();
  }
}

void kiri(){
  while(Serial.available()==0){
    setKecepatan();
    Serial.println("\n  Motor KIRI ON, Motor Kanan off");
    Serial.print("  dengan Kecepatan \t");
    Serial.println(motorSpeed);
    Serial.println("");
    // Menyalakan motor A
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);  
    // Mematikan motor B
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // set speed motor dc
    analogWrite(enA, motorSpeed);
    delay(led[1]);
    ledKanan();
  }
}

void hop(){
   Serial.println("\n  MOTOR KANAN DAN KIRI OFF");
   Serial.println("");
  // Mematikan A & motor B
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  ledMati();
}
//  #################################################################### 
//  ################## FUNGSI UNTUK SETTING KECEPATAN ###################

void setKecepatan(){
  //  membaca nilai adc
//  potValue = analogRead(potPin); 
//  // pembacaan adc menjadi 0 - 255 untuk dijadikan parameter nilai kecepatan             
//  motorSpeed = map(potValue, 0, 1023, 0, 255);
//  delay(200); 
}
//  ####################################################################


void loop(){
  //  Ketika port serial mempunyai masukan
  while(Serial.available()!=0){
    data = Serial.read();
      switch(data){
        case '1':
          Serial.println("\n  Anda memasukkan angka 1");
          maju();
        break;
        case '2':
          Serial.println("\n  Anda memasukkan angka 2");
          mundur();
        break;
        case '3':
          Serial.println("\n  Anda memasukkan angka 3");
          kiri();
        break;
        case '4':
          Serial.println("\n  Anda memasukkan angka 4");
          kanan();
        break;
        case '5':
          Serial.println("\n  Anda memasukkan angka 5");
          hop();
        break;
        default:
          Serial.println("\nMasukan Salah!!!");
          Serial.println("Pilih: 1 ==> Kedua Motor Berputar Maju");
          Serial.println("       2 ==> Kedua Motor Berputar Mundur");
          Serial.println("       3 ==> Mengaktifkan Motor Kanan saja (Belok Kiri)");
          Serial.println("       4 ==> Mengaktifkan Motor Kiri saja (Belok Kanan)");
          Serial.println("       5 ==> Kedua Motor Berhenti");
        break;
      }
    }
}

//  ################## FUNGSI UNTUK ANIMASI LED ###################
void animasiLed(){   
  int t = 350;
  int plus = 150;
  int tt = 350;
  int tam = 100;    
 
  for(int k=0; k<2; k++){
    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
      delay(t);    
    }
    for(int i=5; i>=0; i--){
      digitalWrite(led[i], LOW);
      delay(tt);
    }
    t = t + plus;
    tt = tt + tam;  
    }
    for(int i=0; i<6;){
        digitalWrite(led[i], HIGH);
        delay(500);    
        digitalWrite(led[i], LOW);
        delay(100);
        i+=2;
    }
    for(int i=1; i<6;){
        digitalWrite(led[i], HIGH);
        delay(500);    
        digitalWrite(led[i], LOW);
        delay(100);
        i+=2;
    }
    for(int i=0; i<6;){
      digitalWrite(led[i], HIGH);
      delay(500);    
      digitalWrite(led[i], LOW);
      delay(100);
      i+=2;
    }

    for(int c=0; c<3; c++){
      for(int i=0; i<3; i++){
        digitalWrite(led[i], HIGH);
        digitalWrite(led[5-i], HIGH);
        delay(500);
        digitalWrite(led[i], LOW);
        digitalWrite(led[5-i], LOW);
        delay(100);
      }
    }

    for(int i=0; i<3; i++){
      digitalWrite(led[i], HIGH);
      digitalWrite(led[5-i], HIGH);
      delay(500);
    }

    for(int i=0; i<6; i++){
      digitalWrite(led[i], LOW);
      delay(300);
    }
    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
    }
    delay(500);
    for(int i=0; i<6; i++){
      digitalWrite(led[i], LOW);
      delay(200);
    }
    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
    }
    delay(500);
    for(int i=0; i<6; i++){
      digitalWrite(led[i], LOW);
      delay(100);
    }
    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
    }
    delay(500);

    ////////////////////////////////
    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
      delay(500);
      digitalWrite(led[i], LOW);
      delay(100);
    }

    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
      digitalWrite(led[i+1], HIGH);
      delay(500);
      digitalWrite(led[i], LOW);
      digitalWrite(led[i+1], LOW);
      delay(100);
    }

    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
      digitalWrite(led[i+1], HIGH);
      digitalWrite(led[i+2], HIGH);
      delay(500);
      digitalWrite(led[i], LOW);
      digitalWrite(led[i+1], LOW);
      digitalWrite(led[i+2], LOW);
      delay(100);
    }

    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
      digitalWrite(led[i+1], HIGH);
      digitalWrite(led[i+2], HIGH);
      digitalWrite(led[i+3], HIGH);
      delay(500);
      digitalWrite(led[i], LOW);
      digitalWrite(led[i+1], LOW);
      digitalWrite(led[i+2], LOW);
      digitalWrite(led[i+3], LOW);
      delay(100);
    }

    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
      digitalWrite(led[i+1], HIGH);
      digitalWrite(led[i+2], HIGH);
      digitalWrite(led[i+3], HIGH);
      digitalWrite(led[i+4], HIGH);
      delay(600);
      digitalWrite(led[i], LOW);
      digitalWrite(led[i+1], LOW);
      digitalWrite(led[i+2], LOW);
      digitalWrite(led[i+3], LOW);
      digitalWrite(led[i+4], LOW);
      delay(150);
    }
    
    for(int i=0; i<6; i++){
      digitalWrite(led[i], HIGH);
      digitalWrite(led[i+1], HIGH);
      digitalWrite(led[i+2], HIGH);
      digitalWrite(led[i+3], HIGH);
      digitalWrite(led[i+4], HIGH);
      digitalWrite(led[i+5], HIGH);
      delay(600);
      digitalWrite(led[i], LOW);
      digitalWrite(led[i+1], LOW);
      digitalWrite(led[i+2], LOW);
      digitalWrite(led[i+3], LOW);
      digitalWrite(led[i+4], LOW);
      digitalWrite(led[i+5], LOW);
      delay(150);
    }

    t = 0;
    tt= 0;
}
