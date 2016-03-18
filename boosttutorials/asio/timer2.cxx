#include <iostream>
using std::cout;
using std::endl;
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void Print(const boost::system::error_code& e);

int main()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    t.async_wait(&Print);
    io.run();
    return 0;
}

void Print(const boost::system::error_code& e)
{
    cout << "Hello, World!" << endl;
}
