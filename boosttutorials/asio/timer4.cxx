#include <boost/asio.hpp>
#include "timer4.Printer.h"

int main()
{
    boost::asio::io_service io;
    Printer p(io);
    io.run();
    return 0;
}


