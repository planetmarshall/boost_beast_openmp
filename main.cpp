#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/version.hpp>

#include <omp.h>

#include <iostream>

using boost::asio::ip::tcp;
namespace beast = boost::beast;
namespace http = beast::http;
using tcp = boost::asio::ip::tcp;

int main(int argc, char **argv) {
    #pragma omp parallel
    {
        std::cout << "Thread Number: " << omp_get_thread_num() << std::endl;
    }

    boost::asio::io_context io_context;
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 8001));

    tcp::socket socket{io_context};
    acceptor.accept(socket);

    http::request<http::string_body> req;
    beast::error_code ec;
    beast::flat_buffer buffer;
    http::read(socket, buffer, req, ec);

    return 0;
}
