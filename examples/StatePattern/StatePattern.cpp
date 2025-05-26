#include <iostream>
using namespace std;

class State;
class ConcreteStateB;
class ConcreteStateA;
class Context;

class State {
public:
    virtual void OperationChangeState(Context*) = 0;
    virtual void OperationInterface(Context*) = 0;
    virtual ~State() { }
protected:
    bool ChangeState(Context* con, State *st);
};

class ConcreteStateA :public State {
public:
    void OperationChangeState(Context* con);

    void OperationInterface(Context* con) {
        std::cout << "ConcreteStateA::OperationInterface..." << std::endl;
    }
};


class ConcreteStateB :public State {
public:
    void OperationChangeState(Context* con) {
        OperationInterface(con);
        this->ChangeState(con, new ConcreteStateA());
    }

    void OperationInterface(Context* con) {
        std::cout << "ConcreteStateB::OperationInterface..." << std::endl;
    }
};

class Context {
public:
    Context(State* st) {
        _st = st;
    }

    void OperationInterface() {
        _st->OperationInterface(this);
    }

    void OperationChangeState() {
        _st->OperationInterface(this);
    }
private:
    friend class State;
    bool ChangeState(State* st) {
        _st = st;
        return true;
    }

    State *_st;
};

bool State::ChangeState(Context* con, State *st)
{
    return con->ChangeState(st);
}

void ConcreteStateA::OperationChangeState(Context* con)
{
    OperationInterface(con);
    this->ChangeState(con, new ConcreteStateB());
}

int main() {
    State *st = new ConcreteStateA();
    Context *con = new Context(st);
    con->OperationInterface();
    con->OperationInterface();
    con->OperationInterface();

    delete con;
    delete st;

    return 0;
}
