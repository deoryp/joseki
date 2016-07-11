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

void Board::AB(int x, int y) {
  board[x-1][y-1] = BLACK;
}

void Board::AW(int x, int y) {
  board[x-1][y-1] = WHITE;
}

void Board::AB(std::string value) {
  int x = value.at(0) - 'a';
  int y = (value.at(1) - 'a');
  print(std::to_string(x) + " " + std::to_string(y));
  AB(x, y);
}

void Board::AW(std::string value) {
  int x = value.at(0) - 'a';
  int y = (value.at(1) - 'a');
  print(std::to_string(x) + " " + std::to_string(y));
  AW(x, y);
}


std::string Board::ToString() {
  std::string out;

  out += "   ";
  for (int i = 0; i < board[0].size(); i++) {
    out += (char) ('a' + i);
    out += " ";
  }
  out += "\n";

  int y = board.size();
  for(std::vector< std::vector<Vertex> >::iterator xit = board.begin(); xit != board.end(); ++xit) {
    std::string y_l = std::to_string(y--);
    if (y_l.size() == 1) {
      out += " ";
    }
    out += y_l + " ";

    for(std::vector<Vertex>::iterator yit = xit->begin(); yit != xit->end(); ++yit) {
      switch (*yit) {
        case OPEN:
        out += "· ";
        break;
          if (xit == board.begin()) {
            if (yit == xit->begin()) {
              out += "┌ ";
            } else if (yit + 1 == xit->end()) {
              out += "┐ ";
            } else {
              out += "┬ ";
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
          out += "○ ";
          break;
        case BLACK:
          out += "• ";
          break;
        default:
          out += "? ";
      }
    }
    // out += "◯ ";
    // out += "◉ ";
    // out += " ◉ ";
    // out += " ○ ";
    // out += " ● ";
    out += "\n";
  }
  return out;
}

Board::~Board() {}

}
