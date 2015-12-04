#ifndef __RESPONSE_H__
#define __RESPONSE_H__

#include <stdarg.h>

class Response
{
public:
    static void SendError( const char* err );
    static void SendErrorFormat( const char* fmt, ... );
    static void SendOk();
    static void SendOk( const char* data );
    static void SendOkFormat( const char* fmt, ... );
};
#endif
