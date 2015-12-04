#include <DHT.h>

#include "Rest.h"
#include "Response.h"
#include "Light.h"

Light light;

void setup() {
  Serial.begin(115200);
  light.setup();
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0) {
    rest restObj = Rest::getComand();

    if (restObj.type == "light") {
      
      light.ModuleHandler( restObj.id, restObj.value );
    }

//    Response::SendOkFormat(", \"type\": \"%s\", \"id\": \"%s\", \"val\": \"%s\"", restObj.type.c_str(), restObj.id.c_str(), restObj.value.c_str());
  }
}
