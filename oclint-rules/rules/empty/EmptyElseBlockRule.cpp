#include "oclint/AbstractASTVisitorRule.h"
#include "oclint/RuleSet.h"

#include "AbstractEmptyBlockStmtRule.h"

class EmptyElseBlockRule : public AbstractEmptyBlockStmtRule<EmptyElseBlockRule>
{
private:
    static RuleSet rules;

public:
    virtual const string name() const
    {
        return "empty else block";
    }

    virtual const int priority() const
    {
        return 2;
    }

    bool VisitIfStmt(IfStmt *ifStmt)
    {
        return checkLexicalEmptyStmt(ifStmt->getElse(), this);
    }
};

RuleSet EmptyElseBlockRule::rules(new EmptyElseBlockRule());
