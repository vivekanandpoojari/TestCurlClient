# TestCurlClient
This is a gtest which uses C++ based httpserver to test your culr clients

In a legacy C/C++ application which uses curl library for http requests, its often difficult
to write small integration tests around the HttpClient class.

You may use POSTMAN or Java Based MockServer frameworks for the same.
However these are used to test the complete application rather than the HttpClient code itself.

If you want to test only the HttpClient code for robustness you need a smaller 
lightweight framework which can embed a web server in your test itself.

You can then create a HTTP server with trained HTTP responses and then start 
your HttpClient to test specific test scenarios.

In the sample test I have a web server which is trained to return 200 OK 
response for /hello GET request.

References : https://github.com/etr/libhttpserver
