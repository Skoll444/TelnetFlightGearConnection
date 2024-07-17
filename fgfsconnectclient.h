#include <errno.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>


class FGFSSocket
{

public:
    FGFSSocket(const char* name, unsigned port);
    ~FGFSSocket();

    int write(const char* msg, ...);
    const char* read(void);
    inline void flush(void);
    void settimeout(unsigned t) { _timeout = t; }
    static const int BUFLEN = 256;

private:
    int close(void);
    int _sock;
    bool _connected;
    unsigned _timeout;
    char _buffer[BUFLEN];
    bool _isShutdown = false;

};
