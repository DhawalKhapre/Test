#include <iostream>
#include "mongo_clent.hpp"

using namespace std;

void Mongo_Client::insert_doc(string database, string collection, bsoncxx::document::view doc)
{
    auto db = this->client[database];
    auto coll = db[collection];

    auto insert_one_result = coll.insert_one(doc);
    assert(insert_one_result);
}

void Mongo_Client::find_doc(string database, string collection)
{
    auto db = this->client[database];
    auto coll = db[collection];

    auto cursor_all = collection.find({});
    cout << "collection " << collection.name() << " contains these documents:" << endl;
    for (auto doc : cursor_all) {
        cout << bsoncxx::to_json(doc, bsoncxx::ExtendedJsonMode::k_relaxed) << endl;
    }
    cout << endl;
}