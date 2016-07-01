#include "Processor.h"

#include "StandardGameFile.h"
#include "Node.h"

namespace joseki {

Processor::Processor() : indent_(0), currentNode_(nullptr), root_(nullptr), currentTree_(nullptr) {
  root_ = new GameTree(nullptr);
}

Processor::~Processor() {}

void Processor::PropertyIdent(std::string token) {
  
  if (currentProperty_ != nullptr && currentNode_ != nullptr) {
    currentNode_->AddProperty(currentProperty_);
  }
  std::cout << std::string(indent_, ' ') << "propIdent = " << token << std::endl;
  currentProperty_ = new Property(token);
}

void Processor::PropertyValue(std::string token) {
  std::cout << std::string(indent_, ' ') << "propValue = " << token << std::endl;
  if (currentProperty_ != nullptr) {
    currentProperty_->AddValue(token);
  }
}

void Processor::GameTreeStart() {
  if (currentProperty_ != nullptr && currentNode_ != nullptr) {
    currentNode_->AddProperty(currentProperty_);
    currentProperty_ = nullptr;
  }
  if (currentNode_ != nullptr) {
    std::cout << currentNode_->ToString() << std::endl;
  }
  currentProperty_ = nullptr;
  
  if (currentTree_ == nullptr) {
    currentTree_ = root_;
  } else {
    currentTree_ = new GameTree(root_);
  }
  
  std::cout << std::string(indent_, ' ') << ">>> " << std::endl;
  indent_++;
}

void Processor::GameTreeEnd() {
  if (currentProperty_ != nullptr && currentNode_ != nullptr) {
    currentNode_->AddProperty(currentProperty_);
    currentProperty_ = nullptr;
  }

  if (indent_) {
    indent_--;
  }
  std::cout << std::string(indent_, ' ') << "<<< " << std::endl;
  if (currentTree_ != nullptr) {
    std::cout << "tree " + currentTree_->ToString() << std::endl;

    currentTree_ = currentTree_->Parent();
  }
}

void Processor::NodeStart() {
  if (currentNode_ != nullptr) {
    std::cout << std::string(indent_, ' ') << currentNode_->ToString() << std::endl;
    currentNode_ = nullptr;
  }

  currentProperty_ = nullptr;

  currentNode_ = new Node();
  indent_++;
  if (currentTree_ == nullptr) {
    currentTree_ = root_;
  }
}

void Processor::NodeEnd() {
  if (indent_) {
    indent_--;
  }
  if (currentTree_ != nullptr && currentNode_ != nullptr) {
    std::cout << "added a node to a tree." << std::endl;
    currentTree_->AddNode(currentNode_);
    currentNode_ = nullptr;
  }
}

}


/*

(;FF[4]C[root](;C[a];C[b](;C[c])
(;C[d];C[e]))
(;C[f](;C[g];C[h];C[i])
(;C[j])))

*/