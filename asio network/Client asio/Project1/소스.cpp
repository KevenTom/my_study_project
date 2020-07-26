#include<iostream>

#include<asio.hpp>
#include<asio/system_error.hpp>

using asio::ip::tcp;

int main(int argc, char* argv[]) {
	try {
		if (argc != 2) {
			std::cerr << "Usage: client <host>" << std::endl;
			return 1;
		}

		tcp::iostream stream(argv[1], std::to_string(int(13)));
		if (!stream) {
			std::cout << "unable to connect: " << stream.error().message() << std::endl;
			return 1;
		}

		std::string line;
		std::getline(stream, line);
		std::cout << line << '\n' << std::endl;

		while (true) {
			std::string chat;
			std::cin >> chat;
			stream << chat;
			stream << std::endl;

			//std::string line;
			//std::getline(stream, line);
			//std::cout << line << std::endl;
		}

	}
	catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}


	return 0;
}