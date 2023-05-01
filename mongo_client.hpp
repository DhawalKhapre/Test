#include <string>

#include <mongocxx/instance.hpp>

class Mongo_Client
{
public:
    mongocxx::instance instance{};
    mongocxx::uri uri{"mongodb://localhost:27017"};
    mongocxx::client client{uri};

    void insert_doc(string database, string collection, bsoncxx::document::view document);
    void find_doc(string database, string collection);
};