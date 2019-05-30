#ifndef TAX_TAX36_H
#define TAX_TAX36_H

#include "TaxReturn.h"
#include <iostream>

class Tax36:public TaxReturn {
public:
    void Calculate() override;
};

#endif //TAX_TAX36_H
