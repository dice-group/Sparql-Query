#ifndef SPARQL_QUERY_REGULARGROUPINGNODE_HPP
#define SPARQL_QUERY_REGULARGROUPINGNODE_HPP

#include "Dice/sparql-query/Nodes/QueryNodes/GroupingNodes/GroupingNode.hpp"

namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes {
    class RegularGroupingNode : public GroupingNode {

    public:
        std::vector<std::vector<std::string>> generateStringOperands() override {
            std::vector<std::vector<std::string>> operands;
            for (auto &child : children) {
                std::vector<std::vector<std::string>> childOperands = child->generateStringOperands();
                for (auto &subscriptElement : childOperands)
                    operands.push_back(subscriptElement);
            }

            return operands;
        }

        std::vector<TriplePattern> getBgps() override {
            std::vector<TriplePattern> bgps;
            for (auto &child : children)
                for (auto &bgp : child->getBgps())
                    bgps.push_back(bgp);

            return bgps;
        }
    };
}// namespace Dice::sparql::Nodes::QueryNodes::GroupingNodes

#endif//SPARQL_QUERY_REGULARGROUPINGNODE_HPP
