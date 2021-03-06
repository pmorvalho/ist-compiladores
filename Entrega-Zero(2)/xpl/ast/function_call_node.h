#ifndef __XPL_FUNCTIONCALLNODE_H__
#define __XPL_FUNCTIONCALLNODE_H__

#include <cdk/ast/expression_node.h>
#include <cdk/ast/sequence_node.h>

namespace xpl {
  /**
   * Class for describing function_call nodes.
   */
  class function_call_node: public cdk::expression_node {
      std::string _id;
      cdk::sequence_node * _args;

  public:
      inline function_call_node (int lineno, std::string * id, 
        cdk::sequence_node * args):
        cdk::expression_node(lineno), _id(*id), _args(args) {}

  public:
    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // xpl

#endif
