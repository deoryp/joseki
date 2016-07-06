#include <iostream>
#include <list>
#include <string>

#include "Node.h"
#include "Processor.h"
#include "Tokenizer.h"
#include "StandardGameFile.h"
#include "Board.h"

namespace joseki {

void print(std::string s);

}

int main() {

//  std::list<joseki::Node> gameTree;
  
//  joseki::Node *current = NULL;
//  std::list<joseki::Node>* currentSequence; //

  joseki::Processor processor;
  joseki::Tokenizer tokenizer = joseki::Tokenizer(std::cin, &processor);

  tokenizer.Run();
  
  joseki::Board board;
  
  board.SZ(9, 9);
  
  joseki::print(board.ToString());

  return 0;
}
