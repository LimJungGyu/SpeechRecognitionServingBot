char cmd;
char ServeEnd;
int count = 0;
int right = 13;
int left = 11;
int ENA = 10;
int ENB = 5;
int IN1 = 9;
int IN2 = 8;
int IN3 = 7;
int IN4 = 6;

void setup() {
  pinMode(right,INPUT);    //right 출력
  pinMode(left,INPUT);      //left 출력
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  Serial.begin(9600);
}
void GoTable(char cmd,int count){
  while(ServeEnd != 'e'){
    if(digitalRead(right) == LOW && digitalRead(left) == HIGH){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      delay(15);
    }else if(digitalRead(right) == HIGH && digitalRead(left) == LOW){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      delay(15);
    }else if(digitalRead(right) == LOW&& digitalRead(left) == LOW){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      delay(15);
    }else if(digitalRead(right) == HIGH && digitalRead(left) == HIGH){ 
      if(count==1){
        if(cmd=='1' || cmd=='3' || cmd=='5'){
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          analogWrite(ENA, 250);
          analogWrite(ENB, 250);
          delay(470);
          count-=1;        
        }
        else if(cmd=='2' || cmd=='4' || cmd=='6'){
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          analogWrite(ENA, 250);
          analogWrite(ENB, 250);
          delay(470);
          count-=1;
        }
      }
      else if(count>1){
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 100);
        analogWrite(ENB, 100);
        delay(150);
        count -=1;
      }
      else if(count==0){
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 0);
        analogWrite(ENB, 0);
        Serial.println("arrived table");
        delay(100);

        while(true){
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, LOW);
          analogWrite(ENA, 0);
          analogWrite(ENB, 0);
          delay(15);
        if(Serial.available()){
          ServeEnd= Serial.read();
          if(ServeEnd== 'e');{
            Serial.println("serving end");
            break; 
          }       
          }
        }
      }
    }
  }
}
void BackHome(char cmd,int count){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);  
  delay(700);

  while(true){
    if(digitalRead(right) == LOW && digitalRead(left) == HIGH){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      delay(15);
    }else if(digitalRead(right) == HIGH && digitalRead(left) == LOW){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      delay(15);
    }else if(digitalRead(right) == LOW&& digitalRead(left) == LOW){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      delay(15);
    }else if(digitalRead(right) == HIGH&& digitalRead(left) == HIGH){
      if(cmd=='1' || cmd=='3' || cmd=='5'){
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
        analogWrite(ENA, 150);
        analogWrite(ENB, 100);
        delay(700);
        count-=1;
        while(digitalRead(left) == HIGH)
          {
          digitalWrite(IN1, LOW);
          digitalWrite(IN2, HIGH);
          digitalWrite(IN3, HIGH);
          digitalWrite(IN4, LOW);
          analogWrite(ENA, 150);
          analogWrite(ENB, 100);
          delay(15);
          break;}
          break;       
        }
       else if(cmd=='2' || cmd=='4' || cmd=='6'){
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 150);
        analogWrite(ENB, 150);
        delay(700);
        count-=1;
        while(digitalRead(right) == HIGH)
        {
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          analogWrite(ENA, 150);
          analogWrite(ENB, 150);
          delay(15);
          break;  }
          break;       
          }
        
        }
    }
 
  while(true){
    if(digitalRead(right) == LOW && digitalRead(left) == HIGH){
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      delay(15);
    }else if(digitalRead(right) == HIGH && digitalRead(left) == LOW){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      delay(15);
    }else if(digitalRead(right) == LOW&& digitalRead(left) == LOW){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, 100);
      analogWrite(ENB, 100);
      delay(15);
    }else if(digitalRead(right) == HIGH && digitalRead(left) == HIGH){
      if(count>=1){
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 100);
        analogWrite(ENB, 100);
        delay(200);
        count -=1;
      }else if(count==0){
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENA, 200);
        analogWrite(ENB, 200);
        delay(700);
       
        while(true)
        {
          Serial.println("end-1");
          digitalWrite(IN1, HIGH);
          digitalWrite(IN2, LOW);
          digitalWrite(IN3, LOW);
          digitalWrite(IN4, HIGH);
          analogWrite(ENA, 200);
          analogWrite(ENB, 200);
          delay(10);
          if(digitalRead(left) == HIGH || digitalRead(right) == HIGH){
            Serial.println("end-2");
            digitalWrite(IN1, HIGH);
            digitalWrite(IN2, LOW);
            digitalWrite(IN3, LOW);
            digitalWrite(IN4, HIGH);
            analogWrite(ENA, 0);
            analogWrite(ENB, 0);
            Serial.println("home");
            delay(1000);
            
            break;}}break;
        } 
    }
  }
}
void loop() {
  ServeEnd='0';

  if(Serial.available()){
    cmd = Serial.read(); 
    if(cmd=='1' || cmd=='2'){
      count =1;
      Serial.print("serving:table ");
      Serial.println(cmd);
      delay(1);
      GoTable(cmd,count);
      delay(1);
      count =1;
      BackHome(cmd,count);
      delay(1);
      cmd=0;
    }
    else if(cmd=='3' || cmd=='4'){
      count =2;
      Serial.print("serving:table ");
      Serial.println(cmd);
      delay(1);
      GoTable(cmd,count);
      delay(1);
      count =2;
      BackHome(cmd,count);
      delay(1);
      cmd=0;
    }
    else if(cmd=='5' || cmd=='6'){
      count =3;
      Serial.print("serving:table ");
      Serial.println(cmd);
      delay(1);
      GoTable(cmd,count);
      delay(1); 
      count =3;
      BackHome(cmd,count);
      delay(1);
      cmd=0;
    }
    else if(cmd=='0'){
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, 0);
      analogWrite(ENB, 0);
      Serial.println("home");
      delay(15);
       }

  }
}