#ifndef _FUNCTION_INTERFACE_H_
#define _FUNCTION_INTERFACE_H_

#include "global_value.h"
#include "Node.h"
#include "Channel.h"
#include "Text.h"

void ClickKey(sf::Event& event);
void WorkEvent(sf::Event& event);
void ClickMouseBottom(sf::Event& event);
void CollisionMouseAndNodes(std::vector<Node*>& listOfNode, sf::Vector2i mousePosition);
void CreateChannel(std::vector<Channel*>& listOfChannel, std::vector<Node*>& listOfNode, std::vector<Text*>& listOfTextOfTypeChannel, std::vector<Text*>& listOfTextOfWeightChannel, sf::Vector2i mousePosition);
void DeleteSelectedNode(std::vector<Channel*>& listOfChannel, std::vector<Node*>& listOfNode);
void CollisonMouseAndChannel(std::vector <Channel*>& listOfChannel, sf::Vector2i mousePosition);

#endif // !_FUNCTION_INTERFACE_H_
#pragma once
