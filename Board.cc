#include "Board.h"

#include <iostream>

#include "StandardGameFile.h"
#include "Node.h"

namespace joseki {

void print(std::string s);

Board::Board() {
}

void Board::SZ(int x, int y) {
  board.resize(x);
  for(int i = 0 ; i < y ; ++i){
      board[i].resize(y);
  }
}

std::string Board::ToString() {
  std::string out;

  for(std::vector< std::vector<Vertex> >::iterator xit = board.begin(); xit != board.end(); ++xit) {
    for(std::vector<Vertex>::iterator yit = xit->begin(); yit != xit->end(); ++yit) {
      switch (*yit) {
        case OPEN:
//              out += "◯ ";
//          break;
          if (xit == board.begin()) {
            if (yit == xit->begin()) {
    out += "○ ";
//              out += "┌ ";
            } else if (yit + 1 == xit->end()) {
              out += "┐ ";
            } else {
    out += "● ";
//              out += "┬ ";
            }
          } else if (xit + 1 == board.end()) {
            if (yit == xit->begin()) {
              out += "└ ";
            } else if (yit + 1 == xit->end()) {
              out += "┘ ";
            } else {
              out += "┴ ";
            }
          } else {
            if (yit == xit->begin()) {
              out += "├ ";
            } else if (yit + 1 == xit->end()) {
              out += "┤ ";
            } else {
              out += "┼ ";
            }
          }
          break;
        case WHITE:
          out += "w";
          break;
        case BLACK:
          out += "b";
          break;
        default:
          out += "?";
      }
    }
    out += "◯ ";
    out += "◉ ";
//    out += " ◉ ";
    out += " ○ ";
    out += " ● ";
    out += "\n";
  }
  return out;
}

Board::~Board() {}

}
