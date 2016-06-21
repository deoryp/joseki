#ifndef JOSEKI_STANDARD_GAME_FILE_H_
#define JOSEKI_STANDARD_GAME_FILE_H_

#include <list>

namespace joseki {


/*
  Property Types (currently five):

  move	Properties of this type concentrate on the move made, not on
  	the position arrived at by this move.
  	Move properties must not be mixed with setup properties within
  	the same node.
  	Note: it's bad style to have move properties in root nodes.
  	(it isn't forbidden though)

  setup	Properties of this type concentrate on the current position.
  	Setup properties must not be mixed with move properties within
  	a node.

  root	Root properties may only appear in root nodes. Root nodes are
  	the first nodes of gametrees, which are direct descendants from a
  	collection (i.e. not gametrees within other gametrees).
  	They define some global 'attributes' such as board-size, kind
  	of game, used file format etc.

  game-info
  	Game-info properties provide some information about the game
  	played (e.g. who, where, when, what, result, rules, etc.).
  	These properties are usually stored in root nodes.
  	When merging a set of games into a single gametree, game infos
  	are stored at the nodes where a game first becomes distinguishable
  	from all other games in the tree.

          A node containing game-info properties is called a game-info node.
          There may be only one game-info node on any path within the tree,
          i.e. if some game-info properties occur in one node there may not be
          any further game-info properties in following nodes:
          a) on the path from the root node to this node.
          b) in the subtree below this node.

  -	no type. These properties have no special types and may appear
  	anywhere in a collection.
  Because of the strict distinction between move and setup properties nodes could also be divided into two classes: move-nodes and setup-nodes. This is important for databases, converting to/from ISHI-format and for some special applications.
*/
enum NodeType {
  MOVE,
  SETUP,
  ROOT,
  GAME_INFO,
  NO_TYPE
}

enum ParseMode {
  START,
  ERROR
}

}  // namespace joseki

#endif  // JOSEKI_STANDARD_GAME_FILE_H_
