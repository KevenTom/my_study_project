#include<iostream>
#include<string>
#include<future>

#include<asio.hpp>
#include<asio/system_error.hpp>

using asio::ip::tcp;

int main() {
	try {
		asio::io_service io_service;
		tcp::endpoint endpoint(tcp::v4(), 13);

		tcp::acceptor acceptor(io_service, endpoint);

		std::cout << "Server started" << '\n' << std::endl;

		while (true) {
			const std::string message_to_send = "server asio join";

			asio::ip::tcp::iostream stream;

			std::cout << "wating player..." << std::endl;

			asio::error_code ec;
			acceptor.accept(*stream.rdbuf(), ec);

			std::cout << "join player" << '\n' << std::endl;
			
			if (!ec) {
				stream << message_to_send;
				stream << std::endl;

				auto async1 = std::async([&]() {
					while (true) {
						std::string line;
						std::getline(stream, line);
						printf("aaaa");
					}
					});

				auto async2 = std::async([&]() {
					while (true) {
						std::string chat;
						std::cin >> chat;
						stream << chat;
						stream << std::endl;
					}
					});
			}
		}
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}


	return 0;
}