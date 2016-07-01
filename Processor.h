#ifndef JOSEKI_PROCESSOR_H_
#define JOSEKI_PROCESSOR_H_

#include <string>

namespace joseki {

class GameTree;
class Node;
class Property;

class Processor {
 public:
  Processor();
  ~Processor();

  void PropertyIdent(std::string token);
  void PropertyValue(std::string token);
  void GameTreeStart();
  void GameTreeEnd();
  void SequenceStart();
  void SequenceEnd();
  void NodeStart();
  void NodeEnd();
  void PropertyStart();
  void PropertyEnd();
  
  void GetCollection(); // TODO
  
 private:
  int indent_;
  int move_;
  GameTree* root_;
  GameTree* currentTree_;
  Node* currentNode_;
  Property* currentProperty_;
};

}  // namespace joseki

#endif  // JOSEKI_PROCESSOR_H_
