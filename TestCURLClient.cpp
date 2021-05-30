#include "TestCURLClient.h"

using namespace std;
using namespace httpserver;

std::shared_ptr<httpserver::webserver> TestHTTPChannel::webserverPtr_;
TestWebServer* TestHTTPChannel::testWebServerPtr_;

const shared_ptr<http_response> TestWebServer::render_GET(const http_request &req)
{
    return shared_ptr<string_response>(new string_response("OK", 200, "text/plain"));
}

const shared_ptr<http_response> TestWebServer::render_POST(const http_request &req)
{
    return shared_ptr<string_response>(
        new string_response(req.get_arg("arg1") + req.get_arg("arg2"), 200, "text/plain"));
}

void TestHTTPChannel::SetUpTestCase() {
    webserverPtr_ = make_shared<webserver>(create_webserver(1080));
    TestWebServer* testWebServerPtr_ = new TestWebServer();
    webserverPtr_->register_resource("/hello", testWebServerPtr_);
    webserverPtr_->start(false);
}

void TestHTTPChannel::TearDownTestCase() {
    if (webserverPtr_->is_running()) {
        webserverPtr_->stop();
    }
}

void TestHTTPChannel::SetUp() 
{
    EXPECT_TRUE(TestHTTPChannel::webserverPtr_->is_running());
}

TEST_F(TestHTTPChannel, SendGetRequestSuccess)
{
    //Invoke the curl client here and send a request to http://localhost:1080
    //The GET request to http://localhost:1080/hello should return 200 OK
}