

#include <iostream>
#include "example_controller.hpp"

using namespace web;
using namespace aoi_rest;

int main(int argc, const char * argv[]) {
    ExampleController server;
    utility::string_t server_address;
    if(argc > 1)
        server_address.append(argv[2]);
    else
        server_address.append("http://host_auto_ip4");
    if(argc > 0)
        server_address.append(argv[1]);
    else
        server_address.append(":8080");
    server_address.append("/v1/aoi/api");
    server.endpoint(server_address);
    
    try {
        server.Accept().wait();// wait for server initialization...
        std::cout << "Listening for requests at: " << server.endpoint() << std::endl;
        std::cout << "Press ENTER to exit." << std::endl;
        std::string line;
        std::getline(std::cin, line); // blocking call so server doesn't shut down
        server.Shutdown().wait();
    }
    catch(std::exception&  e) {
        std::cerr << "There was an error" << std::endl;
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
