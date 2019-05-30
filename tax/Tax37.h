#ifndef TAX_TAX37_H
#define TAX_TAX37_H

#include "TaxReturn.h"
#include <iostream>

class Tax37:public TaxReturn {
public:

    void Calculate() override;
};

#endif //TAX_TAX37_H
