#include <Arduino.h>
#include "Rest.h"
#include "Response.h"
#include "Light.h"

Light::Light(void) {
}

void Light::setup() {
  for(int i = 0; i < this->count; i++) {

    pinMode(this->pins[i].pin, OUTPUT);
    if (this->pins[i].pinType == 'D') {
      digitalWrite(this->pins[i].pin, HIGH);
    }
    //TODO: remove
    Response::SendOkFormat(", \"pin\": \"%d\", \"val\": %d", this->pins[i].pin, OUTPUT);
  }
}

void Light::ModuleHandler( String id, String val ) {
  if  (val == "on") {
    this->setPin( id, LOW );
  }
  if  (val == "off") {
    this->setPin( id, HIGH );
  }
  if  (val.endsWith("%")) {
    this->SetCopmplexValue( id, val );
  } 
  if  (val.startsWith("#")) {
    this->SetColor( id, val );
  } 
}

void Light::setPin( String id, int val ) {
  pinMap str = Rest::findByName(this->pins, id, this->count);
  digitalWrite(str.pin, val);
  //TODO: remove
  Response::SendOkFormat(", \"id\": \"%s\", \"pin\": \"%d\", \"val\": %d", id.c_str(), str.pin, val);
}
  
void Light::SetValue( String id, String val ) {
  pinMap str = Rest::findByName(this->pins, id, this->count);
  if  (val.endsWith("%")) {
    val = val.substring(0, val.indexOf("%"));
  }
  int value = val.toInt();
  value = map(value, 0, 100, 0, 255);
  analogWrite(str.pin, value); 
  
  //TODO: remove
  Response::SendOkFormat(", \"id\": \"%s\", \"pin\": \"%d\", \"val\": %d", id.c_str(), str.pin, value); 
}

void Light::SetValue( String id, long val ) {
  pinMap str = Rest::findByName(this->pins, id, this->count);
  analogWrite(str.pin, val); 
  
  //TODO: remove
  Response::SendOkFormat(", \"id\": \"%s\", \"pin\": \"%d\", \"val\": %d", id.c_str(), str.pin, val); 
}

void Light::SetCopmplexValue( String id, String val ) {
  if (id.endsWith("RGB")) {
    String _id = id.substring(0, id.indexOf("RGB"));
    char arr[3] = {'R', 'G', 'B'};
    for(int i = 0; i < 3; i++) {
      this->SetValue(_id + arr[i], val);
    }
  }
  else {
      this->SetValue(id, val);
  }
}

void Light::SetColor( String id, String color ) {
  String _id = id;
  if (_id.endsWith("RGB")) {
    _id = _id.substring(0, id.indexOf("RGB"));
  }
  
  // Get rid of '#' and convert it to integer
  long number = strtol( &color[1], NULL, 16);
  // Split them up into r, g, b values
  long rgb[3];
  rgb[0] = number >> 16;
  rgb[1] = number >> 8 & 0xFF;
  rgb[2] = number & 0xFF;
  char arr[3] = {'R', 'G', 'B'};
  
  for(int i = 0; i < 3; i++) {
    this->SetValue(_id + arr[i], rgb[i]);
  }
}

