#ifndef _FUNCTION_INTERFACE_H_
#define _FUNCTION_INTERFACE_H_

#include "global_value.h"
#include "Node.h"

void ClickKey(sf::Event& event);
void WorkEvent(sf::Event& event);
void ClickMouseBottom(sf::Event& event);
void CollisionMouseAndNodes(std::vector<Node*>& listOfNode, sf::Vector2i mousePosition);

#endif // !_FUNCTION_INTERFACE_H_
#pragma once
