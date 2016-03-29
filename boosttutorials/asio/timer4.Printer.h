#include <boost/asio.hpp>

class Printer
{
    public:
              Printer(boost::asio::io_service& io);
             ~Printer();
        void  Print();
    private:
        boost::asio::deadline_timer timer_;
        int count_;
};
