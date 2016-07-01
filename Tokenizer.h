#ifndef JOSEKI_TOKENIZER_H_
#define JOSEKI_TOKENIZER_H_

#include <iostream>

namespace joseki {

class Processor;

class Tokenizer {
 public:
  Tokenizer(std::istream& stream, joseki::Processor* processor);
  ~Tokenizer();
  int Run();

 private:
  std::istream& stream_;
  Processor* processor_;
};

}  // namespace joseki

#endif  // JOSEKI_TOKENIZER_H_
