#pragma once

#include<string>
#include<thread>

class Server {
    public:

        explicit Server(int port);
        ~Server();

        void start();
        void stop();

    private:

        void accept_connection();
        void handle_client(int client_socket);

        void send_message(int socket, const std::string& message);
        std::string receive_message(int socket);

        int server_socket;
        int port;
        bool is_running;
};