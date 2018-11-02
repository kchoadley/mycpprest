#include <iostream>

#include "example_controller.hpp"

using namespace web;
using namespace aoi_rest;

int main(int argc, const char * argv[]) {
    //InterruptHandler::hookSIGINT();
    ExampleController server;
    
    // utility::string_t server_address;
    // if(argc > 2)
    //     server_address.append(argv[2]);
    // else
    //     server_address.append("http://host_auto_ip4");
    // if(argc > 1)
    //     server_address.append(argv[1]);
    // else
    //     server_address.append(":8080");
    // server_address.append("/v1/aoi/api");
    // server.endpoint(server_address);
    
    server.endpoint("http://host_auto_ip4:6502/v1/ivmero/api");

    
    try {
        // wait for server initialization...
        server.Accept().wait();
        std::cout << "Modern C++ Microservice now listening for requests at: " << server.endpoint() << '\n';
        
        //InterruptHandler::waitForUserInterrupt();
        
        std::cout << "Press ENTER to exit." << std::endl;

        std::string line;
        // blocking call so server doesn't shut down
        std::getline(std::cin, line);

        server.Shutdown().wait();
    }
    catch(std::exception&  e) {
        std::cerr << "somehitng wrong happen! :(" << '\n';
    }
    catch(...) {
        //RuntimeUtils::printStackTrace();
    }
    return 0;
}
