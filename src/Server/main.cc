//SERVER MAIN

#include "Server.h"

int main()
{
    Server server("127.0.0.1", "7778");
    server.do_messages();

    return 0;
}