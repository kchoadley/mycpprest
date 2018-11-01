#pragma once 

#include <controller.hpp>

namespace aoi_rest {
class ExampleController: public Controller {
  public: 
    ExampleController() : Controller() { }
    ~ExampleController() { }

    // must make virtual methods non-virtual
    void InitHandlers() override;
    void HandleGet(http_request message) override;
    void HandlePut(http_request message) override;
    void HandlePost(http_request message) override;
    void HandleDelete(http_request message) override;
};
}