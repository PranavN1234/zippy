#include "ZippyService.h"
#include "ClientHandler.h"
#include <sstream>
#include <string>
#include <iostream>

ZippyService::ZippyService(Database& db) : db_(db) {}

ZippyService::~ZippyService() {
    std::cout << "ZippyService instance destroyed" << std::endl;
    server_->Shutdown();
    cq_->Shutdown();
    for (auto& thread : threads_) {
        thread.join();
    }
}

grpc::Status ZippyService::ExecuteCommand(grpc::ServerContext* context, const zippy::CommandRequest* request, zippy::CommandResponse* response) {
    std::string command = request->command();
    std::istringstream iss(command);
    std::string arg;
    iss >> arg;

    if (arg == "SET") {
        std::string key, value;
        iss >> key >> value;
        db_.set(key, value);
        response->set_result("Set operation performed successfully");
        log(arg, key, value);
    } else if (arg == "GET") {
        std::string key;
        iss >> key;
        std::string retrievedValue = db_.get(key);
        response->set_result("Retrieved value: " + retrievedValue);
        log(arg, key, retrievedValue);
    } else if (arg == "DEL") {
        std::string key;
        iss >> key;
        db_.del(key);
        response->set_result("Delete operation performed successfully");
        log(arg, key);
    } else {
        response->set_result("Invalid command");
    }
    return grpc::Status::OK;
}

void ZippyService::log(const std::string& operation, const std::string& key, const std::string& value) {
    if (operation == "SET") {
        std::cout << "Client: " << "client-1" << ", Operation: " << operation << ", Key: " << key << ", Value: " << value << std::endl;
    } else if (operation == "GET") {
        if (value.empty()) {
            std::cout << "Client: " << "client-1" << ", Operation: " << operation << ", Key: " << key << ", Result: Key not found" << std::endl;
        } else {
            std::cout << "Client: " << "client-1" << ", Operation: " << operation << ", Key: " << key << ", Value: " << value << std::endl;
        }
    } else if (operation == "DEL") {
        std::cout << "Client: " << "client-1" << ", Operation: " << operation << ", Key: " << key << std::endl;
    } else {
        std::cout << "Client: " << "client-1" << ", Operation: " << operation << ", Command: " << key << std::endl;
    }
}

void ZippyService::HandleRpcs() {
    new ClientHandler(&db_, this, cq_.get());
    void *tag;
    bool ok;
    while (true) {
        GPR_ASSERT(cq_->Next(&tag, &ok));
        if (ok) {
            static_cast<ClientHandler*>(tag)->Proceed();
        } else {
            delete static_cast<ClientHandler*>(tag);
        }
    }
}