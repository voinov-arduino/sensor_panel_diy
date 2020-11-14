// coding by Voinoff
        // for art-object 
            //
int firstPin = 3;   // Пин, который отправляет сигнал
int secondPin = 2;  // Пин, который принимает сигнал
int ledPin = 13;    // общий анод
int redPin = 9; // Красный пин (может быть)
int bluePin = 10; // Синий пин (может быть)
int greenPin = 11; // Зеленый пин (может быть)
int i = 0;
void setup()
{
    pinMode(secondPin, OUTPUT);
    pinMode(firstPin, INPUT);
    pinMode(ledPin, OUTPUT);
    pinMode(redPin,OUTPUT);
    pinMode(bluePin, OUTPUT);
    pinMode(greenPin, OUTPUT);


    Serial.begin(9600);
    
}


int getDeltaTime()
{
    
    int time_start=0;
    int time_finish = 0;
    int time_delta = 0;

    time_start = micros(); // Количество микросекунд со старта программы
    digitalWrite(secondPin, HIGH); // Отправляем сигнал
    while(digitalRead(firstPin) == LOW); // ждем пока дойдет сигнал от одного пина к другому
    time_finish = micros(); // Еще раз смотрим сколько прошло микросекунд со старта программы
    time_delta = time_finish - time_start; // Высчитываем сколько микросекунд ушло на передачу сигнала между пинами
    digitalWrite(secondPin, LOW); // Останавливаем передачу сигнала

    //Serial.println(time_delta);
    return time_delta;
}
void loop(){
    
  int ms = getDeltaTime();
    
  if(ms > 100){
    i++;
    delay (500);
    if(i >=6){
      i = 0;
    }
  }
     
        Serial.println(i);
        switch(i){
          case 0:
          digitalWrite(redPin, LOW);
          digitalWrite(bluePin, LOW);
          digitalWrite(greenPin, LOW);
          case 1:
          digitalWrite(redPin, HIGH);
          digitalWrite(bluePin, LOW);
          digitalWrite(greenPin, LOW);
          break;
          case 2:
          digitalWrite(bluePin, HIGH);
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, LOW);
          break;
          case 3:
          digitalWrite(greenPin, HIGH);
          digitalWrite(redPin, LOW);
          digitalWrite(bluePin, LOW);
          break;
          case 4:
          digitalWrite(greenPin, HIGH);
          digitalWrite(redPin, HIGH);
          digitalWrite(bluePin, LOW);
          break;
          case 5:
          digitalWrite(redPin, HIGH);
          digitalWrite(bluePin, HIGH);
          digitalWrite(greenPin, LOW);
          break;
          
          
        }
}