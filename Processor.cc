#include "Processor.h"

#include <iostream>

#include "StandardGameFile.h"
#include "Node.h"

namespace joseki {

void print(std::string s);

Processor::Processor() : indent_(0), move_(0), currentNode_(nullptr), root_(nullptr), currentTree_(nullptr) {
  root_ = new GameTree(nullptr);
}

Processor::~Processor() {}

void Processor::PropertyStart() {
  currentProperty_ = nullptr;
}

void Processor::PropertyEnd() {
  currentNode_->AddProperty(currentProperty_);
  currentProperty_ = nullptr;
}

void Processor::PropertyIdent(std::string token) {
  currentProperty_ = new Property(token);
}

void Processor::PropertyValue(std::string token) {
  currentProperty_->AddValue(token);
}

void Processor::GameTreeStart() {
  if (currentTree_ == nullptr) {
    currentTree_ = root_;
  } else {
    currentTree_ = new GameTree(currentTree_);
  }
}

void Processor::GameTreeEnd() {
  move_ -= currentTree_->GetSequence()->size();
  currentTree_ = currentTree_->Parent();
}

void Processor::SequenceStart() {

}

void Processor::SequenceEnd() {

}

void Processor::NodeStart() {
  currentNode_ = new Node(move_++);
}

void Processor::NodeEnd() {
  currentTree_->AddNode(currentNode_);
  currentNode_ = nullptr;
}

GameTree* Processor::GetCollection() {
  print("\nResulting Tree: \n" + root_->ToString());
  return root_;
}

}
