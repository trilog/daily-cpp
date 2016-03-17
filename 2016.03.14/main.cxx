// ************************************************************************* //
// * Daily Programmer 2016-03-17 easy: IRC Making a Connection             * //
// * https://www.reddit.com/r/dailyprogrammer/comments/4ad23z/             * //
// ************************************************************************* //

#include <iostream>
using std::cerr;
using std::cout;
using std::endl;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;

int main(const int argc, const char** argv)
{
    string server;
    unsigned int port = 0;
    string nickName;
    string userName;
    string realName;
    if (argc > 1)
    {
        ifstream configFile(argv[1]);
        if (configFile.is_open())
        {
            getline(configFile, server);
            size_t found = server.find(':');
            if (found < server.size())
            {
                port = stoul(server.substr(found + 1, server.size() - found - 1));
                server = server.substr(0, found);
            }
            getline(configFile, nickName);
            getline(configFile, userName);
            getline(configFile, realName);
            configFile.close();
        }
    }
    else
    {
        cout << "Enter Server: ";
        cin >> server;
        cout << "Enter Port: ";
        cin >> port;
        cout << "Enter Nickname: ";
        cin >> nickName;
        cout << "Enter Username: ";
        cin >> userName;
        cout << "Enter Real name: ";
        cin >> realName;
    }
    return 0;
}
