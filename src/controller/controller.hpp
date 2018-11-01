#pragma once 

#include <string>
#include <cpprest/http_listener.h>
#include <cpprest/http_msg.h>
#include <pplx/pplxtasks.h>

using namespace web;
using namespace http;
using namespace http::experimental::listener;

namespace aoi_rest {
class Controller {
  public: 
    Controller();
    ~Controller();

    void endpoint(const std::string& endpoint);
    std::string endpoint() const;
    pplx::task<void> Accept();
    pplx::task<void> Shutdown();
    std::vector<std::string> RequestPath(const http_request& message);

    virtual void InitHandlers() = 0;
    virtual void HandleGet(http_request message) = 0;
    virtual void HandlePut(http_request message) = 0;
    virtual void HandlePost(http_request message) = 0;
    virtual void HandleDelete(http_request message) = 0;
  protected:
    http_listener listener__;
    static json::value ResponseNotImpl(const http::method& method);
};
}