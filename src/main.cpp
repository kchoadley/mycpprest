#include <iostream>

#include "controller.hpp"

using namespace web;
using namespace aoi_rest;

int main(int argc, const char * argv[]) {
    InterruptHandler::hookSIGINT();

    MicroserviceController server;
    server.setEndpoint("http://172.0.0.1:9080/v1/aoi/api");
    
    try {
        // wait for server initialization...
        server.accept().wait();
        std::cout << "Modern C++ Microservice now listening for requests at: " << server.endpoint() << '\n';
        
        InterruptHandler::waitForUserInterrupt();

        server.shutdown().wait();
    }
    catch(std::exception&  e) {
        std::cerr << "somehitng wrong happen! :(" << '\n';
    }
    catch(...) {
        RuntimeUtils::printStackTrace();
    }

    return 0;
}
