#include <Arduino.h>
#include "Response.h"

void Response::SendError( const char* err )
{
    String _err = err;
    Serial.print("{ \"status\": \"ERROR\", \"error\": \"" + _err + "\" }");
}

void Response::SendErrorFormat( const char* fmt, ... )
{
    char buffer[256];
    va_list args;
    va_start (args, fmt);
    vsnprintf(buffer, 256, fmt, args);
    SendError( buffer);
    va_end (args);    
}

void Response::SendOk()
{
    Serial.println(F("{ \"status\": \"ok\" }"));
}

void Response::SendOk( const char* data )
{
    String _data = data;
    Serial.println("{ \"status\": \"ok\"" + _data + " }");
}

void Response::SendOkFormat( const char* fmt, ... )
{
    char buffer[256];
    va_list args;
    va_start (args, fmt);
    vsnprintf(buffer, 256, fmt, args);
    SendOk(buffer);
    va_end (args);    
}

