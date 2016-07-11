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

  joseki::GameTree* game = tokenizer.Run();
  joseki::GameTree* g = game;
  
  joseki::Board board;
  

  
  for(std::list<joseki::Node>::iterator itNode = g->GetSequence()->begin(); 
      itNode != g->GetSequence()->end();
      ++itNode) {
    for(std::list<joseki::Property>::iterator itProp = itNode->GetProperties();
        itProp != itNode->GetPropertiesEnd();
        ++itProp) {
      if (itProp->GetIdent() == "SZ") {
        joseki::print("found SZ");
        std::list<joseki::PropValue>::iterator values = itProp->GetValues();
        int sz = std::stoi(*values);
        board.SZ(sz, sz);
      }
      if (itProp->GetIdent() == "AW") {
        joseki::print("found AW");
        for (std::list<joseki::PropValue>::iterator values = itProp->GetValues();
        values != itProp->GetValuesEnd();
        values++){
          joseki::print(" " + *values);
          board.AW(*values);
        }
      }
      if (itProp->GetIdent() == "AB") {
        joseki::print("found AB");
        for (std::list<joseki::PropValue>::iterator values = itProp->GetValues();
        values != itProp->GetValuesEnd();
        values++){
          joseki::print(" " + *values);
          board.AB(*values);
        }
      }
    }
  }

//  g = game->GetVariants().begin();
  for(std::list<joseki::GameTree>::iterator gt = game->GetVariants()->begin(); 
      gt != game->GetVariants()->end();
      ++gt) {
    g = &*gt;
    for(std::list<joseki::Node>::iterator itNode = g->GetSequence()->begin(); 
        itNode != g->GetSequence()->end();
        ++itNode) {
      for(std::list<joseki::Property>::iterator itProp = itNode->GetProperties();
          itProp != itNode->GetPropertiesEnd();
          ++itProp) {
        joseki::PropIdent prop = itProp->GetIdent();
        joseki::print(prop);
        if (prop == "AW") {
          joseki::print("found AW");
          for (std::list<joseki::PropValue>::iterator values = itProp->GetValues();
          values != itProp->GetValuesEnd();
          values++){
            joseki::print(" " + *values);
          }
        }
        if (prop == "AB") {
          joseki::print("found AB");
          for (std::list<joseki::PropValue>::iterator values = itProp->GetValues();
          values != itProp->GetValuesEnd();
          values++){
            joseki::print(" " + *values);
          }
        }
      }
    }
  }
  joseki::print(board.ToString());

  return 0;
}
