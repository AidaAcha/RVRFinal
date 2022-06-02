#include "Server.h"

#include "../Utilities/Message.h"

Server::Server(const char * s, const char * p): socket(s, p){
    socket.bind();
}

void Server::do_messages(){
    while (true)
    {
        // /*
        //  * NOTA: los clientes están definidos con "smart pointers", es necesario
        //  * crear un unique_ptr con el objeto socket recibido y usar std::move
        //  * para añadirlo al vector
        //  */

        // //Recibir Mensajes en y en función del tipo de mensaje
        // // - LOGIN: Añadir al vector clients
        // // - LOGOUT: Eliminar del vector clients
        // // - MESSAGE: Reenviar el mensaje a todos los clientes (menos el emisor)


        // ChatMessage msg;
        // Socket *s;
        // int sd = socket.recv(msg, s);
        // if(sd == -1){
        //     std::cerr << "Error en socket.recv()\n";
        //     return;
        // }

        // switch(msg.type) {
	    // case ChatMessage::LOGIN:
        // {
	    //     std::cout << "Login de jugador:  " << msg.nick << "\n";
	    //     clients.push_back(std::move(std::make_unique<Socket>(*s)));
        //     break;
        // }
	    // case ChatMessage::LOGOUT:
        // {
        //     auto it = clients.begin();
	    //     while (it != clients.end() && (**it != *s))
		//         ++it;

	    //     if (it == clients.end())
		//         std::cout << "Error, logout de jugador que no estaba conectado\n";
	    //     else {
		//         std::cout << "Logout de jugador:  " << msg.nick << "\n";
        //         clients.erase(it);
		//         Socket *delSock = (*it).release();
		//         delete delSock; 
	    //     }
	    //     break;
        // }
	    // case ChatMessage::MESSAGE:
        // {
        //     std::cout << msg.nick << ": " << msg.message << "\n";
	    //     for (auto it = clients.begin(); it != clients.end(); ++it) {
		//     if (**it !=  *s)
		//         s->send(msg, **it);
	    //     }
	    //     break;
        // }
	    // default:
        //     break;
	    // }

    }
}

void Server::msg_to_clients(Message msg){
    for(Socket* s : clients)
        socket.send(msg, *s);
}