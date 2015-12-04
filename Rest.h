#ifndef __REST_H__
#define __REST_H__
#include <Arduino.h>
struct rest {
  String type;
  String id;
  String value;
};

struct pinMap {
  String name;
  int pin;
  char pinType;
};
  
class Rest
{
public:

  static rest getComand();
  static rest split(String str);
  static pinMap findByName(pinMap* pinMapArr, String name, int count);
  static String read();

};
#endif
