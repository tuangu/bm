/** \file account_factory.h
 *  \brief Account factory header
 */

#ifndef __ACCOUNT_FACTORY_H__
#define __ACCOUNT_FACTORY_H__

#include <memory>
#include <string>
#include "basic.h"
#include "customer.h"
#include "enterprise.h"

class AccountFactory {
public:
    AccountFactory(const AccountFactory&) = delete;
    AccountFactory(AccountFactory&&) = delete;
    AccountFactory& operator=(const AccountFactory&) = delete;
    AccountFactory& operator=(AccountFactory&&) = delete;

    static std::shared_ptr<AccountFactory> getInstance();

    std::shared_ptr<Basic> makeBasic(float initial);

    std::shared_ptr<Basic> makeCustomer(float initial, std::string firstName, std::string lastName);

    std::shared_ptr<Basic> makeEnterprise(float initial, std::string name, std::string y_tunnus);

private:
    AccountFactory() {};

    static std::shared_ptr<AccountFactory> factoryInstance;
};

#endif /* define __ACCOUNT_FACTORY_H__ */