#include <iostream>
using std::cout;
using std::endl;
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include "timer4.Printer.h"

Printer::Printer(boost::asio::io_service& io):
timer_(io, boost::posix_time::seconds(1)), count_(0)
{
    timer_.async_wait(boost::bind(&Printer::Print, this));
}

Printer::~Printer()
{
    cout << "Final count: " << count_ << endl;
}
        
void Printer::Print()
{
    if (count_ < 5)
    {
        cout << count_ << endl;
        ++count_;
        timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(1));
        timer_.async_wait(boost::bind(&Printer::Print, this));
    }
}
