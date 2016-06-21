#ifndef JOSEKI_NODE_H_
#define JOSEKI_NODE_H_

#include <list>

namespace joseki {

class Node {
 public:
  Node();
  ~Node() override;
  
  void AddVariation(Node variant);
  
 private:
   std::list<Node> variations_;
};

}  // namespace joseki

#endif  // JOSEKI_NODE_H_
