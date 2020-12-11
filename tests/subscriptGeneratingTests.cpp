#include <gtest/gtest.h>
#include <Dice/Sparql-Query/TriplePatternElement.hpp>
#include "Dice/Sparql-Query/QueryNodes/leafNodes/TriplePatternNode.hpp"
#include <Dice/Sparql-Query/QueryNodes/SpecialNodes/OptionalPatternNode.hpp>
#include <Dice/Sparql-Query/QueryNodes/GroupNode.hpp>
#include <Dice/Sparql-Query/QueryNodes/SelectNodes/DefaultSelectNode.hpp>
#include <Dice/Sparql-Query/QueryNodes/SolutionDecorator.hpp>

TEST(subscriptGeneratingTests, basic1) {
    //creating 2 triple patterns and adding them into a node
    std::vector<TriplePatternElement> elements{TriplePatternElement{TripleVariable{"?book"},Term("<dc:title>"),TripleVariable("?title")},
                                               TriplePatternElement{TripleVariable{"?book"},Term("<ns:price>"),TripleVariable("?price")}
                                               };
    std::shared_ptr<TriplePatternNode> triplePatternNode=std::make_shared<TriplePatternNode>(elements);
    //creating 1 optional node which has 1 triple pattern inside it
    std::vector<TriplePatternElement> elements2{TriplePatternElement{TripleVariable{"?book"},Term("<dc:title>"),TripleVariable("?title")}};
    std::shared_ptr<TriplePatternNode> triplePatternNode2=std::make_shared<TriplePatternNode>(elements);
    std::shared_ptr<OptionalPatternNode> optionalNode1=std::make_shared<OptionalPatternNode>(triplePatternNode2);
    //group the 2 nodes
    std::shared_ptr<GroupNode> groupNode=std::make_shared<GroupNode>();
    groupNode->addChild(triplePatternNode);
    groupNode->addChild(optionalNode1);
    //
    std::vector<TripleVariable> selectVariables{TripleVariable{"book"},TripleVariable{"nameY"},TripleVariable{"nickY"}};
    std::shared_ptr<SelectNode> selectNode=std::make_shared<DefaultSelectNode>(groupNode, selectVariables);
    auto operands=selectNode->getOperands();
    auto variables=selectNode->getSelectVariables();
    auto bgps=selectNode->getBgps();
    std::cout<<"end";
}