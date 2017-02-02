#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>

class Expression
{
public:
    virtual ~Expression()
    {}

    virtual void print() const =0;

    //! Evaluate the tree using the given mapping of variables to numbers
    virtual double evaluate(
        const std::map<std::string,double> &bindings
    ) const =0;
    
    virtual double evaluate() const =0;

    //! Return a new tree which is the derivative w.r.t. given variable
    virtual const Expression *differentiate(
        const std::string &variable
    ) const =0;
    
    //! Return a new tree without all the zeros
    virtual const Expression *shrink(
    ) const =0;
    
    virtual bool is_number() const{
      return false;
    }
    
    virtual bool is_variable() const{
      return false;
    }
    
    virtual bool is_op() const{
      if ((!(this->is_number())) && (!(this->is_variable()))){
        return true;
      }
      return false;
    }
};


#endif
