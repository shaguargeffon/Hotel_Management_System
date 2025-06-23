#pragma once

#include "database.hpp"



class ServiceAbs{
public:
    virtual void ParseRequest() = 0;

};


template <typename Protocol, typename Database>
class ServiceRegister : public ServiceAbs{
public:
    ServiceRegister(Protocol protocol): register_protocol_(protocol), database_(Database::GetInstance()) {

    }

    void ParseRequest() override{
        name_ = register_protocol_.GetName();
        email_ = register_protocol_.GetEmail();
        telefon_number_ = register_protocol_.GetTel();
        password_ = register_protocol_.GetPassword();
    }

    int Register() {
        return database_.Register(name_, email_, telefon_number_);
    }


private:
    Protocol register_protocol_;
    Database& database_;
    std::string name_;
    std::string email_;
    std::string telefon_number_;
    std::string password_;
};



