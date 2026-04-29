#include <math.h>
#include <string.h>

char str[] = "hello world";  //string
char array[sizeof(str)][15];  // store binary strings

void bin_con(char array[][15], int len);

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);//output set

  long int temp[sizeof(str)];//var to store equivalent binary 

  for (int i = 0; str[i] != '\0'; i++) {
    temp[i] = (int)str[i];
  }

  bin_con(array, strlen(str));
}

void bin_con(char array[][15], int len) {
  char bit[100];

  for (int i = 0; i < len; i++) {
    int index = 0;

    int b = (int)str[i];
    int msb = (int)(log(b) / log(2));
    int c = msb;

    for (int j = msb; j >= 0; j--) {
      if (b >= pow(2, c)) {
        bit[index++] = '1';
        b = b - pow(2, c);
      } else {
        bit[index++] = '0';
      }
      c--;
    }

    bit[index] = '\0';

    strcpy(array[i], bit);  // store full binary string
  }
}

void loop() {
  for (int i = 0; i < strlen(str); i++) {
    char str2[15];
    strcpy(str2, array[i]);

    for (int j = 0; str2[j] != '\0'; j++) {
      if (str2[j] == '1') {
        digitalWrite(12,HIGH);//glow if 1
        Serial.print(1);
        delay(1000);//delay for a second
        
      } else {
        digitalWrite(12,LOW);//off if 0
        Serial.print(0);
        delay(1000);//delay for a second
      }
    }
  }
  Serial.print('\n');
  exit(0);

}