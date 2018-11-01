#include <iostream>

#include "example_controller.hpp"

using namespace web;
using namespace aoi_rest;

int main(int argc, const char * argv[]) {
    //InterruptHandler::hookSIGINT();

    ExampleController server;
    
    server.endpoint("http://127.0.0.1:9080/v1/aoi/api");
    
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
