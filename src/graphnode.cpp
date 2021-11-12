#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE done
    ////

    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge>edge)
{   // std::move() here is very importent, teddy G said, because vector.push_back() will trigger an internal copy
    // and delete. But according to https://yasenh.github.io/post/cpp-diary-1-emplace_back/, emplace_back() should work.
    // But it doesn't work. It woulb be nice, if mentor read this and give some point to the problem. 
    _childEdges.emplace_back(std::move(edge)); // get idea from https://knowledge.udacity.com/questions/520281
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot *chatbot)
{
    _chatBot = chatbot;
    _chatBot->SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(_chatBot);
    _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE done
    ////

    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}