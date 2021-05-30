#ifndef TEST_CURL_CLIENT_H
#define TEST_CURL_CLIENT_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "httpserver.hpp"
#include <string.h>
#include <memory>

class TestWebServer : public httpserver::http_resource
{
public:
    const std::shared_ptr<httpserver::http_response> render_GET(const httpserver::http_request &req);
    const std::shared_ptr<httpserver::http_response> render_POST(const httpserver::http_request &req);
};

class TestHTTPChannel : public ::testing::Test
{
   protected:
    void SetUp() override;
    static void SetUpTestCase();
    static void TearDownTestCase();

   protected:
    static std::shared_ptr<httpserver::webserver> webserverPtr_;
    static TestWebServer *testWebServerPtr_;
};

#endif // TEST_CURL_CLIENT_H