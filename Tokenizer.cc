#include "Tokenizer.h"

#include "Processor.h"
#include "Node.h"

namespace joseki {

Tokenizer::Tokenizer(std::istream& stream, Processor* processor)
    : stream_(stream), processor_(processor) {}

GameTree* Tokenizer::Run() {
  std::string line;
  std::string token;
  bool insideNode = false;
  bool insideProperty = false;
  bool insideSequence = false;

  // TODO:: need a way to be in the property value state.

  while(std::getline(std::cin, line)) {
    for (std::string::iterator it = line.begin(); it != line.end(); ++it) {
      switch (*it){
        case '(':
          if (insideProperty) {
            processor_->PropertyEnd();
            insideProperty = false;
          }
          if (insideNode) {
            processor_->NodeEnd();
            insideNode = false;
          }
          processor_->GameTreeStart();
          if (insideSequence) {
            processor_->SequenceEnd();
            insideSequence = false;
          } else {
            processor_->SequenceStart();
            insideSequence = true;
          }
          token = "";
          break;
        case ')':
          if (insideProperty) {
            processor_->PropertyEnd();
            insideProperty = false;
          }
          if (insideNode) {
            processor_->NodeEnd();
            insideNode = false;
          }
          processor_->SequenceEnd();
          insideSequence = false;
          processor_->GameTreeEnd();
          insideNode = false;
          token = "";
          break;
        case ';':
          if (insideProperty) {
            processor_->PropertyEnd();
            insideProperty = false;
          }
          if (insideNode) {
            processor_->NodeEnd();
          }
          insideNode = true;
          processor_->NodeStart();
          token = "";
          break;
        case '[':
          if (token.size() > 0) { 
            if (insideProperty) {
              processor_->PropertyEnd();
              insideProperty = false;
            }
            processor_->PropertyStart();
            insideProperty = true;
            processor_->PropertyIdent(token);
          }
          token = "";
          break;
        case ']':
          processor_->PropertyValue(token);
          token = "";
          break;
        default:
          token += *it;
      }
    }
  }
  return processor_->GetCollection();
}

Tokenizer::~Tokenizer() {
  processor_ = NULL;
}

}
