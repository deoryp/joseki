#include "Node.h"

#include <iostream>

namespace joseki {

void print(std::string s) {
  std::cout << s << std::endl;
}

Property::Property(PropIdent i) : ident(i) {
  value = new std::list<PropValue>();
}

void Property::SetIdent(PropIdent i) {
  ident = i;
}
PropIdent Property::GetIdent() {
  return ident;
}


void Property::AddValue(PropValue v) {
  value->push_back(v);
}

std::list<PropValue>::iterator Property::GetValues() {
  return value->begin();
}

std::list<PropValue>::iterator Property::GetValuesEnd() {
  return value->end();
}


std::string Property::ToString() {
  std::string out = ident;
  for(std::list<PropValue>::iterator it = value->begin(); it != value->end(); ++it) {
    out += "[" + *it + "]";
  }
  return out;
}

Node::Node(int m) : move(m), properties(new std::list<Property>()) {
}

void Node::AddProperty(Property* property) {
  properties->push_back(*property);
}

std::list<Property>::iterator Node::GetProperties() {
  return properties->begin();
}

std::list<Property>::iterator Node::GetPropertiesEnd() {
  return properties->end();
}

int Node::GetMove() {
  return move;
}

std::string Node::ToString() {
  std::string out;
  for(std::list<Property>::iterator it = properties->begin(); it != properties->end(); ++it) {
    if (it != properties->begin()) {
      out += " ";
    }
    out += it->ToString();
  }
  return out;
}

GameTree::GameTree(GameTree* p) 
    : parent(p), sequence(new std::list<Node>()), variants(new std::list<GameTree>()) {
  if (parent != nullptr) {
    parent->AddVariant(this);
  }
}

GameTree* GameTree::Parent() {
  return parent;
}

void GameTree::AddNode(Node* node) {
  sequence->push_back(*node);
}

void GameTree::AddVariant(GameTree* tree) {
  variants->push_back(*tree);
}

std::list<Node>* GameTree::GetSequence() {
  return sequence;
}

std::list<GameTree>* GameTree::GetVariants() {
  return variants;
}

std::string GameTree::ToString() {
  
  std::string out = "\n";
  if (!sequence->empty()) {
    out += std::string(4 * sequence->begin()->GetMove(), ' ');
  }
  for(std::list<Node>::iterator it = sequence->begin(); it != sequence->end(); ++it) {
    if (it != sequence->begin()) {
      out += " ➵ ";
    }
    out += it->ToString();
  }

  for(std::list<GameTree>::iterator it = variants->begin(); it != variants->end(); ++it) {
    if (it == variants->begin()) {
      out += " ➴ ";
    }
    out += it->ToString();
  }
  return out;
}

}
