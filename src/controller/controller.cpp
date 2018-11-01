#include <controller.hpp>
#include <pplx/pplxtasks.h>

namespace aoi_rest {
Controller::Controller() { }
Controller::~Controller() { }

void Controller::endpoint(const std::string& value) {
    uri endpointURI {value};
    uri_builder endpointBuilder;

    endpointBuilder.set_scheme(endpointURI.scheme());
    endpointBuilder.set_host(endpointURI.host());
    endpointBuilder.set_port(endpointURI.port());
    endpointBuilder.set_path(endpointURI.path());
    listener__ = http_listener(endpointBuilder.to_uri());
}
std::string Controller::endpoint() const {
    return listener__.uri().to_string();
}
pplx::task<void> Controller::Accept() {
    InitHandlers();
    return listener__.open();
}
pplx::task<void> Controller::Shutdown() {
    return listener__.close();
}
std::vector<std::string> Controller::RequestPath(const http_request& message) {
    auto relative_path = uri::decode(message.relative_uri().path());
    return uri::split_path(relative_path);
}
json::value Controller::ResponseNotImpl(const http::method & method) {
    auto response = json::value::object();
    response["serviceName"] = json::value::string("C++ Mircroservice Sample");
    response["http_method"] = json::value::string(method);
    return response ;
}
}