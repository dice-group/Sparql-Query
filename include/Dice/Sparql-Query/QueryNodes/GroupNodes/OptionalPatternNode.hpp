//
// Created by fakhr on 18.02.20.
//

#ifndef SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
#define SPARQL_QUERY_OPTIONALPATTERNNODE_HPP

#include "GroupNode.hpp"

class OptionalPatternNode :public GroupNode
        {
                public:
                SelectQueryResult execute(const SelectQueryResult& previousQueryResult) override {
                    SelectQueryResult queryResult=previousQueryResult;
                    for(auto child:children)
                        queryResult=child->execute(queryResult);
                    //ToDo implement the logic here to perform : return queryResult=previousQueryResult-queryResult
                    return queryResult;
                }
        };

#endif //SPARQL_QUERY_OPTIONALPATTERNNODE_HPP
