#include <iostream>
using std::cout;
using std::endl;
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void Print(const boost::system::error_code& e, boost::asio::deadline_timer* t, int* count);

int main()
{
    boost::asio::io_service io;

    int count = 0;
    boost::asio::deadline_timer t(io, boost::posix_time::seconds(1));
    t.async_wait(boost::bind(Print, boost::asio::placeholders::error, &t, &count));
    io.run();
    cout << "Final count: " << count << endl;
    return 0;
}

void Print(const boost::system::error_code& e, boost::asio::deadline_timer* t, int* count)
{
    if (*count < 5)
    {
        cout << *count << endl;
        ++(*count);
        t->expires_at(t->expires_at() + boost::posix_time::seconds(1));
        t->async_wait(boost::bind(Print, boost::asio::placeholders::error, t, count));
    }
}
