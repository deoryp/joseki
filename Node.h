#ifndef JOSEKI_NODE_H_
#define JOSEKI_NODE_H_

#include <list>
#include <string>

namespace joseki {

typedef std::string PropIdent;
typedef std::string PropValue;

class Property {
 public:
  Property(PropIdent i);

  std::string ToString();
  void SetIdent(PropIdent i);
  void AddValue(PropValue v);

 private:
  PropIdent ident;
  std::list<PropValue>* value;
};

class Node {
 public:
  Node(int m);

  std::string ToString();
  void AddProperty(Property* property);
  int GetMove();

 private:
  int move;
  std::list<Property>* properties;
};

//typedef std::list<Node> Sequence;

class GameTree {
 public:
  GameTree(GameTree* parent);

  GameTree* Parent();
  std::string ToString();
  void AddNode(Node* node);
  void AddVariant(GameTree* tree);

  std::list<Node>* GetSequence();
  std::list<GameTree>* GetVariants();

 private:
  std::list<Node>* sequence;
  std::list<GameTree>* variants;
  GameTree* parent;
};

//typedef std::list<GameTree> Collection;

}  // namespace joseki

#endif  // JOSEKI_NODE_H_

/*

Collection = GameTree { GameTree }
  GameTree   = "(" Sequence { GameTree } ")"
  Sequence   = Node { Node }
  Node       = ";" { Property }
  Property   = PropIdent PropValue { PropValue }
  PropIdent  = UcLetter { UcLetter }
  PropValue  = "[" CValueType "]"
  CValueType = (ValueType | Compose)
  ValueType  = (None | Number | Real | Double | Color | SimpleText |
                Text | Point  | Move | Stone)


Collection = List<GameTree>
GameTree = List<Node> + List<GameTree>
                  
*/