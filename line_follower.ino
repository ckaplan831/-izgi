int S_A = 11;  //speed motor a
int M_A1 = 2; //motor a = +
int M_A2 = 3; //motor a = - // PİN BAĞLANTILARIMIZI TANIMLADIK 
int M_B1 = 4; //motor b = -
int M_B2 = 5; //motor b = +
int S_B = 10;  //speed motor b

int R_S = A0; //sincer R
int S_S = A1; //sincer S
int L_S = A2; //sincer L

void setup() 
{
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT); // UCLARIMIZI ÇIKIŞ PİNİ OLDUGUNU BELİRLEDİK 
pinMode(M_A2, OUTPUT);
pinMode(S_B, OUTPUT);
pinMode(S_A, OUTPUT);

pinMode(L_S, INPUT);
pinMode(S_S, INPUT); // UCLARIMIZIN GİRİS PİNİ OLDUGUNU BELİRLEDİK 
pinMode(R_S, INPUT);

analogWrite(S_A, 150); // SAĞ MOTOR HIZI 
analogWrite(S_B, 150); // SOL MOTOR HIZI 
delay(200);
}
void loop()
{  
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){forword();}

if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 0)){turnLeft();}
if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) ==0)&&(digitalRead(R_S) == 0)) {turnLeft();} // SENSOR ALGILAMA KISMINDA NELER YAPMASI GEREKTIGINI BELİRLEYEN KODLARIIZI YAZGIK 

if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){turnRight();}
if ((digitalRead(L_S) == 0)&&(digitalRead(S_S) == 0)&&(digitalRead(R_S) == 1)){turnRight();}

if ((digitalRead(L_S) == 1)&&(digitalRead(S_S) == 1)&&(digitalRead(R_S) == 1)){Stop();}
}

void forword(){ // İLERİ KOMUTLARI 
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}


void turnRight(){ //SAĞ KOMUTLARI 
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, HIGH);
digitalWrite(M_B2, LOW);  
}

void turnLeft(){ // SOL KOMUTLARI
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, HIGH);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}

void Stop(){ // DUR KOMUTU 
digitalWrite(M_A1, LOW);
digitalWrite(M_A2, LOW);
digitalWrite(M_B1, LOW);
digitalWrite(M_B2, LOW);
}
