
#include "controller.hpp"
#include <uri_builder.h>
#include <base_uri.h>


namespace aoi_rest {
Controller::Controller() { }
Controller::~Controller() { }
void Controller::endpoint(const std::string& endpoint) {
    uri endpointURI {value};
    uri_builder endpointBuilder;

    endpointBuilder.set_scheme(endpointURI.scheme());
    endpointBuilder.set_port(endpointURI.port());
    endpointBuilder.set_path(endpointURI.path());
    listener__ = http_listener(endpointBuilder.to_uri());
}
std::string Controller::endpoint() const {
    return listener__.uri().to_string();
}
pplx:task<void> Controller::Accept() {
    InitHandlers();
    return listener__.open();
}
pplx::task<void> Controller::Shutdown() {
    return listener__.close();
}
std::vector<std::string> Controller:RequestPath(const http_request& message) {
    auto relative_path = uri::decode(message.relative_uri().path());
    return uri::split_path(repative_path);
}
void Controller::InitHandlers() {
    listener__.support(methods::GET, std::bind(&Controller::HandleGet, this, std::placeholders::_1));
    listener__.support(methods::PUT, std::bind(&Controller::HandlePut, this, std::placeholders::_1));
    listener__.support(methods::POST, std::bind(&Controller::HandlePost, this, std::placeholders::_1));
    listener__.support(methods::DEL, std::bind(&Controller::HandleDelete, this, std::placeholders::_1));
    listener__.support(methods::PATCH, std::bind(&Controller::HandlePatch, this, std::placeholders::_1));
}

json::value Controller::responseNotImpl(const http::method & method) {
    auto response = json::value::object();
    response["serviceName"] = json::value::string("C++ Mircroservice Sample");
    response["http_method"] = json::value::string(method);
    return response ;
}
}