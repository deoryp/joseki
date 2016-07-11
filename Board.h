#ifndef JOSEKI_BOARD_H_
#define JOSEKI_BOARD_H_

#include <string>
#include <vector>

namespace joseki {

// TODO marks and stuff...
enum Vertex {
  OPEN,
  BLACK,
  WHITE
};

class Board {
 public:
  Board();
  ~Board();

  void SZ(int x, int y);
  
  void AB(int x, int y);
  void AB(std::string value);

  void AW(int x, int y);
  void AW(std::string value);
  
  std::string ToString();
  
 private:
  std::vector< std::vector<Vertex> > board;
};

}  // namespace joseki

#endif  // JOSEKI_BOARD_H_


/*

class Planet {  
  public: 
    // Enum value DECLARATIONS - they are defined later 
    static const Planet MERCURY;  
    static const Planet VENUS;  
    // ... 

  private: 
    double mass;   // in kilograms  
    double radius; // in meters  

  private: 
    Planet(double mass, double radius) {  
        this->mass = mass;  
        this->radius = radius;  
    } 

  public: 
    // Properties and methods go here 
}; 

// Enum value DEFINITIONS 
// The initialization occurs in the scope of the class,  
// so the private Planet constructor can be used. 
const Planet Planet::MERCURY = Planet(3.303e+23, 2.4397e6);  
const Planet Planet::VENUS = Planet(4.869e+24, 6.0518e6);  
// ... 

*/