#include "Rest.h"
#include <string.h>
#include <Arduino.h>
#include "Response.h"

rest Rest::getComand() {
  return Rest::split(Rest::read());
}

rest Rest::split(String str) {
  int count = str.length();
  int j = 0;
  String buf[4];

  for (int i = 0; i < count; i++) {
    if (str[i] == '/') {
      j++;
    } else {
      buf[j] += str[i];
    }
  }
  
  return {buf[0], buf[1] + "/" + buf[2], buf[3]};
}


pinMap Rest::findByName(pinMap* pinMapArr, String name, int count) {
  for (int i = 0; i < count; i++) {
    if (pinMapArr[i].name == name) {
      return pinMapArr[i];
    } 
  }
  return {"", 0, 'N'};
}


String Rest::read() {
  String readString;
  while (Serial.available())
  {
    delay(1);
    if (Serial.available() > 0)
    {
      char c = Serial.read();
      readString += c;
    }
  }
  
  return readString;
}

