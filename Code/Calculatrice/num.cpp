#include "num.h"

#include "entier.h"
#include "rationnel.h"



Litterale* Num::execute(QVector<Litterale*> litterals) const {
    if(Rationnel* operande_rationnelle = dynamic_cast<Rationnel *>(litterals[0])) {
        Entier* res= new Entier(operande_rationnelle->getNumerateur());
        LitteraleNombre& ref = *res;
        delete litterals[0];
        return &ref;
    }
    else if (Entier* operande_entiere = dynamic_cast<Entier *>(litterals[0])) {
        return litterals[0];
    }
    else {
        Pile* stack = &Pile::getInstance();
        stack->setMessage("Erreur: Operande du mauvais type");
        //On réeimpile la littérale
        return litterals[0];
    }
}