#include <iostream>
using std::cout;
using std::endl;
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

int main()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));
    t.wait();
    cout << "Hello, World!" << endl;
    return 0;
}
