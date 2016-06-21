#include "Node.h"

namespace joseki {

 Node();
 ~Node() override;
 
 void AddVariation(Node variant);
 
private:
  std::list<Node> variations_;
  
}